package leetcode.kotlin.daily.january2024.minimumnumberofoperationstomakearrayempty

import leetcode.kotlin.println

class Solution1 {
  fun minOperations(nums: IntArray): Int {
    val counter = mutableMapOf<Int, Int>()
    for (num in nums) {
      val curr = counter[num] ?: 0
      counter[num] = curr + 1
    }
    var result = 0
    for ((_, value) in counter) {
      if (value == 1) {
        return -1
      }
      result += (value + 2) % 3
    }
    return result
  }
}

fun main() {
  Solution1().minOperations(intArrayOf(2, 3, 3, 2, 2, 4, 2, 3, 4)).println()
}