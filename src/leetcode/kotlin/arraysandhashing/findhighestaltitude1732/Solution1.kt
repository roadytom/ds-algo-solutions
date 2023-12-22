package leetcode.kotlin.arraysandhashing.findhighestaltitude1732

class Solution1 {
  fun largestAltitude(gain: IntArray): Int {
    var sum = 0
    var highestAltitude = 0
    gain.forEach { g ->
      sum += g
      highestAltitude = highestAltitude.coerceAtLeast(sum)
    }
    return highestAltitude
  }
}