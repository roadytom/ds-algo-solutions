package codingninjas.linkedlist.flattenalinkedlist

class Solution1 {
  fun flattenLinkedList(head: Node?): Node? {
    if (head == null) {
      return null
    }
    val heads = buildList {
      var iterator = head
      while (iterator != null) {
        add(iterator)
        val next = iterator.next
        iterator.next = null
        iterator = next
      }
    }
    return flattenLinkedList(0, heads.lastIndex, heads)
  }

  private fun flattenLinkedList(left: Int, right: Int, heads: List<Node>): Node? {
    if (left > right) {
      return null
    } else if (left == right) {
      return heads[left]
    }
    val mid = (right - left) / 2 + left
    val first = flattenLinkedList(left, mid, heads)
    val second = flattenLinkedList(mid + 1, right, heads)
    return merge(first, second)
  }

  private fun merge(first: Node?, second: Node?): Node? {
    val dummyHead = Node(-1)
    var result = dummyHead
    var firstIterator = first
    var secondIterator = second
    while (firstIterator != null && secondIterator != null) {
      if (firstIterator.data < secondIterator.data) {
        result.child = firstIterator
        firstIterator = firstIterator.child
      } else {
        result.child = secondIterator
        secondIterator = secondIterator.child
      }
      result = result.child!!
    }
    while (firstIterator != null) {
      result.child = firstIterator
      firstIterator = firstIterator.child
      result = result.child!!
    }

    while (secondIterator != null) {
      result.child = secondIterator
      secondIterator = secondIterator.child
      result = result.child!!
    }
    return dummyHead.child
  }
}

class Node {
  override fun toString(): String {
    return buildString {
      append(data)
      var iterator = child
      while (iterator != null) {
        append(" => ")
        append(iterator.data)
        iterator = iterator.child
      }
      if (next != null) {
        appendLine()
        appendLine("||")
        appendLine("\\/")
        append(next.toString())
      }
    }
  }

  var data: Int
  var next: Node?
  var child: Node?

  constructor() {
    this.data = 0
    this.next = null
    this.child = null
  }

  constructor(data: Int) {
    this.data = data
    this.next = null
    this.child = null
  }

  constructor(data: Int, next: Node?, child: Node?) {
    this.data = data
    this.next = next
    this.child = child
  }
}

fun main() {
  val head = Node(
    1, next = Node(
      8, next = Node(
        18, next = Node(29), child = Node(22)
      ), child = Node(10, null, Node(15))
    ), child = Node(
      2, null, Node(3)
    )
  )
  println(head)
  val list = Solution1().flattenLinkedList(head)
  println()
  println(list)
}