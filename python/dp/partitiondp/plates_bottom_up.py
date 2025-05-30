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

# sys.setrecursionlimit(1000000)


def main():
    N, K, P = read_int_list()
    plates = read_n_int_lists(N)
    dp = []
    for row in range(N):
        for col in range(K):
            for p in range(P):
                dp[row][col]

    def dp(row, col, p):
        if p == P:
            return 0
        if row >= N:
            return float("-inf")
        if col >= K:
            return dp(row + 1, 0, p)
        if memo[row][col][p] != -1:
            return memo[row][col]
        take = dp(row, col + 1, p + 1) + plates[row][col]
        skip = dp(row + 1, 0, p)
        memo[row][col][p] = max(take, skip)
        return memo[row][col][p]
    a = dp(0, 0, 0)
    return a


if __name__ == '__main__':
    T = read_int()
    for t in range(T):
        print(f"Case #{t + 1}: {main()}")
