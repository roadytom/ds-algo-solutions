package leetcode.kotlin.dailydecember2023.constructstringfrombinarytree606

class Solution1 {
  class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
  }

  fun tree2str(root: TreeNode?): String {
    if (root == null) {
      return ""
    }
    return dfs(root)
  }

  private fun dfs(node: TreeNode): String {
    val current = node.`val`.toString()
    val left = node.left?.let {
      "(${dfs(it)})"
    }

    val right = node.right?.let {
      "(${dfs(it)})"
    }
    return if (left == null && right == null) {
      current
    } else if (left == null) {
      current + "()" + right
    } else if (right == null) {
      current + left
    } else {
      current + left + right
    }
  }
}