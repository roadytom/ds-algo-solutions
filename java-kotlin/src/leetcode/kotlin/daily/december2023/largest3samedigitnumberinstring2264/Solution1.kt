package leetcode.kotlin.daily.december2023.largest3samedigitnumberinstring2264

import leetcode.kotlin.println

class Solution1 {
  fun largestGoodInteger(num: String): String {
    var max = -1
    var maxStr = ""
    for (start in 0..num.length - 3) {
      val str = num.substring(start, start + 3)
      if (str.isAllCharsUnique() && max < str[0].digitToInt()) {
        max = str[0].digitToInt()
        maxStr = str
      }
    }
    return maxStr
  }

  fun String.isAllCharsUnique(): Boolean = this.zipWithNext { a, b -> a == b }.all { it }
}

fun main() {
  Solution1().largestGoodInteger("6777133339").println()
}