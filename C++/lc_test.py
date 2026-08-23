#!/usr/bin/env python3
import argparse
import json
import os
import re
import subprocess
import sys
import tempfile

import requests
from bs4 import BeautifulSoup

GRAPHQL_URL = "https://leetcode.com/graphql"
HEADERS = {
    "Content-Type": "application/json",
    "Referer": "https://leetcode.com",
    "User-Agent": "Mozilla/5.0",
}

GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
BOLD = "\033[1m"
RESET = "\033[0m"


def extract_problem_number(filepath):
    basename = os.path.basename(filepath).removesuffix(".cpp")
    patterns = [
        r"^(\d+)$",
        r"^\d{4}_\d{2}_\d{2}_(\d+)$",
        r"^(\d+)\.[a-zA-Z]",
        r"^(\d+)_[a-zA-Z]",
    ]
    for pat in patterns:
        m = re.match(pat, basename)
        if m:
            return m.group(1)
    return None


def fetch_problem_slug(problem_num):
    query = """
    query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
      problemsetQuestionList: questionList(
        categorySlug: $categorySlug
        limit: $limit
        skip: $skip
        filters: $filters
      ) {
        questions: data {
          questionFrontendId
          titleSlug
          title
        }
      }
    }
    """
    variables = {
        "categorySlug": "",
        "skip": 0,
        "limit": 10,
        "filters": {"searchKeywords": str(problem_num)},
    }
    resp = requests.post(
        GRAPHQL_URL, json={"query": query, "variables": variables}, headers=HEADERS
    )
    resp.raise_for_status()
    data = resp.json()
    questions = data["data"]["problemsetQuestionList"]["questions"]
    for q in questions:
        if q["questionFrontendId"] == str(problem_num):
            return q["titleSlug"], q["title"]
    return None, None


def fetch_problem_details(slug):
    query = """
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionFrontendId
        title
        exampleTestcaseList
        metaData
        content
        codeSnippets {
          langSlug
          code
        }
      }
    }
    """
    resp = requests.post(
        GRAPHQL_URL,
        json={"query": query, "variables": {"titleSlug": slug}},
        headers=HEADERS,
    )
    resp.raise_for_status()
    return resp.json()["data"]["question"]


def parse_expected_outputs(html_content):
    if not html_content:
        return []
    soup = BeautifulSoup(html_content, "lxml")
    outputs = []

    blocks = soup.find_all("div", class_="example-block")
    if blocks:
        for block in blocks:
            for p in block.find_all("p"):
                strong = p.find("strong")
                if strong and "Output" in strong.get_text():
                    span = p.find("span", class_="example-io")
                    if span:
                        outputs.append(span.get_text().strip())
                    else:
                        text = p.get_text()
                        m = re.search(r"Output:\s*(.+)", text)
                        if m:
                            outputs.append(m.group(1).strip())
        if outputs:
            return outputs

    pres = soup.find_all("pre")
    for pre in pres:
        text = pre.get_text()
        m = re.search(r"Output:\s*(.+?)(?:\n|$)", text)
        if m:
            outputs.append(m.group(1).strip())
    return outputs


def strip_main(source):
    lines = source.split("\n")
    result = []
    for line in lines:
        if re.match(r"^\s*int\s+main\s*\(", line):
            break
        result.append(line)
    return "\n".join(result)


LC_TYPE_TO_CPP = {
    "integer": "int",
    "long": "long long",
    "double": "double",
    "boolean": "bool",
    "string": "string",
    "character": "char",
    "integer[]": "vector<int>",
    "long[]": "vector<long long>",
    "double[]": "vector<double>",
    "boolean[]": "vector<bool>",
    "string[]": "vector<string>",
    "character[]": "vector<char>",
    "integer[][]": "vector<vector<int>>",
    "long[][]": "vector<vector<long long>>",
    "string[][]": "vector<vector<string>>",
    "list<integer>": "vector<int>",
    "list<long>": "vector<long long>",
    "list<string>": "vector<string>",
    "list<boolean>": "vector<bool>",
    "list<list<integer>>": "vector<vector<int>>",
    "list<list<string>>": "vector<vector<string>>",
    "ListNode": "ListNode*",
    "TreeNode": "TreeNode*",
}

