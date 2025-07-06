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
    n = read_int()
    arr = read_int_list()
    left, right = -1, 0
    prev_idxs = {0: -1}
    sum = 0
    good_array_count = 0
    while right < len(arr):
        sum += arr[right]
        if sum in prev_idxs:
            prev_idx = prev_idxs[sum]
            left = max(left, prev_idx + 1)
        good_array_count += right - left
        # print(good_array_count)
        prev_idxs[sum] = right
        right += 1
    print(good_array_count)


def main_window():
    n = read_int()
    arr = read_int_list()
    left, right = 0, 0
    sum = 0
    ans = 0
    while right < n:
        sum += arr[right]
        while left <= right and sum == 0:
            sum -= arr[left]
            left += 1
        if sum != 0:
            ans += right - left + 1
        # print(ans)
        right += 1
    print(ans)


if __name__ == '__main__':
    main_window()
