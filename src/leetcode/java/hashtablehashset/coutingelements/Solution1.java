package leetcode.java.hashtablehashset.coutingelements;

import java.util.HashSet;
import java.util.Set;

public class Solution1 {
  public int countElements(int[] arr) {
    int count = 0;
    Set<Integer> set = new HashSet<>();
    for (int num : arr) {
      set.add(num);
    }
    for (int num : arr) {
      if (set.contains(num + 1)) {
        count++;
      }
    }
    return count;
  }
}
