package leetcode.kotlin.binarysearch.populatingnextrightpointersineachnode116

class Solution1 {
  class Node(var `val`: Int) {
    var left: Node? = null
    var right: Node? = null
    var next: Node? = null
  }

  fun connect(root: Node?): Node? {
    if (root == null) {
      return null
    }
    val queue = ArrayDeque<Node>()
    queue.addLast(root)

    while (queue.isNotEmpty()) {
      val dummy = Node(-1)
      var iterator = dummy
      var size = queue.size

      while (size != 0) {
        val curr = queue.removeFirst()
        curr.left?.let {
          queue.addLast(it)
        }
        curr.right?.let {
          queue.addLast(it)
        }
        iterator.next = curr
        iterator = curr

        size--
      }
    }
    return root
  }
}