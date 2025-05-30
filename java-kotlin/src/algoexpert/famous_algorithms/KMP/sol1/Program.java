package algoexpert.famous_algorithms.KMP.sol1;

import java.util.Arrays;

class Program {
  public static boolean kmp(String string,
                            String substring) {
    int[] lcp = lcp_optimal(substring);
    int i = 0, j = 0;
    while (i < string.length()) {
      if (string.charAt(i) == substring.charAt(j)) {
        i++;
        j++;
        if (j == substring.length()) {
          return true;
        }
      } else if (j > 0) {
        j = lcp[j - 1];
      } else {
        i++;
      }
    }
    return false;
  }

  public static boolean kmp2(String string,
                             String substring) {
    int[] lcp = lcp_optimal(substring);
    int j = 0;
    for (int i = 0; i < string.length(); i++) {
      while (j > 0 && string.charAt(i) != substring.charAt(j)) {
        j = lcp[j - 1];
      }
      if (string.charAt(i) == substring.charAt(j)) {
        j++;
      }
      if (j == substring.length())
        return true;
    }
    return false;
  }

  private static int[] lcp_optimal(String str) {
    char[] ch = str.toCharArray();
    int[] lcp = new int[str.length()];
    for (int i = 1; i < str.length(); i++) {
      int possibleLength = lcp[i - 1];
      while (possibleLength > 0 && ch[possibleLength] != ch[i]) {
        possibleLength = lcp[possibleLength - 1];
      }
      if (ch[possibleLength] == ch[i]) {
        lcp[i] = possibleLength + 1;
      }
      // else lcp[i] is zero
    }
    return lcp;
  }

  // trivial algorithm
  // O(n^3)
  private static int[] lcp_bad(String str) {
    int[] lcp = new int[str.length()];
    for (int i = 0; i < str.length(); i++)
      for (int k = 0; k <= i; k++)
        if (str.substring(0, k)
            .equals(str.substring(i - k + 1, i + 1)))
          lcp[i] = k;


    return lcp;
  }

  public static void main(String[] args) {
    System.out.println(Arrays.toString(lcp_bad("abcabcd")));
    System.out.println(Arrays.toString(lcp_bad("aabaaab")));
    System.out.println(Arrays.toString(lcp_optimal("abcabcd")));
    System.out.println(Arrays.toString(lcp_optimal("aabaaab")));
    System.out.println(kmp("AAAAABAAABA", "ABA"));
    System.out.println(kmp2("AAAAABAAABA", "ABA"));
  }
}
