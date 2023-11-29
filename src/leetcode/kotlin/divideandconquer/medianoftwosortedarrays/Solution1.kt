package leetcode.kotlin.divideandconquer.medianoftwosortedarrays

/**
 * easy solution, not optimal works in O(n + m)
 * optimal solution is O(log(m + n))
 */
class Solution1 {
  fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
    val size = nums1.size + nums2.size
    val mergedIndex = size / 2
    var index = 0
    var prevElement = 0
    var currentElement = 0
    var firstIndex = 0
    var secondIndex = 0
    while (index <= mergedIndex && firstIndex < nums1.size && secondIndex < nums2.size) {
      if (nums1[firstIndex] < nums2[secondIndex]) {
        prevElement = currentElement
        currentElement = nums1[firstIndex]
        firstIndex++
      } else {
        prevElement = currentElement
        currentElement = nums2[secondIndex]
        secondIndex++
      }
      index++
    }

    while (index <= mergedIndex && firstIndex < nums1.size) {
      prevElement = currentElement
      currentElement = nums1[firstIndex]
      firstIndex++
      index++
    }

    while (index <= mergedIndex && secondIndex < nums2.size) {
      prevElement = currentElement
      currentElement = nums2[secondIndex]
      secondIndex++
      index++
    }
    return if (size % 2 == 0) {
      (prevElement.toDouble() + currentElement) / 2
    } else {
      currentElement.toDouble()
    }
  }
}

fun main() {
  println(Solution1().findMedianSortedArrays(intArrayOf(1, 2), intArrayOf(3, 4)))
}