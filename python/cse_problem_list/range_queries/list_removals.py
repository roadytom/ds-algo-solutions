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


class SegmentTree:
    def __init__(self, arr):
        self.size = len(arr)
        self.tree_size = 4 * self.size
        self.tree = [0] * (self.tree_size)
        self.arr = arr
        self.build_tree(0, 0, self.size - 1, arr)

    def build_tree(self, idx, seg_left, seg_right, arr):
        # is leaf
        if seg_left == seg_right:
            self.tree[idx] = 1
            return
        mid = (seg_left + seg_right) // 2
        self.build_tree(2 * idx + 1, seg_left, mid, arr)
        self.build_tree(2 * idx + 2, mid + 1, seg_right, arr)
        self.tree[idx] = seg_right - seg_left + 1

    def remove_and_get_kth_element(self, idx, seg_left, seg_right, k):
        if k > self.tree[idx]:
            return -1
        if seg_left == seg_right:
            self.tree[idx] = 0
            return self.arr[seg_left]
        mid = (seg_left + seg_right) // 2
        if k < self.tree[2 * idx + 1]:
            result = self.remove_and_get_kth_element(2 * idx + 1, seg_left, mid, k)
        else:
            result = self.remove_and_get_kth_element(2 * idx + 2, mid + 1, seg_right,
                                                     k - self.tree[2 * idx + 1])
        self.tree[idx] = self.tree[2 * idx + 1] + self.tree[2 * idx + 2]
        return result


def main():
    n = read_int()
    arr = read_int_list()
    sg = SegmentTree(arr)
    removals = read_int_list()
    for idx in removals:
        val = sg.remove_and_get_kth_element(0, 0, sg.size - 1, idx - 1)
        print(val)


if __name__ == '__main__':
    main()
