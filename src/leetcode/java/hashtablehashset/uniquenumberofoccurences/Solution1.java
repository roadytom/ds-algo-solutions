package leetcode.java.hashtablehashset.uniquenumberofoccurences;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution1 {
  public boolean uniqueOccurrences(int[] arr) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int num : arr) {
      map.merge(num, 1, Integer::sum);
    }
    return map.values().size() == map.values().stream().distinct().count();
  }
}
