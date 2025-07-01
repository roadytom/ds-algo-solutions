import math
import sys
from functools import cache
from typing import List

sys.stdin = open('odometer.in', 'r')
sys.stdout = open('odometer.out', 'w')


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


def solve(num):
    if num < 0:
        return 0
    num_arr = list(map(int, str(num)))
    num_of_digits = len(num_arr)

    @cache
    def dp(idx, tight, target1, target2, count, is_leading_zero, leading_zero_count):
        if idx == num_of_digits:
            if is_leading_zero:
                return 0
            length = num_of_digits - leading_zero_count
            if target2 != -1:
                return int(count * 2 == length)
            return int(count >= (length + 1) // 2)
        max_digit = num_arr[idx] if tight else 9
        interesting_numbers_count = 0
        for digit in range(0, max_digit + 1):
            new_tight = tight and digit == max_digit
            new_is_leading_zero = is_leading_zero and digit == 0
            new_leading_zero_count = leading_zero_count + int(new_is_leading_zero)
            if not new_is_leading_zero and target2 != -1 and digit not in (target1, target2):
                continue
            interesting_numbers_count += dp(idx + 1, new_tight, target1, target2,
                                            count + int(not new_is_leading_zero and target1 == digit),
                                            new_is_leading_zero,
                                            new_leading_zero_count)
        return interesting_numbers_count

    res = 0
    for digit in range(10):
        res += dp(0, True, digit, -1, 0, True, 0)
    duplicates = 0
    for digit1 in range(10):
        for digit2 in range(10):
            duplicates += dp(0, True, digit1, digit2, 0, True, 0)
    return res - (duplicates // 2)


def main():
    X, Y = read_int_list()
    print(solve(Y) - solve(X - 1))


if __name__ == '__main__':
    main()
