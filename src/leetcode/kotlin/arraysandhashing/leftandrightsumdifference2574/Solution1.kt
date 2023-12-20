package leetcode.kotlin.arraysandhashing.leftandrightsumdifference2574

import kotlin.math.abs

class Solution1 {
  fun leftRightDifference(nums: IntArray): IntArray {
    var leftSum = 0
    var rightSum = nums.sum()
    return IntArray(nums.size) { i ->
      val v = nums[i]
      rightSum -= v
      leftSum += v
      abs(rightSum - leftSum + v)
    }
  }
}