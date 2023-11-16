import java.util.*;
import java.io.*;
import javax.script.Bindings;
import javax.script.ScriptContext;
import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;

class SimpleSAT {

    public static String SimpleSAT(String str) {
        Set<Character> variablesSet = new HashSet<>();
        for (char c : str.toCharArray()) {
            if (Character.isLetter(c)) {
                variablesSet.add(c);
            }
        }
        int numberOfVariables = variablesSet.size();
        int permutations = 1 << numberOfVariables;
        boolean[][] valuesForAllCondition = new boolean[permutations][numberOfVariables];
        for (int possibleCase = 0; possibleCase < permutations; possibleCase++) {
            // numOfVariables = 2
            // possiblecase = 4
            // 00, 01, 10, 11
            for (int variable = 0; variable < numberOfVariables; variable++) {
                valuesForAllCondition[possibleCase][variable] = getBitInPosition(possibleCase, variable) == 1;
            }
        }
        for (boolean[] possibleCondition : valuesForAllCondition) {
            if (checkIfPossible(str, possibleCondition)) {
                return "yes";
            }
        }
        return "no";
    }

    private static int getBitInPosition(int number, int position) {
        // 101010 1 01
        // 000000 1 00 second postion bit
        return number & (1 << position);
    }

    private static boolean checkIfPossible(String str, boolean[] possibleCondition) {
        StringBuilder expression = new StringBuilder();
        for (char c : str.toCharArray()) {
            if (Character.isLetter(c)) {
                // if it is letter then append true or false using current
                // condtion
                expression.append(possibleCondition[getIndex(c)]);
            } else {
                // change logical operator to Java operators
                if (c == '&') {
                    expression.append("&&");
                } else if (c == '|') {
                    expression.append("||");
                } else if (c == '~') {
                    expression.append("!");
                } else {
                    expression.append(c);
                }
            }
        }
        return evaluateUsingScriptManager(expression.toString());
    }

    private static boolean evaluateUsingScriptManager(String expression) {
        ScriptEngineManager manager = new ScriptEngineManager();
        ScriptEngine jsEngine = manager.getEngineByName("js");
        try {
            return Boolean.parseBoolean(String.valueOf(jsEngine.eval(expression)));
        } catch (Exception ex) {
            throw new RuntimeException("cannot evaluate expression");
        }
    }

    private static int getIndex(char letter) {
        return letter - 'a';
    }

    public static void main(String[] args) {
        System.out.println(Character.('a' + 1));
    }

}