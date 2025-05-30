package leetcode.kotlin.daily.december2023.minimumtimevisitingallpoints1266

import kotlin.math.abs

class Solution1 {
  fun minTimeToVisitAllPoints(points: Array<IntArray>): Int {
    return points.toList().zipWithNext { a, b -> calculateMinTime(a, b) }.sum()
  }

  private fun calculateMinTime(a: IntArray, b: IntArray): Int {
    val (x1, y1) = a
    val (x2, y2) = b
    return maxOf(abs(x1 - x2), abs(y1 - y2))
  }
}

fun main() {
  println(Solution1().minTimeToVisitAllPoints(arrayOf(intArrayOf(1, 1), intArrayOf(3, 4), intArrayOf(-1, 0))))
  println(Solution1().minTimeToVisitAllPoints(arrayOf(intArrayOf(3, 2), intArrayOf(-2, 2))))
}