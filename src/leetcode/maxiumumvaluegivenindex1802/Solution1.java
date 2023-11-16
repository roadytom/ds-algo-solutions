package leetcode.maxiumumvaluegivenindex1802;

import java.util.Optional;

public class Solution1 {
    public int maxValue(int n, int index, int maxSum) {
        int left = 1;
        int right = maxSum;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            int leftSum = sumOfProgression(mid - 1, index);
            int rightSum = sumOfProgression(mid, n - index);
            if (leftSum + rightSum <= maxSum) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left != 0 ? (left - 1) : 0;
    }

    public int sumOfProgression(int endValue, int n) {
        if (n <= 0) return 0;
        int startValue = endValue - n + 1;
        if (startValue <= 0) {
            return (1 + endValue) * endValue / 2 - startValue + 1;
        } else {
            return (startValue + endValue) * n / 2;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().maxValue(4, 2, 6));
        System.out.println(new Solution1().maxValue(6, 1, 10));
        System.out.println(new Solution1().maxValue(3, 2, 18));
        System.out.println(new Solution1().maxValue(4, 0, 4));
        System.out.println(new Solution1().maxValue(4, 3, 4));

    }
}