package leetcode.kotlin.dp.maximumprofitinjobscheduling

import leetcode.kotlin.println

/**
 * BOTTOM UP DP + BINARY SEARCH
 */
class Solution2 {
  fun jobScheduling(startTime: IntArray, endTime: IntArray, profits: IntArray): Int {
    val size = startTime.size
    val dp = IntArray(size + 1)
    val startEndProfit = buildList {
      repeat(size) {
        add(Triple(startTime[it], endTime[it], profits[it]))
      }
    }.sortedBy { it.first }
    for (i in size - 1 downTo 0) {
      val (_, end, profit) = startEndProfit[i]
      val nextJob = findNextJob(i + 1, end, startEndProfit)
      dp[i] = maxOf(dp[i + 1], dp[nextJob] + profit)
    }
    return dp[0]
  }

  private fun findNextJob(startIndex: Int, end: Int, startEndProfit: List<Triple<Int, Int, Int>>): Int {
    var left = startIndex
    var right = startEndProfit.lastIndex
    while (left <= right) {
      val mid = (right - left) / 2 + left
      if (startEndProfit[mid].first >= end) {
        right = mid - 1
      } else {
        left = mid + 1
      }
    }
    return left
  }
}

fun main() {
  Solution2().jobScheduling(intArrayOf(1, 2, 3, 3), intArrayOf(3, 4, 5, 6), intArrayOf(50, 10, 40, 70)).println()
  Solution1().jobScheduling(intArrayOf(1, 2, 3, 4, 6), intArrayOf(3, 5, 10, 6, 9), intArrayOf(20, 20, 100, 70, 60))
    .println()
}