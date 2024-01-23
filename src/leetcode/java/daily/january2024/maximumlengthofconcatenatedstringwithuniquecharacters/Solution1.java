package leetcode.java.daily.january2024.maximumlengthofconcatenatedstringwithuniquecharacters;

import leetcode.java.util.BitSet;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solution1 {
  int maxLength = 0;
  BitSet bitSet = new BitSet();

  public int maxLength(List<String> arr) {
    findMaxLength(arr, 0);
    return maxLength;
  }


  private void findMaxLength(List<String> arr, int index) {
    if (index == arr.size()) {
      maxLength = Math.max(maxLength, bitSet.sizeBrian());
      return;
    }
    String curr = arr.get(index);
    boolean possible = true;
    Set<Character> currChars = new HashSet<>();
    for (char c : curr.toCharArray()) {
      if (bitSet.contains(c) || currChars.contains(c)) {
        possible = false;
        break;
      }
      currChars.add(c);
    }
    if (possible) {
      for (char c : curr.toCharArray()) {
        bitSet.add(c);
      }
      findMaxLength(arr, index + 1);
      for (char c : curr.toCharArray()) {
        bitSet.remove(c);
      }
    }
    findMaxLength(arr, index + 1);
  }

  public static void main(String[] args) {
    Solution1 solution1 = new Solution1();
    System.out.println(solution1.maxLength(List.of("un", "iq", "qu")));
  }
}
