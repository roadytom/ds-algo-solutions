package leetcode.kotlin.linkedlist.removeduplicatesfromlinkedlist.fromsortedlistII

class Solution1 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  fun deleteDuplicates(head: ListNode?): ListNode? {
    val dummy = ListNode(-1)
    dummy.next = head
    var prev = dummy
    var curr = head
    while (curr != null) {
      var next = curr.next
      if (curr.`val` == next?.`val`) {
        while (next != null && curr.`val` == next.`val`) {
          next = next.next
        }
        prev.next = next
        curr = next
      } else {
        prev = curr
        curr = curr.next
      }
    }
    return dummy.next
  }
}