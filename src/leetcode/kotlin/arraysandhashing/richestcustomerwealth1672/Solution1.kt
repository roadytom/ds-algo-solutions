package leetcode.kotlin.arraysandhashing.richestcustomerwealth1672

class Solution1 {
  fun maximumWealth(accounts: Array<IntArray>): Int {
    var max = 0
    accounts.forEach { banks ->
      max = max.coerceAtLeast(banks.sum())
    }
    return max
  }
}
