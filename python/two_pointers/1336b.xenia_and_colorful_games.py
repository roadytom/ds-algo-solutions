import math
import sys
from bisect import bisect_right
from functools import reduce
from itertools import combinations
from types import GeneratorType
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


def recursion_fix(f, stack=None):
    if stack is None:
        stack = []

    def wrapped(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrapped


def add(*args):
    return reduce(lambda a, b: (a + b) % MOD, args)


def sub(*args):
    return reduce(lambda a, b: ((a - b) % MOD + MOD) % MOD, args)


def mul(*args):
    return reduce(lambda a, b: (a * b) % MOD, args)


def mod_inverse(x):
    return exp(x, MOD - 2)


def exp(base, exponent):
    if exponent == 0:
        return 1
    half = exp(base, exponent // 2)
    if exponent % 2 == 0:
        return mul(half, half)
    return mul(half, half, base)


# factorials = [1] * 2_000_001
# inv_factorials = [1] * 2_000_001

def precomp_facts(factorials, inv_factorials):
    factorials[0] = 1
    inv_factorials[0] = 1
    for i in range(1, len(factorials)):
        factorials[i] = mul(factorials[i - 1], i)
    inv_factorials[-1] = mod_inverse(factorials[-1])
    for i in reversed(range(len(inv_factorials) - 1)):
        inv_factorials[i] = mul(inv_factorials[i + 1], i + 1)


dire = [[1, 0], [0, 1], [-1, 0], [0, -1]]
dire8 = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]
alphabets = "abcdefghijklmnopqrstuvwxyz"
ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
MOD = 1000000007
INF = float("inf")


# sys.setrecursionlimit(10 ** 5)
def solve():
    def calculate_value(a, b, c):
        # print(a, b, c)
        return sum((x - y) * (x - y) for x, y in combinations([a, b, c], 2))

    def find_min_val(val, A, B):
        first_idx = bisect_right(A, val)
        second_idx = bisect_right(B, val)
        a_options = list(filter(lambda x: 0 <= x < len(A), [first_idx - 1, first_idx]))
        b_options = list(filter(lambda x: 0 <= x < len(B), [second_idx - 1, second_idx]))
        min_val = float("inf")
        for a_idx in a_options:
            for b_idx in b_options:
                min_val = min(min_val, calculate_value(val, A[a_idx], B[b_idx]))
        return min_val

    lengths = read_int_list()
    X = read_int_list()
    Y = read_int_list()
    Z = read_int_list()
    X.sort()
    Y.sort()
    Z.sort()
    min_val = float("inf")
    for x in X:
        min_val = min(min_val, find_min_val(x, Y, Z))
    for y in Y:
        min_val = min(min_val, find_min_val(y, X, Z))
    for z in Z:
        min_val = min(min_val, find_min_val(z, X, Y))
    print(min_val)


def main():
    T = read_int()
    for _ in range(T):
        solve()


if __name__ == '__main__':
    main()
