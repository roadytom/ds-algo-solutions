import math
import sys
from collections import Counter


def read_words() -> list[str]:
    return sys.stdin.readline().split()


def read_line() -> str:
    return sys.stdin.readline().rstrip()


def read_n_lines(n) -> list[str]:
    return [sys.stdin.readline().strip() for _ in range(n)]


def read_int() -> int:
    return int(sys.stdin.readline().rstrip())


def read_int_list() -> list[int]:
    return [int(x) for x in sys.stdin.readline().split()]


def read_int_list_0_indexed() -> list[int]:
    return [int(x) - 1 for x in sys.stdin.readline().split()]


def read_n_lines_words(n) -> list[list[str]]:
    return [read_words() for _ in range(n)]


def read_n_ints(n) -> list[int]:
    return [read_int() for _ in range(n)]


def read_n_int_lists(n) -> list[list[int]]:
    return [read_int_list() for _ in range(n)]


def read_n_int_lists_0_indexed(n) -> list[list[int]]:
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
    n, k = read_int_list()
    arr = read_int_list()
    counter = Counter()
    left, right = 0, 0
    ans = 0
    l, r = -1, -1
    while right < len(arr):
        counter[arr[right]] += 1
        while left <= right and len(counter) > k:
            counter[arr[left]] -= 1
            if counter[arr[left]] == 0:
                del counter[arr[left]]
            left += 1
        if ans < right - left + 1:
            l = left
            r = right
            ans = right - left + 1
        right += 1
    print(f"{l + 1} {r + 1}")


if __name__ == '__main__':
    main()
