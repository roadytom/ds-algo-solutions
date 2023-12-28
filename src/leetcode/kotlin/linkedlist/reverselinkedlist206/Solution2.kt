package leetcode.kotlin.linkedlist.reverselinkedlist206

class Solution2 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  fun reverseList(curr: ListNode?, prev: ListNode? = null): ListNode? {
    if (curr == null) {
      return prev
    }
    val next = curr.next
    curr.next = prev
    return reverseList(next, curr)
  }
}