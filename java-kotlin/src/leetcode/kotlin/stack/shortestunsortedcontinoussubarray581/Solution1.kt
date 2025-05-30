package leetcode.kotlin.stack.shortestunsortedcontinoussubarray581

import leetcode.kotlin.println

/**
 * MONOTONIC STACK SOLUTION:
 * TIME COMPLEXITY: O(n)
 * SPACE COMPLEXITY: O(n)
 *
 */
class Solution1 {
  fun findUnsortedSubarray(nums: IntArray): Int {
    val stack = ArrayDeque<Pair<Int, Int>>()
    var start = nums.size
    for (index in 0..nums.lastIndex) {
      val element = nums[index]
      while (stack.isNotEmpty() && stack.first().second > element) {
        val (poppedIndex, _) = stack.removeFirst()
        start = start.coerceAtMost(poppedIndex)
      }
      stack.addFirst(index to element)
      if (start == 0) {
        break
      }
    }
    var end = -1
    for (index in nums.lastIndex downTo 0) {
      val element = nums[index]
      while (stack.isNotEmpty() && stack.first().second < element) {
        val (poppedIndex, _) = stack.removeFirst()
        end = end.coerceAtLeast(poppedIndex)
      }
      stack.addFirst(index to element)

      if (end == nums.lastIndex) {
        break
      }
    }
    return if (end < start) 0 else end - start + 1
  }
}

fun main() {
  Solution1().findUnsortedSubarray(intArrayOf(2, 6, 4, 8, 10, 9, 15)).println()
}