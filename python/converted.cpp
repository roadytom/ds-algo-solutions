#include <iostream>
#include <vector>
#include <string>
#include <sstream>   // For std::istringstream
#include <numeric>   // For potential future use like std::gcd, std::accumulate
#include <algorithm> // For std::max, std::sort, etc.
#include <cmath>     // For std::pow, std::sqrt, etc.
#include <map>
#include <tuple>
#include <limits>    // For std::numeric_limits

// Corresponds to Python's math.factorial
long long custom_factorial(int n) {
    if (n < 0) {
        // Python's math.factorial raises ValueError.
        // Here, we'll return 0 to indicate an issue, or one could throw.
        // This behavior needs to be consistent with how perm/comb handle it.
        return 0;
    }
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

// Python: def read_words(): return sys.stdin.readline().split()
std::vector<std::string> read_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

// Python: def read_int(): return int(sys.stdin.readline().rstrip())
int read_int() {
    std::string line;
    std::getline(std::cin, line);
    // std::stoi handles leading/trailing whitespace, similar to rstrip() then int()
    return std::stoi(line);
}

// Python: def read_char_list(): return list(sys.stdin.readline().rstrip())
std::vector<char> read_char_list() {
    std::string line;
    std::getline(std::cin, line);
    // Equivalent of rstrip() for common whitespace characters
    size_t endpos = line.find_last_not_of(" \t\n\v\f\r");
    if (std::string::npos != endpos) {
        line.resize(endpos + 1);
    } else {
        line.clear(); // String was all whitespace or empty
    }
    return std::vector<char>(line.begin(), line.end());
}

// Python: def read_int_list(): return [int(x) for x in sys.stdin.readline().split()]
std::vector<int> read_int_list() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> numbers;
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

// Python: def read_int_list_0_indexed(): return [int(x) - 1 for x in sys.stdin.readline().split()]
std::vector<int> read_int_list_0_indexed() {
    std::vector<int> numbers = read_int_list();
    for (size_t i = 0; i < numbers.size(); ++i) {
        numbers[i]--;
    }
    return numbers;
}

// Python: def read_word_char_lists(): return [list(x) for x in sys.stdin.readline().split()]
std::vector<std::vector<char>> read_word_char_lists() {
    std::vector<std::string> words = read_words();
    std::vector<std::vector<char>> result;
    result.reserve(words.size());
    for (const std::string& word : words) {
        result.push_back(std::vector<char>(word.begin(), word.end()));
    }
    return result;
}

// Python: def read_n_lines(n): return [sys.stdin.readline().strip() for _ in range(n)]
std::vector<std::string> read_n_lines(int n) {
    std::vector<std::string> lines_vec; // Renamed to avoid conflict
    lines_vec.reserve(n);
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        // Equivalent of strip() for common whitespace
        size_t startpos = line.find_first_not_of(" \t\n\v\f\r");
        if (std::string::npos == startpos) {
            lines_vec.push_back(""); // Line was all whitespace
        } else {
            size_t endpos = line.find_last_not_of(" \t\n\v\f\r");
            lines_vec.push_back(line.substr(startpos, endpos - startpos + 1));
        }
    }
    return lines_vec;
}

// Python: def read_n_lines_words(n): return [read_words() for _ in range(n)]
std::vector<std::vector<std::string>> read_n_lines_words(int n) {
    std::vector<std::vector<std::string>> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        result.push_back(read_words());
    }
    return result;
}

// Python: def read_n_ints(n): return [read_int() for _ in range(n)]
std::vector<int> read_n_ints(int n) {
    std::vector<int> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        result.push_back(read_int());
    }
    return result;
}

// Python: def read_n_int_lists(n): return [read_int_list() for _ in range(n)]
std::vector<std::vector<int>> read_n_int_lists(int n) {
    std::vector<std::vector<int>> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        result.push_back(read_int_list());
    }
    return result;
}

// Python: def read_n_int_lists_0_indexed(n): return [read_int_list_0_indexed() for _ in range(n)]
std::vector<std::vector<int>> read_n_int_lists_0_indexed(int n) {
    std::vector<std::vector<int>> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        result.push_back(read_int_list_0_indexed());
    }
    return result;
}

// Python: def read_n_char_lists(n): return [read_char_list() for _ in range(n)]
std::vector<std::vector<char>> read_n_char_lists(int n) {
    std::vector<std::vector<char>> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        result.push_back(read_char_list());
    }
    return result;
}

// Python: def read_n_word_char_lists(n): return [read_word_char_lists() for _ in range(n)]
std::vector<std::vector<std::vector<char>>> read_n_word_char_lists(int n) {
    std::vector<std::vector<std::vector<char>>> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        result.push_back(read_word_char_lists());
    }
    return result;
}

