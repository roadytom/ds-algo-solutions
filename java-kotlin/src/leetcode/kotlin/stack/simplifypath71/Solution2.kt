package leetcode.kotlin.stack.simplifypath71

import leetcode.kotlin.println

class Solution2 {
  fun simplifyPath(path: String): String {
    val stack = ArrayDeque<String>()
    val arr = path.split("/")
    for (element in arr) {
      if (element == "") {
        stack.removeFirstOrNull()
      } else if (element != "" && element != ".") {
        stack.addFirst(element)
      }
    }
    return stack.reversed().joinToString(separator = "/", prefix = "/")
  }
}

fun main() {
  Solution2().simplifyPath("/home//foo/").println()
}