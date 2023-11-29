package leetcode.kotlin.twopointers.longestrepeatingcharacterreplacement424

/**
 * O(N) solution
 */
class Solution2 {
  fun characterReplacement(s: String, k: Int): Int {
    var maxCount = 0
    var maxLength = 0
    var start = 0
    val frequency = mutableMapOf<Char, Int>()

    for ((end, c) in s.withIndex()) {
      val updatedFrequency = frequency.getOrDefault(c, 0) + 1
      maxCount = maxOf(maxCount, updatedFrequency)
      frequency[c] = updatedFrequency

      val replacementCount = end - start + 1 - maxCount
      if (replacementCount > k) {
        frequency[s[start]] = frequency[s[start]]!! - 1
        start++
      }
      maxLength = maxOf(end - start + 1, maxLength)
    }

    return maxLength

  }
}

fun main() {
  check(Solution2().characterReplacement("AABABBA", 1) == 4)
  check(Solution2().characterReplacement("ABAB", 2) == 4)
  check(Solution2().characterReplacement("ABBB", 2) == 4)
  check(Solution2().characterReplacement("BAAA", 0) == 3)
}