package leetcode.kotlin.stack.twostackinarray

class Solution1(val size: Int) {
  private var top1: Int = -1
  private var top2: Int = size
  private var arr: IntArray = IntArray(size)

  fun push1(x: Int) {
    if (top1 + 1 < top2) {
      arr[top1 + 1] = x
      top1++
    } else {
      throw IllegalStateException("overflow")
    }
  }

  fun push2(x: Int) {
    if (top2 - 1 > top1) {
      arr[top2 - 1] = x
      top2--
    } else {
      throw IllegalStateException("overflow")
    }
  }

  // Note: Always return -1, when stack becomes empty.
  fun pop1(): Int {
    if (top1 != -1) {
      top1 -= 1
      return arr[top1 + 1]
    }
    return -1
  }

  // Note: Always return -1, when stack becomes empty.
  fun pop2(): Int {
    if (top2 != size) {
      top2++
      return arr[top2 - 1]
    }
    return -1
  }
}