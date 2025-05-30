from math import factorial, log2
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


# sys.setrecursionlimit(1000000)


def main():
    N = read_int()
    LOG = int(log2(N)) + 1
    graph = [[] for _ in range(N)]
    for node in range(N):
        _, *adjs = read_int_list()
        for adj in adjs:
            graph[node].append(adj)
    depth = [0] * N
    up = [[0] * LOG for _ in range(N)]
    root = 0

    def dfs(node):
        for child in graph[node]:
            up[child][0] = node
            depth[child] = depth[node] + 1
            for i in range(1, LOG):
                up[child][i] = up[up[child][i - 1]][i - 1]
            dfs(child)

    def find_lca(u, v):
        if depth[u] > depth[v]:
            return find_lca(v, u)
        diff = depth[v] - depth[u]
        for position in range(LOG):
            if diff & (position << 1) != 0:
                v = up[v][position]
        if u == v:
            return u
        for i in range(LOG - 1, -1, -1):
            if up[u][i] != up[v][i]:
                u = up[u][i]
                v = up[v][i]
        return up[i][0]

    dfs(root, -1)

    Q = read_int()
    for _ in range(Q):
        u, v = read_int_list()
        print(find_lca(u, v))


if __name__ == '__main__':
    main()
