package leetcode.kotlin.linkedlist.maximumtwinsumofalinkedlist2130

class Solution1 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  fun pairSum(head: ListNode?): Int {
    if (head == null) {
      return 0
    }
    val middle = findMiddle(head)
    val reverseHead = reverse(middle.next!!)

    var first = head
    var second: ListNode? = reverseHead
    var max = Int.MIN_VALUE
    while (first != null && second != null) {
      max = max.coerceAtLeast(first.`val` + second.`val`)
      first = first.next
      second = second.next
    }
    return max
  }

  private fun reverse(next: ListNode): ListNode {
    var prev: ListNode? = null
    var curr: ListNode? = next
    while (curr != null) {
      val temp = curr.next
      curr.next = prev
      prev = curr
      curr = temp
    }
    return prev!!
  }

  private fun findMiddle(head: ListNode): ListNode {
    var slow = head
    var fast = head
    while (fast.next?.next != null) {
      fast = fast.next!!.next!!
      slow = slow.next!!
    }
    return slow
  }
}