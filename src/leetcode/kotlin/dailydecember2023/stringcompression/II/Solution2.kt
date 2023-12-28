package leetcode.kotlin.dailydecember2023.stringcompression.II

import leetcode.kotlin.println

class Solution2 {
  data class Key(val index: Int, val lastChar: Char?, val lastCharCount: Int, val k: Int)

  fun getLengthOfOptimalCompression(s: String, k: Int): Int {
    val memo = mutableMapOf<Key, Int>()
    return getLengthOfOptimalCompression(
      s, 0, null, 0, k, memo
    )
  }

  private fun getLengthOfOptimalCompression(
    s: String,
    index: Int,
    lastChar: Char?,
    lastCharCount: Int,
    k: Int,
    memo: MutableMap<Key, Int>
  ): Int {
    if (k < 0) {
      return Int.MAX_VALUE / 2
    }
    if (index == s.length) {
      return 0
    }
    // check if we already have answer
    val key = Key(index, lastChar, lastCharCount, k)
    memo[key]?.let { return it }
    val currChar = s[index]
    // keep the character
    val currCount = if (currChar == lastChar) {
      lastCharCount + 1
    } else {
      1
    }
    val removeLength = getLengthOfOptimalCompression(s, index + 1, lastChar, lastCharCount, k - 1, memo)

    val keepLength = (if (currCount.isPowerOf10() || currCount == 2) 1 else 0) +
        getLengthOfOptimalCompression(s, index + 1, currChar, currCount, k, memo)

    // remove the character
    return minOf(keepLength, removeLength).also {
      memo[key] = it
    }
  }

  private fun Int.isPowerOf10(): Boolean {
    var n = this
    while (n > 1 && n % 10 == 0) {
      n /= 10
    }
    return n == 1
  }
}

fun main() {
  Solution2().getLengthOfOptimalCompression("aaabcccd", 2).println()
  Solution2().getLengthOfOptimalCompression("aabbaa", 2).println()
  Solution2().getLengthOfOptimalCompression("aaaaaaaaaaa", 0).println()
  Solution2().getLengthOfOptimalCompression("a", 1).println()
  Solution2().getLengthOfOptimalCompression("abcdefghijklmnopqrstuvwxyz", 16).println()
}