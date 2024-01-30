package leetcode.java.divideandconquer.kthlargestelementinarray;

import java.util.Random;

/**
 * Lomuto's Partition Algorithm
 */
public class Solution1 {
  private final Random random = new Random();

  public int findKthLargest(int[] nums, int k) {
    int searchIndex = nums.length - k;
    int left = 0, right = nums.length - 1;
    while (left <= right) {
      int foundIndex = quickSelect(left, right, nums);
      if (searchIndex == foundIndex) {
        return nums[foundIndex];
      } else if (searchIndex > foundIndex) {
        left = foundIndex + 1;
      } else {
        right = foundIndex - 1;
      }
    }
    throw new IllegalStateException("given index is not in array range");
  }

  private int quickSelect(int left, int right, int[] nums) {
    swap(random.nextInt(left, right + 1), right, nums);

    int pivot = nums[right];
    int i = left, j = left;
    while (i < right) {
      if (nums[i] <= pivot) {
        swap(i, j, nums);
        j++;
      }
      i++;
    }
    swap(j, right, nums);
    return j;
  }

  private void swap(int first, int second, int[] nums) {
    if (first == second) {
      return;
    }
    int temp = nums[first];
    nums[first] = nums[second];
    nums[second] = temp;
  }

  public static void main(String[] args) {
    System.out.println(new Solution1().findKthLargest(new int[]{3, 2, 1, 5, 6, 4}, 2));
  }
}
