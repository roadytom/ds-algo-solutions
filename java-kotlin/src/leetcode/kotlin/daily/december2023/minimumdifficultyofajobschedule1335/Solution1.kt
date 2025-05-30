package leetcode.kotlin.daily.december2023.minimumdifficultyofajobschedule1335

import leetcode.kotlin.println

/**
 * BOTTOM UP DYNAMIC PROGRAMMING
 * USING RECURSION
 * TIME COMPLEXITY: O(n^2 * d)
 */
class Solution1 {
  fun minDifficulty(jobDifficulty: IntArray, d: Int): Int {
    val memo: Array<IntArray> = Array(d + 1) { IntArray(jobDifficulty.size) { -1 } }
    if (jobDifficulty.size < d) {
      return -1
    }
    return findMinDifficulty(jobDifficulty, d, 0, memo)
  }

  private fun findMinDifficulty(jobDifficulty: IntArray, d: Int, index: Int, memo: Array<IntArray>): Int {
    if (memo[d][index] != -1) {
      return memo[d][index]
    }
    if (d == 1) {
      return jobDifficulty.slice(index..jobDifficulty.lastIndex).max()
    }
    var result = Int.MAX_VALUE
    var dailyMaxJob = Int.MIN_VALUE
    for (i in index until (jobDifficulty.size - d + 1)) {
      dailyMaxJob = dailyMaxJob.coerceAtLeast(jobDifficulty[i])
      result = result.coerceAtMost(dailyMaxJob + findMinDifficulty(jobDifficulty, d - 1, i + 1, memo))
    }
    return result.also { memo[d][index] = it }
  }
}

fun main() {
  Solution1().minDifficulty(intArrayOf(6, 5, 4, 3, 2, 1), 2).println()
}