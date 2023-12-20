package leetcode.kotlin.dailydecember2023.imagesmoother661

import leetcode.kotlin.println

class Solution2 {
  fun imageSmoother(img: Array<IntArray>): Array<IntArray> {
    val m = img.size
    val n = img[0].size
    val temp = IntArray(n)
    var topLeftValue = 0
    for (i in 0..<m) {
      for (j in 0..<n) {
        var sum = 0
        var count = 0
        // Bottom neighbours
        if (i + 1 < m) {
          if (j - 1 >= 0) {
            sum += img[i + 1][j - 1]
            count++
          }
          sum += img[i + 1][j]
          count++
          if (j + 1 < n) {
            sum += img[i + 1][j + 1]
            count++
          }
        }
        // Next neighbour
        if (j + 1 < n) {
          sum += img[i][j + 1]
          count++
        }
        // Itself
        sum += img[i][j]
        count++
        // Prev neighbour
        if (j - 1 >= 0) {
          sum += temp[j - 1]
          count++
        }
        // Top neighbours
        if (i - 1 >= 0) {
          if (j - 1 >= 0) {
            sum += topLeftValue
            count++
          }
          sum += temp[j]
          count++
          if (j + 1 < n) {
            sum += temp[j + 1]
            count++
          }
        }
        topLeftValue = temp[j]
        temp[j] = img[i][j]
        img[i][j] = sum / count
      }
    }
    return img
  }
}

fun main() {
  Solution2().imageSmoother(
    arrayOf(
      intArrayOf(100, 200, 100), intArrayOf(200, 50, 200), intArrayOf(100, 200, 100)
    )
  ).contentDeepToString().println()
}