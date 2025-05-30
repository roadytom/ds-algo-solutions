package leetcode.kotlin.binarysearch.kokoeatingbananas875

import leetcode.kotlin.println

class Solution1 {
  /**
   * O(n * log(m - n))
   */
  fun minEatingSpeed(piles: IntArray, h: Int): Int {
    /**
     * min k = 1 => sumOf(piles) hour
     * max maxOf(piles) => piles.size hour
     */
    var low = 1
    var high = piles.max()

    while (low <= high) {
      val mid = (high - low) / 2 + low
      if (isKPossible(mid, h, piles)) {
        high = mid - 1
      } else {
        low = mid + 1
      }
    }

    return low
  }

  private fun isKPossible(k: Int, h: Int, piles: IntArray): Boolean {
    var currHour = 0L
    for (pile in piles) {
      currHour += (pile + k - 1) / k
      if (currHour > h) {
        return false
      }
    }
    return true
  }
}

fun main() {
  Solution1().minEatingSpeed(intArrayOf(30, 11, 23, 4, 20), 5).println()
}