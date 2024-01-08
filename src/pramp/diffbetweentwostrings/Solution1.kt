package pramp.diffbetweentwostrings

import leetcode.kotlin.print2dWithString
import leetcode.kotlin.println

class Solution1 {
  fun diffBetweenTwoStrings(source: String, target: String): Array<String> {
    val memo = Array(source.length + 1) { IntArray(target.length + 1) { Int.MAX_VALUE } }

    fun dp(i: Int, j: Int): Int {
      if (memo[i][j] != Int.MAX_VALUE) {
        return memo[i][j]
      }
      memo[i][j] = if (i == source.length) {
        target.length - j
      } else if (j == target.length) {
        source.length - i
      } else {
        if (source[i] == target[j]) {
          dp(i + 1, j + 1)
        } else {
          minOf(dp(i + 1, j), dp(i, j + 1)) + 1
        }
      }
      return memo[i][j]
    }
    dp(0, 0)
    memo.print2dWithString(source, target)

    fun construct(): Array<String> {
      val ans = mutableListOf<String>()
      var i = 0
      var j = 0
      //["A","B","-C","D","-E","F","+F","G","+H"]
      while (i < source.length && j < target.length) {
        if (source[i] == target[j]) {
          ans.add(source[i].toString())
          i++
          j++
        } else if (memo[i + 1][j] <= memo[i][j + 1]) {
          ans.add("-" + source[i])
          i++
        } else {
          ans.add("+" + target[j])
          j++
        }
      }
      while (j < target.length) {
        ans.add("+" + target[j])
        j++
      }
      return ans.toTypedArray()
    }
    return construct()
  }
}

fun main() {
  Solution1().diffBetweenTwoStrings("ABCDEFG", "ABDFFGH").contentToString().println()
}
