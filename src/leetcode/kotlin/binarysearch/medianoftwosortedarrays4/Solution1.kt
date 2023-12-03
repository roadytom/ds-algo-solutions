package leetcode.kotlin.binarysearch.medianoftwosortedarrays4

import leetcode.kotlin.println

/**
 * SOLUTION:
 * Binary Search, Recursive
 * APPROACH:
 * we either remove half left part or half right part
 * implemented method which winds any kth element (0 based) after merging
 * TIME COMPLEXITY:
 * O(log(m) + log(n)) we may call all elements
 * BEST CASE:
 * O(min(log(m), log(n)))
 */
class Solution1 {
  fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
    val size1 = nums1.size
    val size2 = nums2.size

    val totalSize = size1 + size2
    val medianIndex = totalSize / 2

//    nums1.contentToString().println()
//    nums2.contentToString().println()
//    val concatArray = (nums1 + nums2)
//    concatArray.sort()
//    concatArray.contentToString().println()

//    TEST all the index:
//    repeat(nums1.size + nums2.size) { index ->
//      findKthElement(nums1, nums2, 0, size1 - 1, 0, size2 - 1, index).also {
//        check(it == concatArray[index]) {
//          "At index $index, ${concatArray[index]} not equal to $it"
//        }
//      }.println()
//    }

//    TEST specific index:
//    val testElement = findKthElement(nums1, nums2, 0, size1 - 1, 0, size2 - 1, 3).println()

//    return if (totalSize % 2 == 0) {
//      val firstElement = findKthElement(nums1, nums2, 0, size1 - 1, 0, size2 - 1, medianIndex - 1).toDouble()
//      val secondElement = findKthElement(nums1, nums2, 0, size1 - 1, 0, size2 - 1, medianIndex).toDouble()
//      (firstElement + secondElement) / 2.0
//    } else {
//      val firstElement = findKthElement(nums1, nums2, 0, size1 - 1, 0, size2 - 1, medianIndex).toDouble()
//      firstElement
//    }

//    DUMMY RETURN TO COMPILE, FOR TEST CASES
    return -1.0
  }

  fun findKthElement(
    nums1: IntArray, nums2: IntArray, start1: Int, end1: Int, start2: Int, end2: Int, k: Int
  ): Int {
    val size1 = end1 - start1 + 1
    val size2 = end2 - start2 + 1
    if (size1 == 0) {
      return nums2[k + start2]
    }
    if (size2 == 0) {
      return nums1[k + start1]
    }
    if (k == 0) {
      return minOf(nums1[start1], nums2[start2])
    }
    val mid1 = (end1 + start1) / 2
    val mid2 = (end2 + start2) / 2

    /**
     * !IMPORTANT WHY THERE k > mid1 - start1 + mid2 - start2
     * because if k is in the left half, we have the possibility
     * of removing right half + either first mid or right mid
     * E.g:
     *      [3, 6, 7, 8] [1, 2, 3, 4]
     *    [3, 6] [7, 8]   [1, 2] [3, 4]
     *    Look if k is on the left side
     *    we either remove [6, 7, 8] by doing start1, mid1 - 1
     *    or remove [2, 3, 4] by doing start2, mid2 - 1
     *    it means if k is in the left half
     *    there must be at least k + 1 elements on the left (so kth index will be on the left)
     *    our check is (k + 1) <= (num. of left elements)
     *    num. of left element is either:
     *    (mid1 - start1 + 1) full left,
     *    +
     *    (mid2 - start2 + 1 - 1) elements from start2 to mid2 - 1
     *
     *    or
     *
     *    (mid1 - start1 + 1 - 1) elements from start1 to mid1 - 1
     *     +
     *    (mid2 - start2 + 1)  full left
     *    because if the k is on the left,
     *    we sure that right full + 1 mid, element removed
     *    so, we got:
     *    (k + 1) <= mid1 - start1 + mid2 - start2 + 1
     *    k <= mid1 - start1 + mid2 - start2
     */

    return if (k > mid1 - start1 + mid2 - start2) {
      // kth index is greater than half of the arrays
      // so, we remove left half of A or left half of B
      // if we remove elements from left half
      // we also have to decrease k to the number of
      // elements on the left
      if (nums1[mid1] > nums2[mid2]) {
        findKthElement(nums1, nums2, start1, end1, mid2 + 1, end2, k - (mid2 - start2 + 1))
      } else {
        findKthElement(nums1, nums2, mid1 + 1, end1, start2, end2, k - (mid1 - start1 + 1))
      }
    } else {
      // kth index is less than half of the arrays
      // so, we remove right half of A or right half of B
      // if we remove elements from right half
      // we don't need change kth index because it
      // is in left half
      if (nums1[mid1] > nums2[mid2]) {
        findKthElement(nums1, nums2, start1, mid1 - 1, start2, end2, k)
      } else {
        findKthElement(nums1, nums2, start1, end1, start2, mid2 - 1, k)
      }
    }
  }
}

fun main() {
  Solution1().findMedianSortedArrays(intArrayOf(1, 2, 2, 3, 4), intArrayOf(4, 5, 6, 7))
  Solution1().findMedianSortedArrays(IntArray(9) { it * 3 }, IntArray(10) { it * 2 })
  Solution1().findMedianSortedArrays(intArrayOf(0, 0, 0, 0, 0), intArrayOf(-1, 0, 0, 0, 0, 0, 1)).println()
  Solution1().findMedianSortedArrays(intArrayOf(1, 3), intArrayOf(2))
  Solution1().findMedianSortedArrays(intArrayOf(3), intArrayOf(-2, -1)).println()
  Solution1().findMedianSortedArrays(intArrayOf(), intArrayOf(1)).println()
}