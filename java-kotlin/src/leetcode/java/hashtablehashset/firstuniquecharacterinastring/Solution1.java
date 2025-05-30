package leetcode.java.hashtablehashset.firstuniquecharacterinastring;

import java.util.HashMap;
import java.util.Map;

public class Solution1 {
  public int firstUniqChar(String s) {
    Map<Character, Integer> hashMap = new HashMap<>();
    for (char c : s.toCharArray()) {
      hashMap.merge(c, 1, Integer::sum);
    }
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (hashMap.get(c) == 1) {
        return i;
      }
    }
    return -1;
  }
}
