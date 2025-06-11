#
# @lc app=leetcode id=2836 lang=python3
#
# [2836] Maximize Value of Function in a Ball Passing Game
#
from math import log2
from typing import List


# @lc code=start


class Solution:
    def getMaxFunctionValue(self, receiver: List[int], k: int) -> int:
        def get_kth_score(node, k):
            res = 0
            for log in range(max_log):
                if k & (1 << log) != 0:
                    res += up_sum[node][log]
                    node = up[node][log]
            # res += up_sum[node][the_last]
            # print(node, k, res)
            return res

        max_log = int(log2(k)) + 1
        nodes_count = len(receiver)
        up = [[-1] * max_log for _ in range(nodes_count)]
        up_sum = [[0] * max_log for node in range(nodes_count)]
        for node in range(nodes_count):
            up[node][0] = receiver[node]
            up_sum[node][0] = receiver[node]
        for log in range(1, max_log):
            for node in range(nodes_count):
                up[node][log] = up[up[node][log - 1]][log - 1]
                up_sum[node][log] = up_sum[node][log - 1] + up_sum[up[node][log - 1]][log - 1]
        # for node in range(nodes_count):
        #     print(up[node])
        # for node in range(nodes_count):
        #     print(up_sum[node])
        return max(get_kth_score(node, k) + node for node in range(nodes_count))

# print(Solution().getMaxFunctionValue([1,1,1,2,3], 3))

# @lc code=end
