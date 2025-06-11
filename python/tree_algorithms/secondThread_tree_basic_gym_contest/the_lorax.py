import sys
from math import factorial


def read_words():
    return sys.stdin.readline().split()


def read_int():
    return int(sys.stdin.readline().rstrip())


def read_long():
    return int(sys.stdin.readline().rstrip())


def read_char_list():
    return list(sys.stdin.readline().rstrip())


def read_int_list():
    return [int(x) for x in sys.stdin.readline().split()]


def read_long_list():
    return [int(x) for x in sys.stdin.readline().split()]


def read_int_list_0_indexed():
    return [int(x) - 1 for x in sys.stdin.readline().split()]


def read_word_char_lists():
    return [list(x) for x in sys.stdin.readline().split()]


def read_n_lines(n):
    return [sys.stdin.readline().strip() for _ in range(n)]


def read_n_lines_words(n):
    return [read_words() for _ in range(n)]


def read_n_ints(n):
    return [read_int() for _ in range(n)]


def read_n_longs(n):
    return [read_long() for _ in range(n)]


def read_n_int_lists(n):
    return [read_int_list() for _ in range(n)]


def read_n_long_lists(n):
    return [read_long_list() for _ in range(n)]


def read_n_int_lists_0_indexed(n):
    return [read_int_list_0_indexed() for _ in range(n)]


def read_n_char_lists(n):
    return [read_char_list() for _ in range(n)]


def read_n_word_char_lists(n):
    return [read_word_char_lists() for _ in range(n)]


def perm(n, r):
    return factorial(n) // factorial(r)


def comb(n, r):
    return factorial(n) // (factorial(r) * factorial(n - r))


def make_list(n, *args, default=0):
    return [make_list(*args, default=default) for _ in range(n)] if len(args) > 0 else [
        default for _ in range(n)]


dire = [[1, 0], [0, 1], [-1, 0], [0, -1]]
dire8 = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]
alphabets = "abcdefghijklmnopqrstuvwxyz"
ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
MOD = 1000000007
INF = float("inf")

sys.setrecursionlimit(10 ** 5)


class SegmentTree:
    def __init__(self, size):
        self.n = size
        self.tree = [0] * (4 * self.n)

    def update(self, idx, value):
        self._update(1, 0, self.n - 1, idx, value)

    def _update(self, node, start, end, idx, value):
        if start == end:
            self.tree[node] += value
        else:
            mid = (start + end) // 2
            if idx <= mid:
                self._update(2 * node, start, mid, idx, value)
            else:
                self._update(2 * node + 1, mid + 1, end, idx, value)
            self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

    def query(self, left, right):
        if left > right:
            return 0
        return self._query(1, 0, self.n - 1, left, right)

    def _query(self, node, start, end, left, right):
        if right < start or end < left:
            return 0
        if left <= start and end <= right:
            return self.tree[node]
        mid = (start + end) // 2
        return (self._query(2 * node, start, mid, left, right) +
                self._query(2 * node + 1, mid + 1, end, left, right))


class TreeFlattening:
    def __init__(self, n):
        self.n = n
        self.timer = 0
        self.adj = [[] for _ in range(n + 1)]
        self.tin = [0] * (n + 1)
        self.tout = [0] * (n + 1)
        self.parent = [0] * (n + 1)
        self.seg_tree = SegmentTree(n + 1)

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def build_tree(self, root=1):
        self._dfs(root, -1)

    def _dfs(self, v, p):
        self.tin[v] = self.timer
        self.timer += 1
        self.parent[v] = p
        for u in self.adj[v]:
            if u != p:
                self._dfs(u, v)
        self.tout[v] = self.timer - 1

    def add_seeds(self, node, count):
        self.seg_tree.update(self.tin[node], -count)  # Seeds are negative

    def add_pots(self, node, count):
        self.seg_tree.update(self.tin[node], count)  # Pots are positive

    def is_ancestor(self, u, v):
        return self.tin[u] <= self.tin[v] and self.tout[v] <= self.tout[u]

    def query_edge(self, u, v):
        # Determine which node is the parent
        if self.is_ancestor(u, v):
            par = u
            child = v
        elif self.is_ancestor(v, u):
            par = v
            child = u
        else:
            # Edge doesn't exist in our tree (shouldn't happen in valid input)
            return 0

        # Get the net balance (pots - seeds) in the subtree rooted at child
        subtree_balance = self.seg_tree.query(self.tin[child], self.tout[child])

        # Get the net balance (pots - seeds) in the entire tree
        total_balance = self.seg_tree.query(0, self.n)

        # Net balance outside the subtree
        outside_balance = total_balance - subtree_balance

        # The number of pairs crossing the edge is determined by the imbalance
        # If subtree has excess seeds (negative balance), they need pots from outside
        # If subtree has excess pots (positive balance), they can serve seeds from outside
        # The crossing pairs is the minimum of what one side needs and the other can provide

        if subtree_balance >= 0 and outside_balance <= 0:
            # Subtree has excess pots, outside has excess seeds
            crossing_pairs = min(subtree_balance, -outside_balance)
        elif subtree_balance <= 0 and outside_balance >= 0:
            # Subtree has excess seeds, outside has excess pots
            crossing_pairs = min(-subtree_balance, outside_balance)
        else:
            # Both sides have the same type of excess, no crossing needed
            crossing_pairs = 0

        return crossing_pairs


def solve():
    n, q = read_int_list()
    tree = TreeFlattening(n)

    # Read edges
    for _ in range(n - 1):
        u, v = read_int_list()
        tree.add_edge(u, v)

    # Build the flattened tree structure
    tree.build_tree(1)

    # Process queries
    for _ in range(q):
        line = sys.stdin.readline().split()
        a = int(line[0])
        b = int(line[1])
        x = int(line[2])  # Read as int to match C++ long long behavior

        if x == 0:
            # Query
            print(tree.query_edge(a, b))
        else:
            # Add seeds and pots
            tree.add_seeds(a, x)
            tree.add_pots(b, x)


def main():
    c = read_int()
    for _ in range(c):
        solve()


if __name__ == '__main__':
    main()
