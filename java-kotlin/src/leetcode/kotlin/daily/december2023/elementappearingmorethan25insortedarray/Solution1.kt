package leetcode.kotlin.daily.december2023.elementappearingmorethan25insortedarray

class Solution1 {
  fun findSpecialInteger(arr: IntArray): Int {
    var left = 0
    var right = arr.size / 4
    while (right < arr.size) {
      if (arr[left] == arr[right]) {
        return arr[left]
      } else {
        left++
        right++
      }
    }
    throw IllegalStateException("cannot be here")
  }
}