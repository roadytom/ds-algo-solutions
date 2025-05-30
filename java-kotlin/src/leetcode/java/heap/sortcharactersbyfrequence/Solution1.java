package leetcode.java.heap.sortcharactersbyfrequence;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collector;

public class Solution1 {
  public String frequencySort(String s) {
    Map<Character, Integer> freq = new HashMap<>();
    for (char c : s.toCharArray()) {
      freq.merge(c, 1, Integer::sum);
    }
    return freq.entrySet().stream().sorted((a, b) -> b.getValue() - a.getValue()).collect(Collector.of(StringBuilder::new, (b, e) -> {
      b.append(String.valueOf(e.getKey()).repeat(e.getValue()));
    }, StringBuilder::append)).toString();
  }
}
