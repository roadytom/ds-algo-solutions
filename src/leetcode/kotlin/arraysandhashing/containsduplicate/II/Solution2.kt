package leetcode.kotlin.arraysandhashing.containsduplicate.II

import java.util.*

class Solution2 {
  fun containsNearbyDuplicate(nums: IntArray, k: Int): Boolean {
    val bst = TreeSet<Int>()
    nums.forEachIndexed { i, num ->
      if (num in bst) {
        return true
      }
      bst += num
      if (i - k >= 0) {
        bst -= nums[i - k]
      }
    }
    return false
  }
}