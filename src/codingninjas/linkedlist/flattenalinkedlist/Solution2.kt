package codingninjas.linkedlist.flattenalinkedlist

import leetcode.kotlin.trees.TreeNode

/**
 * bfs
 */
class Solution2 {
  fun invertTree(root: TreeNode?): TreeNode? {
    val root = root ?: return null
    val queue = ArrayDeque<TreeNode>()
    queue.addFirst(root)
    while (queue.isNotEmpty()) {
      val curr = queue.removeFirst()
      val temp = curr.left
      curr.left = curr.right
      curr.right = temp
      curr.left?.let { queue.addFirst(it) }
      curr.right?.let { queue.addFirst(it) }
    }
    return root
  }
}