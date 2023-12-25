package leetcode.kotlin.stack.shortestunsortedcontinoussubarray581

import leetcode.kotlin.println

/**
 * SOLUTION WITHOUT EXTRA SPACE:
 * TIME COMPLEXITY: O(n)
 * SPACE COMPLEXITY: O(1)
 */
class Solution2 {
  fun findUnsortedSubarray(nums: IntArray): Int {
    val startOfNotSorted = nums.findNotSortedPoint() ?: return 0
    val minElement = nums.minFromStart(startOfNotSorted)

    val endOfNotSorted = nums.findNotSortedPoint(false) ?: return 0
    val maxElement = nums.maxFromStart(endOfNotSorted)

    var left = 0
    while (left < nums.size && nums[left] <= minElement) {
      left++
    }
    var right = nums.lastIndex
    while (right >= 0 && nums[right] >= maxElement) {
      right--
    }
    return right - left + 1
  }


  fun IntArray.minFromStart(start: Int): Int {
    var min = this[start]
    for (i in start + 1..this.lastIndex) {
      min = min.coerceAtMost(this[i])
    }
    return min
  }

  fun IntArray.maxFromStart(start: Int): Int {
    var max = this[start]
    for (i in start - 1 downTo 0) {
      max = max.coerceAtLeast(this[i])
    }
    return max
  }

  fun IntArray.findNotSortedPoint(fromStart: Boolean = true): Int? {
    if (fromStart) {
      var prev = Int.MIN_VALUE
      for (index in 0..this.lastIndex) {
        val curr = this[index]
        if (curr < prev) {
          return index
        }
        prev = curr
      }
    } else {
      var prev = Int.MAX_VALUE
      for (index in this.lastIndex downTo 0) {
        val curr = this[index]
        if (curr > prev) {
          return index
        }
        prev = curr
      }
    }
    return null
  }
}

fun main() {
  Solution2().findUnsortedSubarray(intArrayOf(2, 6, 4, 8, 10, 9, 15)).println()
  Solution2().findUnsortedSubarray(intArrayOf(2, 1)).println()
  Solution2().findUnsortedSubarray(intArrayOf(1, 3, 2, 3, 3)).println()
}