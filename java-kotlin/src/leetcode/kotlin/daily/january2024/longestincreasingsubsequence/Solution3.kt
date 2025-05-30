package leetcode.kotlin.daily.january2024.longestincreasingsubsequence

/**
 * PATIENCE ALGORITHM IMPLEMENTATION
 * FOR THE SPECIFIC PROBLEM
 * I DON'T HAVE TO CREATE N STACKS
 * BECAUSE I ONLY NEED THE LENGTH OF LIS
 * BUT I NEED EXAMPLE LIS, I HAVE TO TRACK
 * EACH ELEMENT IN N STACKS
 * TIME COMPLEXITY: N*LOG(N)
 */
class Solution3 {
  fun lengthOfLIS(nums: IntArray): Int {
    val topOfTheStack = mutableListOf<Int>()
    for (num in nums) {
      if (topOfTheStack.isEmpty() || num > topOfTheStack.last()) {
        topOfTheStack.add(num)
      } else {
        // we have to add element in the one of the pile
        // last elements in the piles is sorted
        // I can use Binary Search
        val upperIndex = findUpperBound(topOfTheStack, num)
        topOfTheStack[upperIndex] = num
      }
    }
    return topOfTheStack.size
  }

  private fun findUpperBound(topOfTheStack: List<Int>, num: Int): Int {
    var left = 0
    var right = topOfTheStack.lastIndex
    while (left <= right) {
      val mid = (right - left) / 2 + left
      if (topOfTheStack[mid] >= num) {
        right = mid - 1
      } else {
        left = mid + 1
      }
    }
    return left
  }
}