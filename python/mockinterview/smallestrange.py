class Solution:
    def smallestRange(self, nums):
        # 1. generate ranges with length 1, 2, 3...
        # 2. for each range check if it is correct range
        # Time Complexity:
        # n^2*k*LEN, n is max_num-min_num
        # binary search on answer can make it <= n * log(n) * k * LEN, n is max_num-min_num
        def check_range(start, end, arr):
            low, high = 0, len(arr) - 1
            while low <= high:
                mid = (low + high) // 2
                if start <= arr[mid] <= end:
                    return True
                elif arr[mid] > start:
                    high = mid - 1
                else:
                    low = mid + 1
            return False

        def get_possible_range_or_none(min_num, max_num, length, nums):
            for start in range(min_num, max_num - length + 1):
                end = start + length - 1
                if all(map(lambda x: check_range(start, end, x), nums)):
                    return (start, end)
            return None

        min_num, max_num = float("inf"), float("-inf")
        for integers in nums:
            min_num = min(min_num, min(integers))
            max_num = max(max_num, max(integers))
        print(min_num, max_num)

        right = max_num - min_num
        left = 0
        answer = None
        while left <= right:
            print(left, right)
            mid = (left + right) // 2
            possible_range = get_possible_range_or_none(min_num, max_num, mid, nums)
            if possible_range is not None:
                answer = possible_range
                right = mid - 1
            else:
                left = mid + 1
        return answer


sol = Solution()
print(sol.smallestRange([[4, 10, 15, 24, 26], [0, 9, 12, 20], [5, 18, 22, 30]]))
