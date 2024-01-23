package leetcode.java.hashtablehashset.ransomnote;

import java.util.HashMap;

public class Solution1 {
  public boolean canConstruct(String ransomNote, String magazine) {
    var map = new HashMap<Character, Integer>();
    for (var c : ransomNote.toCharArray()) {
      map.merge(c, 1, Integer::sum);
    }
    for (var c : magazine.toCharArray()) {
      map.computeIfPresent(c, (key, value) -> value == 1 ? null : value - 1);
    }
    return map.isEmpty();
  }
}
