package leetcode.java.daily.february2024.sequentialdigits;

import java.util.ArrayList;
import java.util.List;

public class Solution1 {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> answer = new ArrayList<>();
        var minLength = length(low);
        var maxLength = length(high);
        for (int length = minLength; length <= maxLength; length++) {
            for (int i = 1; i <= 10 - length; i++) {
                int num = 0;
                for (int j = 0; j < length; j++) {
                    int digit = i + j;
                    num = 10 * num + digit;
                }
                if (num >= low && num <= high) {
                    answer.add(num);
                } else if (num > low) {
                    break;
                }
            }
        }
        return answer;
    }

    private int length(int num) {
        if (num == 0) {
            return 1;
        }
        int length = 0;
        while (num != 0) {
            num /= 10;
            length++;
        }
        return length;
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().sequentialDigits(1000, 13000));
    }
}
