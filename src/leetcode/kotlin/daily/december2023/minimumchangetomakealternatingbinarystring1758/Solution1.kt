package leetcode.kotlin.daily.december2023.minimumchangetomakealternatingbinarystring1758

class Solution1 {
  fun minOperations(s: String): Int {
    var isZero = true
    var first = 0
    for (c in s) {
      if ((isZero && c == '1') || (!isZero && c == '0')) {
        first++
      }
      isZero = !isZero
    }
    isZero = false
    var second = 0
    for (c in s) {
      if ((isZero && c == '1') || (!isZero && c == '0')) {
        second++
      }
      isZero = !isZero
    }
    return minOf(first, second)
  }
}