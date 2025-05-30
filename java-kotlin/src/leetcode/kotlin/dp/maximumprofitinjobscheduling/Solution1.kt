package leetcode.kotlin.dp.maximumprofitinjobscheduling

import leetcode.kotlin.println

/**
 * TOP DOWN DP + Binary Search
 * TIME COMPLEXITY: O(n * log(n))
 */
class Solution1 {
  fun jobScheduling(startTime: IntArray, endTime: IntArray, profit: IntArray): Int {
    val memo = IntArray(startTime.size) { -1 }
    val startToIndex = startTime.mapIndexed { idx, value -> idx to value }.sortedBy { it.second }
    return findJobScheduling(0, startToIndex, endTime, profit, memo)
  }

  private fun findJobScheduling(
    index: Int, startToIndex: List<Pair<Int, Int>>, endTime: IntArray, profits: IntArray, memo: IntArray
  ): Int {
    if (index == startToIndex.size) {
      return 0
    }
    if (memo[index] != -1) {
      return memo[index]
    }
    val skip = findJobScheduling(index + 1, startToIndex, endTime, profits, memo)
    // consider current index
    val (oldIndex, _) = startToIndex[index]
    val end = endTime[oldIndex]
    val profit = profits[oldIndex]
    // find the first index equal or greater than end
    val lowedBound = lowerBound(index + 1, end, startToIndex)
    val consider = findJobScheduling(lowedBound, startToIndex, endTime, profits, memo) + profit
    return maxOf(skip, consider).also {
      memo[index] = it
    }
  }

  private fun lowerBound(startIndex: Int, value: Int, startTime: List<Pair<Int, Int>>): Int {
    var left = startIndex
    var right = startTime.lastIndex
    while (left <= right) {
      val mid = (right - left) / 2 + left
      if (startTime[mid].second >= value) {
        right = mid - 1
      } else {
        left = mid + 1
      }
    }
    return left
  }
}

fun main() {
  Solution1().jobScheduling(intArrayOf(1, 2, 3, 3), intArrayOf(3, 4, 5, 6), intArrayOf(50, 10, 40, 70)).println()
  Solution1().jobScheduling(intArrayOf(1, 2, 3, 4, 6), intArrayOf(3, 5, 10, 6, 9), intArrayOf(20, 20, 100, 70, 60))
    .println()
}