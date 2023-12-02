package leetcode.kotlin.binarysearch.searchinrotatedsortedarray33

class Solution1 {
  fun search(nums: IntArray, target: Int): Int {
    var low = 0
    var high = nums.size
    while (low < high) {
      val mid = (high - low) / 2 + low
      if (nums[mid] == target) {
        return mid
      }
      val toTheRight = nums[mid] < target

      if (nums[mid] < )

    }
  }
}