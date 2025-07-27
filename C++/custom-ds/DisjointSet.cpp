#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> sz;
    int sets;


    explicit DSU(int n) : parent(n), sz(n, 1), sets(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find_set(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find_set(parent[i]);
    }

    bool union_sets(int a, int b) {
        int root_a = find_set(a);
        int root_b = find_set(b);
        if (root_a != root_b) {
            if (sz[root_a] < sz[root_b]) {
                swap(root_a, root_b);
            }
            parent[root_b] = root_a;
            sz[root_a] += sz[root_b];
            sets--;
            return true;
        }
        return false;
    }

    bool same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return sz[find_set(a)];
    }

    int count() const {
        return sets;
    }
};
