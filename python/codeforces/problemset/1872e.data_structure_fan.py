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


class SegmentTreeNode:
    def __init__(self, xor_0=0, xor_1=0, lazy=0):
        self.xor_0 = xor_0
        self.xor_1 = xor_1
        self.lazy = lazy

    def flip(self):
        self.xor_0, self.xor_1 = self.xor_1, self.xor_0


class SegmentTreeCustom:
    def __init__(self, arr, flags):
        self.arr_length = len(arr)
        self.tree_length = 4 * self.arr_length
        self.tree = [SegmentTreeNode() for _ in range(self.tree_length)]
        self.build(0, 0, self.arr_length - 1, arr, flags)

    def build(self, tree_idx, seg_left, seg_right, arr, flags):
        if seg_left == seg_right:
            if flags[seg_left] == '0':
                self.tree[tree_idx].xor_0 = arr[seg_left]
            else:
                self.tree[tree_idx].xor_1 = arr[seg_left]
            return
        mid = (seg_left + seg_right) // 2
        self.build(2 * tree_idx + 1, seg_left, mid, arr, flags)
        self.build(2 * tree_idx + 2, mid + 1, seg_right, arr, flags)
        self._pull(tree_idx)

    def _pull(self, tree_idx):
        left_child = self.tree[2 * tree_idx + 1]
        right_child = self.tree[2 * tree_idx + 2]
        self.tree[tree_idx].xor_0 = left_child.xor_0 ^ right_child.xor_0
        self.tree[tree_idx].xor_1 = left_child.xor_1 ^ right_child.xor_1

    def update_lazy(self, tree_idx, seg_left, seg_right, query_left, query_right):
        self._push(tree_idx, seg_left, seg_right)
        if seg_left > query_right or seg_right < query_left:
            return
        if query_left <= seg_left and seg_right <= query_right:
            self.tree[tree_idx].lazy ^= 1
            self._push(tree_idx, seg_left, seg_right)
        else:
            mid = (seg_left + seg_right) // 2
            self.update_lazy(2 * tree_idx + 1, seg_left, mid, query_left, query_right)
            self.update_lazy(2 * tree_idx + 2, mid + 1, seg_right, query_left, query_right)
            self._pull(tree_idx)

    def _push(self, tree_idx, seg_left, seg_right):
        if self.tree[tree_idx].lazy:
            self.tree[tree_idx].flip()
            self.tree[tree_idx].lazy = 0
            if seg_left != seg_right:
                self.tree[2 * tree_idx + 1].lazy ^= 1
                self.tree[2 * tree_idx + 2].lazy ^= 1

    def query_lazy(self, tree_idx, seg_left, seg_right, query_left, query_right, flag):
        self._push(tree_idx, seg_left, seg_right)
        if seg_left > query_right or seg_right < query_left:
            return 0
        if query_left <= seg_left and seg_right <= query_right:
            return self.tree[tree_idx].xor_0 if flag == 0 else self.tree[tree_idx].xor_1
        mid = (seg_left + seg_right) // 2
        left_child = self.query_lazy(2 * tree_idx + 1, seg_left, mid, query_left, query_right, flag)
        right_child = self.query_lazy(2 * tree_idx + 2, mid + 1, seg_right, query_left, query_right, flag)
        return left_child ^ right_child

    def flip(self, l, r):
        self.update_lazy(0, 0, self.arr_length - 1, l, r)

    def flag_query(self, flag):
        return self.query_lazy(0, 0, self.arr_length - 1, 0, self.arr_length, flag)



# sys.setrecursionlimit(10**6)

def solve():
    n = read_int()
    arr = read_int_list()
    flag = read_char_list()
    sg = SegmentTreeCustom(arr, flag)
    q = read_int()
    res = []
    for _ in range(q):
        data = read_int_list()
        if data[0] == 1:
            l, r = data[1] - 1, data[2] - 1
            # range update query
            sg.flip(l, r)
        else:
            flag = data[1]
            # range xor query
            res.append(str(sg.flag_query(flag)))
    print(" ".join(res))


def main():
    tt = read_int()
    for _ in range(tt):
        solve()


if __name__ == '__main__':
    main()
