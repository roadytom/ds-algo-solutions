import math
import sys

from sortedcontainers import SortedList


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
    def insert(val):
        nonlocal sum_low, sum_up
        if not low or low[-1] >= val:
            low.add(val)
            sum_low += val
        else:
            up.add(val)
            sum_up += val
        balance()

    def pop(val):
        nonlocal sum_low, sum_up
        if not low:
            raise Exception("empty")
        if low[-1] >= val:
            low.remove(val)
            sum_low -= val
        else:
            up.remove(val)
            sum_up -= val
        balance()

    def balance():
        nonlocal sum_low, sum_up
        if len(low) - len(up) > 1:
            sum_low -= low[-1]
            sum_up += low[-1]
            up.add(low.pop(-1))
        elif len(up) > len(low):
            sum_up -= up[0]
            sum_low += up[0]
            low.add(up.pop(0))

    n, k = read_int_list()
    arr = read_int_list()
    low, up = SortedList(), SortedList()
    sum_up, sum_low = 0, 0
    left, right = 0, 0
    ans = []
    while right < len(arr):
        insert(arr[right])
        if right - left + 1 == k:
            med = low[-1]
            ans.append(sum_up - med * len(up) + med * len(low) - sum_low)
            pop(arr[left])
            left += 1
        right += 1
    print(" ".join(map(str, ans)))


if __name__ == '__main__':
    main()
