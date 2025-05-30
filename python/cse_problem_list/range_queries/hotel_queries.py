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


class SegmentTree:
    def __init__(self, arr):
        self.arr_length = len(arr)
        self.tree_length = 4 * self.arr_length
        self.tree = [0] * self.tree_length
        self.build_tree(arr)

    def build_tree(self, arr):
        def do_build_tree(idx, segment_left, segment_right):
            if segment_left == segment_right:
                self.tree[idx] = arr[segment_left]
                return
            mid = (segment_left + segment_right) // 2
            do_build_tree(2 * idx + 1, segment_left, mid)
            do_build_tree(2 * idx + 2, mid + 1, segment_right)
            self.tree[idx] = max(self.tree[2 * idx + 1], self.tree[2 * idx + 2])

        do_build_tree(0, 0, self.arr_length - 1)

    def update(self, idx, addent):
        def do_update(tree_idx, seg_left, seg_right, idx, addent):
            if seg_left == seg_right:
                self.tree[tree_idx] += addent
                return
            mid = (seg_left + seg_right) // 2
            if idx <= mid:
                do_update(2 * tree_idx + 1, seg_left, mid, idx, addent)
            else:
                do_update(2 * tree_idx + 2, mid + 1, seg_right, idx, addent)
            self.tree[tree_idx] = max(self.tree[2 * tree_idx + 1], self.tree[2 * tree_idx + 2])
        do_update(0, 0, self.arr_length - 1, idx, addent)

    def get_first_greater(self, val):
        def do_get(idx, seg_left, seg_right, left, right, val):
            if left > seg_right or right < seg_left:
                return -1
            if self.tree[idx] < val:
                return -1
            if seg_left == seg_right:
                return seg_left
            mid = (seg_left + seg_right) // 2
            result = do_get(2 * idx + 1, seg_left, mid, left, right, val)
            if result != -1:
                return result
            return do_get(2 * idx + 2, mid + 1, seg_right, left, right, val)
        return do_get(0, 0, self.arr_length - 1, 0, self.arr_length, val)


sys.setrecursionlimit(1000000)


def main():
    _, _ = read_int_list()
    arr = read_int_list()
    sg = SegmentTree(arr)
    guests = read_int_list()
    for guest in guests:
        idx = sg.get_first_greater(guest)
        if idx == -1:
            print(0)
            continue
        sg.update(idx, -guest)
        print(idx + 1)


if __name__ == '__main__':
    main()
