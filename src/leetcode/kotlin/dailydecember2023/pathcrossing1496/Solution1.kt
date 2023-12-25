package leetcode.kotlin.dailydecember2023.pathcrossing1496

class Solution1 {
  fun isPathCrossing(path: String): Boolean {
    val points = mutableSetOf<Pair<Int, Int>>()
    val directions = mapOf(
      'N' to (0 to 1), 'S' to (0 to -1), 'W' to (-1 to 0), 'E' to (1 to 0)
    )
    var currPoint = 0 to 0
    points += currPoint
    for (c in path) {
      val (x, y) = directions[c] ?: throw IllegalArgumentException("not existing direction")
      val (currX, currY) = currPoint
      currPoint = x + currX to y + currY
      if (currPoint in points) {
        return true
      }
      points += currPoint
    }
    return false
  }
}