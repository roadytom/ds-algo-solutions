package leetcode.kotlin.dailydecember2023.countofmatchesintournament1688

import leetcode.kotlin.println

class Solution1 {
  fun numberOfMatches(n: Int): Int {
    var currTeams = n
    var matchesCount = 0
    while (currTeams != 1) {
      val nextTeams = if (currTeams % 2 == 1) {
        (currTeams + 1) / 2
      } else {
        currTeams / 2
      }
      matchesCount += currTeams - nextTeams
      currTeams = nextTeams
    }
    return matchesCount
  }
}

fun main() {
  Solution1().numberOfMatches(7).println()
}