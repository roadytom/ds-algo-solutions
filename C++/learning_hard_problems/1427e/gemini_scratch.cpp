#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

// Use long long for all numbers to avoid overflow, as intermediate values can be large.
using ll = long long;

// Global vector to store the sequence of operations.
vector<string> operations;

/**
 * @brief Records a sum operation and returns the result.
 * @param a The first operand.
 * @param b The second operand.
 * @return The sum a + b.
 */
ll add(ll a, ll b) {
    operations.push_back(to_string(a) + " + " + to_string(b));
    return a + b;
}

/**
 * @brief Records a bitwise XOR operation and returns the result.
 * @param a The first operand.
 * @param b The second operand.
 * @return The result of a ^ b.
 */
ll op_xor(ll a, ll b) {
    operations.push_back(to_string(a) + " ^ " + to_string(b));
    return a ^ b;
}

/**
 * @brief Generates n * val on the blackboard using O(log n) additions.
 * This function mimics the binary exponentiation algorithm, but with addition instead of multiplication.
 * @param val The base number already on the blackboard.
 * @param n The multiplier.
 * @return The result n * val.
 */
ll multiply(ll val, ll n) {
    if (n == 0) return 0; // Should not happen with the logic, but good practice.
    if (n == 1) return val;

    // First, generate all necessary powers-of-two multiples of val.
    // e.g., to get 13*val, we need 8*val, 4*val, and 1*val.
    ll current_multiple = val;
    vector<ll> multiples_to_sum;

    for (int i = 0; i < 63; ++i) {
        if ((n >> i) & 1) {
            multiples_to_sum.push_back(current_multiple);
        }
        // Exit early if all bits of n have been processed.
        if ((n >> (i + 1)) == 0) break;
        current_multiple = add(current_multiple, current_multiple); // e.g., val -> 2*val -> 4*val -> ...
    }

    // Sum the required multiples together.
    ll result = multiples_to_sum[0];
    for (size_t i = 1; i < multiples_to_sum.size(); ++i) {
        result = add(result, multiples_to_sum[i]);
    }
    return result;
}

/**
 * @brief Implements the Extended Euclidean Algorithm.
 * Finds integers x and y such that ax + by = gcd(a, b).
 * @param x First integer.
 * @param y Second integer.
 * @param a Reference to store the first coefficient.
 * @param b Reference to store the second coefficient.
 * @return The greatest common divisor of a and b.
 */
ll extended_gcd(ll x, ll y, ll &a, ll &b) {
    if (x == 0) {
        a = 0;
        b = 1;
        return y;
    }
    ll x1, y1;
    ll d = extended_gcd(y % x, x, x1, y1);
    a = y1 - (y / x) * x1;
    b = x1;
    return d;
}


int main() {
    // Optimize standard I/O for speed.
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    cin >> x;

    // Step 1: Write on the blackboard a number y coprime with x.
    // Find the largest power of 2, p2, such that p2 <= x.
    ll p2 = 1;
    while (p2 * 2 <= x) {
        p2 *= 2;
    }

    // Generate p2*x and then y = (p2*x) ^ x.
    // It can be proven that gcd(x, (p2*x)^x) = gcd(x, p2) = 1 since x is odd.
    ll p2x = multiply(x, p2);
    ll y = op_xor(p2x, x);

    // Step 2: Write 1 = gcd(x, y) on the blackboard using Bezout's identity.
    // Find a, b such that ax + by = 1.
    ll a, b;
    extended_gcd(x, y, a, b);

    // We need to find A, B > 0 such that Ax - By = 1 (or By - Ax = 1).
    // The extended_gcd gives ax + by = 1. One coefficient will be negative.
    ll term1_coeff, term2_coeff;
    ll term1_base, term2_base;

    if (a > 0 && b < 0) {
        // Form: ax - (-b)y = 1
        term1_base = x;
        term2_base = y;
        term1_coeff = a;
        term2_coeff = -b;
    } else {
        // a < 0 && b > 0
        // Form: by - (-a)x = 1
        term1_base = y;
        term2_base = x;
        term1_coeff = b;
        term2_coeff = -a;
    }

    // Now we have term1_coeff * term1_base - term2_coeff * term2_base = 1.
    // For the final XOR to work, the second term's coefficient must be even.
    // Both x and y are odd. If term2_coeff is odd, we use the identity:
    // (A+y)x - (B+x)y = 1.
    // The new coefficient for y, (B+x), will be even since B and x are both odd.
    if (term2_coeff % 2 != 0) {
        term1_coeff = term1_coeff + term2_base;
        term2_coeff = term2_coeff + term1_base;
    }

    // Generate the two large numbers needed for the final XOR.
    ll final_term1 = multiply(term1_base, term1_coeff);
    ll final_term2 = multiply(term2_base, term2_coeff);

    // The final XOR operation that produces 1.
    op_xor(final_term1, final_term2);

    // Print the results.
    cout << operations.size() << "\n";
    for (const auto &op: operations) {
        cout << op << "\n";
    }

    return 0;
}
