package leetcode.kotlin.dailydecember2023.stringcompression.II

import leetcode.kotlin.println

/**
 * SOLUTION with TLE, need to investigation
 * potentially exponential time complexity
 *
 */
class Solution1 {
  fun getLengthOfOptimalCompression(s: String, k: Int): Int {
    val memo: Array<Array<Set<String>?>> = Array(s.length) { Array(k + 1) { null } }
    val resultSet = generatePossibleCompressions(s, 0, k, memo)
//    resultSet.println()
    return resultSet.minOfOrNull { it.length } ?: 0
  }

  private fun generatePossibleCompressions(
    s: String, index: Int, k: Int, memo: Array<Array<Set<String>?>>
  ): Set<String> {
    if (k < 0) {
      return emptySet()
    }
    if (s.lastIndex == index) {
      return if (k > 0) {
        emptySet()
      } else {
        setOf(s[index].toString())
      }
    }
    memo[index][k]?.let { return it }
    val notRemoving = generatePossibleCompressions(s, index + 1, k, memo)
    val removing = generatePossibleCompressions(s, index + 1, k - 1, memo)

    val newSet = removing + merge(s[index], notRemoving)
    return newSet.also {
      memo[index][k] = it
    }

  }

  private fun merge(c: Char, stringSet: Set<String>): Set<String> {
    return if (stringSet.isEmpty()) {
      setOf(c.toString())
    } else {
      stringSet.map { string ->
        if (c == string.firstOrNull()) {
          val count = string.substring(1).takeWhile { it in '0'..'9' }
          "$c${((count.toIntOrNull() ?: 1) + 1)}${string.substring(count.length + 1)}"
        } else {
          "$c$string"
        }
      }.toSet()
    }
  }
}

fun main() {
  Solution1().getLengthOfOptimalCompression("aaabcccd", 2).println()
  Solution1().getLengthOfOptimalCompression("aabbaa", 2).println()
  Solution1().getLengthOfOptimalCompression("aaaaaaaaaaa", 0).println()
  Solution1().getLengthOfOptimalCompression("a", 1).println()
  Solution1().getLengthOfOptimalCompression("abcdefghijklmnopqrstuvwxyz", 16).println()
}