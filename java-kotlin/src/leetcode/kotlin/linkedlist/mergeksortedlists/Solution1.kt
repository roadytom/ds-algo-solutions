package leetcode.kotlin.linkedlist.mergeksortedlists

import java.util.*

class Solution1 {
  class ListNode(var `val`: Int) {
    var next: ListNode? = null
  }

  fun mergeKLists(lists: Array<ListNode?>): ListNode? {
    val pq = PriorityQueue<Pair<Int, Int>>(compareBy { it.second })
    val dummy = ListNode(-1)
    var iterator = dummy
    for ((i, v) in lists.withIndex()) {
      if (v != null) {
        pq.offer(i to v.`val`)
        lists[i] = v.next
      }
    }
    while (pq.isNotEmpty()) {
      val (i, v) = pq.poll()
      val next = ListNode(v)
      iterator.next = next
      iterator = next
      val list = lists[i]
      if (list != null) {
        pq.offer(i to list.`val`)
        lists[i] = list.next
      }
    }
    return dummy.next
  }
}