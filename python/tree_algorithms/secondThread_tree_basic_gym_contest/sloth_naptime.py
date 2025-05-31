import math
from math import log2
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
    nodes_count = read_int()
    max_log = int(log2(nodes_count)) + 1
    graph = [[] for _ in range(nodes_count)]
    for _ in range(nodes_count - 1):
        a, b = read_int_list_0_indexed()
        graph[a].append(b)
        graph[b].append(a)

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

    def find_kth_ancestor(node, k):
        for i in range(max_log):
            if k & (1 << i) != 0:
                node = up[node][i]
        return node

    def find_lca(first_node, second_node):
        if depth[first_node] > depth[second_node]:
            first_node, second_node = second_node, first_node
        k = depth[second_node] - depth[first_node]
        second_node = find_kth_ancestor(second_node, k)
        if first_node == second_node:
            return first_node
        for j in range(max_log - 1, -1, -1):
            if up[first_node][j] != up[second_node][j]:
                first_node = up[first_node][j]
                second_node = up[second_node][j]
        return up[first_node][0]

    depth = [0] * nodes_count
    up = [[0] * max_log for _ in range(nodes_count)]
    preprocess()
    query_count = read_int()
    for _ in range(query_count):
        a, b, energy = read_int_list()
        first_node, second_node = a - 1, b - 1
        lca_node = find_lca(first_node, second_node)
        length = depth[first_node] + depth[second_node] - 2 * depth[lca_node]
        if energy >= length:
            print(second_node + 1)
            continue
        length_first_node_lca = depth[first_node] - depth[lca_node]
        if length_first_node_lca >= energy:
            print(find_kth_ancestor(first_node, energy) + 1)
        else:
            print(find_kth_ancestor(second_node, length - energy) + 1)


if __name__ == '__main__':
    main()
