#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/

/**
 * @brief Solves the 2-Satisfiability problem using Kosaraju's algorithm to find Strongly Connected Components (SCCs).
 *
 * The 2-SAT problem asks whether a given boolean formula in conjunctive normal form,
 * with each clause having at most two literals, can be satisfied.
 *
 * This implementation maps the problem to an implication graph and checks for contradictions.
 * A formula is unsatisfiable if and only if a variable and its negation belong to the same SCC.
 */
struct TwoSatSolver {
    // The number of boolean variables in the problem.
    int num_variables;
    // The number of vertices in the implication graph (2 for each variable: one for the literal and one for its negation).
    int num_vertices;

    // Adjacency lists for the implication graph and its transpose.
    vector<vector<int> > implication_graph;
    vector<vector<int> > transposed_graph;

    // --- Helper members for Kosaraju's algorithm ---
    vector<bool> visited;
    // Stores vertices by their finishing time in the first DFS pass. This determines the processing order for the second pass.
    vector<int> processing_order;
    // Stores the Strongly Connected Component (SCC) ID for each vertex.
    vector<int> scc_id;

    // Stores the final satisfying assignment for the variables (if one exists).
    vector<bool> variable_assignment;

    /**
     * @brief Constructor to initialize the solver.
     * @param n_vars The number of boolean variables (e.g., x_0, x_1, ..., x_{n_vars-1}).
     */
    explicit TwoSatSolver(int n_vars) : num_variables(n_vars),
                                        num_vertices(2 * n_vars),
                                        implication_graph(num_vertices),
                                        transposed_graph(num_vertices),
                                        variable_assignment(n_vars) {
        processing_order.reserve(num_vertices);
    }

    /**
     * @brief Adds a disjunctive clause (var1 OR var2) to the problem.
     *
     * @param var1_idx The 0-indexed index of the first variable.
     * @param is_negated1 True if the first variable is negated (e.g., NOT x_1).
     * @param var2_idx The 0-indexed index of the second variable.
     * @param is_negated2 True if the second variable is negated.
     */
    void add_disjunction(int var1_idx, bool is_negated1, int var2_idx, bool is_negated2) {
        // --- Vertex Representation ---
        // A boolean variable `x_i` is mapped to two vertices in the graph:
        // - Vertex `2 * i` represents the literal `x_i`.
        // - Vertex `2 * i + 1` represents its negation `¬x_i`.
        // The `is_negated` flag is XORed to select the correct vertex.
        int u = 2 * var1_idx + is_negated1;
        int v = 2 * var2_idx + is_negated2;

        // --- Implication Logic ---
        // A clause `(a ∨ b)` is logically equivalent to two implications:
        // 1. `(¬a ⇒ b)`: If 'a' is false, 'b' must be true.
        // 2. `(¬b ⇒ a)`: If 'b' is false, 'a' must be true.
        // The negation of a vertex `u` is simply `u ^ 1`. For example, `(2*i)`'s negation is `(2*i+1)` and vice-versa.
        int neg_u = u ^ 1;
        int neg_v = v ^ 1;

        // Add edges corresponding to the implications to the graph and its transpose.
        // Edge for `¬a ⇒ b`
        implication_graph[neg_u].push_back(v);
        transposed_graph[v].push_back(neg_u);
        // Edge for `¬b ⇒ a`
        implication_graph[neg_v].push_back(u);
        transposed_graph[u].push_back(neg_v);
    }

    /**
     * @brief Attempts to solve the 2-SAT instance.
     * @return True if a satisfying assignment exists, false otherwise.
     */
    bool solve() {
        // --- Step 1: Kosaraju's Algorithm - First DFS Pass ---
        // This pass traverses the original implication graph to determine the
        // reverse topological order of vertices, stored in `processing_order`.
        visited.assign(num_vertices, false);
        processing_order.clear();
        for (int i = 0; i < num_vertices; ++i) {
            if (!visited[i]) {
                first_dfs_pass(i);
            }
        }

        // --- Step 2: Kosaraju's Algorithm - Second DFS Pass ---
        // This pass traverses the transposed graph in the order determined by step 1.
        // Each traversal from an unvisited node finds one Strongly Connected Component.
        scc_id.assign(num_vertices, -1);
        int current_scc_id = 0;
        for (int i = 0; i < num_vertices; ++i) {
            int vertex = processing_order[num_vertices - 1 - i];
            if (scc_id[vertex] == -1) {
                second_dfs_pass(vertex, current_scc_id++);
            }
        }

        // --- Step 3: Check for Satisfiability and Construct Assignment ---
        // A solution is possible if and only if no variable and its negation
        // are in the same SCC.
        for (int i = 0; i < num_vertices; i += 2) {
            if (scc_id[i] == scc_id[i + 1]) {
                return false; // Contradiction found: x_i and ¬x_i are in the same SCC.
            }
            // The SCCs are numbered in reverse topological order. If the SCC of `x_i` has a
            // larger ID than the SCC of `¬x_i`, it means `¬x_i` comes before `x_i` in the
            // condensation graph's topological sort. This implies we should satisfy `x_i` (set it to true).
            variable_assignment[i / 2] = scc_id[i] > scc_id[i + 1];
        }
        return true; // A satisfying assignment was found.
    }

private:
    // First pass of Kosaraju's algorithm: populates `processing_order`.
    void first_dfs_pass(int vertex) {
        visited[vertex] = true;
        for (int neighbor: implication_graph[vertex]) {
            if (!visited[neighbor]) {
                first_dfs_pass(neighbor);
            }
        }
        processing_order.push_back(vertex);
    }

    // Second pass of Kosaraju's algorithm: assigns `scc_id` to all vertices in an SCC.
    void second_dfs_pass(int vertex, int current_scc_id) {
        scc_id[vertex] = current_scc_id;
        for (int neighbor: transposed_graph[vertex]) {
            if (scc_id[neighbor] == -1) {
                second_dfs_pass(neighbor, current_scc_id);
            }
        }
    }
};

// --- Example Usage ---
void example_usage() {
    // Problem with 3 variables: x0, x1, x2
    TwoSatSolver solver(3);
    cout << "Formula" << endl;
    // Add clauses:
    cout << "(x0 ∨ ¬x1)";
    // 1. (x0 ∨ ¬x1)
    solver.add_disjunction(0, false, 1, true);

    // 2. (¬x0 ∨ ¬x1)
    cout << " ∧ (¬x0 ∨ ¬x1)";
    solver.add_disjunction(0, true, 1, true);

    // 3. (x1 ∨ x2)
    cout << " ∧ (x1 ∨ x2)";
    solver.add_disjunction(1, false, 2, false);

    // 4. (x0 ∨ x0)  equivalent to (x0)
    cout << " ∧ (x0 ∨ x0)";
    solver.add_disjunction(0, false, 0, false);
    cout << endl;
    bool is_satisfiable = solver.solve();

    assert(is_satisfiable == true);
    cout << "The formula is satisfiable." << endl;

    // A valid assignment is x0=true, x1=false, x2=true.
    // The solver might find a different valid assignment depending on implementation details.
    // In this case, the assignment derived is {x0: true, x1: false, x2: true}
    cout << "A valid assignment is:" << endl;
    for (int i = 0; i < solver.num_variables; ++i) {
        cout << "x" << i << " = " << (solver.variable_assignment[i] ? "true" : "false") << endl;
    }
}


int main() {
    example_usage();
    return 0;
}
