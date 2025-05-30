from typing import List


def longestWPI(hours: List[int]) -> int:
    nums = [1 if val > 8 else -1 for val in hours]
    prefix_sum = [0] * len(nums)
    prefix_sum[0] = nums[0]
    for i in range(1, len(nums)):
        prefix_sum[i] = prefix_sum[i - 1] + nums[i]
    indices = [i for i in range(len(nums))]
    indices.sort(key=lambda i: (prefix_sum[i], i))
    min_index = len(nums)
    max_width = 0
    for i in indices:
        if prefix_sum[i] > 0:
            max_width = max(max_width, i + 1)
        elif min_index == len(nums) or prefix_sum[i] != prefix_sum[min_index]:
            max_width = max(max_width, i - min_index)
        min_index = min(min_index, i)
    return max_width


print(longestWPI([6, 6, 9]))
