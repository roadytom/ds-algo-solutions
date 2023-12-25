package leetcode.kotlin.queue.slidingwindowmaximum239

import leetcode.kotlin.println
import java.util.*

/**
 * Priority Queue with hashmap solution
 */
class Solution1 {
  fun maxSlidingWindow(nums: IntArray, k: Int): IntArray {
    val pq = PriorityQueue<Int>(compareBy { -nums[it] })
    val result = IntArray(nums.size - k + 1)
    for (i in nums.indices) {
      // remove elements outside the window
      while (pq.isNotEmpty() && pq.peek() < i - k + 1) {
        pq.poll()
      }
      pq.offer(i)

      if (i >= k - 1) {
        result[i - k + 1] = nums[pq.peek()]
      }
    }
    return result
  }
}

fun main() {
  Solution1().maxSlidingWindow(intArrayOf(1, 3, -1, -3, 5, 3, 6, 7), 3).contentToString().println()
}