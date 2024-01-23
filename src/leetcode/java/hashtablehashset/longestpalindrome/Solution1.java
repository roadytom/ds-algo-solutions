package leetcode.java.hashtablehashset.longestpalindrome;

import java.util.HashMap;

public class Solution1 {
  public int longestPalindrome(String s) {
    var counter = new HashMap<Character, Integer>();
    for (var c : s.toCharArray()) {
      counter.merge(c, 1, Integer::sum);
    }
    boolean evenExists = false;
    var count = 0;
    for (var entry : counter.entrySet()) {
      if (entry.getValue() % 2 == 1) {
        evenExists = true;
      }
      count += entry.getValue() - entry.getValue() % 2;
    }
    return count + (evenExists ? 1 : 0);
  }
}
