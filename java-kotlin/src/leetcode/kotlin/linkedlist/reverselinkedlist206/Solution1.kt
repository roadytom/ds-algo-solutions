package leetcode.kotlin.linkedlist.reverselinkedlist206

class Solution1 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  fun reverseList(head: ListNode?): ListNode? {
    if (head == null) {
      return null
    }
    var prev: ListNode? = null
    var curr = head
    while (curr != null) {
      val next = curr.next
      curr.next = prev
      prev = curr
      curr = next
    }
    return prev
  }
}