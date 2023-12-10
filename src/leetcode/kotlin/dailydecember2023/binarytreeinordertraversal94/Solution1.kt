package leetcode.kotlin.dailydecember2023.binarytreeinordertraversal94

class Solution1 {
  class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
  }

  fun inorderTraversal(root: TreeNode?): List<Int> {
    if (root == null) {
      return emptyList()
    }
    return inorderTraversal(root.left) + root.`val` + inorderTraversal(root.right)
  }
}