#
# @lc app=leetcode id=1691 lang=python3
#
# [1691] Maximum Height by Stacking Cuboids 
#
from typing import List


# @lc code=start
class Solution:

    def maxHeight(self, cuboids: List[List[int]]) -> int:
        def possible(idx, prev_idx):
            if prev_idx == -1:
                return True
            for curr, prev in zip(cuboids[idx], cuboids[prev_idx]):
                if curr > prev:
                    return False
            return True

        cuboids = list(map(lambda x: list(sorted(x)), cuboids))
        cuboids.sort(reverse=True)

        def dp(idx, prev_idx):
            if idx == len(cuboids):
                return 0
            skip = dp(idx + 1, prev_idx)
            take = 0
            if possible(idx, prev_idx):
                take = cuboids[idx][2] + dp(idx + 1, idx)
            return max(skip, take)

        return dp(0, -1)

# @lc code=end
# print(Solution().maxHeight([[38,25,45],[76,35,3]]))
