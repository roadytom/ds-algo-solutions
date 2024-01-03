package leetcode.kotlin.dp1d.validparenthesisstring678

class Solution3 {
  fun checkValidString(s: String): Boolean {
    var low = 0
    var high = 0
    for (c in s) {
      when (c) {
        '(' -> {
          low++
          high++
        }

        ')' -> {
          low = maxOf(low - 1, 0)
          high--
        }

        '*' -> {
          low = maxOf(low - 1, 0)
          high++
        }
      }
      // If high becomes negative, it means there are too many ')' without matching '('.
      if (high < 0) {
        return false
      }
    }
    // The string is valid only if the remaining '(' can be matched by '*'.
    return low == 0
  }
}