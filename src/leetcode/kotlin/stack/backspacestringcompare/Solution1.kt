package leetcode.kotlin.stack.backspacestringcompare

class Solution1 {
  fun backspaceCompare(s: String, t: String): Boolean {
    return s.getFinalString() == t.getFinalString()
  }

  fun String.getFinalString(): String {
    val stack = ArrayDeque<Char>()
    for (c in this) {
      if (c == '#') {
        stack.removeFirstOrNull()
      } else {
        stack.addFirst(c)
      }
    }
    return stack.reversed().joinToString("")
  }
}