PARSE_FUNCTIONS = {
    "parse_int": """
int lct_parse_int(const string& s) {
    string t = s;
    while (!t.empty() && (t.front() == ' ' || t.front() == '\\n')) t.erase(t.begin());
    while (!t.empty() && (t.back() == ' ' || t.back() == '\\n')) t.pop_back();
    return stoi(t);
}
""",
    "parse_long": """
long long lct_parse_long(const string& s) {
    string t = s;
    while (!t.empty() && (t.front() == ' ' || t.front() == '\\n')) t.erase(t.begin());
    while (!t.empty() && (t.back() == ' ' || t.back() == '\\n')) t.pop_back();
    return stoll(t);
}
""",
    "parse_double": """
double lct_parse_double(const string& s) {
    string t = s;
    while (!t.empty() && (t.front() == ' ' || t.front() == '\\n')) t.erase(t.begin());
    while (!t.empty() && (t.back() == ' ' || t.back() == '\\n')) t.pop_back();
    return stod(t);
}
""",
    "parse_bool": """
bool lct_parse_bool(const string& s) {
    return s.find("true") != string::npos;
}
""",
    "parse_string": """
string lct_parse_string(const string& s) {
    string t = s;
    while (!t.empty() && (t.front() == ' ' || t.front() == '\\n')) t.erase(t.begin());
    while (!t.empty() && (t.back() == ' ' || t.back() == '\\n')) t.pop_back();
    if (t.size() >= 2 && t.front() == '"' && t.back() == '"')
        return t.substr(1, t.size() - 2);
    return t;
}
""",
    "parse_char": """
char lct_parse_char(const string& s) {
    string t = s;
    while (!t.empty() && (t.front() == ' ' || t.front() == '\\n')) t.erase(t.begin());
    while (!t.empty() && (t.back() == ' ' || t.back() == '\\n')) t.pop_back();
    if (t.size() >= 2 && t.front() == '"' && t.back() == '"')
        return t[1];
    return t[0];
}
""",
    "parse_vector_int": """
vector<int> lct_parse_vector_int(const string& s) {
    vector<int> res;
    string t = s;
    while (!t.empty() && t.front() != '[') t.erase(t.begin());
    while (!t.empty() && t.back() != ']') t.pop_back();
    if (t.size() < 2) return res;
    t = t.substr(1, t.size() - 2);
    if (t.empty()) return res;
    stringstream ss(t);
    string tok;
    while (getline(ss, tok, ',')) {
        while (!tok.empty() && tok.front() == ' ') tok.erase(tok.begin());
        while (!tok.empty() && tok.back() == ' ') tok.pop_back();
        if (!tok.empty()) res.push_back(stoi(tok));
    }
    return res;
}
""",
    "parse_vector_long": """
vector<long long> lct_parse_vector_long(const string& s) {
    vector<long long> res;
    string t = s;
    while (!t.empty() && t.front() != '[') t.erase(t.begin());
    while (!t.empty() && t.back() != ']') t.pop_back();
    if (t.size() < 2) return res;
    t = t.substr(1, t.size() - 2);
    if (t.empty()) return res;
    stringstream ss(t);
    string tok;
    while (getline(ss, tok, ',')) {
        while (!tok.empty() && tok.front() == ' ') tok.erase(tok.begin());
        while (!tok.empty() && tok.back() == ' ') tok.pop_back();
        if (!tok.empty()) res.push_back(stoll(tok));
    }
    return res;
}
""",
    "parse_vector_double": """
vector<double> lct_parse_vector_double(const string& s) {
    vector<double> res;
    string t = s;
    while (!t.empty() && t.front() != '[') t.erase(t.begin());
    while (!t.empty() && t.back() != ']') t.pop_back();
    if (t.size() < 2) return res;
    t = t.substr(1, t.size() - 2);
    if (t.empty()) return res;
    stringstream ss(t);
    string tok;
    while (getline(ss, tok, ',')) {
        while (!tok.empty() && tok.front() == ' ') tok.erase(tok.begin());
        while (!tok.empty() && tok.back() == ' ') tok.pop_back();
        if (!tok.empty()) res.push_back(stod(tok));
    }
    return res;
}
""",
    "parse_vector_bool": """
vector<bool> lct_parse_vector_bool(const string& s) {
    vector<bool> res;
    string t = s;
    while (!t.empty() && t.front() != '[') t.erase(t.begin());
    while (!t.empty() && t.back() != ']') t.pop_back();
    if (t.size() < 2) return res;
    t = t.substr(1, t.size() - 2);
    if (t.empty()) return res;
    stringstream ss(t);
    string tok;
    while (getline(ss, tok, ',')) {
        while (!tok.empty() && tok.front() == ' ') tok.erase(tok.begin());
        while (!tok.empty() && tok.back() == ' ') tok.pop_back();
        res.push_back(tok == "true");
    }
    return res;
}
""",
    "parse_vector_string": """
vector<string> lct_parse_vector_string(const string& s) {
    vector<string> res;
    string t = s;
    while (!t.empty() && t.front() != '[') t.erase(t.begin());
    while (!t.empty() && t.back() != ']') t.pop_back();
    if (t.size() < 2) return res;
    t = t.substr(1, t.size() - 2);
    if (t.empty()) return res;
    bool in_quote = false;
    string cur;
    for (int i = 0; i < (int)t.size(); i++) {
        if (t[i] == '"') {
            in_quote = !in_quote;
        } else if (t[i] == ',' && !in_quote) {
            res.push_back(cur);
            cur.clear();
        } else {
            cur += t[i];
        }
    }
    res.push_back(cur);
    return res;
}
""",
    "parse_vector_char": """
vector<char> lct_parse_vector_char(const string& s) {
    vector<char> res;
    string t = s;
    while (!t.empty() && t.front() != '[') t.erase(t.begin());
    while (!t.empty() && t.back() != ']') t.pop_back();
    if (t.size() < 2) return res;
    t = t.substr(1, t.size() - 2);
    if (t.empty()) return res;
    bool in_quote = false;
    for (int i = 0; i < (int)t.size(); i++) {
        if (t[i] == '"') {
            in_quote = !in_quote;
        } else if (t[i] != ',' && t[i] != ' ' && in_quote) {
            res.push_back(t[i]);
        }
    }
    return res;
}
""",
    "parse_vector_vector_int": """
vector<vector<int>> lct_parse_vector_vector_int(const string& s) {
    vector<vector<int>> res;
    string t = s;
    while (!t.empty() && t.front() != '[') t.erase(t.begin());
    while (!t.empty() && t.back() != ']') t.pop_back();
    if (t.size() < 2) return res;
    t = t.substr(1, t.size() - 2);
    int depth = 0;
    string cur;
    for (char c : t) {
        if (c == '[') {
            depth++;
            cur += c;
        } else if (c == ']') {
            depth--;
            cur += c;
            if (depth == 0) {
                res.push_back(lct_parse_vector_int(cur));
                cur.clear();
            }
        } else if (c == ',' && depth == 0) {
            continue;
        } else {
            cur += c;
        }
    }
    return res;
}
""",
    "parse_vector_vector_long": """
vector<vector<long long>> lct_parse_vector_vector_long(const string& s) {
    vector<vector<long long>> res;
    string t = s;
    while (!t.empty() && t.front() != '[') t.erase(t.begin());
    while (!t.empty() && t.back() != ']') t.pop_back();
    if (t.size() < 2) return res;
    t = t.substr(1, t.size() - 2);
    int depth = 0;
    string cur;
    for (char c : t) {
        if (c == '[') { depth++; cur += c; }
        else if (c == ']') { depth--; cur += c; if (depth == 0) { res.push_back(lct_parse_vector_long(cur)); cur.clear(); } }
        else if (c == ',' && depth == 0) { continue; }
        else { cur += c; }
    }
    return res;
}
""",
    "parse_vector_vector_string": """
vector<vector<string>> lct_parse_vector_vector_string(const string& s) {
    vector<vector<string>> res;
    string t = s;
    while (!t.empty() && t.front() != '[') t.erase(t.begin());
    while (!t.empty() && t.back() != ']') t.pop_back();
    if (t.size() < 2) return res;
    t = t.substr(1, t.size() - 2);
    int depth = 0;
    string cur;
    for (char c : t) {
        if (c == '[') { depth++; cur += c; }
        else if (c == ']') { depth--; cur += c; if (depth == 0) { res.push_back(lct_parse_vector_string(cur)); cur.clear(); } }
        else if (c == ',' && depth == 0) { continue; }
        else { cur += c; }
    }
    return res;
}
""",
    "parse_listnode": """
ListNode* lct_parse_listnode(const string& s) {
    vector<int> vals = lct_parse_vector_int(s);
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int v : vals) { cur->next = new ListNode(v); cur = cur->next; }
    return dummy.next;
}
""",
    "parse_treenode": """
TreeNode* lct_parse_treenode(const string& s) {
    string t = s;
    while (!t.empty() && t.front() != '[') t.erase(t.begin());
    while (!t.empty() && t.back() != ']') t.pop_back();
    if (t.size() < 2) return nullptr;
    t = t.substr(1, t.size() - 2);
    if (t.empty()) return nullptr;
    vector<string> tokens;
    stringstream ss(t);
    string tok;
    while (getline(ss, tok, ',')) {
        while (!tok.empty() && tok.front() == ' ') tok.erase(tok.begin());
        while (!tok.empty() && tok.back() == ' ') tok.pop_back();
        tokens.push_back(tok);
    }
    if (tokens.empty() || tokens[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)tokens.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < (int)tokens.size() && tokens[i] != "null") {
            node->left = new TreeNode(stoi(tokens[i]));
            q.push(node->left);
        }
        i++;
        if (i < (int)tokens.size() && tokens[i] != "null") {
            node->right = new TreeNode(stoi(tokens[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}
""",
}

