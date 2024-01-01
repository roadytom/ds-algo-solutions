package leetcode.kotlin.daily.december2023.specialpositionsinabinarymatrix

import leetcode.kotlin.println

class Solution1 {
  fun numSpecial(mat: Array<IntArray>): Int {
    val rowOnes = IntArray(mat.size) { 0 }
    val colOnes = IntArray(mat[0].size) { 0 }

    for (row in mat.indices) {
      var count = 0
      for (col in mat[0].indices) {
        if (mat[row][col] == 1) {
          count++
        }
      }
      rowOnes[row] = count
    }

    for (col in mat[0].indices) {
      var count = 0
      for (element in mat) {
        if (element[col] == 1) {
          count++
        }
      }
      colOnes[col] = count
    }
    var specialIndexes = 0
    for (row in 0..<mat.size) {
      for (col in 0..<mat[0].size) {
        if (mat[row][col] == 1 && rowOnes[row] == 1 && colOnes[col] == 1) {
          specialIndexes++
        }
      }
    }
    return specialIndexes
  }
}

fun main() {
  Solution1().numSpecial(
    arrayOf(
      intArrayOf(1, 0, 0), intArrayOf(0, 0, 1), intArrayOf(1, 0, 0)
    )
  ).println()
}