import math
import sys
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


dire = [[1, 0], [0, 1], [-1, 0], [0, -1]]
dire8 = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]
alphabets = "abcdefghijklmnopqrstuvwxyz"
ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
MOD = 1000000007
INF = float("inf")


# sys.setrecursionlimit(10**6)

# def solve(num):
#     digit_arr = list(map(int, str(num)))
#     digits_count = len(digit_arr)
#
#     def dp(pos, under, is_zero_leading, product):
#         if pos == digits_count:
#             return 0 if is_zero_leading else product
#         max_product = 0
#         for digit in range(10):
#             if not under and digit > digit_arr[pos]:
#                 break
#             new_under = under or digit < digit_arr[pos]
#             new_is_zero_leading = is_zero_leading and digit == 0
#             new_product = product if new_is_zero_leading else product * digit
#             max_product = max(max_product, dp(pos + 1, new_under, new_is_zero_leading, new_product))
#         return max_product
#
#     return dp(0, False, True, 1)


# def digit_product(x):
#     product = 1
#     for ch in str(x):
#         product *= int(ch)
#     return product
#
#
# def solve(a, b):
#     candidates = [b]
#     s = list(str(b))
#     for i in range(len(s)):
#         if s[i] == '0':
#             continue
#         temp = list(s)
#         temp[i] = str(int(temp[i]) - 1)
#         for j in range(i + 1, len(temp)):
#             temp[j] = '9'
#         num = int("".join(temp))
#         if num >= a:
#             candidates.append(num)
#     candidates.append(a)
#
#     best = a
#     best_product = digit_product(a)
#     for num in candidates:
#         prod = digit_product(num)
#         if prod > best_product:
#             best_product = prod
#             best = num
#     print(best)

def solve(a, b):
    def get_first_non_zero_idx(arr):
        first_non_zero_idx = 0
        while first_non_zero_idx < len(arr) and ans[first_non_zero_idx] == 0:
            first_non_zero_idx += 1
        return first_non_zero_idx

    def prod(arr):
        ans = 1
        for num in arr[get_first_non_zero_idx(arr):]:
            ans *= num
        return ans

    digit_array_b = list(map(int, str(b)))
    digit_array_a = list(map(int, str(a)))
    digit_array_a = [0] * (len(digit_array_b) - len(digit_array_a)) + digit_array_a
    equal = True
    ans = [-1]
    for right in range(len(digit_array_a) + 1):
        equal = equal and digit_array_a[right] == digit_array_b[right]
        curr = digit_array_b[:right]
        if right < len(digit_array_b) and equal:
            continue
        if right < len(digit_array_b):
            curr.append(digit_array_b[right] - 1)
        curr = curr + [9] * (len(digit_array_b) - len(curr))
        if prod(curr) > prod(ans):
            ans = curr
    print("".join(map(str, ans[get_first_non_zero_idx(ans):])))


def main():
    a, b = read_int_list()
    solve(a, b)


if __name__ == '__main__':
    main()
