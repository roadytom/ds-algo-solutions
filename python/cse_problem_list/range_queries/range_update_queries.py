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
        self.lazy = [0] * self.tree_length
        self.build_tree(0, 0, self.arr_length - 1, arr)

    def build_tree(self, tree_idx, seg_left, seg_right, arr):
        if seg_left == seg_right:
            self.tree[tree_idx] = arr[seg_left]
            return
        mid = (seg_left + seg_right) // 2
        self.build_tree(2 * tree_idx + 1, seg_left, mid, arr)
        self.build_tree(2 * tree_idx + 2, mid + 1, seg_right, arr)
        self.tree[tree_idx] = self.tree[2 * tree_idx + 1] + self.tree[2 * tree_idx + 2]

    def update_lazily(self, tree_idx, seg_left, seg_right, query_left, query_right, val):
        if seg_right < query_left or seg_left > query_right:
            return

        if query_left <= seg_left and seg_right <= query_right:
            self.tree[tree_idx] += (seg_right - seg_left + 1) * val
            self.lazy[tree_idx] += val

        else:
            self._push(tree_idx, seg_left, seg_right)
            mid = (seg_left + seg_right) // 2
            self.update_lazily(2 * tree_idx + 1, seg_left, mid, query_left, query_right, val)
            self.update_lazily(2 * tree_idx + 2, mid + 1, seg_right, query_left, query_right, val)
            self.tree[tree_idx] = self.tree[2 * tree_idx + 1] + self.tree[2 * tree_idx + 2]

    def query_lazily(self, tree_idx, seg_left, seg_right, query_left, query_right):
        if seg_right < query_left or seg_left > query_right:
            return 0
        if query_left <= seg_left and seg_right <= query_right:
            return self.tree[tree_idx]
        else:
            self._push(tree_idx, seg_left, seg_right)
            mid = (seg_left + seg_right) // 2
            left = self.query_lazily(2 * tree_idx + 1, seg_left, mid, query_left, query_right)
            right = self.query_lazily(2 * tree_idx + 2, mid + 1, seg_right, query_left, query_right)
            return left + right

    def _push(self, tree_idx, seg_left, seg_right):
        mid = (seg_left + seg_right) // 2
        self.tree[2 * tree_idx + 1] += (mid - seg_left + 1) * self.lazy[tree_idx]
        self.lazy[2 * tree_idx + 1] += self.lazy[tree_idx]
        self.tree[2 * tree_idx + 2] += (seg_right - mid) * self.lazy[tree_idx]
        self.lazy[2 * tree_idx + 2] += self.lazy[tree_idx]
        self.lazy[tree_idx] = 0


# sys.setrecursionlimit(1000000)


def main():
    n, q = read_int_list()
    arr = read_int_list()
    sg = SegmentTree(arr)
    for _ in range(q):
        query_type, *query = read_int_list()
        if query_type == 1:
            a, b, u = query
            sg.update_lazily(0, 0, sg.arr_length - 1, a - 1, b - 1, u)
        else:
            k = query[0]
            print(sg.query_lazily(0, 0, sg.arr_length - 1, k - 1, k - 1))


if __name__ == '__main__':
    main()
