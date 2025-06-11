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

# sys.setrecursionlimit(10 ** 3)


def main():
    r, g = read_int_list()

    def max_height(r, g):
        total = r + g
        h = 0
        while (h + 1) * (h + 2) // 2 <= total:
            h += 1
        return h

    h = max_height(r, g)
    total = h * (h + 1) // 2
    dp = [0] * (r + 1)
    dp[0] = 1  # 0 red blocks used at level 0

    for level in range(1, h + 1):
        next_dp = [0] * (r + 1)
        for red_used in range(r + 1):
            if dp[red_used] == 0:
                continue
            # Option 1: use red for this level
            if red_used + level <= r:
                next_dp[red_used + level] = (next_dp[red_used + level] + dp[red_used]) % MOD
            # Option 2: use green for this level (no change in red count)
            next_dp[red_used] = (next_dp[red_used] + dp[red_used]) % MOD
        dp = next_dp

    result = 0
    for red_used in range(r + 1):
        green_used = total - red_used
        if green_used <= g:
            result = (result + dp[red_used]) % MOD
    print(result)


if __name__ == '__main__':
    main()
