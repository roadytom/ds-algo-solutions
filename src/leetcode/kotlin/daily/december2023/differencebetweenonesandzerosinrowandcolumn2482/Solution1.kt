package leetcode.kotlin.daily.december2023.differencebetweenonesandzerosinrowandcolumn2482

class Solution1 {
  /**
   * diff[i][j] = 2 * onesRowi + 2 * onesColj - m - n
   */
  fun onesMinusZeros(grid: Array<IntArray>): Array<IntArray> {
    val m = grid.size
    val n = grid[0].size
    val rowOnes = grid.map { row ->
      row.count { it == 1 }
    }
    val colOnes = (0..<n).map { col ->
      (0..<m).count { grid[it][col] == 1 }
    }
    val diff = Array(m) { IntArray(n) }
    repeat(m) { row ->
      repeat(n) { col ->
        diff[row][col] = 2 * rowOnes[row] + 2 * colOnes[col] - m - n
      }
    }
    return diff
  }
}
