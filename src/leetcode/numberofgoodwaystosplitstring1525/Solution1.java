package leetcode.numberofgoodwaystosplitstring1525;

import java.util.HashMap;

public class Solution1 {
  public int numSplits(String s) {
    HashMap<Character, Integer> rightMap = new HashMap<>();
    for (int i = s.length() - 1; i >= 0; i--) {
      char c = s.charAt(i);
      rightMap.merge(c, 1, Integer::sum);
    }
    HashMap<Character, Integer> leftMap = new HashMap<>();
    int answer = 0;
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      rightMap.computeIfPresent(c, (key, value) -> {
        value--;
        if (value == 0) {
          return null;
        } else
          return value;
      });

      if (leftMap.containsKey(c)) {
        leftMap.merge(c, 1, Integer::sum);
      } else {
        leftMap.put(c, 1);
      }
      if (leftMap.size() == rightMap.size()) {
        answer++;
      }
    }
    return answer;
  }

  public static void main(String[] args) {
    System.out.println(new Solution1().numSplits("abcd"));
  }
}
