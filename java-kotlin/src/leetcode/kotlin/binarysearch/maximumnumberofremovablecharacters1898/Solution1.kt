package leetcode.kotlin.binarysearch.maximumnumberofremovablecharacters1898

import leetcode.kotlin.println

class Solution1 {
  fun String.removeIndices(removable: IntArray, k: Int): String {
    val removedSet = removable.take(k).toSet()
    return this.filterIndexed { index, c -> index !in removedSet }
  }

  fun String.isSubsequence(subSequence: String): Boolean {
    var subSequenceIndex = 0
    for (c in this) {
      if (subSequence[subSequenceIndex] == c) {
        subSequenceIndex++
        if (subSequenceIndex == subSequence.length) {
          return true
        }
      }
    }
    return false
  }

  fun maximumRemovals(s: String, p: String, removable: IntArray): Int {
    var left = 0
    var right = removable.size
    while (left <= right) {
      val mid = (right - left) / 2 + left
      val removedString = s.removeIndices(removable, mid)
      if (removedString.isSubsequence(p)) {
        left = mid + 1
      } else {
        right = mid - 1
      }
    }
    return left - 1
  }
}

fun main() {
  check(Solution1().maximumRemovals("abcacb", "ab", intArrayOf(3, 1, 0)) == 2)
  check(Solution1().maximumRemovals("abcbddddd", "abcd", intArrayOf(3, 2, 1, 4, 5, 6)) == 1)
  Solution1().maximumRemovals("abcab", "abc", intArrayOf(0, 1, 2, 3, 4)).println()
  check(Solution1().maximumRemovals("abcab", "abc", intArrayOf(0, 1, 2, 3, 4)) == 0)
}