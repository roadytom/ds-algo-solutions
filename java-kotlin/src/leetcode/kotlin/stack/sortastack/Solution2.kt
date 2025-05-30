package leetcode.kotlin.stack.sortastack

import leetcode.kotlin.println

class Solution2 {
  fun sortStack(stack: ArrayDeque<Int>): ArrayDeque<Int> {
    val sortedStack = ArrayDeque<Int>()
    while (stack.isNotEmpty()) {
      val curr = stack.removeFirst()
      while (sortedStack.isNotEmpty() && sortedStack.first() > curr) {
        stack.addFirst(sortedStack.removeFirst())
      }
      sortedStack.addFirst(curr)
    }
    return sortedStack
  }
}

fun main() {
  Solution2().sortStack(ArrayDeque(listOf(34, 3, 31, 98, 92, 23))).println()
}