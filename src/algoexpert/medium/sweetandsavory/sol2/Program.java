package algoexpert.medium.sweetandsavory.sol2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.function.Function;

/**
 * Time Complexity: O(n * log(n) + m * log(n)) = O(N * log(n or m)
 * n and m positive and negative numbers
 * N = n + m all numbers;
 */
public class Program {
    public int[] sweetAndSavory(int[] dishes, int target) {
        int[] sweetDishes = Arrays.stream(dishes)
                .filter(flavor -> flavor < 0)
                .sorted()
                .toArray();
        int[] savoryDishes = Arrays.stream(dishes)
                .filter(flavor -> flavor >= 0)
                .sorted()
                .toArray();
        int sweetPointer = 0;
        int savoryPointer = savoryDishes.length - 1;
        int[] ans = new int[]{0, 0};
        int bestDiff = Integer.MAX_VALUE;
        while (sweetPointer < sweetDishes.length && savoryPointer >= 0) {
            int currDiff = target - sweetDishes[sweetPointer] - savoryDishes[savoryPointer];
            if (currDiff >= 0) {
                if (bestDiff > currDiff) {
                    ans = new int[]{sweetDishes[sweetPointer], savoryDishes[savoryPointer]};
                    bestDiff = currDiff;
                }
                sweetPointer++;
            } else {
                savoryPointer--;
            }
        }
        return ans;
    }


    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        Program program = new Program();
        out.println(Arrays.toString(program.sweetAndSavory(new int[]{2, 5, -4, -7, 12, 100, -25}, 7)));
        out.close();
    }

    static final Random random = new Random();
    static final int mod = 1_000_000_007;

    static void ruffleSort(int[] a) {
        int n = a.length;//shuffle, then sort
        for (int i = 0; i < n; i++) {
            int oi = random.nextInt(n), temp = a[oi];
            a[oi] = a[i];
            a[i] = temp;
        }
        Arrays.sort(a);
    }

    static long add(long a, long b) {
        return (a + b) % mod;
    }

    static long sub(long a, long b) {
        return ((a - b) % mod + mod) % mod;
    }

    static long mul(long a, long b) {
        return (a * b) % mod;
    }

    static long exp(long base, long exp) {
        if (exp == 0) return 1;
        long half = exp(base, exp / 2);
        if (exp % 2 == 0) return mul(half, half);
        return mul(half, mul(half, base));
    }

    static long[] factorials = new long[2_000_001];
    static long[] invFactorials = new long[2_000_001];

    static void precompFacts() {
        factorials[0] = invFactorials[0] = 1;
        for (int i = 1; i < factorials.length; i++) factorials[i] = mul(factorials[i - 1], i);
        invFactorials[factorials.length - 1] = exp(factorials[factorials.length - 1], mod - 2);
        for (int i = invFactorials.length - 2; i >= 0; i--)
            invFactorials[i] = mul(invFactorials[i + 1], i + 1);
    }

    static long nCk(int n, int k) {
        return mul(factorials[n], mul(invFactorials[k], invFactorials[n - k]));
    }

    static void sort(int[] a) {
        ArrayList<Integer> l = new ArrayList<>();
        for (int i : a) l.add(i);
        Collections.sort(l);
        for (int i = 0; i < a.length; i++) a[i] = l.get(i);
    }


    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens()) try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long[] readLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}