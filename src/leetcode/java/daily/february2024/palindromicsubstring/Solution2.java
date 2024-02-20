package leetcode.java.daily.february2024.palindromicsubstring;

/**
 * EXPAND OVER MIDDLE
 */
public class Solution2 {
    public int countSubstrings(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count += countOverMiddle(i, i, s);
            count += countOverMiddle(i, i + 1, s);
        }
        return count;
    }

    private int countOverMiddle(int low, int high, String s) {
        int length = s.length();
        int ans = 0;
        while (low >= 0 && high < length) {
            if (s.charAt(low) == s.charAt(high)) {
                ans++;
            } else {
                break;
            }
            low--;
            high++;
        }
        return ans;
    }
}
