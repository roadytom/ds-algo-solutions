package algoexpert.medium.threenumbersort.sol1;

public class Program {
  public int[] threeNumberSort(int[] array, int[] order) {
    int firstNumCount = 0, secondNumCount = 0, thirdNumCount = 0;
    for (int num : array) {
      if (num == order[0]) {
        firstNumCount++;
      } else if (num == order[1]) {
        secondNumCount++;
      } else if (num == order[2]) {
        thirdNumCount++;
      } else {
        throw null;
      }
    }
    int start = 0;
    while (start < firstNumCount) {
      array[start++] = order[0];
    }
    while (start < firstNumCount + secondNumCount) {
      array[start++] = order[1];
    }
    while (start < firstNumCount + secondNumCount + thirdNumCount) {
      array[start++] = order[2];
    }
    return array;
  }
}
