package leetcode.java.divideandconquer;

public class Solution1 {
  public String kthLargestNumber(String[] nums, int k) {
    int left = 0, right = nums.length - 1;
    int searchingIndex = nums.length - k;
    while (left <= right) {
      int index = quickSelect(nums, left, right);
      if (index == searchingIndex) {
        return nums[index];
      } else if (searchingIndex > index) {
        left = index + 1;
      } else {
        right = index - 1;
      }
    }
    throw null;
  }

  private int quickSelect(String[] nums, int left, int right) {
    String pivot = nums[right];
    int i = left, upperBound = left;
    while (i < right) {
      if (firstLessThanOrEqualTo(nums[i], pivot)) {
        swap(nums, upperBound, i);
        upperBound++;
      }
      i++;
    }
    swap(nums, upperBound, right);
    return upperBound;
  }

  private boolean firstLessThanOrEqualTo(String num, String pivot) {
    if (num.length() != pivot.length()) {
      return num.length() < pivot.length();
    }
    for (int i = num.length() - 1; i >= 0; i--) {
      int pDigit = pivot.charAt(i) - '0';
      int nDigit = num.charAt(i) - '0';
      if (nDigit > pDigit) {
        return false;
      }
    }
    return true;
  }

  private void swap(String[] nums, int first, int second) {
    if (first == second) {
      return;
    }
    String temp = nums[first];
    nums[first] = nums[second];
    nums[second] = temp;
  }

  public static void main(String[] args) {
    String answer = new Solution1().kthLargestNumber(new String[]{"3", "6", "7", "10"}, 4);
    System.out.println(answer);
  }
}
