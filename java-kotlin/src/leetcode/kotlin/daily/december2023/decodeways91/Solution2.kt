package leetcode.kotlin.daily.december2023.decodeways91

import leetcode.kotlin.println

class Solution2 {
  fun numDecodings(s: String): Int {
    if (s.isEmpty()) {
      return 0
    }
    val dp = IntArray(s.length + 1)
    dp[0] = 1
    dp[1] = if (s[0] == '0') 0 else 1
    for (i in 2..dp.lastIndex) {
      val c = s[i - 1]
      if (c != '0') {
        dp[i] += dp[i - 1]
      }
      if (s.substring(i - 2, i).toInt() in 10..26) {
        dp[i] += dp[i - 2]
      }
    }
    return dp.last()
  }
}

fun main() {
  Solution2().numDecodings("06").println()
}