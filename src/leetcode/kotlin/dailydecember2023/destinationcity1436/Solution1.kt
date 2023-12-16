package leetcode.kotlin.dailydecember2023.destinationcity1436

import leetcode.kotlin.println

class Solution1 {
  fun destCity(paths: List<List<String>>): String {
    val hasOutGoing = mutableSetOf<String>()
    for ((src, _) in paths) {
      hasOutGoing += src
    }
    for ((_, dest) in paths) {
      if (dest !in hasOutGoing) {
        return dest
      }
    }
    throw IllegalStateException("cannot be here")
  }
}

fun main() {
  Solution1().destCity(
    listOf(
      listOf("London", "New York"), listOf("New York", "Lima"), listOf("Lima", "Sao Paulo")
    )
  ).println()
}