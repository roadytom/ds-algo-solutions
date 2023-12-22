package leetcode.kotlin.dailydecember2023.widestverticalarea1637

class Solution1 {
  fun maxWidthOfVerticalArea(points: Array<IntArray>): Int {
    points.sortBy { it[0] }
    var max = Int.MIN_VALUE
    for (i in 1 until points.size) {
      max = max.coerceAtLeast(points[i][0] - points[i - 1][0])
    }
    return max
  }
}