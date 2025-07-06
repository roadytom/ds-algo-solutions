import math
import sys
from typing import List, Counter


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
    n, k = read_int_list()
    arr = read_int_list()
    costs = [0] * (2 * k + 2)
    for i in range(n // 2):
        left, right = arr[i], arr[n - i - 1]
        if left > right:
            left, right = right, left
        total = left + right
        costs[2] += 2
        costs[2 * k + 1] -= 2
        costs[left + 1] -= 1
        costs[right + k + 1] += 1
        costs[total] -= 1
        costs[total + 1] += 1

    prefix_cost = 0
    min_cost = float("inf")
    for idx in range(2, 2 * k + 1):
        cost = costs[idx]
        prefix_cost += cost
        min_cost = min(min_cost, prefix_cost)
    print(min_cost)


def solve_general():
    n, k = read_int_list()
    arr = read_int_list()
    prefix = [0] * (2 * k + 2)
    counter = Counter()
    for i in range(n // 2):
        left, right = arr[i], arr[n - i - 1]
        if left > right:
            left, right = right, left
        total = left + right
        counter[total] += 1
        prefix[left + 1] += 1
        prefix[right + k + 1] -= 1
    min_cost = float("inf")
    prefix_cost = 0
    for x in range(2, 2 * k + 1):
        prefix_cost += prefix[x]
        equal_cost = counter[x]
        curr_cost = (prefix_cost - equal_cost) + (n // 2 - prefix_cost) * 2
        min_cost = min(min_cost, curr_cost)
    print(min_cost)


def main():
    T = read_int()
    for _ in range(T):
        solve_general()


if __name__ == '__main__':
    main()
