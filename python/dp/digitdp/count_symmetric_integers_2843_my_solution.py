class Solution:
    def countSymmetricIntegers(self, l: int, r: int) -> int:
        def count_upto_num(num):
            num_arr = list(map(int, str(num)))
            number_of_digits = len(num_arr)
            mapper = 9 * number_of_digits
            memo = [[[[[-1] * 2 for _ in range(2)] for _ in range(18 * number_of_digits + 1)] for _ in
                     range(number_of_digits + 1)] for _ in range(number_of_digits)]

            def dp(idx, tight, diff=0, is_leading_zero=True, leading_zero_count=0):
                if idx == number_of_digits:
                    return (number_of_digits - leading_zero_count) % 2 == 0 and diff == 0
                # print(idx, number_of_digits)
                # print(leading_zero_count, number_of_digits + 1)
                # print(diff + mapper, 18 * number_of_digits + 1)

                if memo[idx][leading_zero_count][diff + mapper][is_leading_zero][tight] != -1:
                    return memo[idx][leading_zero_count][diff + mapper][is_leading_zero][tight]
                max_digit = num_arr[idx] if tight else 9
                count = 0
                for digit in range(max_digit + 1):
                    new_tight = tight and digit == max_digit
                    new_is_leading_zero = is_leading_zero and digit == 0
                    new_leading_zero_count = leading_zero_count + (1 if new_is_leading_zero else 0)
                    length = number_of_digits - new_leading_zero_count
                    pos = idx - new_leading_zero_count
                    if length % 2 == 0 and not new_is_leading_zero:
                        if pos < length // 2:
                            new_diff = diff + digit
                        else:
                            new_diff = diff - digit
                        count += dp(idx + 1, new_tight, new_diff, new_is_leading_zero, new_leading_zero_count)
                    else:
                        count += dp(idx + 1, new_tight, diff, new_is_leading_zero, new_leading_zero_count)
                memo[idx][leading_zero_count][diff + mapper][is_leading_zero][tight] = count
                return count

            return dp(0, True)

        return count_upto_num(r) - count_upto_num(l - 1)


assert Solution().countSymmetricIntegers(1,
                                         100) == 9, f"1:100 should 9 but found: {Solution().countSymmetricIntegers(1, 100)}"

assert Solution().countSymmetricIntegers(1200,
                                         1230) == 4, f"1200:1230 should 4 but found: {Solution().countSymmetricIntegers(1200, 1230)}"
