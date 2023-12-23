package leetcode.kotlin.stack.simplifypath71

import leetcode.kotlin.println

class Solution1 {
  fun simplifyPath(path: String): String {
    val stack = ArrayDeque<String>()
    var idx = 0
    while (idx < path.length) {
      while (idx < path.length && path[idx] == '/') {
        idx++
      }
      val builder = StringBuilder()
      while (idx < path.length && path[idx] != '/') {
        builder.append(path[idx])
        idx++
      }
      val curr = builder.toString()
      if (curr != "" && curr != ".") {
        if (curr == "..") {
          stack.removeFirstOrNull()
        } else {
          stack.addFirst(curr)
        }
      }
    }
    return stack.reversed().joinToString("/", "/")
  }
}

fun main() {
  Solution1().simplifyPath("/home//foo/").println()
}