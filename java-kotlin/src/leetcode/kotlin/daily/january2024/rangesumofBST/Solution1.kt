package leetcode.kotlin.daily.january2024.rangesumofBST

import leetcode.kotlin.trees.TreeNode

class Solution1 {
  fun rangeSumBST(root: TreeNode?, low: Int, high: Int): Int {
    val root = root ?: return 0
    return if (root.`val` in low..high) {
      root.`val` + rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high)
    } else if (root.`val` < low) {
      rangeSumBST(root.right, low, high)
    } else {
      rangeSumBST(root.left, low, high)
    }
  }
}