package leetcode.kotlin.daily.december2023.findwordsthatcanbeformedbycharacters1160

import leetcode.kotlin.println

class Solution1 {
  fun countCharacters(words: Array<String>, chars: String): Int {
    val countChars = IntArray(26)
    chars.forEach { countChars[it - 'a']++ }
    var count = 0
    outer@ for (word in words) {
      val currentWordCount = IntArray(26)
      for (c in word) {
        val index = c - 'a'
        currentWordCount[index]++
        if (countChars[index] < currentWordCount[index]) {
          continue@outer
        }
      }
      count += word.length
    }
    return count
  }
}

fun main() {
  Solution1().countCharacters(
    arrayOf("hello", "world", "leetcode"), "welldonehoneyr"
  ).println()
}