package leetcode.kotlin.stack.decimaltobinary

import leetcode.kotlin.println

class Solution1 {
  fun decimalToBinary(num: Int): String {
    val sb = StringBuilder()
    var currNum = num
    while (currNum != 0) {
      sb.append(currNum % 2)
      currNum /= 2
    }
    return sb.reverse().toString()
  }
}

fun main() {
  Solution1().decimalToBinary(4).println()
}