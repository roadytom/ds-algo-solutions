package leetcode.kotlin.stack.removealladjacentduplicatesinstring.II

class Solution1 {
  fun removeDuplicates(s: String, k: Int): String {
    val stack = ArrayDeque<Pair<Char, Int>>()
    for (c in s) {
      val top = stack.firstOrNull()
      if (top == null || top.first != c) {
        stack.addFirst(c to 1)
      } else {
        if (top.second == k - 1) {
          stack.removeFirst()
        } else {
          stack.removeFirst()
          stack.addFirst(top.first to top.second + 1)
        }
      }
    }
    return stack.reversed().joinToString("") { (c, t) -> c.toString().repeat(t) }
  }
}