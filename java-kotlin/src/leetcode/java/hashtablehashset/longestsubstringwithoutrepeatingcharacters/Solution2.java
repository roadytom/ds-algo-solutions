package leetcode.java.hashtablehashset.longestsubstringwithoutrepeatingcharacters;

import java.util.HashMap;
import java.util.Map;

/**
 * two pointer technique, the same time complexity
 * but little slower than Solution1
 */
public class Solution2 {
  public int lengthOfLongestSubstring(String s) {
    Map<Character, Integer> counter = new HashMap<>();
    int left = 0;
    int right = 0;
    int maxLength = 0;
    while (right < s.length()) {
      char c = s.charAt(right);
      counter.merge(c, 1, Integer::sum);
      while (counter.get(c) > 1) {
        counter.put(s.charAt(left), counter.get(s.charAt(left)) - 1);
        left++;
      }
      maxLength = Math.max(maxLength, right - left + 1);
      right++;
    }
    return maxLength;
  }
}
