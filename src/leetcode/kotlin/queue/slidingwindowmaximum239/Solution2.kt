package leetcode.kotlin.queue.slidingwindowmaximum239

import leetcode.kotlin.println

class Solution2 {
  /**
   * [7,2,4]
   * 1) 7
   * 2) 2 7
   * 3) 2 dropped because 4 is new and bigger, 4 7
   * depending on k (windows size) we can remove
   * the highest element from queue if it is equal to
   * element to be removed from windows (first element outside of window)
   */
  fun maxSlidingWindow(nums: IntArray, k: Int): IntArray {
    val queue = ArrayDeque<Int>()
    val result = IntArray(nums.size - k + 1)
    var resultIndex = 0
    for ((index, element) in nums.withIndex()) {
      // remove smaller elements
      while (queue.isNotEmpty() && nums[queue.last()] < element) {
        queue.removeLast()
      }
      queue.addLast(index)
      // remove element outside the window
      if (queue.first() < index - k + 1) {
        queue.removeFirst()
      }
      if (index >= k - 1) {
        result[resultIndex++] = nums[queue.first()]
      }
    }
    return result
  }
}

fun main() {
  Solution2().maxSlidingWindow(intArrayOf(7, 2, 4), 2).contentToString().println()
}