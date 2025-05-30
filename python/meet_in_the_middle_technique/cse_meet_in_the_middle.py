import sys
import math


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
    def fill_subset_sums(idx, curr_sum, arr, container):
        if idx == len(arr):
            container.append(curr_sum)
            return
        fill_subset_sums(idx + 1, curr_sum, arr, container)
        fill_subset_sums(idx + 1, curr_sum + arr[idx], arr, container)

    n, x = read_int_list()
    arr = read_int_list()
    left_arr = arr[:n//2]
    right_arr = arr[n//2:]
    left_subset_sums = []
    fill_subset_sums(0, 0, left_arr, left_subset_sums)
    right_subset_sums = []
    fill_subset_sums(0, 0, right_arr, right_subset_sums)
    left_subset_sums.sort()
    right_subset_sums.sort()
    left, right = 0, len(right_subset_sums) - 1
    ways = 0
    while left < len(left_subset_sums) and right >= 0:
        sm = left_subset_sums[left] + right_subset_sums[right]
        if sm == x:
            left_count = 0
            left_val = left_subset_sums[left]
            while left < len(left_subset_sums) and left_subset_sums[left] == left_val:
                left_count += 1
                left += 1
            right_count = 0
            right_val = right_subset_sums[right]
            while right >= 0 and right_subset_sums[right] == right_val:
                right -= 1
                right_count += 1
            ways += left_count * right_count
        elif sm > x:
            right -= 1
        else:
            left += 1
    print(ways)

if __name__ == '__main__':
    main()
