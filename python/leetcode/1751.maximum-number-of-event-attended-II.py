from bisect import bisect_right
from functools import cache
from typing import List


class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()
        starts = list(map(lambda x: x[0], events))

        def find_next_possible_idx(idx):
            end = events[idx][1]

            return bisect_right(starts, end, idx + 1, len(events))

        @cache
        def dp(idx, attend_count):
            if idx >= len(events) or attend_count == k:
                return 0
            curr_start, curr_end, curr_val = events[idx]
            take = 0
            if attend_count < k:
                next_idx = find_next_possible_idx(idx)
                take = dp(next_idx, attend_count + 1) + curr_val
            skip = dp(idx + 1, attend_count)
            return max(take, skip)

        return max(dp(idx, 0) for idx in range(len(events)))


print(Solution().maxValue([[1, 2, 4], [3, 4, 3], [2, 3, 1]], 2))
