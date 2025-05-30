package leetcode.kotlin.linkedlist.palindromelinkedlist


class Solution1 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  fun isPalindrome(head: ListNode?): Boolean {
    if (head?.next == null) {
      return true
    }
    val middle = findMiddle(head)
    val reverseHead = reverse(middle)
    var first = head
    var second: ListNode? = reverseHead
    while (first != null && second != null) {
      if (first.`val` != second.`val`) {
        return false
      }
      first = first.next
      second = second.next
    }
    return true
  }

  private fun reverse(middle: ListNode): ListNode {
    var prev: ListNode? = null
    var curr = middle.next
    while (curr != null) {
      val next = curr.next
      curr.next = prev
      prev = curr
      curr = next
    }
    return prev!!
  }

  private fun findMiddle(head: ListNode): ListNode {
    var slow = head
    var fast = head
    while (fast.next?.next != null) {
      slow = slow.next!!
      fast = fast.next!!.next!!
    }
    return slow
  }
}