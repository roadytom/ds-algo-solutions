package leetcode.kotlin.binarysearch.reversepairs493

import leetcode.kotlin.println

/**
 * RESOLVED SOLUTION
 */
class Solution1_1 {
  fun reversePairs(nums: IntArray): Int {
    val answer = mergeSort(0, nums.lastIndex, nums)
//    nums.contentToString().println()
    return answer
  }

  fun mergeSort(left: Int, right: Int, nums: IntArray): Int {
    // base case: if there is one element, no pair so, return 0
    if (left == right) {
      return 0
    }
    val mid = (right - left) / 2 + left

    val leftReversePairsCount = mergeSort(left, mid, nums)
    val rightReversePairsCount = mergeSort(mid + 1, right, nums)
    val currentReversePairsCount = countCurrentReversePairs(left, right, nums)

    merge(left, right, nums)
    return leftReversePairsCount + rightReversePairsCount + currentReversePairsCount
  }

  private fun merge(left: Int, right: Int, nums: IntArray) {
    val mid = (right - left) / 2 + left
    var leftIterator = left
    var rightIterator = mid + 1

    val tempArray = IntArray(right - left + 1)
    var tempArrayIndex = 0

    while (leftIterator <= mid && rightIterator <= right) {
      if (nums[leftIterator] < nums[rightIterator]) {
        tempArray[tempArrayIndex++] = nums[leftIterator++]
      } else {
        tempArray[tempArrayIndex++] = nums[rightIterator++]
      }
    }
    while (leftIterator <= mid) {
      tempArray[tempArrayIndex++] = nums[leftIterator++]
    }
    while (rightIterator <= right) {
      tempArray[tempArrayIndex++] = nums[rightIterator++]
    }
    for ((index, value) in tempArray.withIndex()) {
      nums[left + index] = value
    }
  }

  private fun countCurrentReversePairs(left: Int, right: Int, nums: IntArray): Int {
    val mid = (right - left) / 2 + left
    var leftIterator = left
    var rightIterator = mid + 1
    var count = 0
    while (leftIterator <= mid) {
      var possibles = 0
      while (rightIterator <= right && nums[leftIterator] > 2L * nums[rightIterator]) {
        rightIterator++
        possibles++
      }
      count += (mid - leftIterator + 1) * possibles
      /**
       * we can also do:
       * count += (right - 1) - (mid - 1) + 1
       * it means all element from mid - 1 index to right - 1
       * is pair for this left iterator
       *
       * nums[leftIterator] > 2 * nums[mid + 1, rightIterator - 1]
       * it means all elements from leftIterator to mid, all has pairs with them
       *
       *
       * quick test:
       *  0   1  m=2
       * [3|, 4, 5]
       *
       *  3  4
       * [1, 2|]
       */
      leftIterator++
    }
    return count
  }
}

fun main() {
  Solution1_1().reversePairs(intArrayOf(1, 3, 2, 3, 1)).println()
  Solution1_1().reversePairs(intArrayOf(2, 4, 3, 5, 1)).println()

  Solution1_1().reversePairs(intArrayOf(5, 4, 3, 2, 1)).println()
}