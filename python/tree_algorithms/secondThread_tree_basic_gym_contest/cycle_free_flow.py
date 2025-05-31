import math
import sys
from collections import deque
from functools import wraps
from math import log2


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
    return math.factorial(n) // math.factorial(r)


def comb(n, r):
    return math.factorial(n) // (math.factorial(r) * math.factorial(n - r))


def make_list(n, *args, default=0):
    return [make_list(*args, default=default) for _ in range(n)] if len(args) > 0 else [
        default for _ in range(n)]


dire = [[1, 0], [0, 1], [-1, 0], [0, -1]]
dire8 = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]
alphabets = "abcdefghijklmnopqrstuvwxyz"
ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
MOD = 1000000007
INF = float("inf")


def require_built(method):
    @wraps(method)
    def wrapper(self, *args, **kwargs):
        if not self._built:
            raise Exception("Tree not built. Call build() before calling")
        return method(self, *args, **kwargs)

    return wrapper


class BinaryLiftingTreeWithMinQuery:
    def __init__(self, nodes_count):
        self.nodes_count = nodes_count
        self.max_log = int(log2(nodes_count)) + 1
        self.up: list[list[int]] = [[-1] * self.max_log for _ in range(nodes_count)]
        self.up_min: list[list[int]] = [[-1] * self.max_log for _ in range(nodes_count)]
        self.depth: list[int] = [0] * nodes_count
        self.tree: list[list[tuple[int, int]]] = [[] for _ in range(nodes_count)]
        self._built = False

    def add_edge(self, a: int, b: int, weight: int):
        self.tree[a].append((b, weight))
        self.tree[b].append((a, weight))
        self._built = False

    def build(self, root=0, recursive=True):
        if recursive:
            self.dfs(root, -1)
        else:
            self.dfs_iterative(root)
        self._built = True

    def dfs(self, node, parent):
        for child, weight in self.tree[node]:
            if child == parent:
                continue
            self.depth[child] = self.depth[node] + 1
            self.up[child][0] = node
            self.up_min[child][0] = weight
            for log in range(1, self.max_log):
                if self.up[child][log - 1] != -1:
                    self.up[child][log] = self.up[self.up[child][log - 1]][log - 1]
                    self.up_min[child][log] = min(self.up_min[child][log - 1],
                                                  self.up_min[self.up[child][log - 1]][log - 1])
            self.dfs(child, node)

    def dfs_iterative(self, root):
        stack = deque()
        stack.append((root, -1))
        while stack:
            node, parent = stack.pop()
            for child, weight in self.tree[node]:
                if child == parent:
                    continue
                self.depth[child] = self.depth[node] + 1
                self.up[child][0] = node
                self.up_min[child][0] = weight
                for log in range(1, self.max_log):
                    if self.up[child][log - 1] != -1:
                        self.up[child][log] = self.up[self.up[child][log - 1]][log - 1]
                    self.up_min[child][log] = min(self.up_min[child][log - 1],
                                                  self.up_min[self.up[child][log - 1]][log - 1])
                stack.append((child, node))

    @require_built
    def get_kth_ancestor(self, node, k):
        for i in range(self.max_log):
            if k & (1 << i) != 0:
                node = self.up[node][i]
                if node == -1:
                    break
        return node

    @require_built
    def get_kth_min_ancestor(self, node: int, k):
        min_ancestor = INF
        for i in range(self.max_log):
            if k & (1 << i) != 0:
                min_ancestor = min(min_ancestor, self.up_min[node][i])
                node = self.up[node][i]
                if node == -1:
                    break
        return min_ancestor

    @require_built
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

    @require_built
    def get_distance(self, first_node, second_node):
        lca_node = self.get_lca(first_node, second_node)
        return self.depth[first_node] + self.depth[second_node] - 2 * self.depth[lca_node]

    @require_built
    def get_min_in_path(self, first_node, second_node):
        lca_node = self.get_lca(first_node, second_node)
        return min(self.get_kth_min_ancestor(first_node, self.depth[first_node] - self.depth[lca_node]),
                   self.get_kth_min_ancestor(second_node, self.depth[second_node] - self.depth[lca_node]))


def main():
    nodes_count, edges_count = read_int_list()
    binary_lifting_tree = BinaryLiftingTreeWithMinQuery(nodes_count)
    for _ in range(edges_count):
        a, b, weight = read_int_list()
        a, b = a - 1, b - 1
        binary_lifting_tree.add_edge(a, b, weight)
    binary_lifting_tree.build(recursive=False)
    query_count = read_int()
    for _ in range(query_count):
        a, b = read_int_list()
        a, b = a - 1, b - 1
        print(binary_lifting_tree.get_min_in_path(a, b))


if __name__ == '__main__':
    main()
