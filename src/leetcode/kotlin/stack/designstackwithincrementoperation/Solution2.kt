package leetcode.kotlin.stack.designstackwithincrementoperation

/**
 * OPTIMAL SOLUTION
 */
class CustomStack2(val size: Int) {
  val stack = mutableListOf<Int>()

  fun push(x: Int) {
    if (stack.size < size) {
      stack += x
    }
  }

  fun pop(): Int {
    if (stack.isEmpty()) {
      return -1
    }
    val popedElement = stack.removeLast()
    return popedElement
  }

  private fun <E> MutableList<E>.removeLast(): E {
    return this.removeAt(lastIndex)
  }

  fun increment(k: Int, `val`: Int) {
    repeat(minOf(k, stack.size)) {
      stack[it] += `val`
    }
  }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * var obj = CustomStack(maxSize)
 * obj.push(x)
 * var param_2 = obj.pop()
 * obj.increment(k,`val`)
 */