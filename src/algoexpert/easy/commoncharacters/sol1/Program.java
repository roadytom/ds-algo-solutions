package algoexpert.easy.commoncharacters;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

/**
 * Time complexity: O (n * m) and Space complexity: O (n * m) in worst case;
 */
public class Program {
    public String[] commonCharacters(String[] strings) {
        if (strings.length == 0) {
            return new String[]{};
        }
        HashMap<Character, Integer> counter = new HashMap<>();
        for (String string : strings) {
            Set<Character> currSet = new HashSet<>();
            for (char c : string.toCharArray()) {
                if (!currSet.contains(c)) {
                    counter.merge(c, 1, Integer::sum);
                    currSet.add(c);
                }
            }
        }
        return counter.entrySet()
                .stream()
                .filter(entry -> entry.getValue() == strings.length)
                .map(entry -> String.valueOf(entry.getKey()))
                .toArray(String[]::new);
    }
}