SERIALIZE_FUNCTIONS = {
    "serialize_int": """
string lct_serialize_int(int v) { return to_string(v); }
""",
    "serialize_long": """
string lct_serialize_long(long long v) { return to_string(v); }
""",
    "serialize_double": """
string lct_serialize_double(double v) {
    ostringstream oss;
    oss << fixed << setprecision(5) << v;
    string r = oss.str();
    if (r.find('.') != string::npos) {
        while (r.back() == '0') r.pop_back();
        if (r.back() == '.') r.pop_back();
    }
    return r;
}
""",
    "serialize_bool": """
string lct_serialize_bool(bool v) { return v ? "true" : "false"; }
""",
    "serialize_string": """
string lct_serialize_string(const string& v) { return "\\\"" + v + "\\\""; }
""",
    "serialize_char": """
string lct_serialize_char(char v) { return string("\\\"") + v + "\\\""; }
""",
    "serialize_vector_int": """
string lct_serialize_vector_int(const vector<int>& v) {
    string r = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) r += ",";
        r += to_string(v[i]);
    }
    return r + "]";
}
""",
    "serialize_vector_long": """
string lct_serialize_vector_long(const vector<long long>& v) {
    string r = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) r += ",";
        r += to_string(v[i]);
    }
    return r + "]";
}
""",
    "serialize_vector_double": """
string lct_serialize_vector_double(const vector<double>& v) {
    string r = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) r += ",";
        r += lct_serialize_double(v[i]);
    }
    return r + "]";
}
""",
    "serialize_vector_bool": """
string lct_serialize_vector_bool(const vector<bool>& v) {
    string r = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) r += ",";
        r += (v[i] ? "true" : "false");
    }
    return r + "]";
}
""",
    "serialize_vector_string": """
string lct_serialize_vector_string(const vector<string>& v) {
    string r = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) r += ",";
        r += "\\\"" + v[i] + "\\\"";
    }
    return r + "]";
}
""",
    "serialize_vector_char": """
string lct_serialize_vector_char(const vector<char>& v) {
    string r = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) r += ",";
        r += string("\\\"") + v[i] + "\\\"";
    }
    return r + "]";
}
""",
    "serialize_vector_vector_int": """
string lct_serialize_vector_vector_int(const vector<vector<int>>& v) {
    string r = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) r += ",";
        r += lct_serialize_vector_int(v[i]);
    }
    return r + "]";
}
""",
    "serialize_vector_vector_long": """
string lct_serialize_vector_vector_long(const vector<vector<long long>>& v) {
    string r = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) r += ",";
        r += lct_serialize_vector_long(v[i]);
    }
    return r + "]";
}
""",
    "serialize_vector_vector_string": """
string lct_serialize_vector_vector_string(const vector<vector<string>>& v) {
    string r = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) r += ",";
        r += lct_serialize_vector_string(v[i]);
    }
    return r + "]";
}
""",
    "serialize_listnode": """
string lct_serialize_listnode(ListNode* head) {
    string r = "[";
    bool first = true;
    while (head) {
        if (!first) r += ",";
        r += to_string(head->val);
        first = false;
        head = head->next;
    }
    return r + "]";
}
""",
    "serialize_treenode": """
string lct_serialize_treenode(TreeNode* root) {
    if (!root) return "[]";
    string r = "[";
    queue<TreeNode*> q;
    q.push(root);
    vector<string> tokens;
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            tokens.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            tokens.push_back("null");
        }
    }
    while (!tokens.empty() && tokens.back() == "null") tokens.pop_back();
    for (int i = 0; i < (int)tokens.size(); i++) {
        if (i) r += ",";
        r += tokens[i];
    }
    return r + "]";
}
""",
}

