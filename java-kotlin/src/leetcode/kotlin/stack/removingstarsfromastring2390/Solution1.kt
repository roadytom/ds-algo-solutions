package leetcode.kotlin.stack.removingstarsfromastring2390

class Solution1 {
  fun removeStars(s: String): String {
    val stack = ArrayDeque<Char>()
    for (c in s) {
      if (c == '*') {
        stack.removeLastOrNull()
      } else {
        stack.addLast(c)
      }
    }
    return stack.joinToString("")
  }
}