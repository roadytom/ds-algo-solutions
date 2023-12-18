package leetcode.kotlin.dailydecember2023.maximumproductdifferencebetweentwopairs1913

class Solution1 {
  fun maxProductDifference(nums: IntArray): Int {
    val numsSorted = nums.sorted()
    return numsSorted.run {
      last() * this[lastIndex - 1] - first() * this[1]
    }
  }
}