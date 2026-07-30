#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define len(x) static_cast<int>((x).size())
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define v vector

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
/**

*/
class Spreadsheet {
public:
    v<v<int> > data;

    Spreadsheet(int rows) {
        data = v<v<int> >(26, v<int>(rows + 1));
    }

    int get_row(string &cell) {
        char c = cell[0];
        return (int) c - 'A';
    }

    int get_col(string &cell) {
        return get_num(cell, 1);
    }

    int get_num(string &d, int start = 0) {
        int n = len(d);
        int num = 0;
        for (int i = start; i < n; i++) {
            int digit = d[i] - '0';
            num = 10 * num + digit;
        }
        return num;
    }

    int is_cell(string &cell) {
        return isalpha(cell[0]);
    }

    int get_val(string &cell_or_num) {
        if (is_cell(cell_or_num)) {
            return data[get_row(cell_or_num)][get_col(cell_or_num)];
        }
        return get_num(cell_or_num, 0);
    }

    void setCell(string cell, int value) {
        int row = get_row(cell);
        int col = get_col(cell);
        data[row][col] = value;
    }

    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int getValue(string formula) {
        string data1, data2;
        bool before_plus = true;
        for (int i = 1; i < len(formula); i++) {
            if (formula[i] == '+') {
                before_plus = false;
                continue;
            }
            if (before_plus) {
                data1.pb(formula[i]);
            } else {
                data2.pb(formula[i]);
            }
        }
        return get_val(data1) + get_val(data2);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto *obj = new Spreadsheet(3);
    obj->getValue("=5+7");
    obj->setCell("A1", 10);
    obj->getValue("=A1+6");
    obj->setCell("B2", 15);
    obj->getValue("=A1+B2");
    obj->resetCell("A1");
    obj->getValue("=A1+B2");

    return 0;
}
