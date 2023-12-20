package leetcode.kotlin.dailydecember2023.imagesmoother661

class Solution1 {
  fun imageSmoother(img: Array<IntArray>): Array<IntArray> {
    val directions = arrayOf(
      intArrayOf(0, 0),
      intArrayOf(0, 1),
      intArrayOf(1, 0),
      intArrayOf(1, 1),
      intArrayOf(-1, -1),
      intArrayOf(-1, 0),
      intArrayOf(0, -1),
      intArrayOf(-1, 1),
      intArrayOf(1, -1),
    )
    val result = Array(img.size) { IntArray(img[0].size) }
    for (i in 0..img.lastIndex) {
      for (j in 0..img[i].lastIndex) {
        result[i][j] = directions.mapNotNull { (x, y) ->
          img.getOrNull(i + x)?.getOrNull(j + y)
        }.average().toInt()
      }
    }
    return result
  }
}