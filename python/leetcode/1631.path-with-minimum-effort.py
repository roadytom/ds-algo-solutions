#
# @lc app=leetcode id=1631 lang=python3
#
# [1631] Path With Minimum Effort
#

# @lc code=start
class Solution:

    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        def valid(row, col):
            return 0 <= row < row_length and 0 <= col < col_length

        row_length, col_length = len(heights), len(heights[0])
        distances = [[float("inf")] * col_length for _ in range(row_length)]
        distances[0][0] = 0
        min_heap = [(0, 0, 0)]
        DIRECTIONS = ((0, 1), (1, 0), (0, -1), (-1, 0))
        while min_heap:
            dist, row, col = heappop(min_heap)
            if distances[row][col] < dist:
                continue
            if row == row_length - 1 and col == col_length - 1:
                return dist
            for diff_row, diff_col in DIRECTIONS:
                new_row = row + diff_row
                new_col = col + diff_col
                if not valid(new_row, new_col):
                    continue
                new_effort = max(dist, abs(heights[new_row][new_col] - heights[row][col]))
                if distances[new_row][new_col] > new_effort:
                    distances[new_row][new_col] = new_effort
                    heappush(min_heap, (new_effort, new_row, new_col))

                    # @lc code=end
