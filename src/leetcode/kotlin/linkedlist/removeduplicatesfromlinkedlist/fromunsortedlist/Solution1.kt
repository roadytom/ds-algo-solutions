package leetcode.kotlin.linkedlist.removeduplicatesfromlinkedlist.fromunsortedlist

class Solution1 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  fun deleteDuplicatesUnsorted(head: ListNode?): ListNode? {
    val set = mutableSetOf<Int>()
    val valuesToRemove = mutableSetOf<Int>()
    var iterator = head
    while (iterator != null) {
      if (iterator.`val` in set) {
        valuesToRemove += iterator.`val`
      } else {
        set += iterator.`val`
      }
      iterator = iterator.next
    }

    val dummy = ListNode(-1)
    dummy.next = head
    var prev = dummy
    var curr = dummy.next

    while (curr != null) {
      if (curr.`val` in valuesToRemove) {
        prev.next = curr.next
      } else {
        prev = curr
      }
      curr = curr.next
    }
    return dummy.next
  }
}