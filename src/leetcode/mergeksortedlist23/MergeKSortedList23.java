package leetcode;

import java.util.Objects;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class MergeKSortedList23 {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }
        return mergeSort(lists, 0, lists.length - 1);
    }

    private ListNode mergeSort(ListNode[] lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        int mid = (right - left) / 2 + left;
        ListNode leftSide = mergeSort(lists, left, mid);
        ListNode rightSide = mergeSort(lists, mid + 1, right);
        return merge(leftSide, rightSide);
    }

    private ListNode merge(ListNode left, ListNode right) {
        ListNode dummyHead = new ListNode(-1);
        ListNode itr = dummyHead;
        while (left != null && right != null) {
            if (left.val < right.val) {
                itr.next = left;
                left = left.next;
            } else {
                itr.next = right;
                right = right.next;
            }
            itr = itr.next;
        }
        if (left != null) {
            itr.next = left;
        } else if (right != null) {
            itr.next = right;
        }
        return dummyHead.next;
    }


    static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }

        @Override
        public String toString() {
            return "";
//            return Stream.iterate(this, Objects::nonNull, node -> node.next)
//                    .map(node -> String.valueOf(node.val))
//                    .collect(Collectors.joining(" -> "));
//            StringBuilder builder = new StringBuilder();
//            ListNode itr = this;
//            while (itr != null) {
//                builder.append(itr.val).append(" -> ");
//                itr = itr.next;
//            }
//            return builder.toString();
        }
    }

    public static void main(String[] args) {
        ListNode[] lists = new ListNode[]{
                new ListNode(1,
                        new ListNode(4, new ListNode(5))),
                new ListNode(1,
                        new ListNode(3, new ListNode(4))),
                new ListNode(2,
                        new ListNode(6)),
                null
        };
        ListNode head = new MergeKSortedList23().mergeKLists(lists);
        System.out.println(head);
    }
}

