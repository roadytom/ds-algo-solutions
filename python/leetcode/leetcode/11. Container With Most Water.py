from bisect import bisect_left, insort

from typing import List


class Solution:
    def maxArea(self, heights: List[int]) -> int:
        return max(self.solve(heights), self.solve(list(reversed(heights))))

    def solve(self, heights: List[int]) -> int:
        mon_inc_stack = []
        max_area = -1
        for idx, height in enumerate(heights):
            left_idx = bisect_left(mon_inc_stack, height, key=lambda t: t[0])
            if left_idx < len(mon_inc_stack):
                max_area = max(max_area, (idx - mon_inc_stack[left_idx][1]) * height)

            if not mon_inc_stack or mon_inc_stack[-1][0] < height:
                mon_inc_stack.append((height, idx))
        return max_area

print(Solution().maxArea([1,8,6,2,5,4,8,3,7]))