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


def main():
    nodes_count = read_int()
    max_log = int(log2(nodes_count)) + 1
    graph: list[list[int]] = [[] for _ in range(nodes_count)]
    for node in range(nodes_count):
        m, *children = read_int_list()
        for i in range(m):
            graph[node].append(children[i])
    depth = [0] * nodes_count
    up = [[0] * max_log for _ in range(nodes_count)]
    root = 0

    def dfs(curr_node):
        for child in graph[curr_node]:
            up[child][0] = curr_node
            depth[child] = depth[curr_node] + 1
            for log in range(max_log - 1, 0, - 1):
                up[child][log] = up[up[child][log - 1]][log - 1]
            dfs(child)

    def find_lca(first_node, second_node):
        if depth[first_node] > depth[second_node]:
            return find_lca(second_node, first_node)
        diff = depth[second_node] - depth[first_node]
        for position in range(max_log):
            if diff & (1 << position) != 0:
                second_node = up[second_node][position]
        if first_node == second_node:
            return first_node
        for log in range(max_log - 1, -1, -1):
            if up[first_node][log] != up[second_node][log]:
                first_node = up[first_node][log]
                second_node = up[second_node][log]
        return up[first_node][0]

    dfs(root)

    queries_count = read_int()
    for _ in range(queries_count):
        u, v = read_int_list()
        print(find_lca(u, v))


if __name__ == '__main__':
    main()
