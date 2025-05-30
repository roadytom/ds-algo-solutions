package leetcode.java.util;

public class BitSet {
  int bitSet = 0;


  public int size() {
    int count = 0;
    int currBitset = bitSet;
    while (currBitset != 0) {
      if ((currBitset & 1) != 0) {
        count++;
      }
      currBitset = currBitset >> 1;
    }
    return count;
  }

  /**
   * Brian Kernighan’s algorithm
   * flip rightmost bit and remove,
   * count removed characters until zero
   */
  public int sizeBrian() {
    int iterate = bitSet;
    int count = 0;
    while (iterate != 0) {
      iterate = iterate & (iterate - 1);
      count++;
    }
    return count;
  }

  public boolean contains(int n) {
    return (bitSet & (1 << n)) != 0;
  }

  public boolean contains(char c) {
    int n = c - 'a';
    return (bitSet & (1 << n)) != 0;
  }

  public void add(int n) {
    bitSet = bitSet | (1 << n);
  }

  public void add(char c) {
    int n = c - 'a';
    bitSet = bitSet | (1 << n);
  }

  public void remove(int n) {
    bitSet = bitSet ^ (1 << n);
  }

  public void remove(char c) {
    int n = c - 'a';
    bitSet = bitSet ^ (1 << n);
  }
}
