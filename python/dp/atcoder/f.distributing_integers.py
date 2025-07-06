import math
import sys
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


dire = [[1, 0], [0, 1], [-1, 0], [0, -1]]
dire8 = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]
alphabets = "abcdefghijklmnopqrstuvwxyz"
ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
MOD = 1000000007
INF = float("inf")

sys.setrecursionlimit(10 ** 6)


def precompute_factorials(fact, inv_fact):
    fact[0] = inv_fact[0] = 1
    for i in range(1, len(fact)):
        fact[i] = fact[i - 1] * i % MOD
    inv_fact[-1] = mod_inverse(fact[-1])
    for i in range(len(inv_fact) - 2, 0, -1):
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD


def mod_pow(x, n):
    res = 1
    while n > 0:
        if n % 2 == 1:
            res = (res * x) % MOD
        x = x * x % MOD
        n >>= 1
    return res


def mod_inverse(x):
    return mod_pow(x, MOD - 2)


def main():
    N = read_int()
    tree: List[List[int]] = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = read_int_list()
        tree[a - 1].append(b - 1)
        tree[b - 1].append(a - 1)
    dp = [0] * N
    size = [1] * N
    fact = [0] * (N + 1)
    inv_fact = [0] * (N + 1)
    precompute_factorials(fact, inv_fact)

    def dfs_post_order(node, parent):
        facts = 1
        children = 1
        for child in tree[node]:
            if child == parent:
                continue
            dfs_post_order(child, node)
            size[node] += size[child]
            children = children * dp[child] % MOD
            facts = facts * fact[size[child]] % MOD
        dp[node] = children * fact[size[node] - 1] * mod_inverse(facts)

    def dfs_pre_order(node, parent):
        for child in tree[node]:
            if child == parent:
                continue
            dp[child] = (((((dp[node] * fact[size[child]]) % MOD * fact[N - size[child] - 1]) % MOD) * inv_fact[
                N - size[child]]) % MOD * inv_fact[
                             size[child] - 1]) % MOD
            dfs_pre_order(child, node)

    dfs_post_order(0, -1)
    # print(size)
    dfs_pre_order(0, -1)
    for val in dp:
        print(val)
    # print(dp[0])


if __name__ == '__main__':
    main()
