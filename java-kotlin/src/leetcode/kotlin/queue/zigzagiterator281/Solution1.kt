package leetcode.kotlin.queue.zigzagiterator281

class ZigzagIterator(v1: IntArray, v2: IntArray) {
  val queue = ArrayDeque<IntIterator>()

  init {
    listOf(v1, v2).filter { it.isNotEmpty() }.forEach { queue.addFirst(it.iterator()) }
  }

  fun next(): Int {
    if (!hasNext()) {
      throw IllegalStateException("no more elements")
    }
    val currIterator = queue.removeLast()
    val nextElement = currIterator.next()
    if (currIterator.hasNext()) {
      queue.addFirst(currIterator)
    }
    return nextElement
  }

  fun hasNext(): Boolean {
    return queue.isNotEmpty()
  }
}

// Your ZigzagIterator object will be instantiated and called as such:
// var i = ZigzagIterator(v1, v2)
// var ret = ArrayList<Int>()
// while(i.hasNext()){
//		ret.add(i.next())
// }