package pramp

import leetcode.kotlin.trees.TreeNode

private fun solve() {

}

fun main() {
  repeat(readInt()) {
    println(solve())
  }
}

fun convert(curr: TreeNode?, parent: TreeNode? = null, adjList: MutableMap<Int, MutableList<Int>>) {
  val curr = curr ?: return
  val list = listOfNotNull(parent?.`val`, curr.left?.`val`, curr.right?.`val`)
  adjList[curr.`val`] = list.toMutableList()
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }