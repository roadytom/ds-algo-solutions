package leetcode.kotlin.binarysearch.successfulpairsofspellsandpotions2300

/**
 * SORTING AND BINARY SEARCH
 */
class Solution1 {
  fun successfulPairs(spells: IntArray, potions: IntArray, success: Long): IntArray {
    val potionsSorted = potions.sorted().toIntArray()
    return spells.map { countSuccessFulPairs(potionsSorted, success, it) }.toIntArray()
  }

  fun countSuccessFulPairs(potions: IntArray, success: Long, spell: Int): Int {
    var left = 0
    var right = potions.size
    while (left < right) {
      val mid = (right - left) / 2 + left
      if (1L * potions[mid] * spell >= success) {
        right = mid
      } else {
        left = mid + 1
      }
    }
    return potions.size - left
  }
}