package codingninjas.linkedlist.maximumdepthofbinarytree

import leetcode.kotlin.println
import leetcode.kotlin.trees.TreeNode

/**
 * bfs iterative
 */
class Solution2 {
  fun maxDepth(root: TreeNode?): Int {
    if (root == null) {
      return 0
    }
    val stack = ArrayDeque<Pair<TreeNode, Int>>()
    stack.addFirst(root to 1)
    var maxDepth = 1
    while (stack.isNotEmpty()) {
      val (node, currDepth) = stack.removeFirst()
      maxDepth = maxDepth.coerceAtLeast(currDepth)
      node.left?.let {
        stack.addFirst(it to currDepth + 1)
      }
      node.right?.let {
        stack.addFirst(it to currDepth + 1)
      }
    }
    return maxDepth
  }
}

fun main() {
  val head = TreeNode(3)
  head.left = TreeNode(9)
  head.right = TreeNode(20).apply {
    left = TreeNode(15)
    right = TreeNode(7)
  }
  Solution2().maxDepth(head).println()
}