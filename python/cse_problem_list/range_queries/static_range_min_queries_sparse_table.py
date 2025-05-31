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


class SparseTable:
    def __init__(self, arr):
        self.arr_length = len(arr)
        self.max_log = int(math.log2(self.arr_length)) + 1
        self.table = [[0] * self.max_log for _ in range(self.arr_length)]
        self.build_table(arr)

    def build_table(self, arr):
        for i in range(self.arr_length):
            self.table[i][0] = arr[i]
        for j in range(1, self.max_log):
            for i in range(0, self.arr_length - (1 << j) + 1):
                self.table[i][j] = min(self.table[i][j - 1], self.table[i + (1 << (j - 1))][j - 1])

    def query(self, left, right):
        length = right - left + 1
        max_2_power = len(bin(length)) - 3
        return min(self.table[left][max_2_power], self.table[right - (1 << max_2_power) + 1][max_2_power])


sys.setrecursionlimit(1000000)


def main():
    n, q = read_int_list()
    arr = read_int_list()
    sg = SparseTable(arr)
    for _ in range(q):
        left, right = read_int_list()
        print(sg.query(left - 1, right - 1))


if __name__ == '__main__':
    main()
