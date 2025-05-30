package leetcode.kotlin.dp.validparenthesisstring678

import leetcode.kotlin.println

class Solution4 {
  fun checkValidString(s: String): Boolean {
    val len = s.length
    val dp = Array(len) { BooleanArray(len) }
    for (size in 0 until len) {
      for (start in 0 until len - size) {
        val end = start + size
        if (s[start] == '*' && dp.valid(start + 1, end)) {
          dp[start][end] = true
        } else {
          if (s[start] == '*' || s[start] == '(') {
            for (k in start + 1..end) {
              if ((s[k] == '*' || s[k] == ')') && dp.valid(start + 1, k - 1) && dp.valid(k + 1, end)) {
                dp[start][end] = true
              }
            }
          }
        }
      }
    }
    return dp[0][len - 1]
  }

  private fun Array<BooleanArray>.valid(start: Int, end: Int): Boolean {
    return start > end || this[start][end]
  }
}

fun main() {
  Solution4().checkValidString("((((*)))))*)").println()
}