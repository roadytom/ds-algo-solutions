package dailycodingproblems.arrays.getproductofallotherelements1;

public class SolutionChatGPT {
  public int[] productExceptSelf(int[] nums) {
    int n = nums.length;

    // Initialize arrays to store left and right products.
    int[] leftProducts = new int[n];
    int[] rightProducts = new int[n];
    int[] result = new int[n];

    // Calculate left products.
    int leftProduct = 1;
    for (int i = 0; i < n; i++) {
      leftProducts[i] = leftProduct;
      leftProduct *= nums[i];
    }

    // Calculate right products.
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
      rightProducts[i] = rightProduct;
      rightProduct *= nums[i];
    }

    // Calculate the final result by multiplying left and right products.
    for (int i = 0; i < n; i++) {
      result[i] = leftProducts[i] * rightProducts[i];
    }

    return result;
  }
}
