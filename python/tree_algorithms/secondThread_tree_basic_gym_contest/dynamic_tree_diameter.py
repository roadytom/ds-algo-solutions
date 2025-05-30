import math
import sys
from collections import deque


def read_words():
    return sys.stdin.readline().split()


def read_int():
    return int(sys.stdin.readline().rstrip())


def read_char_list():
    return list(sys.stdin.readline().rstrip())


def read_int_list():
    return [int(x) for x in sys.stdin.readline().split()]


def read_int_list_0_indexed():
    return [int(x) - 1 for x in sys.stdin.readline().split()]


def read_word_char_lists():
    return [list(x) for x in sys.stdin.readline().split()]


def read_n_lines(n):
    return [sys.stdin.readline().strip() for _ in range(n)]


def read_n_lines_words(n):
    return [read_words() for _ in range(n)]


def read_n_ints(n):
    return [read_int() for _ in range(n)]


def read_n_int_lists(n):
    return [read_int_list() for _ in range(n)]


def read_n_int_lists_0_indexed(n):
    return [read_int_list_0_indexed() for _ in range(n)]


def read_n_char_lists(n):
    return [read_char_list() for _ in range(n)]


def read_n_word_char_lists(n):
    return [read_word_char_lists() for _ in range(n)]


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


# sys.setrecursionlimit(1000000)


def find_the_last_nodes(graph, N, root=0):
    visited = [False] * N
    queue = deque([root])
    visited[root] = True
    the_last_nodes = []
    while queue:
        size = len(queue)
        level_nodes = []
        for _ in range(size):
            pop = queue.popleft()
            level_nodes.append(pop)
            for neighbor in graph[pop]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)
        the_last_nodes = level_nodes
    return the_last_nodes


def find_the_diameter(graph, root, N):
    visited = [False] * N
    queue = deque([root])
    visited[root] = True
    level = 0
    while queue:
        size = len(queue)
        for _ in range(size):
            pop = queue.popleft()
            for neighbor in graph[pop]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)
        level += 1
    return level - 1


def main():
    N = read_int()
    edges = read_n_int_lists_0_indexed(N - 1)
    graph = [[] for _ in range(N)]
    for a, b in edges:
        graph[a].append(b)
        graph[b].append(a)
    the_last_nodes = find_the_last_nodes(graph, N)
    second_last_nodes = find_the_last_nodes(graph, N, the_last_nodes[0])
    diameter = find_the_diameter(graph, the_last_nodes[0], N)
    changing_nodes = set(the_last_nodes + second_last_nodes)
    for i in range(N):
        if i in changing_nodes:
            print(diameter + 1)
        else:
            print(diameter)


if __name__ == '__main__':
    # main()
    print(bin(17))
