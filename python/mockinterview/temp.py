from bisect import bisect_left
from typing import List


class Solution:
    def kthSmallestSubarraySum(self, nums: List[int], k: int) -> int:

        # Helper function to check if the count of subarrays with sum less than or equal to 'limit'
        # is at least k
        def has_k_or_more_subarrays_with_sum_at_most(limit):
            total_sum = 0  # Sum of the current subarray
            start = 0  # Start index for the current subarray
            count = 0  # Count of subarrays with sum less than or equal to 'limit'
            # Iterate over the numbers in the array
            for end, num in enumerate(nums):
                total_sum += num
                # Shrink the window from the left if the total sum exceeds the limit
                while total_sum > limit:
                    total_sum -= nums[start]
                    start += 1
                # The count is increased by the number of subarrays ending with nums[end]
                count += end - start + 1
            # Check if we have at least k subarrays
            return count >= k

        # Binary search to find the kth smallest subarray sum
        left, right = min(nums), sum(nums)
        # Perform binary search with a custom key function by using the bisect_left function
        kth_smallest_sum = left + bisect_left(range(left, right + 1), True,
                                              key=has_k_or_more_subarrays_with_sum_at_most)
        return kth_smallest_sum

# Explanation:
# 1. A binary search is applied to find the kth smallest sum within the range of the minimum
#    element (left) and the sum of all elements (right), inclusively.
# 2. The `has_k_or_more_subarrays_with_sum_at_most` function checks if the number of all
#    possible subarrays with a sum less than or equal to the passed limit is at least k.
# 3. The bisect_left function is used to find the insertion point (the kth smallest sum) for
#    which the condition in `has_k_or_more_subarrays_with_sum_at_most` returns True.
