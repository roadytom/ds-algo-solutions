package dailycodingproblems.arrays.getproductofallotherelements1;

import java.util.Arrays;
import java.util.stream.IntStream;

public class Solution2 {
  public static void main(String[] args) {

    assert Arrays.equals(new int[]{120,
        60, 40, 30, 24}, product(new int[]{1, 2, 3, 4, 5}));

  }

  public static int[] product(int[] arr) {
    /**
     * 1,2,3,4,5
     * 1,1,2,6,24
     * 120,60,20,5,1
     */
    final int N = arr.length;
    int[] rightToLeft = new int[N];
    int[] lefToRight = new int[N];
    lefToRight[0] = 1;
    for (int i = 0; i < N - 1; i++) {
      lefToRight[i + 1] = lefToRight[i] * arr[i];
    }
    lefToRight[N - 1] = 1;
    for (int i = N - 1; i > 0; i--) {
      rightToLeft[i - 1] = rightToLeft[i] * arr[i];
    }
    return IntStream.range(0, N)
        .map(i -> rightToLeft[i] * lefToRight[i])
        .toArray();
  }
}
