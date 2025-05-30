package leetcode.kotlin.binarysearch.searcha2dmatrix

/**
 * OPTIMAL SOLUTION WITH O(log(m*n))
 * THINK MATRIX AS FULL SIZED 1D ARRAY
 */
class Solution1 {
  fun searchMatrix(matrix: Array<IntArray>, target: Int): Boolean {
    val m = matrix.size
    val n = matrix[0].size
    var low = 0
    var high = m + n
    while (low < high) {
      val mid = (low + high) / 2
      val value = matrix.getValue(mid)
      if (value == target) {
        return true
      } else if (value > target) {
        high = mid
      } else {
        low = mid + 1
      }
    }
    return false
  }

  fun Array<IntArray>.getValue(virtualIndex: Int): Int {
    val m = size
    val n = get(0).size
    val row = virtualIndex / n
    val col = virtualIndex % n
    return this[row][col]
  }
}

fun main() {
  println(
    Solution1().searchMatrix(
      arrayOf(
        intArrayOf(1, 3, 5, 7), intArrayOf(10, 11, 16, 20), intArrayOf(23, 30, 34, 60)
      ), 13
    )
  )
  println(
    Solution1().searchMatrix(
      arrayOf(
        intArrayOf(1, 3)
      ), 1
    )
  )
}