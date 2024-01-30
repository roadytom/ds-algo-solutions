package leetcode.java.daily.january2024.longestcommonsubsequence;

import java.util.Arrays;

/**
 * SPACE OPTIMIZED DP, ITERATIVE, BOTTOM UP
 */
public class Solution3 {
  public int longestCommonSubsequence(String text1, String text2) {
    int m = text1.length(), n = text2.length();
    int[] prev = new int[n + 1];
    int[] curr = new int[n + 1];
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
          curr[j] = prev[j - 1] + 1;
        } else {
          curr[j] = Math.max(curr[j - 1], prev[j]);
        }
      }
      System.out.println(Arrays.toString(curr));
      prev = curr;
      curr = new int[n + 1];
    }
    return prev[n];
  }

  public static void main(String[] args) {
    System.out.println(new Solution3().longestCommonSubsequence("abcba", "abcbcba"));
  }
}
