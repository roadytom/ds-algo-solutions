package leetcode.kotlin.binarysearch.findpeakelement162

class Solution1 {
  fun IntArray.isBiggerThanPrev(index: Int): Boolean {
    return index == 0 || this[index] > this[index - 1]
  }

  fun IntArray.isBiggerThanNext(index: Int): Boolean {
    return index == lastIndex || this[index] > this[index + 1]
  }

  fun findPeakElement(nums: IntArray): Int {
    var left = 0
    var right = nums.size
    while (left < right) {
      val mid = (right - left) / 2 + left
      if (nums.isBiggerThanPrev(mid) && nums.isBiggerThanNext(mid)) {
        return mid
      }
      if (!nums.isBiggerThanNext(mid)) {
        left = mid + 1
      } else {
        right = mid
      }
    }
    throw IllegalStateException("cannot be here")
  }
}