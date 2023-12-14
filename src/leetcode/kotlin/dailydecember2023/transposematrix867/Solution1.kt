package leetcode.kotlin.dailydecember2023.transposematrix867

import leetcode.kotlin.println

class Solution1 {
  fun transpose(matrix: Array<IntArray>): Array<IntArray> {
    val m = matrix.size
    val n = matrix[0].size
    val transposed = Array(n) { IntArray(m) }
    repeat(m) { row ->
      repeat(n) { col ->
        transposed[col][row] = matrix[row][col]
      }
    }
    return transposed
  }
}

fun main() {
  Solution1().transpose(
    arrayOf(
      intArrayOf(1, 2, 3), intArrayOf(4, 5, 6)
    )
  ).contentDeepToString().println()
}