TYPE_TO_PARSER = {
    "integer": "parse_int",
    "long": "parse_long",
    "double": "parse_double",
    "boolean": "parse_bool",
    "string": "parse_string",
    "character": "parse_char",
    "integer[]": "parse_vector_int",
    "long[]": "parse_vector_long",
    "double[]": "parse_vector_double",
    "boolean[]": "parse_vector_bool",
    "string[]": "parse_vector_string",
    "character[]": "parse_vector_char",
    "integer[][]": "parse_vector_vector_int",
    "long[][]": "parse_vector_vector_long",
    "string[][]": "parse_vector_vector_string",
    "list<integer>": "parse_vector_int",
    "list<long>": "parse_vector_long",
    "list<string>": "parse_vector_string",
    "list<boolean>": "parse_vector_bool",
    "list<list<integer>>": "parse_vector_vector_int",
    "list<list<string>>": "parse_vector_vector_string",
    "ListNode": "parse_listnode",
    "TreeNode": "parse_treenode",
}

TYPE_TO_SERIALIZER = {
    "integer": "serialize_int",
    "long": "serialize_long",
    "double": "serialize_double",
    "boolean": "serialize_bool",
    "string": "serialize_string",
    "character": "serialize_char",
    "integer[]": "serialize_vector_int",
    "long[]": "serialize_vector_long",
    "double[]": "serialize_vector_double",
    "boolean[]": "serialize_vector_bool",
    "string[]": "serialize_vector_string",
    "character[]": "serialize_vector_char",
    "integer[][]": "serialize_vector_vector_int",
    "long[][]": "serialize_vector_vector_long",
    "string[][]": "serialize_vector_vector_string",
    "list<integer>": "serialize_vector_int",
    "list<long>": "serialize_vector_long",
    "list<string>": "serialize_vector_string",
    "list<boolean>": "serialize_vector_bool",
    "list<list<integer>>": "serialize_vector_vector_int",
    "list<list<string>>": "serialize_vector_vector_string",
    "ListNode": "serialize_listnode",
    "TreeNode": "serialize_treenode",
}


