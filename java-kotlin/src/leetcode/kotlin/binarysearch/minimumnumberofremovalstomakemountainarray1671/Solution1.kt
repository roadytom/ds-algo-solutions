package leetcode.kotlin.binarysearch.minimumnumberofremovalstomakemountainarray1671

import leetcode.kotlin.println

/**
 * Basic idea to solve this problem
 * find Longest Increasing Subsequence
 * and Longest Decreasing Subsequence
 * for each index. And it shows maximum
 * elements we can keep without removing.
 * Subtracting this value from the size
 * of array gives minimum removals we can
 * achieve. We have to find minimum among
 * all index.
 * TIME COMPLEXITY: O(n * log(n))
 *
 */
class Solution1 {
  fun minimumMountainRemovals(nums: IntArray): Int {
    // array for storing Longest Increasing Subsequence till the index (included)
    val lis = IntArray(nums.size)
    // array for storing Longest Decreasing Subsequence till the index (included)
    val lds = IntArray(nums.size)

    // Patience Sorting Algorithm Stacks implementation for finding LIS/LDS length
    // FULL EXPLANATION FOR OPTIMISING LIS/LDS finding
    // https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
    // We don't need list of stacks because,
    // we only interested in LIS/LDS size
    // not actual elements used to construct it
    val topOfTheStack = mutableListOf<Int>()
    // just iterate array and accomplish LIS algorithm
    for ((idx, num) in nums.withIndex()) {
      if (topOfTheStack.isEmpty() || topOfTheStack.last() < num) {
        topOfTheStack.add(num)
        lis[idx] = topOfTheStack.size
      } else {
        /**
         * 2,3,101 + 18 ->
         */
        val lowerBound = findLowerBound(num, topOfTheStack)
        topOfTheStack[lowerBound] = num
        lis[idx] = lowerBound + 1
      }
    }
    topOfTheStack.clear()
    // the same algorithm as LIS but we iterate reversely
    for (idx in nums.lastIndex downTo 0) {
      val num = nums[idx]
      if (topOfTheStack.isEmpty() || topOfTheStack.last() < num) {
        topOfTheStack.add(num)
        lds[idx] = topOfTheStack.size
      } else {
        val lowerBound = findLowerBound(num, topOfTheStack)
        topOfTheStack[lowerBound] = num
        lds[idx] = lowerBound + 1
      }
    }
//    lis.contentToString().println()
//    lds.contentToString().println()
    var min = Int.MAX_VALUE
    for (i in 1..<nums.lastIndex) {
      // lis/lds[i] = 1 means there is only
      // element itself, and it is not enough
      // to construct mountains
      if (lis[i] > 1 && lds[i] > 1) {
        min = min.coerceAtMost(nums.size - lis[i] - lds[i] + 1)
      }
    }
    return min
  }

  private fun findLowerBound(num: Int, topOfTheStack: List<Int>): Int {
    var left = 0
    var right = topOfTheStack.lastIndex
    while (left <= right) {
      val mid = (right - left) / 2 + left
      if (num <= topOfTheStack[mid]) {
        right = mid - 1
      } else {
        left = mid + 1
      }
    }
    return left
  }
}

fun main() {
  Solution1().minimumMountainRemovals(intArrayOf(2, 1, 1, 5, 6, 2, 3, 1)).println()
  Solution1().minimumMountainRemovals(intArrayOf(1, 3, 1)).println()
  Solution1().minimumMountainRemovals(intArrayOf(100, 92, 89, 77, 74, 66, 64, 66, 64)).println()
}