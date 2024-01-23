package leetcode.java.hashtablehashset.longestsubstringwithoutrepeatingcharacters;

import java.util.HashMap;
import java.util.Map;

public class Solution1 {
  public int lengthOfLongestSubstring(String s) {
    Map<Character, Integer> charToValue = new HashMap<>();
    int maxLength = 0;
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (charToValue.containsKey(c) && charToValue.get(c) >= start) {
        int prevIndex = charToValue.get(c);
        start = prevIndex + 1;
      }
      charToValue.put(c, i);
      end = i;
      maxLength = Math.max(maxLength, end - start + 1);
    }
    return maxLength;
  }
  /**
   * a b b a
   */
}