def get_parser_deps(parser_name):
    deps = {
        "parse_vector_vector_int": ["parse_vector_int"],
        "parse_vector_vector_long": ["parse_vector_long"],
        "parse_vector_vector_string": ["parse_vector_string"],
        "parse_listnode": ["parse_vector_int"],
    }
    return deps.get(parser_name, [])


def get_serializer_deps(ser_name):
    deps = {
        "serialize_vector_vector_int": ["serialize_vector_int"],
        "serialize_vector_vector_long": ["serialize_vector_long"],
        "serialize_vector_vector_string": ["serialize_vector_string"],
        "serialize_vector_double": ["serialize_double"],
    }
    return deps.get(ser_name, [])


def needs_struct(lc_type):
    if "ListNode" in lc_type:
        return "ListNode"
    if "TreeNode" in lc_type:
        return "TreeNode"
    return None


LISTNODE_DEF = """
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
"""

TREENODE_DEF = """
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
"""


def generate_harness(user_source, metadata):
    meta = json.loads(metadata)

    if "classname" in meta and meta.get("classname") != "Solution":
        print(f"{YELLOW}Design-class problems are not supported.{RESET}")
        sys.exit(1)

    method_name = meta["name"]
    params = meta["params"]
    return_type = meta["return"]["type"]

    stripped = strip_main(user_source)

    needed_structs = set()
    for p in params:
        ns = needs_struct(p["type"])
        if ns:
            needed_structs.add(ns)
    ns = needs_struct(return_type)
    if ns:
        needed_structs.add(ns)

    struct_defs = ""
    if "ListNode" in needed_structs and "struct ListNode" not in stripped:
        struct_defs += LISTNODE_DEF
    if "TreeNode" in needed_structs and "struct TreeNode" not in stripped:
        struct_defs += TREENODE_DEF

    needed_parsers = set()
    for p in params:
        pname = TYPE_TO_PARSER.get(p["type"])
        if pname:
            needed_parsers.add(pname)
            for dep in get_parser_deps(pname):
                needed_parsers.add(dep)

    needed_serializers = set()
    if return_type != "void":
        sname = TYPE_TO_SERIALIZER.get(return_type)
        if sname:
            needed_serializers.add(sname)
            for dep in get_serializer_deps(sname):
                needed_serializers.add(dep)
    else:
        if params:
            sname = TYPE_TO_SERIALIZER.get(params[0]["type"])
            if sname:
                needed_serializers.add(sname)
                for dep in get_serializer_deps(sname):
                    needed_serializers.add(dep)

    harness = struct_defs + "\n" + stripped + "\n"
    harness += "\n#undef s\n#undef f\n#undef v\n#undef mp\n#undef pb\n#undef ppb\n#undef len\n"
    harness += "\n// === LeetCode Test Harness ===\n"
    harness += "#include <sstream>\n#include <queue>\n\n"

    ordered_parsers = []
    added = set()

    def add_parser(name):
        if name in added:
            return
        for dep in get_parser_deps(name):
            add_parser(dep)
        added.add(name)
        ordered_parsers.append(name)

    for pname in needed_parsers:
        add_parser(pname)

    for pname in ordered_parsers:
        if pname in PARSE_FUNCTIONS:
            harness += PARSE_FUNCTIONS[pname]

    ordered_serializers = []
    added_s = set()

    def add_serializer(name):
        if name in added_s:
            return
        for dep in get_serializer_deps(name):
            add_serializer(dep)
        added_s.add(name)
        ordered_serializers.append(name)

    for sname in needed_serializers:
        add_serializer(sname)

    for sname in ordered_serializers:
        if sname in SERIALIZE_FUNCTIONS:
            harness += SERIALIZE_FUNCTIONS[sname]

    harness += "\nint main() {\n"
    harness += "    vector<string> lct_lines;\n"
    harness += "    { string lct_line; while (getline(cin, lct_line)) { if (!lct_line.empty()) lct_lines.push_back(lct_line); } }\n"

    for i, p in enumerate(params):
        cpp_type = LC_TYPE_TO_CPP.get(p["type"], p["type"])
        parser = TYPE_TO_PARSER.get(p["type"])
        if parser:
            harness += f"    {cpp_type} lct_{p['name']} = lct_{parser}(lct_lines[{i}]);\n"
        else:
            print(f"{YELLOW}Unsupported parameter type: {p['type']}{RESET}")
            sys.exit(1)

    args = ", ".join(f"lct_{p['name']}" for p in params)

    if return_type == "void":
        harness += f"    Solution lct_sol;\n"
        harness += f"    lct_sol.{method_name}({args});\n"
        if params:
            ser = TYPE_TO_SERIALIZER.get(params[0]["type"])
            if ser:
                harness += f"    cout << lct_{ser}(lct_{params[0]['name']}) << endl;\n"
    else:
        cpp_ret = LC_TYPE_TO_CPP.get(return_type, return_type)
        ser = TYPE_TO_SERIALIZER.get(return_type)
        harness += f"    Solution lct_sol;\n"
        harness += f"    {cpp_ret} lct_result = lct_sol.{method_name}({args});\n"
        if ser:
            harness += f"    cout << lct_{ser}(lct_result) << endl;\n"
        else:
            harness += f"    cout << lct_result << endl;\n"

    harness += "    return 0;\n}\n"
    return harness


