package leetcode.kotlin.daily.january2024.amountoftimeforbinarytreetobeinfected

import leetcode.kotlin.println
import leetcode.kotlin.trees.TreeNode
import java.util.ArrayDeque

class Solution1 {
  fun amountOfTime(root: TreeNode?, start: Int): Int {
    if (root == null) {
      return 0
    }
    val adjList = mutableMapOf<Int, List<Int>>()
    convert(root, adjList)
    val queue = ArrayDeque<Int>()
    queue.offer(start)
    var depth = 0
    val visited = mutableSetOf<Int>()
    while (queue.isNotEmpty()) {
      val size = queue.size
      repeat(size) {
        val curr = queue.poll()
        visited += curr
        for (n in adjList[curr]!!) {
          if (n !in visited) {
            queue.offer(n)
          }
        }
      }
      depth++
    }
    return depth - 1
  }

  private fun convert(curr: TreeNode?, adjList: MutableMap<Int, List<Int>>, parent: TreeNode? = null) {
    val curr = curr ?: return
    val list = listOfNotNull(parent?.`val`, curr.left?.`val`, curr.right?.`val`)
    adjList[curr.`val`] = list
    curr.left?.let { convert(it, adjList, curr) }
    curr.right?.let { convert(it, adjList, curr) }
  }
}

fun main() {
  val tree = TreeNode(1).apply {
    left = TreeNode(5).apply {
      right = TreeNode(4).apply {
        left = TreeNode(9)
        right = TreeNode(2)
      }
    }
    right = TreeNode(3).apply {
      left = TreeNode(10)
      right = TreeNode(6)
    }
  }
  tree.println()
  val tree2 = TreeNode(1).apply {
    left = TreeNode(2).apply {
      left = TreeNode(3).apply {
        left = TreeNode(4).apply {
          left = TreeNode(5)
        }
      }
    }
  }
  tree2.println()
//  Solution1().amountOfTime(tree, 3).println()
  Solution1().amountOfTime(tree2, 2).println()
}