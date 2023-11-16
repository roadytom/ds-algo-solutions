package algoexpert.medium.threenumbersort.sol2;

import java.util.Arrays;
import java.util.Random;
import java.util.stream.IntStream;

public class Program {
    public int[] threeNumberSort(int[] array, int[] order) {
        int first = 0;
        int second = 0;
        int third = 0;
        for (int j : array) {
            if (order[0] == j) {
                swap(second, third, array);
                swap(first, second, array);
                first++;
                second++;
                third++;
            } else if (order[1] == j) {
                swap(second++, third++, array);
            } else {
                third++;
            }
        }
        return array;
    }

    private void swap(int first, int second, int[] array) {
        int temp = array[first];
        array[first] = array[second];
        array[second] = temp;
    }

    public static void main(String[] args) {
        for (int test = 0; test < 100; test++) {
            int[] order = new int[3];
            Random random = new Random();
            for (int i = 0; i < 3; i++) {
                order[i] = random.nextInt(10);
            }
            int length = random.nextInt(20);
            int[] array = IntStream.range(0, length).map(i -> {
                int num = random.nextInt(3);
                return order[num];
            }).toArray();
            System.out.println(Arrays.toString(array) + ", " + Arrays.toString(order));
            int[] arrayCopy = Arrays.copyOf(array, length);
            new Program().threeNumberSort(array, order);
            System.out.println("After sort: \n" + Arrays.toString(array));
            new algoexpert.medium.threenumbersort.sol1.Program().threeNumberSort(arrayCopy, order);
            if (!Arrays.equals(arrayCopy, array)) {
                throw null;
            }
        }

        System.out.println("WORKING!");
    }
}
