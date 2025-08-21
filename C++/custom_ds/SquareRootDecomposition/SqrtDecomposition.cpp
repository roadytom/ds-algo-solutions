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

class SqrtDecomposition {
    vector<ll> blocks; // Array to store sums of blocks
    int block_size; // Size of each block
    int n; // Size of the original array

public:
    // Constructor to preprocess the array
    explicit SqrtDecomposition(const vector<int> &input_arr) {
        n = input_arr.size();
        if (n == 0) {
            block_size = 0;
            return;
        }

        // 1. Calculate block size
        block_size = (int) (sqrt(n + .0)) + 1;

        // 2. Initialize the blocks array
        blocks.assign(block_size, 0);
        // arr.resize(n);

        // 3. Populate the original array and pre-calculate block sums
        for (int i = 0; i < n; ++i) {
            // arr[i] = input_arr[i];
            blocks[i / block_size] += input_arr[i];
        }
    }

    // Point update: O(1)
    void update(int index, int new_value, vector<int> &input_arr) {
        if (index < 0 || index >= n) {
            return; // Index out of bounds
        }
        int block_index = index / block_size;

        // Update the block sum and the array value
        blocks[block_index] += (new_value - input_arr[index]);
        input_arr[index] = new_value;
    }

    // Range sum query: O(sqrt(N))
    ll query(int l, int r, const vector<int> &input_arr) {
        if (l < 0 || r >= n || l > r) {
            return 0; // Invalid range
        }

        ll sum = 0;
        int start_block = l / block_size;
        int end_block = r / block_size;

        if (start_block == end_block) {
            // Case 1: Query range is within a single block
            for (int i = l; i <= r; ++i) {
                sum += input_arr[i];
            }
        } else {
            // Case 2: Query range spans multiple blocks

            // Part 1: Handle the first partial block
            for (int i = l; i < (start_block + 1) * block_size; ++i) {
                sum += input_arr[i];
            }

            // Part 2: Handle the full blocks in between
            for (int i = start_block + 1; i < end_block; ++i) {
                sum += blocks[i];
            }

            // Part 3: Handle the last partial block
            for (int i = end_block * block_size; i <= r; ++i) {
                sum += input_arr[i];
            }
        }
        return sum;
    }
};

// Example Usage
int main() {
    vector<int> nums = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
    SqrtDecomposition sd(nums);

    // Query for the sum of the range [2, 8]
    // Original subarray: {2, 4, 6, 1, 3, 5, 7}
    // Expected sum: 28
    cout << "Sum of range [2, 8]: " << sd.query(2, 8, nums) << endl;

    // Update the element at index 4 to 10
    // New array: {1, 5, 2, 4, 10, 1, 3, 5, 7, 10}
    sd.update(4, 10, nums);

    // Query the same range again
    // New subarray: {2, 4, 10, 1, 3, 5, 7}
    // Expected sum: 32
    cout << "Sum of range [2, 8] after update: " << sd.query(2, 8, nums) << endl;

    return 0;
}
