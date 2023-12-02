package leetcode.java.greatestcommondivisorofstrings1071;

public class Solution1 {
  public static void main(String[] args) {
    System.out.println(new Solution1().gcdOfStrings("AA", "A"));
  }

  public String gcdOfStrings(String str1, String str2) {
    int gcd = 1;
    int firstLen = str1.length();
    int secondLen = str2.length();
    for (int i = 2; i <= firstLen && i <= secondLen; i++) {
      if (firstLen % i == 0 && secondLen % i == 0) {
        gcd = i;
      }
    }
    if (!str1.substring(0, gcd).equals(str2.substring(0, gcd))) {
      return "";
    }
    if (isDivisible(str1, gcd) && isDivisible(str2, gcd)) {
      return str1.substring(0, gcd);
    }
    return "";
  }

  private boolean isDivisible(String str, int gcd) {
    for (int i = 0; i < gcd; i++) {
      char c = str.charAt(i);
      for (int j = i; j < str.length(); j += gcd) {
        if (c != str.charAt(j)) {
          return false;
        }
      }
    }
    return true;
  }
}
