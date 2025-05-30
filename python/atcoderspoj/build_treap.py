import math
import sys


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

ans = []


def find_max_priority_idx(nodes, left, right):
    max_priority = float("-inf")
    max_priority_idx = left
    for i in range(left, right):
        if max_priority < int(nodes[i][1]):
            max_priority_idx = i
            max_priority = int(nodes[i][1])
    return max_priority_idx


def solve(nodes, left, right):
    if left >= right:
        return
    max_el_idx = find_max_priority_idx(nodes, left, right)
    ans.append("(")
    solve(nodes, left, max_el_idx)
    ans.append(f"{nodes[max_el_idx][0]}/{nodes[max_el_idx][1]}")
    solve(nodes, max_el_idx + 1, right)
    ans.append(")")


def main():
    while True:
        line = read_words()
        if len(line) == 1 or line[0][0] == '0':
            break
        nodes = [tuple(element.split("/")) for element in line[1:]]
        nodes.sort(key=lambda x: x[0])
        global ans
        ans = []
        solve(nodes, 0, len(nodes))
        print("".join(ans))


if __name__ == '__main__':
    main()
