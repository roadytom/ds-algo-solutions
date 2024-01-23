package leetcode.java.daily.january2024.findplayerswithzerooronelosses;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution1 {
  public List<List<Integer>> findWinners(int[][] matches) {
    Map<Integer, Integer> counter = new HashMap<>();
    for (int[] match : matches) {
      int winner = match[0];
      int loser = match[1];
      counter.merge(loser, 1, Integer::sum);
      counter.merge(winner, 0, Integer::sum);
    }
    return List.of(
        counter.entrySet().stream().filter(entry -> entry.getValue() == 0).map(Map.Entry::getKey).sorted().toList(),
        counter.entrySet().stream().filter(entry -> entry.getValue() == 1).map(Map.Entry::getKey).sorted().toList()
    );
  }
}
