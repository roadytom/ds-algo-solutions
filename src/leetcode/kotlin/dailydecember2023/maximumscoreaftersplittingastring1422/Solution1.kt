package leetcode.kotlin.dailydecember2023.maximumscoreaftersplittingastring1422

class Solution1 {
  fun maxScore(s: String): Int {
    var ones = s.count { it == '1' }
    var zeros = 0
    var max = 0
    for (i in 0..s.lastIndex - 1) {
      if (s[i] == '0') {
        zeros++
      } else {
        ones--
      }
      max = max.coerceAtLeast(zeros + ones)
    }
    return max
  }
}