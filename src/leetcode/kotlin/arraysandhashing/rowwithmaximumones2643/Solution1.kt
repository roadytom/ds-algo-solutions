package leetcode.kotlin.arraysandhashing.rowwithmaximumones2643

class Solution1 {
  fun rowAndMaximumOnes(mat: Array<IntArray>): IntArray {
    var max = -1
    var maxRow = IntArray(mat.size)
    mat.forEachIndexed { i, row ->
      val onesCount = row.sum()
      if (max < onesCount) {
        max = onesCount
        maxRow = intArrayOf(i, max)
      }
    }
    return maxRow
  }
}