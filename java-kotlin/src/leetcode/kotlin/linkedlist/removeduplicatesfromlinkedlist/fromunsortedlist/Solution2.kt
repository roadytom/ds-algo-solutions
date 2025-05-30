package leetcode.kotlin.linkedlist.removeduplicatesfromlinkedlist.fromunsortedlist

class Solution2 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  fun deleteDuplicatesUnsorted(head: ListNode?): ListNode? {
    val set = mutableSetOf<Int>()
    val dummy = ListNode(-1)
    dummy.next = head
    var prev = dummy
    var curr = dummy.next
    while (curr != null) {
      if (curr.`val` in set) {
        // need to remove
        prev.next = curr.next
      } else {
        // keep it
        set += curr.`val`
        prev = curr
      }
      curr = curr.next
    }
    return dummy.next
  }
}