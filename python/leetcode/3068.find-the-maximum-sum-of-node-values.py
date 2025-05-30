#
# @lc app=leetcode id=3068 lang=python3
#
# [3068] Find the Maximum Sum of Node Values
#

# @lc code=start
class Solution:
    def maximumValueSum(self, nums, k, edges):
        n = len(nums)

        # Build adjacency list
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        def dfs(node, odd, parent):

            dp = [0, 0]
            dp[0] = nums[node]
            dp[1] = nums[node] ^ k

            children = [child for child in graph[node] if child != parent]

            for child in children:
                child_even, child_odd = dfs(child, 0, node), dfs(child, 1, node)
                new_dp = [0, 0]
                new_dp[0] = max(dp[0] + child_even, dp[1] + child_odd)
                new_dp[1] = max(dp[0] + child_odd, dp[1] + child_even)

                dp = new_dp

            return dp[odd]

        return dfs(0, 0, -1)

# @lc code=end
