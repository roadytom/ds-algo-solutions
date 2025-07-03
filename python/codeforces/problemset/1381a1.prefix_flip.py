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

def solve():
    n = read_int()
    a = list(map(int, read_line()))
    b = list(map(int, read_line()))
    operations_count = 0
    prefixes = []
    for right in range(n - 1, -1, -1):
        if a[right] == b[right]:
            continue
        if (a[0] ^ 1) != b[right]:
            prefixes.append(1)
            operations_count += 1
            a[0] = a[0] ^ 1
        prefixes.append(right + 1)
        operations_count += 1
        for left in range(right + 1):
            a[left] = a[left] ^ 1
        a[:right + 1] = a[:right + 1][::-1]
    print(operations_count, " ".join(map(str, prefixes)))


def solve_optimized():
    n = read_int()
    a = list(map(int, read_line()))
    b = list(map(int, read_line()))
    operations_count = 0
    prefixes = []
    start_idx = 0
    flip = 0
    for right in range(n - 1, -1, -1):
        if (a[start_idx] ^ flip) == b[right]:
            prefixes.append(1)
        prefixes.append(right + 1)

        for left in range(right + 1):
            a[left] = a[left] ^ 1
        a[:right + 1] = a[:right + 1][::-1]
    print(operations_count, " ".join(map(str, prefixes)))


def main():
    T = read_int()
    for _ in range(T):
        solve_optimized()


if __name__ == '__main__':
    main()
