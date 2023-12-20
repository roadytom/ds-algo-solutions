package leetcode.kotlin.arraysandhashing.containsduplicate.I

class Solution1 {
  fun containsDuplicate(nums: IntArray): Boolean {
    val set = HashSet<Int>()
    nums.forEach { num ->
      if (num in set) {
        return true
      }
      set.add(num)
    }
    return false
  }
}