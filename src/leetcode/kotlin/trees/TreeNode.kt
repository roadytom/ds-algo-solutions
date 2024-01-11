package leetcode.kotlin.trees

class TreeNode(val `val`: Int) {
  var left: TreeNode? = null
  var right: TreeNode? = null
  override fun toString() = diagram(this)
  private fun diagram(
    node: TreeNode?, top: String = "", root: String = "", bottom: String = ""
  ): String {
    return node?.let {
      if (node.left == null && node.right == null) {
        "$root${node.`val`}\n"
      } else {
        diagram(node.right, "$top ", "$top┌──", "$top│ ") + root + "${node.`val`}\n" + diagram(
          node.left, "$bottom│ ", "$bottom└──", "$bottom "
        )
      }
    } ?: "${root}null\n"
  }
}