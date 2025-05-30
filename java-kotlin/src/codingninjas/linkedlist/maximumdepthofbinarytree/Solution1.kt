package codingninjas.linkedlist.maximumdepthofbinarytree

import leetcode.kotlin.trees.TreeNode

/**
 * bfs recursion
 */
class Solution1 {
  fun maxDepth(root: TreeNode?): Int {
    if (root == null) {
      return 0
    }
    return maxOf(maxDepth(root.left), maxDepth(root.right)) + 1
  }
}