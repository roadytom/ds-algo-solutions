package leetcode.kotlin.arraysandhashing.containsduplicate.II

class Solution1 {
  fun containsNearbyDuplicate(nums: IntArray, k: Int): Boolean {
    val map = HashMap<Int, Int>()
    nums.forEachIndexed { idx, num ->
      map[num]?.let { pIdx ->
        if (idx - pIdx <= k) {
          return true
        }
      }
      map[num] = idx
    }
    return false
  }
}