package leetcode.kotlin.linkedlist.removeduplicatesfromlinkedlist.fromsortedlist

class Solution1 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  fun deleteDuplicates(head: ListNode?): ListNode? {
    if (head == null) {
      return null
    }
    var prev: ListNode? = null
    var curr = head
    while (curr != null) {
      while (curr != null && prev?.`val` == curr.`val`) {
        curr = curr.next
      }
      prev?.next = curr
      prev = curr
      curr = curr?.next
    }
    return head
  }
}