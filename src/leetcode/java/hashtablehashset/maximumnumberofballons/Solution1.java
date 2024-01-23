package leetcode.java.hashtablehashset.maximumnumberofballons;

import java.util.HashMap;
import java.util.Map;

public class Solution1 {
  public int maxNumberOfBalloons(String text) {
    Map<Character, Integer> ballon = Map.of('b', 1, 'a', 1, 'l', 2, 'o', 2, 'n', 1);
    Map<Character, Integer> counter = new HashMap<>();
    for (char c : text.toCharArray()) {
      counter.merge(c, 1, Integer::sum);
    }
    var result = Integer.MAX_VALUE;
    for (var b : ballon.entrySet()) {
      var count = counter.getOrDefault(b.getKey(), 0);
      result = Math.min(result, count / b.getValue());
    }
    return result;
  }
}
