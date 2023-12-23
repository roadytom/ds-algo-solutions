package leetcode.kotlin.queue.implementstackusingqueue225

/**
 * push: O(1)
 * pop: O(n)
 */
class MyStack2 {
  var queue = ArrayDeque<Int>()
  var top: Int? = null
  fun push(x: Int) {
    queue.addFirst(x)
    top = x
  }

  fun pop(): Int {
    val size = queue.size
    repeat(size - 1) {
      top = queue.removeLast()
      queue.addFirst(top!!)
    }
    val popped = queue.removeLast()
    return popped
  }

  fun top(): Int? {
    return top
  }

  fun empty(): Boolean {
    return queue.isEmpty()
  }
}

fun main() {
//    Your MyStack object will be instantiated and called as such:
  /**
   * 5 2 1
   */
  var obj = MyStack2()
  obj.push(1)
  obj.push(2)
  obj.top().
  var param_3 = obj.top()
  var param_4 = obj.empty()
}