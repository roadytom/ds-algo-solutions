package leetcode.kotlin.stack.designcircularqueue

import java.util.concurrent.locks.ReentrantLock


class MyCircularQueue2(k: Int) {
  val size = k
  var count = 0
  var head: Node? = null
  var tail: Node? = null

  // FOLLOW UP: MAY ASK EVERYTHING THREAD SAFE
  // SO I HAVE TO USE LOCK FOR ENQUEUE AND DEQUE
  private val lock: ReentrantLock = ReentrantLock()

  fun enQueue(value: Int): Boolean {
    if (count == size) {
      return false
    }
    val node = Node(value)
    if (count == 0) {
      head = node
      tail = node
    } else {
      // if count not zero then definitely we have tail and head
      tail!!.next = node
      tail = tail!!.next
    }
    count++
    return true
  }

  fun deQueue(): Boolean {
    if (count == 0) {
      return false
    }
    count--
    head = head!!.next
    return true
  }

  fun Front(): Int = if (count == 0) -1 else head!!.value

  fun Rear(): Int = if (count == 0) -1 else tail!!.value

  fun isEmpty(): Boolean = count == 0

  fun isFull(): Boolean = count == size
  data class Node(val value: Int, var next: Node? = null)
}