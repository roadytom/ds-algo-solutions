package leetcode.kotlin.arraysandhashing.containsduplicate.III

import java.util.*

class Solution1 {
  fun containsNearbyAlmostDuplicate(nums: IntArray, indexDiff: Int, valueDiff: Int): Boolean {
    val size = nums.size
    val bst = TreeSet<Int>()
    for ((i, v) in nums.withIndex()) {
      // check the successor, possible for require pair
      bst.ceiling(v)?.let { suc ->
        if (suc - v <= valueDiff) {
          return true
        }
      }
      bst.floor(v)?.let { pre ->
        if (v - pre <= valueDiff) {
          return true
        }
      }
      bst += v
      if (i - indexDiff >= 0) {
        bst -= nums[i - indexDiff]
      }
    }
    return false
  }
}