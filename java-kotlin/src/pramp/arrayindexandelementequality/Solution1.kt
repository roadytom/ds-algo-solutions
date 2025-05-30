package pramp.arrayindexandelementequality

import leetcode.kotlin.println

class Solution1 {
  fun indexEqualsValueSearch(arr: IntArray): Int {
    var index = 0
    while (index < arr.size) {
      if (arr[index] == index) {
        return index
      }
      if (index < arr[index]) {
        index = arr[index] + 1
      } else {
        index++
      }
    }
    return -1
  }
}

fun main() {
  Solution1().indexEqualsValueSearch(intArrayOf(-8, 0, 2, 5)).println()
}