import sys
from functools import reduce
from math import factorial, gcd
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
    return factorial(n) // factorial(r)


def comb(n, r):
    return factorial(n) // (factorial(r) * factorial(n - r))


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


def solve_GEMINI():
    """
    Solves the Tree Beauty problem using a recursive DFS approach.
    """
    # It's good practice to increase the recursion limit for deep trees.
    sys.setrecursionlimit(200005)

    # Read problem input
    n = read_int()
    a = read_int_list()
    tree = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = read_int_list()
        tree[u].append(v)
        tree[v].append(u)

    ans = [0] * (n + 1)

    # The beauty of the root is its own value.
    ans[1] = a[0]

    def gcd(x, y):
        """Helper for greatest common divisor."""
        return gcd(x, y)

    def dfs(u, p, parent_path_gcd, parent_dp):
        """
        Performs DFS to calculate maximum beauty.

        Args:
            u: Current vertex.
            p: Parent of u.
            parent_path_gcd: GCD of values on the path from root to p.
            parent_dp: A map of {beauty: count} for the path to p with one skip.
        """

        # 1. Calculate GCD for the full path to u.
        current_path_gcd = gcd(parent_path_gcd, a[u - 1])

        # 2. Build the dp map for u.
        current_dp = {}
        # Case a: Skip a[u]. Beauty is the GCD of the path to its parent.
        current_dp[parent_path_gcd] = 1
        # Case b: Skip an ancestor. Update GCDs from the parent's dp map.
        for g, count in parent_dp.items():
            new_gcd = gcd(g, a[u - 1])
            current_dp[new_gcd] = current_dp.get(new_gcd, 0) + count

        # 3. Determine the max beauty for u.
        max_beauty = current_path_gcd
        for g in current_dp.keys():
            max_beauty = max(max_beauty, g)
        ans[u] = max_beauty

        # 4. Recurse for children.
        for v in tree[u]:
            if v != p:
                dfs(v, u, current_path_gcd, current_dp)

    # Start DFS for all children of the root node 1.
    # For the root, the parent path GCD is a[0] and the dp map reflects skipping a[0],
    # which results in an empty path whose GCD can be considered 0.
    for v in tree[1]:
        if v != 0:  # Assuming parent of root is a dummy node 0
            dfs(v, 1, a[0], {0: 1})

    # Output the results
    print(*(ans[i] for i in range(1, n + 1)))


def solve():
    # sys.setrecursionlimit(200005)

    n = read_int()
    arr = read_int_list()
    tree: List[List[int]] = [[] for _ in range(n)]
    for i in range(n - 1):
        a, b = read_int_list()
        tree[a - 1].append(b - 1)
        tree[b - 1].append(a - 1)

    answer = [0] * n

    @recursion_fix
    def dfs1(node, parent):
        for child in tree[node]:
            if child == parent:
                continue
            answer[child] = gcd(arr[child], answer[node])
            yield dfs1(child, node)
        yield

    dfs1(0, -1)
    divisors = []

    num = 1
    while num * num <= arr[0]:
        if arr[0] % num == 0:
            divisors.append(num)
            if num * num != arr[0]:
                divisors.append(arr[0] // num)
        num += 1

    answer[0] = arr[0]
    # print(divisors)
    divisors.sort()
    div_count = [0] * (len(divisors))

    @recursion_fix
    def dfs2(node, parent, depth):
        for idx, divisor in enumerate(divisors):
            if arr[node] % divisor == 0:
                div_count[idx] += 1
            if div_count[idx] >= depth:
                answer[node] = max(answer[node], divisor)

        for child in tree[node]:
            if child == parent:
                continue
            yield dfs2(child, node, depth + 1)
        for idx, divisor in enumerate(divisors):
            if arr[node] % divisor == 0:
                div_count[idx] -= 1
        yield

    dfs2(0, -1, 0)
    print(" ".join(map(str, answer)))


if __name__ == '__main__':
    solve()
