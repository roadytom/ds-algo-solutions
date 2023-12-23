package leetcode.kotlin.stack.reverstring

class Solution1 {
  fun reverseString(s: CharArray): Unit {
    val stack = ArrayDeque<Char>()
    s.forEach { c -> stack.addFirst(c) }
    for (i in 0 until s.size) {
      s[i] = stack.removeFirst()
    }
  }
}