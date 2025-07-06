import math
import sys
from collections import deque, defaultdict
from functools import reduce, cache
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
    N, src = read_int_list()
    src -= 1
    cost = read_int_list()
    tree = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = read_int_list()
        tree[a - 1].append(b - 1)
        tree[b - 1].append(a - 1)
    distances = [0] * N

    def dfs(node, parent):
        for child in tree[node]:
            if child != parent:
                distances[child] = distances[node] + 1
                dfs(child, node)

    dfs(0, -1)

    @cache
    def dp(node, time, life):
        life += cost[node]
        if life == 0 or time >= distances[node]:
            return 0
        max_move = 0
        for child in tree[node]:
            max_move = max(max_move, dp(child, time + 1, life))
        return max_move + 1

    print(dp(src, 0, 1))


def solve_new():
    n, st = map(int, input().split())
    weights = list(map(int, input().split()))

    adj = defaultdict(list)
    for _ in range(n - 1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)

    dist_from_root = [float('inf')] * (n + 1)
    dist_from_root[1] = 0
    queue = deque([1])

    while queue:
        node = queue.popleft()
        for neighbor in adj[node]:
            if dist_from_root[neighbor] == float('inf'):
                dist_from_root[neighbor] = dist_from_root[node] + 1
                queue.append(neighbor)

    queue = deque([(st, 0, 1)])
    visited = {}  # (vertex, time) -> max_life seen
    max_moves = 0

    while queue:
        vertex, time, life = queue.popleft()

        new_life = life + weights[vertex - 1]  # weights are 0-indexed

        if new_life <= 0 or dist_from_root[vertex] <= time:
            continue

        max_moves = max(max_moves, time)

        state_key = (vertex, time)
        if state_key in visited and visited[state_key] >= new_life:
            continue
        visited[state_key] = new_life

        for next_vertex in adj[vertex]:
            next_time = time + 1

            if dist_from_root[next_vertex] <= next_time:
                continue

            if next_time > n + 100:  # generous upper bound
                continue

            queue.append((next_vertex, next_time, new_life))

    return max_moves + 1


def main():
    T = read_int()
    for _ in range(T):
        print(solve_new())


if __name__ == '__main__':
    main()
