package leetcode.kotlin.dailydecember2023.numberofdicerollswithtargetsum1155

import leetcode.kotlin.println

class Solution1 {
  fun numRollsToTarget(n: Int, k: Int, target: Int): Int {
    val memo = Array(n + 1) { IntArray(target + 1) { -1 } }
    return solve(n, k, target, memo)
  }

  private fun solve(n: Int, k: Int, target: Int, memo: Array<IntArray>): Int {
    if (n == target) {
      return 1
    } else if (n == 0 || target == 0 || n > target) {
      return 0
    }
    if (memo[n][target] != -1) {
      return memo[n][target]
    }
    var sum = 0
    for (i in (1..k)) {
      sum += solve(n - 1, k, target - i, memo)
      sum %= 1_000_000_007
    }
    memo[n][target] = sum
    return memo[n][target]
  }
}

fun main() {
  Solution1().numRollsToTarget(30, 30, 500).println()
}