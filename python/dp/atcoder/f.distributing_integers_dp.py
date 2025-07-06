import math
import sys
from functools import reduce
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


def fix(f, stack=None):
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


def main():
    N = read_int()
    tree: List[List[int]] = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = read_int_list()
        tree[a - 1].append(b - 1)
        tree[b - 1].append(a - 1)
    dp = [0] * N
    size = [1] * N
    fact = [1] * (N + 1)
    inv_fact = [1] * (N + 1)
    precomp_facts(fact, inv_fact)

    def dfs_post_order(node, parent):
        facts = 1
        children = 1
        for child in tree[node]:
            if child == parent:
                continue
            dfs_post_order(child, node)
            size[node] += size[child]
            children = mul(children, dp[child])
            facts = mul(facts, inv_fact[size[child]])
        dp[node] = mul(children, fact[size[node] - 1], facts)

    def dfs_pre_order(node, parent):
        for child in tree[node]:
            if child == parent:
                continue
            nom = mul(dp[node], fact[size[child]], fact[N - size[child] - 1])
            denom = mul(inv_fact[N - size[child]], inv_fact[size[child] - 1])
            dp[child] = mul(nom, denom)
            dfs_pre_order(child, node)

    dfs_post_order(0, -1)
    # print(size)
    dfs_pre_order(0, -1)
    for val in dp:
        print(val)
    # print(dp[0])


if __name__ == '__main__':
    main()
