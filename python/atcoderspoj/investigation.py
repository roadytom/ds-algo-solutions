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
# https://lightoj.com/problem/investigation

def investigate_up_to_num(num, k):
    def dp(idx, digits_sum_mod_by_k, remainder, tight):
        if idx == len(num_str):
            return 1 if digits_sum_mod_by_k == 0 and remainder == 0 else 0
        if memo[idx][digits_sum_mod_by_k][remainder][tight] != -1:
            return memo[idx][digits_sum_mod_by_k][remainder][tight]
        max_digit = int(num_str[idx]) if tight == 1 else 9
        count = 0
        for digit in range(max_digit + 1):
            count += dp(idx + 1, (digits_sum_mod_by_k + digit) % k, (remainder * 10 + digit) % k, tight and digit == max_digit)
        memo[idx][digits_sum_mod_by_k][remainder][tight] = count
        return count

    num_str = str(num)
    memo = [[[[-1] * 2 for _ in range(k)] for _ in range(min(len(num_str) * 9, k))] for _ in range(len(num_str))]
    return dp(0, 0, 0, 1)


def solve(l, r, k):
    return investigate_up_to_num(r, k) - investigate_up_to_num(l - 1, k)


def main():
    T = read_int()
    for i in range(T):
        l, r, k = read_int_list()
        print(f"Case {i + 1}: {solve(l, r, k)}")


if __name__ == '__main__':
    main()
