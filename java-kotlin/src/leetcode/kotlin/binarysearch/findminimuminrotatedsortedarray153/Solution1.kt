package leetcode.kotlin.binarysearch.findminimuminrotatedsortedarray153

class Solution1 {
  fun findMin(nums: IntArray): Int {
    var low = 0
    var high = nums.size
    val lastValue = nums.last()
    while (low < high) {
      val mid = (high - low) / 2 + low
      val currentValue = nums[mid]
      if (currentValue > lastValue) {
        low = mid + 1
      } else {
        high = mid
      }
    }
    return nums[low]
  }
}

fun main() {
  
}