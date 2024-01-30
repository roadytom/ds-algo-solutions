package leetcode.java.daily.blind.day1;

import java.util.*;

/**
 * Run-length encoding is a string compression
 * method that works by replacing consecutive
 * identical characters (repeated 2 or more times)
 * with the concatenation of the character and the
 * number marking the count of the characters (length
 * of the run). For example, to compress the string "aabccc"
 * we replace "aa" by "a2" and replace "ccc" by "c3".
 * Thus, the compressed string becomes "a2bc3".
 * Notice that in this problem, we are not adding '1'
 * after single characters.
 * Given a string s and an integer k. You need to
 * delete at most k characters from s such that the
 * run-length encoded version of s has minimum length.
 * EXAMPLE:
 * aaabcccd, k = 2
 */
public class Solution1 {
    private record Key(int index, int k, char lastChar, int lastCharCount) {
    }

    Map<Key, Integer> memo = new HashMap<>();
    Set<Integer> INCREASE_LENGTH_COUNT = Set.of(2, 10, 100, 1000);

    public int getLengthOfOptimalCompression(String s, int k) {
        if (s.isEmpty()) {
            return 0;
        }
        return dp(s, k, 0, ' ', 0, memo);
    }

    private int dp(String str, int k, int index, char lastChar, int lastCharCount, Map<Key, Integer> memo) {
        Key key = new Key(index, k, lastChar, lastCharCount);
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        if (index == str.length()) {
            return 0;
        }
        int deleteChar = Integer.MAX_VALUE;
        if (k > 0) {
            deleteChar = dp(str, k - 1, index + 1, lastChar, lastCharCount, memo);
        }

        // deleting curr character
        int keepChar;
        if (lastChar == str.charAt(index)) {
            keepChar = dp(str, k, index + 1, lastChar, lastCharCount + 1, memo) + (INCREASE_LENGTH_COUNT.contains(lastCharCount + 1) ? 1 : 0);
        } else {
            keepChar = dp(str, k, index + 1, str.charAt(index), 1, memo) + 1;
        }
        int minChar = Math.min(keepChar, deleteChar);
        memo.put(key, minChar);
        return minChar;
    }


    public static void main(String[] args) {
        System.out.println(new Solution1().getLengthOfOptimalCompression("aaabcccd", 2));
    }
}
