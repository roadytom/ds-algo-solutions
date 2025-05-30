package leetcode.kotlin.binarysearch.searcha2dmatrix

/**
 * OPTIMAL SOLUTION
 * O(log(m) + log(n))
 * FIRST FIND EXACT ROW USING BINARY SEARCH
 * AND DO BINARY SEARCH IN THIS ROW
 */
class Solution2 {
  fun searchMatrix(matrix: Array<IntArray>, target: Int): Boolean {
    var up = 0
    var down = matrix.size
    var possibleRow: Int? = null
    while (up < down) {
      val mid = (up + down) / 2
      if (target in matrix[mid].first()..matrix[mid].last()) {
        possibleRow = mid
        break
      } else if (target < matrix[mid].first()) {
        down = mid
      } else {
        up = mid + 1
      }
    }
    possibleRow?.let {
      var left = 0
      var right = matrix[it].size
      while (left < right) {
        val mid = (left + right) / 2
        if (matrix[it][mid] == target) {
          return true
        } else if (matrix[it][mid] < target) {
          left = mid + 1
        } else {
          right = mid
        }
      }
    }
    return false
  }
}

fun main() {
  println(
    Solution2().searchMatrix(
      arrayOf(
        intArrayOf(1, 3, 5, 7),
        intArrayOf(10, 11, 16, 20),
        intArrayOf(23, 30, 34, 60)
      ),
      13
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