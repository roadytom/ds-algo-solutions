package leetcode.kotlin.binarysearch.splitarraylargestsum410

import leetcode.kotlin.binarysearch.searchsuggestionssystem1268.println

class Solution2 {
  fun splitArray(nums: IntArray, k: Int): Int {
    val dp = Array(k + 1) { IntArray(nums.size + 1) { -1 } }
    return recurrenceRelation(0, 0, k, 0, nums, dp)
  }

  private fun recurrenceRelation(
    largestSum: Int, sumUptoNow: Int, k: Int, index: Int, nums: IntArray, dp: Array<IntArray>
  ): Int {
    if (k == 1) {
      var currIndex = index
      var currSum = sumUptoNow
      while (currIndex < nums.size) {
        currSum += nums[currIndex]
        currIndex++
      }
      return maxOf(largestSum, currSum)
    } else if (index == nums.size) {
      return Int.MAX_VALUE
    }
    if (dp[k][index] != -1) {
      return dp[k][index]
    }
    // CASE 1: continue current array
    var currSum = sumUptoNow
    currSum += nums[index]
    var currLargestSum = maxOf(largestSum, currSum)
    val continuedLargestSum = recurrenceRelation(currLargestSum, currSum, k, index + 1, nums, dp)
    // CASE 2: split array
    currSum = nums[index]
    currLargestSum = maxOf(largestSum, currSum)
    val splitLargestSum = recurrenceRelation(currLargestSum, currSum, k - 1, index + 1, nums, dp)

    return minOf(continuedLargestSum, splitLargestSum).also {
      dp[k][index] = it
    }
  }
}

fun main() {
//  Solution2().splitArray(intArrayOf(1, 4, 4), 3).println()
  Solution2().splitArray(intArrayOf(1, 2, 3, 4, 5), 2).println()
}