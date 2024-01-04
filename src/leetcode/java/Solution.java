package leetcode.java;


// Following is the class structure of the Node class:

import java.util.ArrayList;
import java.util.List;

class Node {
    public int data;
    public Node next;
    public Node child;

    Node() {
        this.data = 0;
        this.next = null;
        this.child = null;
    }

    Node(int data) {
        this.data = data;
        this.next = null;
        this.child = null;
    }

    Node(int data, Node next, Node child) {
        this.data = data;
        this.next = next;
        this.child = child;
    }
}


public class Solution {
    private static List<Node> buildList(Node head) {
        List<Node> result = new ArrayList<>();
        Node iterator = head;
        while (iterator != null) {
            result.add(iterator);
            iterator = iterator.next;
        }
        return result;
    }

    private static Node flattenLinkedList(int left, int right, List<Node> heads) {
        if (left > right) {
            return null;
        } else if (left == right) {
            return heads.get(left);
        }
        int mid = (right - left) / 2 + left;
        Node first = flattenLinkedList(left, mid, heads);
        Node second = flattenLinkedList(mid + 1, right, heads);
        return merge(first, second);
    }

    private static Node merge(Node first, Node second) {
        Node dummyHead = new Node(-1);
        Node result = dummyHead;
        Node firstIterator = first;
        Node secondIterator = second;
        while (firstIterator != null && secondIterator != null) {
            if (firstIterator.data < secondIterator.data) {
                result.next = firstIterator;
                Node next = firstIterator.child;
                firstIterator.child = null;
                firstIterator = next;
            } else {
                result.next = secondIterator;
                Node next = secondIterator.child;
                secondIterator.child = null;
                secondIterator = next;
            }
            result = result.next;
        }
        while (firstIterator != null) {
            result.next = firstIterator;
            Node next = firstIterator.child;
            firstIterator.child = null;
            firstIterator = next;
            result = result.next;
        }

        while (secondIterator != null) {
            result.next = secondIterator;

            Node next = secondIterator.child;
            secondIterator.child = null;
            secondIterator = next;

            result = result.next;
        }
        return dummyHead.next;
    }

    public static Node flattenLinkedList(Node head) {
        if (head == null) {
            return null;
        }
        List<Node> heads = buildList(head);
        return flattenLinkedList(0, heads.size() - 1, heads);
    }
}
