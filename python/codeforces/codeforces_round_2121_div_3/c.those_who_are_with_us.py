import math
import sys
from collections import Counter


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

def solve():
    n, m = read_int_list()
    matrix = []
    max_num = float("-inf")
    for i in range(n):
        matrix.append(read_int_list())
        max_num = max(max_num, max(matrix[i]))
    rows = Counter()
    cols = Counter()
    maxs_count = 0
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == max_num:
                rows[i] += 1
                cols[j] += 1
                maxs_count += 1
    for i in range(n):
        for j in range(m):
            can_remove_count = rows[i] + cols[j] - (1 if matrix[i][j] == max_num else 0)
            if can_remove_count == maxs_count:
                print(max_num - 1)
                return
    print(max_num)


def main():
    tt = read_int()
    for _ in range(tt):
        solve()


if __name__ == '__main__':
    main()
