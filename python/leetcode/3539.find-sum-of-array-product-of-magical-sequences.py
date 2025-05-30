#
# @lc app=leetcode id=3539 lang=python3
#
# [3539] Find Sum of Array Product of Magical Sequences
#

# @lc code=start
class Solution:
    def magicalSum(self, M: int, K: int, nums: List[int]) -> int:
        def dp(idx, curr_m, curr_k, mask):
            if idx == len(nums) or curr_m == 0:
                return int(curr_m == 0 and bin(mask).count('1') == curr_k)
            
            if curr_m < 0 or curr_k < 0:
                return 0
            if memo[idx][curr_m][curr_k][mask]
# @lc code=end

