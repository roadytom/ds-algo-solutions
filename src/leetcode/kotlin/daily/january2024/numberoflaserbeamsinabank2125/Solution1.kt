package leetcode.kotlin.daily.january2024.numberoflaserbeamsinabank2125

import leetcode.kotlin.println

class Solution1 {
  fun numberOfBeams(bank: Array<String>): Int {
    var answer = 0
    var prev = 0
    for (row in bank) {
      var count = 0
      for (c in row) {
        if (c == '1') {
          count++
        }
      }
      if (count == 0) {
        continue
      }
      answer += count * prev
      prev = count
    }
    return answer
  }
}

fun main() {
  Solution1().numberOfBeams(arrayOf("011001", "000000", "010100", "001000")).println()
}