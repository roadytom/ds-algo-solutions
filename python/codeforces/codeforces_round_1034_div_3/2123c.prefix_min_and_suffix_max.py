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

def solve_X():
    n = read_int()
    arr = read_int_list()
    ans = ['0'] * n
    prefix_min = [float("inf")] * (n + 1)
    for i in range(1, n + 1):
        prefix_min[i] = min(prefix_min[i - 1], arr[i - 1])

    suffix_max = float("-inf")
    for i in range(n - 1, -1, -1):
        mn = prefix_min[i]
        mx = suffix_max
        curr = arr[i]
        if curr > mx or curr < mn:
            ans[i] = '1'
        suffix_max = max(suffix_max, arr[i])
    print("".join(map(str, ans)))


def solve():
    n = int(input())
    a = list(map(int, input().split()))

    result = []

    # For each position i, check if a[i] can be the final element
    for i in range(n):
        can_survive = False

        # Check if a[i] can be minimum of some prefix that includes position i
        # This means a[i] <= all elements at positions 0 to i-1
        is_prefix_min = True
        for j in range(i):
            if a[j] < a[i]:
                is_prefix_min = False
                break

        if is_prefix_min:
            can_survive = True

        # Check if a[i] can be maximum of some suffix that includes position i
        # This means a[i] >= all elements at positions i+1 to n-1
        if not can_survive:
            is_suffix_max = True
            for j in range(i + 1, n):
                if a[j] > a[i]:
                    is_suffix_max = False
                    break

            if is_suffix_max:
                can_survive = True

        result.append('1' if can_survive else '0')

    print(''.join(result))


def main():
    T = read_int()
    for _ in range(T):
        solve_X()


if __name__ == '__main__':
    main()
