package leetcode.java.daily.january2024.evaluatereversepolishnotation;

import java.util.ArrayDeque;
import java.util.Deque;

public class Solution1 {
    public int evalRPN(String[] tokens) {
        Deque<Integer> dq = new ArrayDeque<>();
        for (String token : tokens) {
            if (isDigit(token)) {
                dq.push(Integer.valueOf(token));
            } else {
                int second = dq.pop();
                int first = dq.pop();
                int calculatedResult = calculate(first, second, token.charAt(0));
                dq.push(calculatedResult);
            }
        }

        return dq.pop();
    }

    private int calculate(int first, int second, char token) {
        return switch (token) {
            case '+' -> first + second;
            case '-' -> first - second;
            case '/' -> first / second;
            case '*' -> first * second;
            default -> throw new IllegalArgumentException("unknown arithmetic expression");
        };
    }

    private boolean isDigit(String str) {
        for (char c : str.toCharArray()) {
            if (!Character.isDigit(c)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().evalRPN(new String[]{"2", "1", "+", "3", "*"}));
    }
}
