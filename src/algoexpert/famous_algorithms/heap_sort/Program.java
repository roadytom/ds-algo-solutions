package algoexpert.famous_algorithms.heap_sort;

import java.util.Arrays;

class Program {
    public static int[] heapSort(int[] array) {
        Heap heap = new Heap(array);
        System.out.println(Arrays.toString(heap.getHeapArray()));
        for (int i = 0; i < 2; i++) {
            heap.pop();
        }
        heap.insert(100);
        heap.insert(200);
        for (int i = 0; i < heap.getHeapArray().length; i++) {
            heap.pop();
        }
        return heap.getHeapArray();
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(heapSort(new int[]{-4, 5, 10, 8, -10, -6, -4, -2, -5, 3, 5, -4, -5, -1, 1, 6, -7, -6, -7, 8, Integer.MAX_VALUE, Integer.MAX_VALUE})));

    }
}

class Heap {
    private final int[] heapArray;
    private final int maxSize;
    private int currentSize;

    public int[] getHeapArray() {
        return heapArray;
    }

    public Heap(int[] array) {
        this.heapArray = array;
        this.maxSize = array.length;
        this.currentSize = array.length;
        buildHeap();
    }

    private void buildHeap() {
        int startIdx = (currentSize - 2) / 2;
        for (int i = startIdx; i >= 0; i--) {
            siftDown(i);
        }
    }

    public void insert(int val) {
        heapArray[currentSize] = val;
        currentSize++;
        siftUp(currentSize - 1);
    }

    public int pop() {
        int lastIdx = this.currentSize - 1;
        swap(0, lastIdx);
        this.currentSize--;
        siftDown(0);
        return this.heapArray[lastIdx];
    }


    private void siftUp(Integer currentIdx) {
        if (currentIdx == 0) {
            return;
        }
        int parent = currentIdx / 2;
        if (heapArray[currentIdx] > heapArray[parent]) {
            swap(currentIdx, parent);
            siftUp(parent);
        }
    }

    private void siftDown(Integer currentIdx) {
        if (currentIdx == null || currentIdx >= this.currentSize) {
            return;
        }
        int largestIdx = currentIdx;
        Integer leftIdx = leftIdx(currentIdx);
        Integer rightIdx = rightIdx(currentIdx);
        if (leftIdx != null) {
            if (heapArray[leftIdx] > heapArray[largestIdx]) {
                largestIdx = leftIdx;
            }
        }
        if (rightIdx != null) {
            if (heapArray[rightIdx] > heapArray[largestIdx]) {
                largestIdx = rightIdx;
            }
        }
        if (largestIdx != currentIdx) {
            swap(largestIdx, currentIdx);
            siftDown(largestIdx);
        }
    }

    private void swap(int first, int second) {
        int temp = this.heapArray[first];
        heapArray[first] = heapArray[second];
        heapArray[second] = temp;
    }

    private Integer leftIdx(int currentIdx) {
        int leftIdx = currentIdx * 2 + 1;
        if (leftIdx >= this.currentSize) {
            return null;
        } else {
            return leftIdx;
        }
    }

    private Integer rightIdx(int currentIdx) {
        int rightIdx = currentIdx * 2 + 2;
        if (rightIdx >= this.currentSize) {
            return null;
        } else {
            return rightIdx;
        }
    }
}
