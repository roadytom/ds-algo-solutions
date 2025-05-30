class Solution:
    def minArea(self, image, r: int, c: int) -> int:
        row_length, col_length = len(image), len(image[0])
        left = 0
        right = row_length - 1
        while left <= right:
            mid = (left + right) // 2
            is_black = any(
                [image[mid][col] == '1' for col in range(col_length)])
            print(is_black)
            if is_black:
                right = mid - 1
                print(left, right)
            else:
                left = mid + 1
        min_r = left
        print(min_r)
        left = 0
        right = row_length - 1
        while left <= right:
            mid = (left + right) // 2
            is_black = any(
                [image[mid][col] == '1' for col in range(col_length)])
            if is_black:
                left = mid + 1
            else:
                rigth = mid - 1
        max_r = right
        print(max_r)
        left = 0
        right = col_length - 1
        while left <= right:
            mid = (left + right) // 2
            is_black = any(
                [image[row][mid] == '1' for row in range(row_length)])
            if is_black:
                right = mid - 1
            else:
                left = mid + 1
        min_c = left
        print(min_c)

        left = 0
        right = col_length - 1
        while left <= right:
            mid = (left + right) // 2
            is_black = any(
                [image[row][mid] == '1' for row in range(row_length)])
            print(is_black)
            if is_black:
                left = mid + 1
            else:
                right = mid - 1

        max_c = right
        print(min_r, min_c, max_r, max_c)
        return (max_r - min_r + 1) * (max_c - min_c + 1)


print(Solution().minArea([["0", "0", "1", "0"], [
      "0", "1", "1", "0"], ["0", "1", "0", "0"]], 0, 2))
