package leetcode.kotlin.trees.serializeanddeserializebinarytree

import leetcode.kotlin.println
import leetcode.kotlin.trees.TreeNode

class Codec() {
  // Encodes a URL to a shortened URL.
  fun serialize(root: TreeNode?): String {
    val nodes = mutableListOf<Int?>()
    serialize(root, nodes)
    return nodes.joinToString(",")
  }

  private fun serialize(node: TreeNode?, nodes: MutableList<Int?>) {
    nodes.add(node?.`val`)
    if (node == null) {
      return
    }
    serialize(node.left, nodes)
    serialize(node.right, nodes)
  }

  var index = 0

  // Decodes your encoded data to tree.
  fun deserialize(data: String): TreeNode? {
    val list = data.split(",")
    return deserialize(list)
  }

  private fun deserialize(data: List<String>): TreeNode? {
    if (index >= data.size || data[index] == "null") {
      index++
      return null
    }
    val curr = TreeNode(data[index].toInt())
    index++
    curr.left = deserialize(data)
    curr.right = deserialize(data)
    return curr
  }
}

fun main() {
  fun generateSampleTree(): TreeNode {
    val zero = TreeNode(0)
    val one = TreeNode(1)
    val fife = TreeNode(5)
    val seven = TreeNode(7)
    val nine = TreeNode(9)
    val eight = TreeNode(8)
    one.left = zero
    one.right = fife
    seven.left = one
    seven.right = nine
    nine.left = eight
    return seven
  }

  val tree = generateSampleTree()
  tree.println()
  val codec = Codec()
  val str = codec.serialize(tree)
  str.println()
  codec.deserialize(str).println()
}