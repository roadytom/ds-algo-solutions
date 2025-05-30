package leetcode.kotlin.binarysearch.capacitytoshippackageswithinddays1011

import leetcode.kotlin.println

class Solution1 {
  fun shipWithinDays(weights: IntArray, days: Int): Int {
    var low = weights.max()
    var high = weights.sum()
    while (low <= high) {
      val mid = (high - low) / 2 + low
      if (isPossible(weights, days, mid)) {
        high = mid - 1
      } else {
        low = mid + 1
      }
    }
    return low
  }

  fun isPossible(weights: IntArray, days: Int, capacity: Int): Boolean {
    var wIdx = 0
    var currDays = 1
    var currWeight = 0
    while (wIdx < weights.size) {
      if (currWeight + weights[wIdx] <= capacity) {
        currWeight += weights[wIdx]
        wIdx++
      } else {
        currDays++
        if (currDays > days) {
          return false
        }
        currWeight = 0
      }
    }
    println(currDays)
    return true
  }
}

fun main() {
  Solution1().shipWithinDays(intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 5).println();
  Solution1().isPossible(intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 5, 11).println()
}