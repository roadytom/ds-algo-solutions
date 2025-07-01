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


sys.setrecursionlimit(10**6)


def main():
    n, m, x, y = read_int_list()
    array = []
    for _ in range(n):
        row = read_line()
        array.append([*map(lambda it: 0 if it == '.' else 1, row)])
    # print(array)
    count = [[0] * 2 for _ in range(m)]
    for row in range(n):
        for col in range(m):
            count[col][array[row][col]] += 1
    # print(count)
    @cache
    def dp(col_idx, prev, sign):
        # base case
        if col_idx == m:
            if x <= prev <= y:
                return 0
            return float('inf')
        opposite = (sign + 1) % 2
        if prev == y:
            return dp(col_idx + 1, 1, opposite) + count[col_idx][opposite]
        if prev < x:
            return dp(col_idx + 1, prev + 1, sign) + count[col_idx][sign]
        return min(dp(col_idx + 1, prev + 1, sign) + count[col_idx][sign],
                   dp(col_idx + 1, 1, opposite) + count[col_idx][opposite])

    print(min(dp(0, 0, 0), dp(0, 0, 1)))


if __name__ == '__main__':
    main()
