package leetcode.kotlin.sorting.sortanarray912

class Solution1 {
  fun sortArray(nums: IntArray): IntArray {
    val mergeSort = MergeSort(nums)
    mergeSort.mergeSort()
    return nums
  }
}

fun main() {
  println(Solution1().sortArray(intArrayOf(5, 1, 1, 2, 0, 0)).contentToString())
}

class MergeSort(private val arr: IntArray) {

  fun mergeSort(start: Int = 0, end: Int = arr.lastIndex) {
    if (start >= end) {
      return
    }
    val mid = (start + end) / 2
    mergeSort(start, mid)
    mergeSort(mid + 1, end)
    merge(start, end)
  }

  private fun merge(start: Int, end: Int) {
    val mid = (start + end) / 2
    val tempArray = IntArray(end - start + 1)
    var firstHalfIdx = start
    var secondHalfIdx = mid + 1
    var arrayIdx = 0
    while (firstHalfIdx <= mid && secondHalfIdx <= end) {
      if (arr[firstHalfIdx] < arr[secondHalfIdx]) {
        tempArray[arrayIdx] = arr[firstHalfIdx]
        firstHalfIdx++
      } else {
        tempArray[arrayIdx] = arr[secondHalfIdx]
        secondHalfIdx++
      }
      arrayIdx++
    }
    while (firstHalfIdx <= mid) {
      tempArray[arrayIdx] = arr[firstHalfIdx]
      firstHalfIdx++
      arrayIdx++
    }
    while (secondHalfIdx <= end) {
      tempArray[arrayIdx] = arr[secondHalfIdx]
      secondHalfIdx++
      arrayIdx++
    }
    for ((idx, value) in tempArray.withIndex()) {
      arr[start + idx] = value
    }
  }
}