def compile_harness(harness_code, compiler, cpp_file_dir):
    tmp_src = tempfile.NamedTemporaryFile(suffix=".cpp", mode="w", delete=False)
    tmp_src.write(harness_code)
    tmp_src.close()

    tmp_bin = tmp_src.name.replace(".cpp", "")

    try:
        result = subprocess.run(
            [compiler, "-std=c++23", "-O2", f"-I{cpp_file_dir}", "-o", tmp_bin, tmp_src.name],
            capture_output=True,
            text=True,
            timeout=30,
        )
        if result.returncode != 0:
            print(f"{RED}Compilation failed:{RESET}")
            print(result.stderr)
            os.unlink(tmp_src.name)
            return None, None
        return tmp_bin, tmp_src.name
    except subprocess.TimeoutExpired:
        print(f"{RED}Compilation timed out (30s){RESET}")
        os.unlink(tmp_src.name)
        return None, None


def run_test(binary_path, input_str):
    try:
        result = subprocess.run(
            [binary_path],
            input=input_str,
            capture_output=True,
            text=True,
            timeout=10,
        )
        if result.returncode != 0:
            return None, f"Runtime error (exit code {result.returncode})\n{result.stderr}"
        return result.stdout.strip(), None
    except subprocess.TimeoutExpired:
        return None, "Time Limit Exceeded (10s)"


