package leetcode.kotlin.dailydecember2023.decodeways91

class Solution {
  fun numDecodings(s: String): Int {
    val memo = IntArray(s.length) { -1 }
    return numDecodings(s, 0, memo)
  }

  fun numDecodings(s: String, start: Int, memo: IntArray): Int {
    if (start == s.length) {
      return 1
    }
    if (s[start] == '0') {
      return 0
    }
    if (memo[start] != -1) {
      return memo[start]
    }
    var possibleDecodings = numDecodings(s, start + 1, memo)
    if (start < s.lastIndex) {
      if (s.substring(start, start + 2).toInt() <= 26) {
        possibleDecodings += numDecodings(s, start + 2, memo)
      }
    }
    return possibleDecodings.also {
      memo[start] = it
    }
  }
}