package leetcode.kotlin.stack.makethestringgreat1544

import java.util.PriorityQueue

class Solution1 {
  fun makeGood(s: String): String {
    val stack = ArrayDeque<Char>()
    val queue = PriorityQueue<Int>()
    for (c in s) {
      if (stack.firstOrNull()?.equalOtherCase(c) == true) {
        stack.removeFirst()
      } else {
        stack.addFirst(c)
      }
    }
    return stack.reversed().joinToString("")
  }

  private fun Char.equalOtherCase(c: Char): Boolean {
    return this.uppercaseChar() == c.uppercaseChar() && this != c
  }
}