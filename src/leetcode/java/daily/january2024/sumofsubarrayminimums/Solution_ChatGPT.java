package leetcode.java.daily.january2024.sumofsubarrayminimums;

import java.util.ArrayList;
import java.util.List;

public class Solution_ChatGPT {
  private static final int P = 1000000007;

  public int sumSubarrayMins(List<Integer> arr) {
    List<Long> tmp = new ArrayList<>(arr.size());
    for (int num : arr) {
      tmp.add((long) num);
    }
    return (int) f(tmp, 0, tmp.size());
  }

  private long f(List<Long> arr, int l, int r) {
    if (r == l + 1) {
      return arr.get(l);
    }
    int m = (l + r) / 2;
    long ans = f(arr, l, m) + f(arr, m, r);
    System.out.println(l + " " + r);
    long lptr = 1, lmin = arr.get(m - 1);
    long rptr = 1, rmin = arr.get(m);
    ans += Math.min(lmin, rmin);
    while (m + rptr < r || m - lptr - 1 >= l) {
      long lval = 0;
      if (m - lptr - 1 >= l) {
        lval = Math.min(lmin, arr.get((int) (m - lptr - 1)));
      }

      long rval = 0;
      if (m + rptr < r) {
        rval = Math.min(rmin, arr.get((int) (m + rptr)));
      }

      if (lval > rval) {
        System.out.println(lval + " > " + rval);
        System.out.println("lmin: " + lmin + "\nrmin: " + rmin);
        System.out.println("ans += " + Math.min(lval, rmin) + " * " + rptr);
        ans += Math.min(lval, rmin) * rptr;
        ++lptr;
        lmin = lval;
      } else {
        System.out.println(lval + " < " + rval);
        System.out.println("lmin: " + lmin + "\nrmin: " + rmin);
        System.out.println("ans += " + Math.min(rval, lmin) + " * " + lptr);
        ans += Math.min(rval, lmin) * lptr;
        ++rptr;
        rmin = rval;
      }
      ans %= P;
    }

    return ans;
  }

  public static void main(String[] args) {
    Solution_ChatGPT solution = new Solution_ChatGPT();
    List<Integer> arr = List.of(5, 1, 2, 3, 1, 2, 5, 4, 10);
    System.out.println(solution.sumSubarrayMins(arr)); // Output: 17
  }
}

