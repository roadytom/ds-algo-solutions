package leetcode.kotlin.queue.generatebinarynumbersfrom1toN

import leetcode.kotlin.println

class Solution1 {
  fun generateBinaryNumbers(n: Int): Array<String> {
    val res = mutableListOf<String>()
    val queue = ArrayDeque<String>()
    queue.addFirst("1")
    var count = 0
    while (count < n) {
      val currNum = queue.removeLast()
      res += currNum

      queue.addFirst(currNum + '0')
      queue.addFirst(currNum + '1')
      count++
    }

    return res.toTypedArray()
  }

  fun queryString(s: String, n: Int): Boolean {
    val queue = ArrayDeque<String>()
    queue.addFirst("1")
    var count = 0
    while (count < n) {
      val currNum = queue.removeLast()
      if (s.indexOf(currNum) == -1) {
        return false
      }
      queue.addFirst(currNum + '0')
      queue.addFirst(currNum + '1')
      count++
    }
    return true
  }
}

fun main() {
  Solution1().queryString("0110", 3).println()
}
/**
 * 10 11
 * 100 110
 * 101 111
 */