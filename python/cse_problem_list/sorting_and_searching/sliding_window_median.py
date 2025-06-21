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
    def __init__(self, n):
        self.arr_length = n
        self.tree_length = 4 * n
        self.tree = [0] * self.tree_length

    def update(self, idx, addend):
        def do_update(tree_idx, seg_left, seg_right, idx, addend):
            if seg_left == seg_right:
                self.tree[tree_idx] += addend
                return
            mid = (seg_left + seg_right) // 2
            if idx <= mid:
                do_update(2 * tree_idx + 1, seg_left, mid, idx, addend)
            else:
                do_update(2 * tree_idx + 2, mid + 1, seg_right, idx, addend)
            self.tree[tree_idx] = self.tree[2 * tree_idx + 1] + self.tree[2 * tree_idx + 2]

        do_update(0, 0, self.arr_length - 1, idx, addend)

    def get_kth_element(self, k):
        def do_get_kth_element(tree_idx, seg_left, seg_right, k):
            if k > self.tree[tree_idx]:
                return -1
            if seg_left == seg_right:
                return seg_left
            mid = (seg_left + seg_right) // 2
            if k < self.tree[2 * tree_idx + 1]:
                return do_get_kth_element(2 * tree_idx + 1, seg_left, mid, k)
            else:
                return do_get_kth_element(2 * tree_idx + 2, mid + 1, seg_right, k - self.tree[2 * tree_idx + 1])

        return do_get_kth_element(0, 0, self.arr_length - 1, k)


def main():
    n, k = read_int_list()
    arr = read_int_list()
    sorted_unique = list(set(arr))
    sorted_unique.sort()
    val_to_idx = {val: idx for idx, val in enumerate(sorted_unique)}
    idx_to_val = {val: key for key, val in val_to_idx.items()}
    left, right = 0, 0
    res = []
    segment_tree = SegmentTree(len(sorted_unique))
    total_sum = 0
    while right < n:
        total_sum += arr[right]
        segment_tree.update(val_to_idx[arr[right]], 1)
        if right - left + 1 == k:
            mid = (k - 1) // 2
            median_idx = segment_tree.get_kth_element(mid)
            # print(median_idx)
            median_val = idx_to_val[median_idx]
            res.append(median_val)
            segment_tree.update(val_to_idx[arr[left]], -1)
            left += 1
        right += 1
    print(" ".join(map(str, res)))


if __name__ == '__main__':
    main()
