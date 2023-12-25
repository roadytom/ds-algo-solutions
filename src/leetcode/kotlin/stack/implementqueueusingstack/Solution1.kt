package leetcode.kotlin.stack.implementqueueusingstack

import leetcode.kotlin.println

/**
 * For this solution I have to achieve
 * amortized O(1) for pop
 * I will store elements in two stacks
 * first one corresponds to the queue
 * second one we use just store when element pushed
 */
class MyQueue() {
  private val stackOrdered = ArrayDeque<Int>()
  private val stackStore = ArrayDeque<Int>()

  // if we have element is ordered stack
  // then we can return peek of it as peek of our queue
  // but if it is empty we either fill it using store stack
  // or we can just use front variable
  private var front: Int? = null

  fun push(x: Int) {
    val str = "asd"
    val a = str.toCharArray()
    if (stackStore.isEmpty()) {
      front = x
    }
    stackStore.addFirst(x)
  }

  fun pop(): Int {
    if (stackOrdered.isEmpty()) {
      while (stackStore.isNotEmpty()) {
        stackOrdered.addFirst(stackStore.removeFirst())
      }
    }
    return stackOrdered.removeFirst()
  }

  fun peek(): Int? {
    if (stackOrdered.isNotEmpty()) {
      return stackOrdered.first()
    }
    return front
  }

  fun empty(): Boolean {
    return stackOrdered.isEmpty() && stackStore.isEmpty()
  }
}

fun main() {
  val q = MyQueue()
  q.push(1)
  q.push(2)
  q.peek().println()
  q.pop().println()
  q.empty().println()
}