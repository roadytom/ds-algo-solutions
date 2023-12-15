package leetcode.kotlin.binarysearch.medianoftwosortedarrays4

class Solution_resolve_after_10days_2 {
  fun findMedianSortedArrays(a: IntArray, b: IntArray): Double {
    if (a.size > b.size) {
      return findMedianSortedArrays(b, a)
    }
    // we add 1 because
    // we want to make
    // sure our solution
    // will be in the
    // LEFT PART ALWAYS
    // for example:
    // a = [1, 9, 10]
    // b = [2, 5, 8, 11]
    // we take:
    // 1       | 9, 10
    // 2, 5, 8 | 11
    // left has 4 elements right 3, so we will calculate everything accordingly
    // for even both of them will be equal elements
    val requiredCount = (a.size + b.size + 1) / 2
    var left = 0
    var right = a.size
    while (left <= right) {
      val aCount = (right - left) / 2 + left
      val bCount = requiredCount - aCount
      val aLeftMax = if (aCount == 0) Int.MIN_VALUE else a[aCount - 1]
      val bLeftMax = if (bCount == 0) Int.MIN_VALUE else b[bCount - 1]
      val aRightMin = if (aCount == a.size) Int.MAX_VALUE else a[aCount]
      val bRightMin = if (bCount == b.size) Int.MAX_VALUE else b[bCount]
      if (aLeftMax <= bRightMin && bLeftMax <= aRightMin) {
        return if ((a.size + b.size) % 2 == 0) {
          (maxOf(aLeftMax, bLeftMax) + minOf(aRightMin, bRightMin)) / 2.0
        } else {
          maxOf(aLeftMax, bLeftMax).toDouble()
        }
      } else {
        if (aLeftMax > bRightMin) {
          right = aCount - 1
        } else {
          left = aCount + 1
        }
      }
    }
    throw IllegalStateException("cannot be here")
  }
}