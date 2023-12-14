package leetcode.kotlin.binarysearch.successfulpairsofspellsandpotions2300

import leetcode.kotlin.println

/**
 * SORTING AND TWO POINTERS
 */
class Solution2 {
  fun successfulPairs(spells: IntArray, potions: IntArray, success: Long): IntArray {
    val potionsSorted = potions.sorted()
    val spellsSorted = spells.mapIndexed { index, value -> index to value }.sortedBy { it.second }
    val successfulPairsList = IntArray(spellsSorted.size) { 0 }
    var spellsSortedIndex = 0
    var potionsSortedIndex = potionsSorted.lastIndex
    while (spellsSortedIndex < spellsSorted.size) {
      val (index, spell) = spellsSorted[spellsSortedIndex]
      while (potionsSortedIndex >= 0 && 1L * spell * potionsSorted[potionsSortedIndex] >= success) {
        potionsSortedIndex--
      }
      successfulPairsList[index] = potionsSorted.lastIndex - potionsSortedIndex
      spellsSortedIndex++
    }
    return successfulPairsList
  }
}

fun main() {
  Solution2().successfulPairs(intArrayOf(5, 1, 3), intArrayOf(1, 2, 3, 4, 5), 7).contentToString().println()
}