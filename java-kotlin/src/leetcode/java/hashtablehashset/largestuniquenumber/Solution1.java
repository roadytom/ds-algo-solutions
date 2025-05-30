package leetcode.java.hashtablehashset.largestuniquenumber;

import java.util.HashMap;
import java.util.Map;

public class Solution1 {
  public int largestUniqueNumber(int[] nums) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int num : nums) {
      map.merge(num, 1, Integer::sum);
    }
    return map.entrySet().stream().filter(entry -> entry.getValue() == 1)
        .map(Map.Entry::getKey)
        .max(Integer::compare)
        .orElse(-1);
  }
}
