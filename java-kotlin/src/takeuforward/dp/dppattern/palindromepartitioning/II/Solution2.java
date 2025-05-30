package takeuforward.dp.dppattern.palindromepartitioning.II;

import java.util.Arrays;

class Solution2 {
    public int minCut(String str) {
        final int n = str.length();
        int[] dp = new int[n + 1];
        boolean[][] dpPalindrome = new boolean[n + 1][n + 1];
        for (boolean[] row : dpPalindrome) {
            Arrays.fill(row, true);
        }
        for (int start = n - 1; start >= 0; start--) {
            int minCut = Integer.MAX_VALUE;
            for (int cut = start; cut < str.length(); cut++) {
                boolean equal = str.charAt(start) == str.charAt(cut);
                if (start == cut || start + 1 == cut) {
                    dpPalindrome[start][cut + 1] = equal;
                }
                dpPalindrome[start][cut + 1] = equal && dpPalindrome[start + 1][cut];
                if (dpPalindrome[start][cut + 1]) {
                    minCut = Math.min(minCut, dp[cut + 1] + ((cut == str.length() - 1) ? 0 : 1));
                }
            }
            dp[start] = minCut;
        }
        return dp[0];
    }

    public static void main(String[] args) {
        System.out.println(new Solution2().minCut("aab"));
    }
}
