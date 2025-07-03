import math
import sys
from functools import cache
from typing import List


def read_words() -> List[str]:
    return sys.stdin.readline().split()


def read_line() -> str:
    return sys.stdin.readline().rstrip()


def read_n_lines(n) -> List[str]:
    return [sys.stdin.readline().strip() for _ in range(n)]


def read_int() -> int:
    return int(sys.stdin.readline().rstrip())


def read_int_list() -> List[int]:
    return [int(x) for x in sys.stdin.readline().split()]


def read_int_list_0_indexed() -> List[int]:
    return [int(x) - 1 for x in sys.stdin.readline().split()]


def read_n_lines_words(n) -> List[List[str]]:
    return [read_words() for _ in range(n)]


def read_n_ints(n) -> List[int]:
    return [read_int() for _ in range(n)]


def read_n_int_lists(n) -> List[List[int]]:
    return [read_int_list() for _ in range(n)]


def read_n_int_lists_0_indexed(n) -> List[List[int]]:
    return [read_int_list_0_indexed() for _ in range(n)]


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
def dp_solve(num):
    num_arr = list(map(int, str(num)))
    digit_count = len(num_arr)

    @cache
    def dp(idx, non_zero_count, under, is_zero_leading):
        if idx == digit_count:
            return int(not is_zero_leading)
        max_digit = 9 if under else num_arr[idx]
        res = 0
        for digit in range(max_digit + 1):
            new_is_zero_leading = is_zero_leading and digit == 0
            new_under = under or digit != max_digit
            if digit != 0 and non_zero_count >= 3:
                continue
            res += dp(idx + 1, non_zero_count + int(digit != 0), new_under, new_is_zero_leading)
        return res

    return dp(0, 0, False, True)


def solve():
    l, r = read_int_list()
    print(dp_solve(r) - dp_solve(l - 1))


def main():
    T = read_int()
    for _ in range(T):
        solve()


if __name__ == '__main__':
    main()
