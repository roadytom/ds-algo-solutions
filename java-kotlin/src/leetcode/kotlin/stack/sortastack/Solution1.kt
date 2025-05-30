package leetcode.kotlin.stack.sortastack

import leetcode.kotlin.println
import java.util.Stack

class Solution1 {
  fun sortStack(stack: ArrayDeque<Int>): ArrayDeque<Int> {
    val sortedStack = ArrayDeque<Int>()
    val tempStack = ArrayDeque<Int>()

    while (stack.isNotEmpty()) {
      val curr = stack.removeFirst()
      while (sortedStack.isNotEmpty() && sortedStack.first() > curr) {
        tempStack.addFirst(sortedStack.removeFirst())
      }
      while (tempStack.isNotEmpty() && tempStack.first() < curr) {
        sortedStack.addFirst(tempStack.removeFirst())
      }
      sortedStack.addFirst(curr)
    }
    while (tempStack.isNotEmpty()) {
      sortedStack.addFirst(tempStack.removeFirst())
    }
    return sortedStack
  }
}

fun main() {
  Solution1().sortStack(ArrayDeque(listOf(34, 3, 31, 98, 92, 23))).println()
}