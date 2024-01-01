package leetcode.kotlin.daily.december2023.minimumtimetomakeropecolorful1578

class Solution1 {
  fun minCost(colors: String, neededTime: IntArray): Int {
    var maxCandidateSum = 0
    var start = 0
    while (start < colors.length) {
      var max = 0
      var end = start
      while (end < colors.length && colors[start] == colors[end]) {
        max = max.coerceAtLeast(neededTime[end])
        end++
      }
      maxCandidateSum += max
      start = end
    }
    return neededTime.sum() - maxCandidateSum
  }
}