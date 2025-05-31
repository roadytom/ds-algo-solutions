import math
import sys
from collections import deque


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


def main():
    n, q = read_int_list()
    max_log = int(math.log2(n)) + 1
    graph: list[list[int]] = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = read_int_list_0_indexed()
        graph[a].append(b)
        graph[b].append(a)
    depth = [0] * n
    up = [[0] * max_log for _ in range(n)]

    def preprocess():
        stack = deque()
        stack.append((0, -1))
        while stack:
            node, parent = stack.pop()
            for child in graph[node]:
                if child == parent:
                    continue
                depth[child] = depth[node] + 1
                up[child][0] = node
                for j in range(1, max_log):
                    up[child][j] = up[up[child][j - 1]][j - 1]
                stack.append((child, node))

    def find_lca(a, b):
        if depth[a] > depth[b]:
            a, b = b, a
        k = depth[b] - depth[a]
        for i in range(max_log):
            if k & (1 << i) != 0:
                b = up[b][i]
        if a == b:
            return a
        for i in range(max_log - 1, -1, -1):
            if up[a][i] != up[b][i]:
                a = up[a][i]
                b = up[b][i]
        return up[a][0]

    preprocess()

    for _ in range(q):
        a, b = read_int_list_0_indexed()
        lca_node = find_lca(a, b)
        print(depth[a] + depth[b] - 2 * depth[lca_node])


if __name__ == '__main__':
    main()
