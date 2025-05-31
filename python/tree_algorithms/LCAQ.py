import sys
from math import factorial, log2


def read_words():
    return sys.stdin.readline().split()


def read_int():
    return int(sys.stdin.readline().rstrip())


def read_char_list():
    return list(sys.stdin.readline().rstrip())


def read_int_list():
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


def read_n_int_lists(n):
    return [read_int_list() for _ in range(n)]


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

sys.setrecursionlimit(1000000)


class BinaryLiftingTree:
    def __init__(self, nodes_count):
        self.nodes_count = nodes_count
        self.max_log = int(log2(nodes_count)) + 1
        self.up: list[list[int]] = [[-1] * self.max_log for _ in range(nodes_count)]
        self.depth: list[int] = [0] * nodes_count
        self.tree: list[list[int]] = [[] for _ in range(nodes_count)]

    def add_edge(self, a: int, b: int):
        self.tree[a].append(b)
        self.tree[b].append(a)

    def build(self, root=0):
        self.dfs(root, -1)

    def dfs(self, node, parent):
        for child in self.tree[node]:
            if child == parent:
                continue
            self.depth[child] = self.depth[node] + 1
            self.up[child][0] = node
            for log in range(1, self.max_log):
                if self.up[child][log - 1] != -1:
                    self.up[child][log] = self.up[self.up[child][log - 1]][log - 1]
            self.dfs(child, node)

    def get_kth_ancestor(self, node, k):
        for i in range(self.max_log):
            if k & (1 << i) != 0:
                node = self.up[node][i]
                if node == -1:
                    return -1
        return node

    def get_lca(self, first_node, second_node):
        if self.depth[first_node] > self.depth[second_node]:
            first_node, second_node = second_node, first_node
        diff = self.depth[second_node] - self.depth[first_node]
        second_node = self.get_kth_ancestor(second_node, diff)
        if first_node == second_node:
            return first_node
        for log in range(self.max_log - 1, -1, -1):
            if self.up[first_node][log] != -1 and self.up[first_node][log] != self.up[second_node][log]:
                first_node = self.up[first_node][log]
                second_node = self.up[second_node][log]
        return self.up[first_node][0]


def main():
    nodes_count = read_int()
    binary_lifting_tree = BinaryLiftingTree(nodes_count)
    for node in range(nodes_count):
        m, *children = read_int_list()
        for i in range(m):
            binary_lifting_tree.add_edge(node, children[i])
    binary_lifting_tree.build()
    queries_count = read_int()
    for _ in range(queries_count):
        u, v = read_int_list()
        print(binary_lifting_tree.get_lca(u, v))


if __name__ == '__main__':
    main()
