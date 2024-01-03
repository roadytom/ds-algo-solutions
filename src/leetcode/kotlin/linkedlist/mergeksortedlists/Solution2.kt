package leetcode.kotlin.linkedlist.mergeksortedlists

import leetcode.kotlin.println

class Solution2 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  fun mergeKLists(lists: Array<ListNode?>): ListNode? {
    return mergeKLists(0, lists.lastIndex, lists)
  }

  private fun mergeKLists(start: Int, end: Int, lists: Array<ListNode?>): ListNode? {
    if (start > end) {
      return null
    }
    if (start == end) {
      return lists[start]
    }
    val mid = (end - start) / 2 + start
    var first = mergeKLists(start, mid, lists)
    var second = mergeKLists(mid + 1, end, lists)
    val dummyHead = ListNode(-1)
    var iterator = dummyHead
    while (first != null && second != null) {
      if (first.`val` < second.`val`) {
        iterator.next = first
        first = first.next
      } else {
        iterator.next = second
        second = second.next
      }
      iterator = iterator.next!!
    }
    if (first != null) {
      iterator.next = first
    }
    if (second != null) {
      iterator.next = second
    }
    return dummyHead.next
  }
}

fun main() {
  Solution2().mergeKLists(arrayOf(null, null, null)).println()
}