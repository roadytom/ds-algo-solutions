package leetcode.kotlin.dailydecember2023.maximumproductoftwoelementsinanarray1464

class Solution1 {
  fun maxProduct(nums: IntArray): Int {
    var max = 0
    var secondMax = 0
    for (num in nums) {
      if (num > max) {
        secondMax = max
        max = num
      } else if (num > secondMax) {
        secondMax = num
      }
    }
    return (max - 1) * (secondMax - 1)
  }
}

fun main() {
  check(Solution1().maxProduct(intArrayOf(3, 4, 5, 2)) == 12)
  check(Solution1().maxProduct(intArrayOf(1, 5, 4, 5)) == 16)
  check(Solution1().maxProduct(intArrayOf(3, 7)) == 12)


}