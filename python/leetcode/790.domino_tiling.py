from functools import cache


class Solution:
    def numTilings(self, n: int) -> int:
        changes = ((2, 0), (0, 2), (1, 1), (2, 1), (1, 2))
        max_diff_col = 2

        @cache
        def dp(row, col):
            print(row, col)
            if row >= n or col >= n:
                return int(row == n and col == n)
            # base case
            ans = 0
            for diff_row, diff_col in changes:
                new_row = row + diff_row
                new_col = col + diff_col
                if abs(new_row - new_col) > 2:
                    continue
                ans += dp(new_row, new_col)
            return ans

        return dp(0, 0)


print(Solution().numTilings(3))
