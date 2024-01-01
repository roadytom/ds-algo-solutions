package leetcode.kotlin.daily.december2023.numberofdicerollswithtargetsum1155

import leetcode.kotlin.println

class Solution2 {
  fun numRollsToTarget(n: Int, k: Int, target: Int): Int {
    val dp = Array(n + 1) { IntArray(target + 1) }
    dp[0][0] = 1
    for (diceIndex in 1..n) {
      for (currSum in 1..target) {
        for (faceValue in 1..k) {
          if (currSum >= faceValue) {
            dp[diceIndex][currSum] = (dp[diceIndex][currSum] + dp[diceIndex - 1][currSum - faceValue]) % 1_000_000_007
          }
        }
      }
    }
//    dp.contentDeepToString().println()
    return dp[n][target]
  }
}

fun main() {
  Solution2().numRollsToTarget(30, 30, 500).println()
}