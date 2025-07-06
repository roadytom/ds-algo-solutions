import math
import sys


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


def build_prefix_arr(max_element, k) -> list[int]:
    prefix_arr = [0] * (max_element + 1)
    prefix_arr[0] = 0
    for i in range(1, min(len(prefix_arr), k + 1)):
        prefix_arr[i] = 1
    if k <= max_element:
        prefix_arr[k] += 1
    for length in range(k + 1, max_element + 1):
        group = 0
        if length > k:
            group = prefix_arr[length - k]
        prefix_arr[length] = (group + prefix_arr[length - 1]) % MOD
    return prefix_arr


def main():
    t, k = read_int_list()
    query = []
    for i in range(t):
        query.append(read_int_list())
    prefix_arr = build_prefix_arr(max(max(q) for q in query), k)
    prefix_sum = [0] * len(prefix_arr)
    for i in range(1, len(prefix_arr)):
        prefix_sum[i] = (prefix_arr[i] + prefix_sum[i - 1]) % MOD
    for a, b in query:
        print((prefix_sum[b] - prefix_sum[a - 1] + MOD) % MOD)


if __name__ == '__main__':
    main()
