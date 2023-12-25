package leetcode.kotlin.stack.designstackwithincrementoperation

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 *
 */
class TreeNode(var `val`: Int) {
  var left: TreeNode? = null
  var right: TreeNode? = null
}

class Solution {
  fun constructMaximumBinaryTree(nums: IntArray): TreeNode? {
    return recurrenceRelation(nums, 0, nums.size - 1)
  }

  fun recurrenceRelation(nums: IntArray, left: Int, right: Int): TreeNode? {
    if (left > right) {
      return null
    }
    val pivotIndex = (left..right).maxBy { nums[it] }
    val currNode = TreeNode(nums[pivotIndex])
    currNode.left = recurrenceRelation(nums, left, pivotIndex - 1)
    currNode.right = recurrenceRelation(nums, pivotIndex + 1, right)
    return currNode
  }
}

fun main() {
  val nums = arrayOf(3 to 1, 2 to 2, 1 to 1, 6 to 8, 0 to 0, 5 to 9)
  var a = Int.MAX_VALUE
  a = a.coerceAtMost(nums.sumOf { (a, b) -> a + b })
  Solution().constructMaximumBinaryTree(intArrayOf(3, 2, 1, 6, 0, 5))
}