package leetcode.kotlin.daily.january2024.convert2darraywithcondition2610

class Solution1 {
  fun findMatrix(nums: IntArray): List<List<Int>> {
    val result = mutableListOf<MutableSet<Int>>()
    for (num in nums) {
      var found = false
      for (row in result) {
        if (num !in row) {
          row.add(num)
          found = true
          break
        }
      }
      if (!found) {
        result.add(mutableSetOf(num))
      }
    }
    return result.map { it.toList() }
  }
}

fun main() {
  println(Solution1().findMatrix(intArrayOf(1, 3, 4, 1, 2, 3, 1)))
}