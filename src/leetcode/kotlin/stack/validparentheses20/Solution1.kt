package leetcode.kotlin.stack.validparentheses20

class Solution1 {
  fun isValid(s: String): Boolean {
    val pair = mutableMapOf(
      ')' to '(', '}' to '{', ']' to '['
    )
    val stack = ArrayDeque<Char>()
    for (c in s) {
      if (pair[c] != null) {
        if (stack.firstOrNull() != pair[c]) {
          return false
        }
        stack.removeFirst()
      } else {
        stack.addFirst(c)
      }
    }
    return stack.isEmpty()
  }
}