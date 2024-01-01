package leetcode.kotlin.daily.december2023.largestoddnumberinstring1903

import leetcode.kotlin.println

class Solution1 {
  fun largestOddNumber(num: String): String {
    return num.dropLastWhile { it.digitToInt() % 2 != 1 }
  }
}

fun main() {
  Solution1().largestOddNumber("52").println()
}