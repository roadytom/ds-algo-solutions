package algoexpert.medium.merginglinkedlists.sol1;

public class Program {
    public static class LinkedList {
        public int value;
        public LinkedList next;

        public LinkedList(int value) {
            this.value = value;
            this.next = null;
        }

        public LinkedList(int value, LinkedList next) {
            this.value = value;
            this.next = next;
        }

        @Override
        public String toString() {
            return "LinkedList{" +
                    "value=" + value +
                    ", next=" + next +
                    '}';
        }
    }

    public LinkedList mergingLinkedLists(
            LinkedList linkedListOne, LinkedList linkedListTwo
    ) {
        LinkedList reverseHeadOne = reverseLinkedList(linkedListOne);
        LinkedList reverseHeadTwo = reverseLinkedList(linkedListTwo);
        LinkedList itr1 = reverseHeadOne;
        LinkedList itr2 = reverseHeadTwo;
        LinkedList ans = null;
        while (itr1 != null && itr2 != null && itr1.value == itr2.value) {
            ans = itr1;
            itr1 = itr1.next;
            itr2 = itr2.next;
        }
        reverseLinkedList(reverseHeadOne);
        reverseLinkedList(reverseHeadTwo);
        return ans;
    }

    private LinkedList reverseLinkedList(LinkedList head) {
        LinkedList prev = null;
        LinkedList curr = head;
        while (curr != null) {
            LinkedList temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    public static void main(String[] args) {
        System.out.println(new Program().mergingLinkedLists(
                new LinkedList(4, new LinkedList(2)),
                new LinkedList(1, new LinkedList(2))
        ));
    }
}
