import sys
from math import log, factorial, exp


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
    return factorial(n) // factorial(r)


def comb(n, r):
    return factorial(n) // (factorial(r) * factorial(n - r))


def make_list(n, *args, default=0):
    return [make_list(*args, default=default) for _ in range(n)] if len(args) > 0 else [
        default for _ in range(n)]


dire = [[1, 0], [0, 1], [-1, 0], [0, -1]]
dire8 = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]
alphabets = "abcdefghijklmnopqrstuvwxyz"
ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
MOD = 1000000007
INF = float("inf")


# sys.setrecursionlimit(1000)


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
            self.tree[idx] = self.tree[2 * idx + 1] + self.tree[2 * idx + 2]

        do_build_tree(0, 0, self.arr_length - 1)

    def query(self, query_left, query_right):
        def do_query(idx, segment_left, segment_right, left, right):
            if segment_right < left or segment_left > right:
                return 0
            if left <= segment_left and segment_right <= right:
                return self.tree[idx]
            mid = (segment_left + segment_right) // 2
            left_result = do_query(2 * idx + 1, segment_left, mid, left, right)
            right_result = do_query(
                2 * idx + 2, mid + 1, segment_right, left, right)
            return left_result + right_result

        return do_query(0, 0, self.arr_length - 1, query_left, query_right)

    def update(self, idx, new_val):
        def do_update(tree_idx, seg_left, seg_right, idx, new_val):
            if seg_left == seg_right:
                self.tree[tree_idx] = new_val
                return
            mid = (seg_left + seg_right) // 2
            if idx <= mid:
                do_update(2 * tree_idx + 1, seg_left, mid, idx, new_val)
            else:
                do_update(2 * tree_idx + 2, mid + 1, seg_right, idx, new_val)
            self.tree[tree_idx] = self.tree[2 * tree_idx + 1] + self.tree[2 * tree_idx + 2]

        do_update(0, 0, self.arr_length - 1, idx, new_val)


def main():
    nodes_count = read_int()
    tree = [[] for _ in range(nodes_count)]
    for _ in range(nodes_count - 1):
        a, b = read_int_list_0_indexed()
        tree[a].append(b)
        tree[b].append(a)
    in_time = [-1] * nodes_count
    out_time = [-1] * nodes_count

    def convert_tree_to_array_with_euler_tour():
        def dfs(node, parent, timer):
            in_time[node] = timer
            for child in tree[node]:
                if child == parent:
                    continue
                timer = dfs(child, node, timer + 1)
            out_time[node] = timer
            return timer

        dfs(0, -1, 0)

    convert_tree_to_array_with_euler_tour()
    segment_tree = SegmentTree([0] * nodes_count)
    # print(segment_tree.tree)

    q = read_int()
    for _ in range(q):
        t, x, y = read_int_list()
        if t == 1:
            x -= 1
            left = in_time[x]
            y = log(y)
            segment_tree.update(left, y)
        else:
            # query
            x -= 1
            y -= 1
            x_left, x_right = in_time[x], out_time[x]
            y_left, y_right = in_time[y], out_time[y]
            x_subtree_value = segment_tree.query(x_left, x_right)
            y_subtree_value = segment_tree.query(y_left, y_right)
            log_diff = x_subtree_value - y_subtree_value
            ans_log = max(log(1e-9), min(log(1e9), log_diff))
            print(f"{exp(ans_log):.10f}")


if __name__ == '__main__':
    main()
