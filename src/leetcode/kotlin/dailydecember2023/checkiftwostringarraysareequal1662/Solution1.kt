package leetcode.kotlin.dailydecember2023.checkiftwostringarraysareequal1662

import leetcode.kotlin.println

class Solution1 {
  fun arrayStringsAreEqual(word1: Array<String>, word2: Array<String>): Boolean {
    var firstPointer = 0
    var secondPointer = 0
    var firstIndex = 0
    var secondIndex = 0
    while (firstIndex < word1.size && secondIndex < word2.size) {
      if (word1[firstIndex][firstPointer] != word2[secondIndex][secondPointer]) {
        return false
      }
      firstPointer++
      secondPointer++
      if (firstPointer == word1[firstIndex].length) {
        firstPointer = 0
        firstIndex++
      }
      if (secondPointer == word2[secondIndex].length) {
        secondPointer = 0
        secondIndex++
      }
    }
    return (firstIndex == word1.size && secondIndex == word2.size)
  }
}

fun main() {
  Solution1().arrayStringsAreEqual(arrayOf("ab", "cb"), arrayOf("a", "bccc")).println()
}