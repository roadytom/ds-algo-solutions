package leetcode.kotlin.dp.maximumlengthofpairchain

class Solution1 {
  fun findLongestChain(pairs: Array<IntArray>): Int {
    pairs.sortBy { it[0] }
    return findLongestChain(0, pairs)
  }

  fun findLongestChain(index: Int, pairs: Array<IntArray>): Int {
    if (index == pairs.size) {
      return 0
    }
    val chain = findNextChain(index, pairs[index][1], pairs)
    TODO()
  }

  private fun findNextChain(startIndex: Int, end: Int, pairs: Array<IntArray>): Int {
    var left = startIndex
    var right = pairs.lastIndex
    while (left <= right) {
      val mid = (right - left) / 2 + left
      if (pairs[mid][0] > end) {
        right = mid - 1
      } else {
        left = mid + 1
      }
    }
    TODO()
  }

}