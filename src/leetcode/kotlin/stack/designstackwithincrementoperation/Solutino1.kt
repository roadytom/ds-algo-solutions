package leetcode.kotlin.stack.designstackwithincrementoperation

/**
 * MY SOLUTION NOT OPTIMAL
 * INCREMENT TAKES O(n) time
 * THERE IS BETTER APPROACH
 * WITH INCREMENT TAKES O(K) time
 */
class CustomStack(val maxSize: Int) {
  var count = 0
  val stack = ArrayDeque<Int>()

  fun push(x: Int) {
    if (count < maxSize) {
      stack.addFirst(x)
      count++
    }
  }

  fun pop(): Int {
    if (count == 0) {
      return -1
    }
    count--
    return stack.removeFirst()
  }

  /**
   * TAKES O(n) time
   * which is not optimal
   * instead I can just store
   * info about incremented elements
   * in another array
   * SEE SOLUTION 2
   */
  fun increment(k: Int, `val`: Int) {
    val untouchedSize = maxOf(count - k, 0)
    val touchedSize = minOf(k, count)
    val tempStack = ArrayDeque<Int>()
    repeat(untouchedSize) {
      tempStack.addFirst(stack.removeFirst())
    }
    repeat(touchedSize) {
      tempStack.addFirst(stack.removeFirst() + `val`)
    }
    while (tempStack.isNotEmpty()) {
      stack.addFirst(tempStack.removeFirst())
    }
  }

}
