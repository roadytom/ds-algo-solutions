import math
import sys
from collections import deque, defaultdict
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

sys.setrecursionlimit(10 ** 5)


def main():
    n = read_int()
    costs = read_int_list()
    m = read_int()
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b = read_int_list()
        graph[a].append(b)

    # toposort or preorder dfs
    def dfs(node, visited, ans):
        if visited[node]:
            return
        visited[node] = True
        for adj in graph[node]:
            dfs(adj, visited, ans)
        ans.appendleft(node)

    def dfs2(node, visited, id, sccs):
        if visited[node]:
            return
        visited[node] = True
        sccs[id].append(node)
        for adj in rev_graph[node]:
            if not visited[adj]:
                dfs2(adj, visited, id, sccs)

    topo_order = deque()
    visited = [False] * (n + 1)
    for node in range(1, n + 1):
        if not visited[node]:
            dfs(node, visited, topo_order)
    # reverse the graph
    rev_graph = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for adj in graph[i]:
            rev_graph[adj].append(i)

    sccs_id = 0
    sccs = defaultdict(list)
    visited = [False] * (n + 1)
    for node in topo_order:
        if not visited[node]:
            dfs2(node, visited, sccs_id, sccs)
            sccs_id += 1
    mins = [float("inf")] * sccs_id
    mins_count = [0] * sccs_id
    for i in range(sccs_id):
        for node in sccs[i]:
            mins[i] = min(mins[i], costs[node - 1])
        count = 0
        for node in sccs[i]:
            if costs[node - 1] == mins[i]:
                count += 1
        mins_count[i] = count

    def find_ways_count(mins_count):
        prod = 1
        for min_count in mins_count:
            prod = (prod * min_count) % MOD
        return prod

    print(sum(mins), find_ways_count(mins_count))


if __name__ == '__main__':
    main()
