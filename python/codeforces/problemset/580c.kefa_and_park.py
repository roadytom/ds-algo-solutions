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


# sys.setrecursionlimit(10**6)


def main():
    n, m = read_int_list()
    cats = read_int_list()
    tree = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = read_int_list_0_indexed()
        tree[a].append(b)
        tree[b].append(a)
    stack = deque([(0, -1, 0)])
    res = 0
    while stack:
        node, parent, streak = stack.pop()
        curr_streak = 0 if cats[node] == 0 else streak + 1
        if parent != -1 and len(tree[node]) == 1:
            res += int(curr_streak <= m)
            continue
        if curr_streak > m:
            continue
        for child in tree[node]:
            if child != parent:
                stack.append((child, node, curr_streak))
    print(res)

    # def dfs(node, parent, streak):
    #     curr_streak = 0 if cats[node] == 0 else streak + 1
    #     if len(tree[node]) == 1:
    #         return curr_streak <= m
    #     if curr_streak > m:
    #         return 0
    #     res = 0
    #     for child in tree[node]:
    #         if child != parent:
    #             res += dfs(child, node, curr_streak)
    #     return res
    #
    # print(dfs(0, -1, 0))


if __name__ == '__main__':
    main()
