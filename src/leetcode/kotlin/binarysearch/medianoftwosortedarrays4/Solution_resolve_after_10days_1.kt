package leetcode.kotlin.binarysearch.medianoftwosortedarrays4

class Solution_resolve_after_10days {
  fun findMedianSortedArrays(a: IntArray, b: IntArray): Double {
    return if ((a.size + b.size) % 2 == 0) {
      // even
      (findKthIndex(a, b, (a.size + b.size) / 2, 0, a.size - 1, 0, b.size - 1) + findKthIndex(
        a,
        b,
        (a.size + b.size) / 2 - 1,
        0,
        a.size - 1,
        0,
        b.size - 1
      )) / 2.0
    } else {
      // odd
      findKthIndex(a, b, (a.size + b.size) / 2, 0, a.size - 1, 0, b.size - 1).toDouble()
    }
  }

  fun findKthIndex(
    a: IntArray, b: IntArray, k: Int, aStart: Int, aEnd: Int, bStart: Int, bEnd: Int
  ): Int {
    if (aStart > aEnd) {
      return b[k + bStart]
    } else if (bStart > bEnd) {
      return a[k + aStart]
    }

    val aMid = (aEnd - aStart) / 2 + aStart
    val bMid = (bEnd - bStart) / 2 + bStart
    if (k > aMid - aStart + bMid - bStart) {
      // remove from left
      // when deleting need to decrease k also
      return if (a[aMid] < b[bMid]) {
        findKthIndex(a, b, k - (aMid - aStart + 1), aMid + 1, aEnd, bStart, bEnd)
      } else {
        findKthIndex(a, b, k - (bMid - bStart + 1), aStart, aEnd, bMid + 1, bEnd)
      }
    } else {
      // remove from right
      return if (a[aMid] > b[bMid]) {
        findKthIndex(a, b, k, aStart, aMid - 1, bStart, bEnd)
      } else {
        findKthIndex(a, b, k, aStart, aEnd, bStart, bMid - 1)
      }
    }
  }
}

fun main() {
  repeat(4) {
    Solution_resolve_after_10days().findKthIndex(intArrayOf(1, 2), intArrayOf(3, 4), it, 0, 1, 0, 1)

  }
}