package takeuforward.dp.dppattern.palindromepartitioning.II;

import java.util.Arrays;

/**
 * a a b
 * x x x x x | x x x x x x
 */
public class Solution1 {
    public int minCut(String s) {
        final int n = s.length();
        int[] memo = new int[n];
        Arrays.fill(memo, -1);
        Boolean[][] palindromeMemo = new Boolean[n][n];
        return cutCount(0, s, memo, palindromeMemo);
    }

    public int cutCount(int start, String str, int[] memo, Boolean[][] palindromeMemo) {
        if (start == str.length()) {
            return 0;
        }
        if (memo[start] != -1) {
            return memo[start];
        }
        int minCut = Integer.MAX_VALUE;
        for (int cut = start; cut < str.length(); cut++) {
            if (isPalindrome(start, cut, str, palindromeMemo)) {
                minCut = Math.min(minCut, cutCount(cut + 1, str, memo, palindromeMemo) + ((cut == str.length() - 1) ? 0 : 1));
            }
        }
        return memo[start] = minCut;
    }

    private boolean isPalindrome(int l, int r, String str, Boolean[][] palindromeMemo) {
        if (palindromeMemo[l][r] != null) {
            return palindromeMemo[l][r];
        }
        boolean equal = str.charAt(l) == str.charAt(r);
        if (l == r || l + 1 == r) {
            return palindromeMemo[l][r] = equal;
        }
        return palindromeMemo[l][r] = equal && palindromeMemo[l + 1][r - 1];
    }
}
