package leetcode.java.daily.january2024.determineiftwostringsareclose;

import java.util.HashMap;

public class Solution1 {
  public boolean closeStrings(String word1, String word2) {
    var counter1 = new HashMap<Character, Integer>();
    var counter2 = new HashMap<Character, Integer>();
    for (var c : word1.toCharArray()) {
      counter1.merge(c, 1, Integer::sum);
    }
    for (var c : word2.toCharArray()) {
      counter2.merge(c, 1, Integer::sum);
    }
    for (var entry : counter1.entrySet()) {
      if (!counter2.containsKey(entry.getKey())) {
        return false;
      }
    }
    if (counter1.size() != counter2.size()) {
      return false;
    }
    var firstValues = counter1.values().stream().sorted().toList();
    var secondValues = counter2.values().stream().sorted().toList();
    return firstValues.equals(secondValues);
  }
}
