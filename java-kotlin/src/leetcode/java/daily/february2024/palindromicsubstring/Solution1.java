package leetcode.java.daily.february2024.palindromicsubstring;

/**
 * DP TOP DOWN, RECURSION AND MEMOIZATION
 */
public class Solution1 {
    public int countSubstrings(String s) {
        int count = 0;
        Boolean[][] memo = new Boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (dp(i, j, s, memo)) {
                    count++;
                }
            }
        }
        return count;
    }

    private boolean dp(int i, int j, String string, Boolean[][] memo) {
        if (memo[i][j] != null) {
            return memo[i][j];
        }
        return memo[i][j] = string.charAt(i) == string.charAt(j) && (i == j || i + 1 == j || dp(i + 1, j - 1, string, memo));
    }
}
