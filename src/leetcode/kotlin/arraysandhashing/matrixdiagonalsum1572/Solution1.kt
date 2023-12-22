package leetcode.kotlin.arraysandhashing.matrixdiagonalsum1572

class Solution1 {
  fun diagonalSum(mat: Array<IntArray>): Int {
    val n = mat.size
    var sum = 0
    repeat(n) { i ->
      val pdR = i
      val pdC = i
      val sdR = i
      val sdC = n - i - 1
      if (pdR != sdR || pdC != sdC) {
        sum += mat[pdR][pdC] + mat[sdR][sdC]
      }
    }
    return sum
  }
}