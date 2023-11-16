package dailycodingproblems.arrays.getproductofallotherelements1;

import java.util.Arrays;

public class Solution1 {
    public static void main(String[] args) {
        assert Arrays.equals(new int[]{120,
                60, 40, 30, 24}, product(new int[]{1, 2, 3, 4, 5}));
        
    }

    public static int[] product(int[] arr) {
        int productOfAll = Arrays.stream(arr).reduce(1, (a, b) -> a * b);
        assert productOfAll != 0 : "cannot be zero value inside array";
        return Arrays.stream(arr).map(x -> productOfAll / x).toArray();
    }
}
