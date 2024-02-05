package leetcode.java.slidingwindow.longestsubstringwithatmostkdistinctcharacters;

import java.util.HashMap;
import java.util.Map;

public class Solution1 {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character, Integer> frequency = new HashMap<>();
        int low = 0, high = 0;
        int maxSize = 0;
        while (high < s.length()) {
            frequency.merge(s.charAt(high), 1, Integer::sum);
            while (frequency.size() > k) {
                int count = frequency.get(s.charAt(low));
                if (count == 1) {
                    frequency.remove(s.charAt(low));
                } else {
                    frequency.put(s.charAt(low), count - 1);
                }
                low++;
            }
            maxSize = Math.max(maxSize, high - low + 1);
            high++;
        }
        return maxSize;
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().lengthOfLongestSubstringKDistinct("eceba", 2));
    }
}

