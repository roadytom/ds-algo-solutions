import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;

public class Sample {
    private static final boolean outputToFile = false;
    private static final boolean inputFromFile = false;
    private static FastScanner fs;
    private static PrintWriter out;

    public static void main(String[] args) {
        fs = new FastScanner(inputFromFile);
        out = createPrintWriter();
        solve();
        out.close();
    }

    private static void solve() {

    }

    private static PrintWriter createPrintWriter() {
        PrintWriter out;
        if (!outputToFile) {
            out = new PrintWriter(System.out);
        } else {
            try {
                out = new PrintWriter(Path.of("src", "resources", "output.txt").toFile());
            } catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }
        }
        return out;
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
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(boolean inputFromFile) {
            if (inputFromFile) {
                try {
                    String fileName = "input.txt";
                    this.br = Files.newBufferedReader(Path.of("src", "resources", fileName));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else {
                this.br = new BufferedReader(new InputStreamReader(System.in));
            }
        }


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