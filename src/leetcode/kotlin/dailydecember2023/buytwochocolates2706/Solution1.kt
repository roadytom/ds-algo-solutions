package leetcode.kotlin.dailydecember2023.buytwochocolates2706

class Solution1 {
  fun buyChoco(prices: IntArray, money: Int): Int {
    var min = Int.MAX_VALUE
    var preMin = Int.MAX_VALUE
    for (price in prices) {
      if (min > price) {
        preMin = min
        min = price
      } else if (preMin > price) {
        preMin = price
      }
    }
    (money - min - preMin).let {
      if (it >= 0) {
        return it
      }
    }
    return money
  }
}