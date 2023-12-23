package leetcode.kotlin.stack.removealladjacentduplicatesinstring.I

class Solution1 {
  fun removeDuplicates(s: String): String {
    val stack = ArrayDeque<Char>()
    for (c in s) {
      if (stack.firstOrNull() == c) {
        stack.removeFirst()
      } else {
        stack.addFirst(c)
      }
    }
    return stack.reversed().joinToString(separator = "")
  }
}