// Python: def perm(n, r): return math.factorial(n) // math.factorial(r)
long long perm(int n, int r_param) { // r renamed to r_param
    if (n < 0 || r_param < 0) { // math.factorial would raise error for negative
        return 0; // Or throw exception to match Python's behavior more closely
    }
    long long fact_n = custom_factorial(n);
    long long fact_r_param = custom_factorial(r_param);

    if (fact_r_param == 0) { // Should only happen if r_param was negative and custom_factorial returned 0
                           // Or if factorial itself could be zero (not for non-negative input)
        // Python would have raised error in math.factorial(r_param) or ZeroDivisionError
        return std::numeric_limits<long long>::max(); // Indicate error or undefined behavior
    }
    return fact_n / fact_r_param; // Integer division
}

// Python: def comb(n, r): return math.factorial(n) // (math.factorial(r) * math.factorial(n - r))
long long comb(int n, int r_param) { // r renamed to r_param
    if (r_param < 0 || r_param > n || n < 0) {
        // Python's math.factorial would error for n < 0, r_param < 0, or (n-r_param) < 0
        return 0; // Standard combinatorial definition C(n,r)=0 for r<0 or r>n.
                  // Also handles n < 0 where factorials are problematic.
    }

    long long fact_n = custom_factorial(n);
    long long fact_r_param = custom_factorial(r_param);
    long long fact_n_minus_r_param = custom_factorial(n - r_param);

    if (fact_r_param == 0 || fact_n_minus_r_param == 0) {
        // This case should ideally be caught by initial checks if custom_factorial(negative) is 0
        return std::numeric_limits<long long>::max(); // Indicate error
    }
    long long denominator = fact_r_param * fact_n_minus_r_param;
    if (denominator == 0) { // Should not happen if individual factorials are non-zero
        return std::numeric_limits<long long>::max(); // Indicate error
    }
    return fact_n / denominator; // Integer division
}

// Python: def make_list(n, *args, default=0): ...
// This function is for creating N-dimensional lists with a default value.
// Translating it with variadic arguments and *args to C++ is complex
// and it's not used in the provided main() logic. So, it's omitted for brevity.
// One would typically use nested std::vector initializations in C++.

// Global constants from Python script
const std::vector<std::vector<int>> dire = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const std::vector<std::vector<int>> dire8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
const std::string py_alphabets = "abcdefghijklmnopqrstuvwxyz";         // Renamed to avoid potential conflicts
const std::string py_ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";       // Renamed
const int PY_MOD = 1000000007;                                       // Renamed
const double PY_INF = std::numeric_limits<double>::infinity();       // Renamed

// sys.setrecursionlimit(10 ** 3)
// C++ does not have a direct, standard portable equivalent to sys.setrecursionlimit.
// The default stack size in C++ is usually larger and often sufficient for recursion depths
// like 1000. If a larger limit is needed, it's typically handled by compiler/linker flags.

// --- Core Logic from Python's main() ---
using DpKeyType = std::tuple<int, int, int>;
std::map<DpKeyType, int> memo_for_dp_func;    // Corresponds to first 'memo = {}'
std::map<DpKeyType, int> memo_for_dp2_func;   // Corresponds to second 'memo = {}'
int global_max_level;                        // To pass max_level from dp_func to dp2_func

// Forward declaration
int dp_func(int level, int r, int g);
int dp2_func(int level, int r, int g);

// Python: def dp(level, r, g): ...
int dp_func(int level, int r, int g) {
    if (level > r && level > g) {
        return 0;
    }
    DpKeyType key = std::make_tuple(level, r, g);
    auto it = memo_for_dp_func.find(key);
    if (it != memo_for_dp_func.end()) {
        return it->second;
    }
    int first = 0, second = 0;
    if (r >= level) {
        first = dp_func(level + 1, r - level, g);
    }
    if (g >= level) {
        second = dp_func(level + 1, r, g - level);
    }
    memo_for_dp_func[key] = std::max(first, second) + 1;
    return memo_for_dp_func[key];
}

// Python: def dp2(level, r, g): ...
int dp2_func(int level, int r, int g) {
    if (level > r && level > g) {
        return static_cast<int>(((level - 1) >= global_max_level));
    }
    DpKeyType key = std::make_tuple(level, r, g);
    auto it = memo_for_dp2_func.find(key);
    if (it != memo_for_dp2_func.end()) {
        return it->second;
    }
    long long first = 0, second = 0; // Use long long for intermediate sum to prevent overflow before modulo
    if (r >= level) {
        first = dp2_func(level + 1, r - level, g);
    }
    if (g >= level) {
        second = dp2_func(level + 1, r, g - level);
    }
    memo_for_dp2_func[key] = static_cast<int>((first + second) % PY_MOD);
    return memo_for_dp2_func[key];
}

// Python: def main(): ...
void translated_main() {
    std::vector<int> initial_rg = read_int_list();
    int R_val = initial_rg[0];
    int G_val = initial_rg[1];

    // memo = {} for dp_func
    memo_for_dp_func.clear();
    global_max_level = dp_func(1, R_val, G_val);

    // memo = {} for dp2_func
    memo_for_dp2_func.clear();
    std::cout << dp2_func(1, R_val, G_val) << std::endl;
}

int main() {
    // Optional: For faster I/O in competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    translated_main(); // Call the translated logic

    return 0;
}