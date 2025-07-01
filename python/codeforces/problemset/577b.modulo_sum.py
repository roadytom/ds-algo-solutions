import math
import sys
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


def main():
    n, m = read_int_list()
    arr = read_int_list()
    if n >= m:
        print("YES")
        return
    dp = [[[0] * 2 for _ in range(m)] for _ in range(n + 1)]
    dp[n][0][1] = 1
    # print(dp)
    for idx in range(n - 1, -1, -1):
        for mod in range(m):
            for is_empty in [0, 1]:
                skip = dp[idx + 1][mod][is_empty]
                new_mod = (mod + arr[idx]) % m
                take = dp[idx + 1][new_mod][1]
                dp[idx][mod][is_empty] = skip or take

    # @cache
    # def dp(idx, curr_sum):
    #     if idx == n:
    #         return curr_sum != -1 and curr_sum % m == 0
    #     skip = dp(idx + 1, curr_sum)
    #     new_sum = (0 if curr_sum == -1 else curr_sum) + arr[idx]
    #     take = dp(idx + 1, new_sum % m)
    #     return skip or take

    # print("YES" if dp(0, -1) else "NO")
    print("YES" if dp[0][0][0] else "NO")


if __name__ == '__main__':
    main()
