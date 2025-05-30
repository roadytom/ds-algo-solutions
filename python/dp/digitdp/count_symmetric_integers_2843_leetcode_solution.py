# https://leetcode.com/problems/count-symmetric-integers/?envType=daily-question&envId=2025-04-11


class Solution:
    def count_symmetric_rec(self, num_str, idx, n, tight, has_non_zero, is_second_half, rem, diff, first_half_sum,
                            diff_from_left,
                            dp):
        # Base Case: When we have processed all digits,
        # check if the number is valid (i.e., non-zero-started and symmetric).
        if idx == n:
            return 1 if (has_non_zero and diff == 0 and rem == 0) else 0

        # Get the memoized result for the current state.
        # We add offsets (FirstHalfSum and diffFromLeft) to shift potential negative values to positive indices.
        if dp[idx][tight][has_non_zero][is_second_half][rem + first_half_sum][diff + diff_from_left] != -1:
            return dp[idx][tight][has_non_zero][is_second_half][rem + first_half_sum][diff + diff_from_left]

        # Determine the maximum digit available at this index:
        # If 'tight' is true, the maximum is bound by the current digit in numStr.
        # Otherwise, we can choose any digit from 0 to 9.
        max_digit = int(num_str[idx]) if tight else 9
        result = 0

        # Try every possible digit from 0 to max_digit at this position.
        for digit in range(max_digit + 1):
            # Update hasNonZero: becomes true if already true, or if the chosen digit is nonzero.
            new_has_non_zero = has_non_zero or (digit != 0)
            # Start with current balance and difference values.
            new_rem = rem
            new_diff = diff

            # Update the running difference and balance counter based on the current half.
            if is_second_half:
                # In the second half, subtract the digit from the running difference.
                new_diff -= digit
                # Also, decrease the balance counter if a nonzero digit has been set.
                if new_has_non_zero:
                    new_rem -= 1
            else:
                # In the first half, add the digit to the running difference.
                new_diff += digit
                # Increase the balance counter if we've started the number.
                if new_has_non_zero:
                    new_rem += 1

            # Determine if the next state remains tight:
            # It's still tight if we chose the maximum allowed digit.
            new_tight = 1 if (tight and (digit == max_digit)) else 0

            # Continue building the number with the chosen digit.
            result += self.count_symmetric_rec(num_str, idx + 1, n, new_tight, new_has_non_zero, is_second_half,
                                               new_rem,
                                               new_diff,
                                               first_half_sum, diff_from_left, dp)

            # Branch into processing the second half if we are currently in the first half and the number has started.
            if new_has_non_zero and not is_second_half:
                result += self.count_symmetric_rec(num_str, idx + 1, n, new_tight, new_has_non_zero, 1, new_rem,
                                                   new_diff,
                                                   first_half_sum, diff_from_left, dp)

        # Save the computed result for this state and return.
        dp[idx][tight][has_non_zero][is_second_half][rem + first_half_sum][diff + diff_from_left] = result
        return result

    # Counts all symmetric numbers up to 'num'.
    def count_up_to(self, num):
        num_str = str(num)
        n = len(num_str)

        # Offsets used to ensure dp table indices are always non-negative.
        first_half_sum = n  # Shifts 'rem' range.
        diff_from_left = 9 * n  # Shifts 'diff' range.

        # Initialize 6D DP array with -1
        dp = [[[[[[-1 for _ in range(18 * n + 1)] for _ in range(2 * n + 1)] for _ in range(2)] for _ in range(2)] for _
               in range(2)] for _ in range(n + 1)]

        # Start recursion from the first digit, with a tight bound (tight = 1),
        # no nonzero digit encountered yet (hasNonZero = 0), and in first half mode (isSecondHalf = 0).
        return self.count_symmetric_rec(num_str, 0, n, 1, 0, 0, 0, 0, first_half_sum, diff_from_left, dp)

    # To count symmetric integers within the inclusive range [low, high].
    def countSymmetricIntegers(self, low, high):
        # Count symmetric numbers up to 'high' and subtract those up to 'low - 1'.
        return self.count_up_to(high) - self.count_up_to(low - 1)
