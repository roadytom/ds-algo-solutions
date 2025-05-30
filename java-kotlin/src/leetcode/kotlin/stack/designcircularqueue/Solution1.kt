package leetcode.kotlin.stack.designcircularqueue

class MyCircularQueue(k: Int) {
  val size = k
  val array = IntArray(k)
  var head = 0
  var count = 0

  val tail: Int
    get() = (head + count - 1) % size

  fun enQueue(value: Int): Boolean {
    if (isFull()) {
      return false
    }
    val enqueueIndex = (tail + 1) % size
    array[enqueueIndex] = value
    count++
    return true
  }

  fun deQueue(): Boolean {
    if (isEmpty()) {
      return false
    }
    head = (head + 1) % size
    count--
    return true
  }

  fun Front(): Int = if (count == 0) -1 else array[head]

  fun Rear(): Int = if (count == 0) -1 else array[tail]

  fun isEmpty(): Boolean = count == 0

  fun isFull(): Boolean = count == size
}