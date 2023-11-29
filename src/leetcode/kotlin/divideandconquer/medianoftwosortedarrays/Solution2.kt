package leetcode.kotlin.divideandconquer.medianoftwosortedarrays

/**
 * Optimal solution is O(log(m + n))
 */
class Solution2 {
  fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
    if (nums1.size > nums2.size) {
      return findMedianSortedArrays(nums2, nums1)
    }
    val n = nums1.size
    val m = nums2.size
    val halfSize = (n + m + 1) / 2

    // my basic task is to find num of elements
    // to pick from first array which correctly
    // partitions array

    // min num of elements I can pick up from first array
    var low = 0
    // max num of elements I can pick up from first array
    var high = n
    //so I can do binary search here

    while (low <= high) {
      val mid1 = (high - low) / 2 + low
      val mid2 = halfSize - mid1

      val l1 = if (mid1 == 0) Int.MIN_VALUE else nums1[mid1 - 1]
      val r1 = if (mid1 == n) Int.MAX_VALUE else nums1[mid1]
      val l2 = if (mid2 == 0) Int.MIN_VALUE else nums2[mid2 - 1]
      val r2 = if (mid2 == m) Int.MAX_VALUE else nums2[mid2]

      if (l1 <= r2 && l2 <= r1) {
        return if ((n + m) % 2 == 0) {
          (maxOf(l1, l2) + minOf(r1, r2)).toDouble() / 2
        } else {
          maxOf(l1, l2).toDouble()
        }
      } else if (l1 > r2) {
        high = mid1 - 1
      } else {
        low = mid1 + 1
      }

    }
    throw IllegalStateException("cannot be here")
  }
}

fun main() {
  println(Solution2().findMedianSortedArrays(intArrayOf(1, 2, 3, 4, 9, 11), intArrayOf(7, 12, 14)))
  println(Solution2().findMedianSortedArrays(intArrayOf(1, 3), intArrayOf(2)))
}