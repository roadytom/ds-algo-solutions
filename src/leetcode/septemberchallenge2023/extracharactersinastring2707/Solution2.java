package leetcode.septemberchallenge2023.extracharactersinastring2707;

import java.util.Arrays;
import java.util.Objects;

public class Solution2 {
  public int minExtraChar(String s, String[] dictionary) {
    Trie head = buildTrie(dictionary);
    int[] dp = new int[s.length()];
    Arrays.fill(dp, Integer.MAX_VALUE);
    solve(0, s, dp, head, head, 0);
    System.out.println(Arrays.toString(dp));
    System.out.println(Arrays.toString(head.children));
    return dp[0];
  }

  private int solve(int currIdx, String s, int[] dp, Trie head, Trie current, int trieLevel) {
    if (currIdx == s.length()) {
      return (current.isEndOfWord) ? 0 : trieLevel;
    }
    if (currIdx == 4) {
      System.out.println();
    }

    char currChar = s.charAt(currIdx);

    // 3. path: end word and begin new
    int pathEnd;
    if (current.isEndOfWord) {
      pathEnd = solve(currIdx, s, dp, head, head, 0);
    } else {
      pathEnd = Integer.MAX_VALUE;
    }

    // 1. path: continuing current trie
    /**
     * d
     * l
     * r
     * o
     * w
     * head
     */
    int pathContinuing;
    boolean prev = current.isEndOfWord;
    current.isEndOfWord = false;
    if (current.children[currChar - 'a'] != null) {
      // exist just continue
      pathContinuing = solve(currIdx + 1, s, dp, head, current.children[currChar - 'a'], trieLevel + 1);
    } else {
      // remove and continue
      pathContinuing = solve(currIdx + 1, s, dp, head, current, trieLevel) + 1;
    }
    current.isEndOfWord = prev;
    // 2. path: beginning new trie
    int pathBeginning;
    if (head.children[currChar - 'a'] != null) {
      pathBeginning = solve(currIdx + 1, s, dp, head, head.children[currChar - 'a'], 1) + trieLevel;
    } else {
      pathBeginning = solve(currIdx + 1, s, dp, head, head, 0) + trieLevel + 1;
    }

    int possiblePath = Math.min(pathEnd, Math.min(pathBeginning, pathContinuing));
    dp[currIdx] = Math.min(dp[currIdx], possiblePath);
    return dp[currIdx];
  }


  private Trie buildTrie(String[] dictionary) {
    Trie head = new Trie();
    for (String word : dictionary) {
      Trie trie = head;
      for (char c : word.toCharArray()) {
        if (trie.children[c - 'a'] == null) {
          trie.children[c - 'a'] = new Trie();
        }
        trie = trie.children[c - 'a'];
      }
      trie.isEndOfWord = true;
    }
    return head;
  }

  static class Trie {
    Trie[] children = new Trie[26];
    boolean isEndOfWord;

    @Override
    public String toString() {
      return "Trie{" +
          "children=" + Arrays.stream(children).map(Objects::nonNull).toString() +
          ", isEndOfWord=" + isEndOfWord +
          '}';
    }
  }

  public static void main(String[] args) {
    Solution2 solution1 = new Solution2();
    System.out.println(solution1.minExtraChar("sayhelloworld",
        new String[]{
            "hello",
            "world"
        }));
  }
}
