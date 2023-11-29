package commonalgorithms.sorting;

import java.util.Arrays;


public class QuickSort {
  public static void main(String[] args) {
    System.out.println(Arrays.toString(quicksort(new int[]{50, 23, 9, 10, 2, 2, 1, 2, 6}, 0, 8)));
  }

  public static int[] quicksort(int[] arr, int left, int right) {
    if (right <= left) {
      return arr;
    }
    int pivotIndex = partition(arr, left, right);
    quicksort(arr, left, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, right);
    return arr;
  }

  private static int partition(int[] arr, int left, int right) {
    int pivot = arr[right];
    int l = left, r = right - 1;
    while (l <= r) {
      while (arr[l] < pivot) {
        l++;
      }
      while (r >= 0 && arr[r] > pivot) {
        r--;
      }
      if (l <= r) {
        swap(arr, l, r);
        l++;
        r--;
      }
    }
    swap(arr, l, right);
    return l;
  }

  private static void swap(int[] arr, int l, int r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
  }

}
