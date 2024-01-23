package leetcode.java.stack.monostack.finalpricewithspecialdiscount;

/**
 * BRUTE FORCE SOLUTION
 * THE SAME AS NEXT SMALLER ELEMENT
 */
public class Solution1 {
  public int[] finalPrices(int[] prices) {
    int n = prices.length;
    int[] ans = new int[n];
    for (int i = 0; i < n; i++) {
      ans[i] = prices[i];
      for (int j = i + 1; j < n; j++) {
        if (prices[j] <= prices[i]) {
          ans[i] -= prices[j];
          break;
        }
      }
    }
    return ans;
  }
}
