package leetcode;

import java.util.ArrayDeque;
import java.util.Queue;

public class CheckCompletenessOfBinaryTree958 {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean beginNull = false;
            for (int i = 0; i < size; i++) {
                TreeNode curr = queue.poll();
                if (beginNull) {
                    if (curr.left != null || curr.right != null) {
                        return false;
                    }
                } else {
                    if (curr.left == null) {
                        beginNull = true;
                    } else {
                        queue.offer(curr.left);
                    }
                    if (curr.right == null) {
                        beginNull = true;
                    } else {
                        if (beginNull) {
                            return false;
                        }
                        queue.offer(curr.right);
                    }
                }
            }
//            if (beginNull && !queue.isEmpty()) {
//                return false;
//            }
        }
        return true;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1,
                new TreeNode(2,
                        new TreeNode(4), new TreeNode(5)),
                new TreeNode(3, new TreeNode(6), null));
        new CheckCompletenessOfBinaryTree958().isCompleteTree(root);
    }
}
