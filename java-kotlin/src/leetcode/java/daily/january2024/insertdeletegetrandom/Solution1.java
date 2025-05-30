package leetcode.java.daily.january2024.insertdeletegetrandom;

import java.util.*;

public class Solution1 {
  static class RandomizedSet {
    Map<Integer, Integer> map;
    List<Integer> list;
    Random random;


    public RandomizedSet() {
      map = new HashMap<>();
      list = new ArrayList<>();
      random = new Random();
    }

    public boolean insert(int val) {
      if (map.containsKey(val)) {
        return false;
      }
      list.add(val);
      map.put(val, list.size() - 1);
      return true;
    }

    public boolean remove(int val) {
      if (!map.containsKey(val)) {
        return false;
      }
      int lastElement = list.get(list.size() - 1);
      int removedIndex = map.remove(val);
      swapWithLast(removedIndex);
      map.put(lastElement, removedIndex);
      return true;
    }

    private void swapWithLast(int index) {
      var temp = list.get(index);
      list.set(index, list.get(list.size() - 1));
      list.set(list.size() - 1, temp);
    }

    public int getRandom() {
      var randomIndex = random.nextInt(list.size());
      return list.get(randomIndex);
    }
  }
}
