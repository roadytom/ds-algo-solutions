package leetcode.kotlin.binarysearch.reversepairs493

class Solution1 {
  fun reversePairs(num: IntArray): Int {
    return mergeSort(0, num.size - 1, num)
  }

  private fun mergeSort(low: Int, high: Int, num: IntArray): Int {
    if (low >= high) {
      return 0
    }
    val mid = (low + high) / 2
    val left = mergeSort(low, mid, num)
    val right = mergeSort(mid + 1, high, num)
    val current = merge(low, high, num)
    return left + right + current
  }

  private fun merge(low: Int, high: Int, num: IntArray): Int {
    val mid = (low + high) / 2


    val tempArray = IntArray(high - low + 1)
    var tempArrayIndex = 0

    var leftIndex = low
    var rightIndex = mid + 1

    /**
     * Now countReversePairs takes O(n + m) time to find
     * reverse pairs from two sorted array
     * previous I used binary search for each right element
     * which is O(m*log(n)) which cause TLE
     */
    val count = countReversePairs(low, high, num)

//    val count = num.filterIndexed { idx, _ -> idx in (mid + 1)..high }.sumOf { countReversePairs(low, mid, it, num) }

    while (leftIndex <= mid && rightIndex <= high) {
      val leftVal = num[leftIndex]
      val rightVal = num[rightIndex]
      if (leftVal < rightVal) {
        tempArray[tempArrayIndex] = leftVal
        leftIndex++
      } else {
        tempArray[tempArrayIndex] = rightVal
        rightIndex++
      }
      tempArrayIndex++
    }
    while (leftIndex <= mid) {
      tempArray[tempArrayIndex] = num[leftIndex]
      tempArrayIndex++
      leftIndex++
    }
    while (rightIndex <= high) {
      tempArray[tempArrayIndex] = num[rightIndex]
      tempArrayIndex++
      rightIndex++
    }
    for ((index, value) in tempArray.withIndex()) {
      num[index + low] = value
    }
    return count
  }

  private fun countReversePairs(low: Int, high: Int, num: IntArray): Int {
    val mid = (high - low) / 2 + low

    var count = 0
    var right = mid + 1

    for (left in low..mid) {
      while (right <= high && 0L + num[left] - num[right] > num[right]) {
        right++
      }
      count += right - mid - 1
    }
    return count
  }
}

fun main() {
  val solution1 = Solution1()
  val num = intArrayOf(2, 4, 3, 5, 1)
  println(solution1.reversePairs(num))
  println(num.contentToString())
}