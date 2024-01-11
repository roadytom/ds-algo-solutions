package leetcode.kotlin.daily.january2024.amountoftimeforbinarytreetobeinfected

import leetcode.kotlin.trees.TreeNode

class Solution1 {
  fun findDepth(node: TreeNode?): Int {
    if (node == null) {
      return 0
    }
    return 1 + findDepth(node.left)
  }
}