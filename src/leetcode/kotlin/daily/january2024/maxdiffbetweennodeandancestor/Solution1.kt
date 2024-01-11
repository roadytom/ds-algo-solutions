package leetcode.kotlin.daily.january2024.maxdiffbetweennodeandancestor

import leetcode.kotlin.println
import leetcode.kotlin.trees.TreeNode
import kotlin.math.abs

class Solution1 {
  fun maxAncestorDiff(root: TreeNode?): Int {
    if (root == null || (root.left == null && root.right == null)) {
      return 0
    }
    return findMaxAncestorDiff(root).third
  }

  private fun findMaxAncestorDiff(node: TreeNode): Triple<Int, Int, Int> {
    var ans = Triple(node.`val`, node.`val`, 0)
    listOf(node.left, node.right).forEach {
      if (it != null) {
        val result = findMaxAncestorDiff(it)
        ans = Triple(
          minOf(result.first, ans.first),
          maxOf(result.second, ans.second),
          maxOf(ans.third, abs(node.`val` - result.first), abs(node.`val` - result.second), result.third)
        )
      }
    }
    return ans
  }
}

fun main() {
  Solution1().maxAncestorDiff(TreeNode(1).apply {
    right = TreeNode(2).apply {
      right = TreeNode(0).apply {
        left = TreeNode(3)
      }
    }
  }).println()
}