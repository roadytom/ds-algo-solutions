package pramp.spiralmatrix

import leetcode.kotlin.println

class Solution1 {
  fun spiralOrder(matrix: Array<IntArray>): List<Int> {
    val row = matrix.size
    val col = matrix[0].size
    var left = 0
    var right = col - 1
    var top = 0
    var bottom = row - 1
    val result = mutableListOf<Int>()
    var index = 0
    while (index < row * col) {
      for (i in left..right) {
        result.add(matrix[top][i])
        index++
      }
      if (index >= row * col) {
        break
      }
      for (i in top + 1..bottom) {
        result.add(matrix[i][right])
        index++
      }
      if (index >= row * col) {
        break
      }
      for (i in right - 1 downTo left) {
        result.add(matrix[bottom][i])
        index++
      }
      if (index >= row * col) {
        break
      }
      for (i in bottom - 1 downTo top + 1) {
        result.add(matrix[i][left])
        index++
      }
      top++
      bottom--
      left++
      right--
    }
    return result
  }
}

fun main() {
  Solution1().spiralOrder(
    arrayOf(
      intArrayOf(1, 2, 3, 4, 5),
      intArrayOf(6, 7, 8, 9, 10),
      intArrayOf(11, 12, 13, 14, 15),
      intArrayOf(16, 17, 18, 19, 20)
    )
  ).println()
}