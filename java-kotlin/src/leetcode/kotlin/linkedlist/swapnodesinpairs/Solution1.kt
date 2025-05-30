package leetcode.kotlin.linkedlist.swapnodesinpairs

class Solution1 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  /**
  //   1 -> 2 -> 3 -> 4
   */

  fun swapPairs(head: ListNode?): ListNode? {
    if (head != null && head.next == null) {
      return head
    }
    val dummyHead = ListNode(-1)
    dummyHead.next = head
    var iterator = dummyHead
    while (iterator.next?.next != null) {
      val first = iterator.next!!
      val second = iterator.next!!.next!!
      val temp = second.next
      iterator.next = second
      second.next = first
      first.next = temp
      iterator = first
    }
    return dummyHead.next
  }
}