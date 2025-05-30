package leetcode.kotlin.trees.invertbinarytree

import leetcode.kotlin.trees.TreeNode

/**
 * dfs
 */
class Solution1 {
  fun invertTree(root: TreeNode?): TreeNode? {
    val root = root ?: return null
    val temp = root.left
    root.left = root.right
    root.right = temp
    invertTree(root.left)
    invertTree(root.right)
    return root
  }
}

fun main() {
}