def normalize(text):
    text = text.strip()
    text = re.sub(r"\s+", "", text)
    return text


def compare(actual, expected, return_type):
    na, ne = normalize(actual), normalize(expected)
    if na == ne:
        return True
    if return_type in ("double",):
        try:
            return abs(float(actual.strip()) - float(expected.strip())) < 1e-5
        except ValueError:
            pass
    return False


def main():
    parser = argparse.ArgumentParser(description="Test C++ LeetCode solutions against sample cases")
    parser.add_argument("file", help="Path to the C++ solution file")
    parser.add_argument("--problem", "-p", type=int, help="LeetCode problem number (auto-detected from filename)")
    parser.add_argument("--compiler", "-c", default="g++", help="C++ compiler (default: g++)")
    args = parser.parse_args()

    if not os.path.isfile(args.file):
        print(f"{RED}File not found: {args.file}{RESET}")
        sys.exit(1)

    problem_num = args.problem
    if not problem_num:
        extracted = extract_problem_number(args.file)
        if not extracted:
            print(f"{RED}Cannot extract problem number from filename.{RESET}")
            print(f"Use: python3 lc_test.py {args.file} --problem NUM")
            sys.exit(1)
        problem_num = extracted

    print(f"Fetching problem {problem_num} from LeetCode...")
    try:
        slug, title = fetch_problem_slug(problem_num)
    except requests.RequestException as e:
        print(f"{RED}Network error: {e}{RESET}")
        sys.exit(1)

    if not slug:
        print(f"{RED}Problem {problem_num} not found on LeetCode.{RESET}")
        sys.exit(1)

    try:
        details = fetch_problem_details(slug)
    except requests.RequestException as e:
        print(f"{RED}Network error: {e}{RESET}")
        sys.exit(1)

    test_inputs = details.get("exampleTestcaseList", [])
    expected_outputs = parse_expected_outputs(details.get("content", ""))
    metadata = details.get("metaData", "")

    if not test_inputs:
        print(f"{YELLOW}No sample test cases found.{RESET}")
        sys.exit(1)

    if not metadata:
        print(f"{RED}No metadata found for this problem.{RESET}")
        sys.exit(1)

    print(f"\n{BOLD}LeetCode {problem_num}: {title}{RESET}")
    print("=" * (len(f"LeetCode {problem_num}: {title}")))

    with open(args.file, "r") as fh:
        user_source = fh.read()

    harness_code = generate_harness(user_source, metadata)

    cpp_file_dir = os.path.dirname(os.path.abspath(args.file))
    project_root = os.path.dirname(os.path.abspath(__file__))

    binary, tmp_src = compile_harness(harness_code, args.compiler, project_root)
    if not binary:
        sys.exit(1)

    passed = 0
    total = len(test_inputs)
    meta = json.loads(metadata)
    return_type = meta["return"]["type"]
    num_params = len(meta["params"])

    try:
        for i, test_input in enumerate(test_inputs):
            actual, error = run_test(binary, test_input)

            expected = expected_outputs[i] if i < len(expected_outputs) else None

            input_display = test_input.replace("\n", ", ")

            if error:
                print(f"\n{YELLOW}Test {i+1}/{total}: ERROR{RESET}")
                print(f"  Input:  {input_display}")
                if expected is not None:
                    print(f"  Expect: {expected}")
                print(f"  Error:  {error}")
            elif expected is None:
                print(f"\nTest {i+1}/{total}: (no expected output)")
                print(f"  Input:  {input_display}")
                print(f"  Output: {actual}")
            elif compare(actual, expected, return_type):
                passed += 1
                print(f"\n{GREEN}Test {i+1}/{total}: PASS{RESET}")
                print(f"  Input:  {input_display}")
                print(f"  Expect: {expected}")
                print(f"  Output: {actual}")
            else:
                print(f"\n{RED}Test {i+1}/{total}: FAIL{RESET}")
                print(f"  Input:  {input_display}")
                print(f"  Expect: {expected}")
                print(f"  Output: {actual}")

        if expected_outputs:
            color = GREEN if passed == total else RED
            print(f"\n{color}Result: {passed}/{total} passed{RESET}")
        else:
            print(f"\n{YELLOW}No expected outputs to compare against.{RESET}")
    finally:
        if binary and os.path.exists(binary):
            os.unlink(binary)
        if tmp_src and os.path.exists(tmp_src):
            os.unlink(tmp_src)


if __name__ == "__main__":
    main()
