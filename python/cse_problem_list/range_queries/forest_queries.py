import math
import sys


def read_words():
    return sys.stdin.readline().split()


def read_line():
    return sys.stdin.readline().rstrip()


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


class SegmentTree2D:
    def __init__(self, grid):
        self.row_length = len(grid)
        self.col_length = len(grid[0])
        self.tree = [[0] * (4 * self.col_length) for _ in range(self.row_length * 4)]
        self.build_row(0, 0, self.row_length - 1, grid)

    def build_row(self, idx, left_row, right_row, grid):
        if left_row == right_row:
            self.build_col(idx, left_row, right_row, 0, 0, self.col_length - 1, grid)
            return
        mid = (left_row + right_row) // 2
        self.build_row(2 * idx + 1, left_row, mid, grid)
        self.build_row(2 * idx + 2, mid + 1, right_row, grid)
        self.build_col(idx, left_row, right_row, 0, 0, self.col_length - 1, grid)

    def build_col(self, row_idx, left_row, right_row, col_idx, left_col, right_col, grid):
        if left_col == right_col:
            if left_row == right_row:
                self.tree[row_idx][col_idx] = grid[left_row][left_col]
            else:
                self.tree[row_idx][col_idx] = self.tree[2 * row_idx + 1][col_idx] \
                    + self.tree[2 * row_idx + 2][col_idx]
        else:
            mid = (left_col + right_col) // 2
            self.build_col(row_idx, left_row, right_row, 2 * col_idx + 1, left_col, mid, grid)
            self.build_col(row_idx, left_row, right_row, 2 * col_idx + 2, mid + 1, right_col, grid)
            self.tree[row_idx][col_idx] = self.tree[row_idx][2 * col_idx + 1] + \
                self.tree[row_idx][2 * col_idx + 2]

    def query_row(self, row_idx, left_row, right_row, q_left_row, q_right_row, q_left_col, q_right_col):
        if q_right_row < left_row or q_left_row > right_row:
            return 0
        if q_left_row <= left_row <= right_row <= q_right_row:
            return self.query_col(row_idx, 0, 0, self.col_length - 1, q_left_col, q_right_col)
        mid = (left_row + right_row) // 2
        left_res = self.query_row(2 * row_idx + 1, left_row, mid, q_left_row, q_right_row, q_left_col, q_right_col)
        right_res = self.query_row(2 * row_idx + 2, mid + 1, right_row, q_left_row, q_right_row, q_left_col, q_right_col)
        return left_res + right_res

    def query_col(self, row_idx, col_idx, left_col, right_col, q_left_col, q_right_col):
        if q_right_col < left_col or q_left_col > right_col:
            return 0
        if q_left_col <= left_col <= right_col <= q_right_col:
            return self.tree[row_idx][col_idx]
        mid = (left_col + right_col) // 2
        return self.query_col(row_idx, 2 * col_idx + 1, left_col, mid, q_left_col, q_right_col) \
            + self.query_col(row_idx, 2 * col_idx + 2, mid + 1, right_col, q_left_col, q_right_col)


def main():
    n, q = read_int_list()
    grid = [[0] * n for _ in range(n)]
    for i in range(n):
        row = read_line()
        grid[i] = [int(ch == '*') for ch in row]
    sg = SegmentTree2D(grid)

    for _ in range(q):
        q_left_row, q_left_col, q_right_row, q_right_col = read_int_list()
        print(sg.query_row(0, 0, n - 1, q_left_row - 1, q_right_row - 1, q_left_col - 1, q_right_col - 1))


if __name__ == '__main__':
    main()
