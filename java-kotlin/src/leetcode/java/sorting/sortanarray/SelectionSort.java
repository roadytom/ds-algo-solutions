package leetcode.java.sorting.sortanarray;

public class SelectionSort {
  public int[] sortArray(int[] nums) {
    int n = nums.length;

    for (int i = 0; i < n - 1; i++) {
      int minIndex = i;
      for (int j = i + 1; j < n; j++) {
        if (nums[minIndex] > nums[j]) {
          minIndex = j;
        }
      }
      // swap
      int temp = nums[i];
      nums[i] = nums[minIndex];
      nums[minIndex] = temp;
    }
    return nums;
  }
  /**
   * 5,2,3,1
   * i: 0, 1, 2
   * j: 0-3, 1-3, 2-3
   */
}
