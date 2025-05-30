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

sys.setrecursionlimit(1000000)


def do_solve(num):
    def dp(idx, digit_sum, tight):
        if idx == len(num_str):
            return digit_sum
        if memo[idx][digit_sum][tight] != -1:
            return memo[idx][digit_sum][tight]
        max_digit = 9 if not tight else int(num_str[idx])
        total_sum = 0
        for digit in range(max_digit + 1):
            total_sum += dp(idx + 1, digit_sum + digit, tight and digit == max_digit)
        memo[idx][digit_sum][tight] = total_sum
        return total_sum

    num_str = str(num)
    memo = [[[-1] * 2 for _ in range(9 * len(num_str))] for _ in range(len(num_str))]
    return dp(0, 0, 1)


def solve(l, r):
    return do_solve(r) - do_solve(l - 1)


def main():
    while True:
        l, r = read_int_list()
        if l == -1 and r == -1:
            break
        print(solve(l, r))


if __name__ == '__main__':
    main()
