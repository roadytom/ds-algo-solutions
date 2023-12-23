package leetcode.kotlin.queue.implementstackusingqueue225

/**
 * push: O(n)
 * pop: O(1)
 * One queue solution
 */
class MyStack {
  var queue = ArrayDeque<Int>()
  fun push(x: Int) {
    queue.addFirst(x)
    val size = queue.size - 1
    repeat(size) {
      queue.addFirst(queue.removeLast())
    }
  }

  fun pop(): Int {
    return queue.removeLast()
  }

  fun top(): Int {
    return queue.last()
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
  var obj = MyStack()
  obj.push(2)
  var param_2 = obj.pop()
  var param_3 = obj.top()
  var param_4 = obj.empty()
}