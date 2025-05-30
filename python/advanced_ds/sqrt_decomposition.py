import math


class SQRTDecomposition:
    def __init__(self, array):
        self.arr = array
        self.array_length = len(array)
        self.decomposition_length = int(math.sqrt(self.array_length)) + 1
        self.sum_arr = [0] * self.decomposition_length
        self.pre_compute_sum()

    def pre_compute_sum(self):
        for idx in range(self.array_length):
            self.sum_arr[idx // self.decomposition_length] += self.arr[idx]

    def range_sum(self, left, right):
        left = max(left, 0)
        right = min(right, self.array_length - 1)
        range_sum = 0
        c_l = left // self.decomposition_length
        c_r = right // self.decomposition_length
        if c_l == c_r:
            for idx in range(left, right + 1):
                range_sum += self.arr[idx]
        else:
            for idx in range(left, (c_l + 1) * self.decomposition_length + 1):
                range_sum += self.arr[idx]
            for idx in range(c_l + 1, c_r):
                range_sum += self.sum_arr[idx]
            for idx in range(c_r * self.decomposition_length, right + 1):
                range_sum += self.arr[idx]
        return range_sum


arr = [1, 2, 34, 5, 0, 1, 2, 4, 9, 1]
s = SQRTDecomposition(arr)
print(s.range_sum(0, 123))
