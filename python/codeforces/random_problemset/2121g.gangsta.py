import math
import sys
from collections import namedtuple
from functools import reduce
from types import GeneratorType
from typing import List


def read_words() -> List[str]:
    return sys.stdin.readline().split()


def read_line() -> str:
    return sys.stdin.readline().rstrip()


def read_n_lines(n) -> List[str]:
    return [sys.stdin.readline().strip() for _ in range(n)]


def read_int() -> int:
    return int(sys.stdin.readline().rstrip())


def read_int_list() -> List[int]:
    return [int(x) for x in sys.stdin.readline().split()]


def read_int_list_0_indexed() -> List[int]:
    return [int(x) - 1 for x in sys.stdin.readline().split()]


def read_n_lines_words(n) -> List[List[str]]:
    return [read_words() for _ in range(n)]


def read_n_ints(n) -> List[int]:
    return [read_int() for _ in range(n)]


def read_n_int_lists(n) -> List[List[int]]:
    return [read_int_list() for _ in range(n)]


def read_n_int_lists_0_indexed(n) -> List[List[int]]:
    return [read_int_list_0_indexed() for _ in range(n)]


def perm(n, r):
    return math.factorial(n) // math.factorial(r)


def comb(n, r):
    return math.factorial(n) // (math.factorial(r) * math.factorial(n - r))


def make_list(n, *args, default=0):
    return [make_list(*args, default=default) for _ in range(n)] if len(args) > 0 else [
        default for _ in range(n)]


def recursion_fix(f, stack=None):
    if stack is None:
        stack = []

    def wrapped(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrapped


def add(*args):
    return reduce(lambda a, b: (a + b) % MOD, args)


def sub(*args):
    return reduce(lambda a, b: ((a - b) % MOD + MOD) % MOD, args)


def mul(*args):
    return reduce(lambda a, b: (a * b) % MOD, args)


def mod_inverse(x):
    return exp(x, MOD - 2)


def exp(base, exponent):
    if exponent == 0:
        return 1
    half = exp(base, exponent // 2)
    if exponent % 2 == 0:
        return mul(half, half)
    return mul(half, half, base)


# factorials = [1] * 2_000_001
# inv_factorials = [1] * 2_000_001

def precomp_facts(factorials, inv_factorials):
    factorials[0] = 1
    inv_factorials[0] = 1
    for i in range(1, len(factorials)):
        factorials[i] = mul(factorials[i - 1], i)
    inv_factorials[-1] = mod_inverse(factorials[-1])
    for i in reversed(range(len(inv_factorials) - 1)):
        inv_factorials[i] = mul(inv_factorials[i + 1], i + 1)


dire = [[1, 0], [0, 1], [-1, 0], [0, -1]]
dire8 = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]
alphabets = "abcdefghijklmnopqrstuvwxyz"
ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
MOD = 1000000007
INF = float("inf")
pair = namedtuple("pair", ("sum", "count"))


class SegmentTree:
    def __init__(self, arr_length):
        self.arr_length = arr_length
        self.tree_length = 4 * self.arr_length
        self.tree = [pair(0, 0) for _ in range(self.tree_length)]

    def merge(self, a, b):
        return pair(a.sum + b.sum, a.count + b.count)

    def update(self, idx, val):
        @recursion_fix
        def do_update(tree_idx, seg_left, seg_right, idx, val):
            if idx < seg_left or idx > seg_right:
                yield
            if seg_left == seg_right:
                self.tree[tree_idx] = self.merge(self.tree[tree_idx], pair(val, 1))
                yield
            mid = (seg_left + seg_right) // 2
            yield do_update(2 * tree_idx, seg_left, mid, idx, val)
            yield do_update(2 * tree_idx + 1, mid + 1, seg_right, idx, val)
            self.tree[tree_idx] = self.merge(self.tree[2 * tree_idx], self.tree[2 * tree_idx + 1])
            yield

        do_update(1, 0, self.arr_length - 1, idx, val)

    def query(self, q_left, q_right):
        @recursion_fix
        def do_query(tree_idx, seg_left, seg_right, left, right):
            if seg_left > right or seg_right < left:
                yield pair(0, 0)
            if left <= seg_left and seg_right <= right:
                yield self.tree[tree_idx]
            mid = (seg_left + seg_right) // 2
            left_res = yield do_query(2 * tree_idx, seg_left, mid, left, right)
            right_res = yield do_query(2 * tree_idx + 1, mid + 1, seg_right, left, right)
            yield self.merge(left_res, right_res)

        return do_query(1, 0, self.arr_length - 1, q_left, q_right)


def solve():
    n = read_int()
    string = read_line()
    # Part I:
    part1 = 0
    for l in range(1, n + 1):
        part1 += l * (n - l + 1)
    curr_diff = 0
    offset = n
    sg = SegmentTree(2 * n + 1)
    part2 = 0
    sg.update(offset, 0)
    for i in range(1, n + 1):
        curr_diff += (1 if string[i - 1] == '1' else -1)
        seg_idx = curr_diff + offset
        less_sum, less_count = sg.query(0, seg_idx - 1)
        total_sum, total_count = sg.query(0, 2 * n)
        gre_count, gre_sum = total_count - less_count, total_sum - less_sum
        sum_diff = (curr_diff * less_count - less_sum) + (gre_sum - gre_count * curr_diff)
        part2 += sum_diff
        sg.update(seg_idx, curr_diff)
    # print(part1, part2)
    print((part1 + part2) // 2)


def main():
    T = read_int()
    for _ in range(T):
        solve()


if __name__ == '__main__':
    main()
