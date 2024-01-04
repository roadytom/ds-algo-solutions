package leetcode.kotlin.trees.validatebinarysearchtree

import leetcode.kotlin.trees.TreeNode

class Solution1 {
  fun isValidBST(root: TreeNode?): Boolean {
    if (root == null) {
      return true
    }
    return isValid(root).first
  }

  private fun isValid(node: TreeNode): Triple<Boolean, Int, Int> {
    var currMin = node.`val`
    var currMax = node.`val`
    node.left?.let {
      val (valid, max, min) = isValid(it)
      if (!valid || node.`val` <= max) {
        return Triple(false, currMax, currMin)
      }
      currMin = min
    }
    node.right?.let {
      val (valid, max, min) = isValid(it)
      if (!valid || node.`val` >= min) {
        return Triple(false, currMax, currMin)
      }
      currMax = max
    }
    return Triple(true, currMax, currMin)
  }
}