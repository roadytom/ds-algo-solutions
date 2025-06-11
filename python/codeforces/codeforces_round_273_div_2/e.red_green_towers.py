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


# sys.setrecursionlimit(10 ** 3)


def is_wavy(num):
    str_num = str(num)
    for i in range(1, len(str_num) - 1):
        if str_num[i - 1] < str_num[i] > str_num[i + 1] or str_num[i - 1] > str_num[i] < str_num[i + 1]:
            continue
        return False
    return True


def main():
    def is_wavy(num):
        if num == 0:
            return False
        # Convert number to list of digits
        digits = [int(d) for d in str(num)]
        d = len(digits)
        if d <= 2:
            return True
        # Check each middle digit (index 1 to d-2)
        for i in range(1, d - 1):
            curr = digits[i]
            prev = digits[i - 1]
            next_d = digits[i + 1]
            # Must be a peak (curr > prev and curr > next) or valley (curr < prev and curr < next)
            if not ((curr > prev and curr > next_d) or (curr < prev and curr < next_d)):
                return False
        return True

    def find_kth_wavy_divisible(n, k):
        # Maximum multiple m such that m * n <= 10^14
        max_m = 10 ** 14 // n
        if k > max_m:
            return -1  # Not enough multiples within 10^14

        # Special case: n = 1, we need k-th smallest wavy number
        if n == 1:
            # For simplicity, handle small k directly
            wavy_numbers = []
            num = 1
            while len(wavy_numbers) < k and num <= 10 ** 14:
                if is_wavy(num):
                    wavy_numbers.append(num)
                num += 1
            if len(wavy_numbers) < k:
                return -1
            return wavy_numbers[k - 1]

        # General case: find k-th wavy multiple of n
        wavy_multiples = []
        for m in range(1, max_m + 1):
            num = m * n
            if num > 10 ** 14:
                break
            if is_wavy(num):
                wavy_multiples.append(num)
            if len(wavy_multiples) >= k:
                return wavy_multiples[k - 1]

        # If we found fewer than k wavy multiples
        return -1

    # Input
    n, k = read_int_list()

    # Output
    print(find_kth_wavy_divisible(n, k))


if __name__ == '__main__':
    main()
