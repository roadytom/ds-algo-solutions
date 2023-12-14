package leetcode.kotlin.binarysearch.populatingnextrightpointersineachnode116

class Solution2 {
  class Node(var `val`: Int) {
    var left: Node? = null
    var right: Node? = null
    var next: Node? = null
  }

  fun connect(root: Node?): Node? {
    if (root == null) {
      return null
    }
    var leftMost = root
    while (leftMost!!.left != null) {
      var iterator = leftMost
      while (iterator != null) {
        // FIRST CONNECTION
        iterator.left!!.next = iterator.right
        // SECOND CONNECTION
        if (iterator.next != null) {
          iterator.right!!.next = iterator.next!!.left
        }
        iterator = iterator.next
      }
      leftMost = leftMost.left
    }
    return root
  }
}