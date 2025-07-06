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


def bootstrap(f, stack=None):
    if stack is None:
        stack = []

    def wrappedfunc(*args, **kwargs):
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

    return wrappedfunc


dire = [[1, 0], [0, 1], [-1, 0], [0, -1]]
dire8 = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]
alphabets = "abcdefghijklmnopqrstuvwxyz"
ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
MOD = 1000000007
INF = float("inf")

# sys.setrecursionlimit(10 ** 5)


def main():
    n = read_int()
    tree: list[list[int]] = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = read_int_list()
        tree[a - 1].append(b - 1)
        tree[b - 1].append(a - 1)

    subtree_size = [1] * n
    answer = [0] * n

    @bootstrap
    def dfs_post_order(node, parent):
        for adj in tree[node]:
            if adj == parent:
                continue
            yield dfs_post_order(adj, node)
            subtree_size[node] += subtree_size[adj]
            answer[node] += answer[adj]
        answer[node] += subtree_size[node]
        yield

    dfs_post_order(0, -1)

    # print(answer)

    @bootstrap
    def dfs_pre_order(node, parent):
        for adj in tree[node]:
            if adj == parent:
                continue
            answer[adj] = answer[node] + (n - subtree_size[adj]) - subtree_size[adj]
            yield dfs_pre_order(adj, node)
        yield

    dfs_pre_order(0, -1)
    print(max(answer))


if __name__ == '__main__':
    main()
