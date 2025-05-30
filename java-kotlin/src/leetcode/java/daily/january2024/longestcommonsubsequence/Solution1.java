package leetcode.java.daily.january2024.longestcommonsubsequence;

import java.util.Arrays;

/**
 * DP: top down recursive
 */
public class Solution1 {
  public int longestCommonSubsequence(String text1, String text2) {
    int[][] memo = new int[text1.length()][text2.length()];
    for (int[] m : memo) {
      Arrays.fill(m, -1);
    }
    return findLongestCommonSubsequence(text1, text2, 0, 0, memo);
  }

  private int findLongestCommonSubsequence(String text1, String text2, int f, int s, int[][] memo) {
    if (f == text1.length() || s == text2.length()) {
      return 0;
    }
    if (memo[f][s] != -1) {
      return memo[f][s];
    }
    if (text1.charAt(f) == text2.charAt(s)) {
      return memo[f][s] = findLongestCommonSubsequence(text1, text2, f + 1, s + 1, memo) + 1;
    }
    return memo[f][s] = Math.max(findLongestCommonSubsequence(text1, text2, f + 1, s, memo), findLongestCommonSubsequence(text1, text2, f, s + 1, memo));
  }
}
