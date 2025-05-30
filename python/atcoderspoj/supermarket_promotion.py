import math
import sys
from collections import Counter
from heapq import heappush, heappop


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


def main():
    days = read_int()
    min_heap = []
    max_heap = []
    removed = Counter()
    total = 0
    for _ in range(days):
        day_promotions = read_int_list()
        for promotion in day_promotions:
            heappush(min_heap, promotion)
            heappush(max_heap, -promotion)
        while min_heap[0] in removed and removed[min_heap[0]] != 0:
            removed[heappop(min_heap)] -= 1
        min_element = heappop(min_heap)
        while max_heap[0] in removed and removed[max_heap[0]] != 0:
            removed[heappop(max_heap)] -= 1
        max_element = heappop(max_heap)
        removed[min_element] += 1
        removed[max_element] += 1
        total -= (min_element + max_element)
    print(total)


if __name__ == '__main__':
    main()
