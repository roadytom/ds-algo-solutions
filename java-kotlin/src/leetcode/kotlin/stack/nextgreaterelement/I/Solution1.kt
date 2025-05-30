package leetcode.kotlin.stack.nextgreaterelement.I

import leetcode.kotlin.println

class Solution1 {
  fun nextGreaterElement(nums1: IntArray, nums2: IntArray): IntArray {
    val solutionMap = mutableMapOf<Int, Int>()
    val stack = ArrayDeque<Int>()
    for (num in nums2.reversed()) {
      while (stack.isNotEmpty() && stack.first() < num) {
        solutionMap[stack.removeFirst()] = num
      }
      stack.addFirst(num)
    }
    return nums1.map { num ->
      solutionMap[num] ?: -1
    }.toIntArray()
  }
}

fun main() {
  Solution1().nextGreaterElement(intArrayOf(), intArrayOf(13, 7, 6, 12)).contentToString().println()
}