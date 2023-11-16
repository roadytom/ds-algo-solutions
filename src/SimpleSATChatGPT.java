import javax.script.*;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class SimpleSATChatGPT {
    public static String simpleSAT(String expression) {
        // Define a set to store unique variables
        Set<Character> variables = new HashSet<>();
        // Initialize the variables set
        for (char c : expression.toCharArray()) {
            if (Character.isLetter(c)) {
                variables.add(c);
            }
        }

        // Generate all possible assignments of TRUE and FALSE to variables
        int numVariables = variables.size();
        int numAssignments = 1 << numVariables;
        boolean[][] assignments = new boolean[numAssignments][numVariables];

        for (int i = 0; i < numAssignments; i++) {
            for (int j = 0; j < numVariables; j++) {
                assignments[i][j] = (i & (1 << j)) != 0;
            }
        }

        // Check if any assignment makes the expression true
        for (boolean[] assignment : assignments) {
            if (evaluateExpression(expression, variables, assignment)) {
                return "yes";
            }
        }

        return "no";
    }

    private static boolean evaluateExpression(String expression, Set<Character> variables, boolean[] assignment) {
        StringBuilder updatedExpression = new StringBuilder();
        for (char c : expression.toCharArray()) {
            if (Character.isLetter(c)) {
//                int index = variables.indexOf(c);
//                updatedExpression.append(assignment[index]);
            } else {
                updatedExpression.append(c);
            }
        }

        // Replace logical operators with Java's operators
        updatedExpression = new StringBuilder(updatedExpression.toString().replace("&", "&&").replace("|", "||").replace("~", "!"));

        try {
            // Evaluate the expression using Java's Boolean logic

//            return Boolean.parseBoolean(String.valueOf(eval(updatedExpression.toString())));
        } catch (Exception e) {
            return false;
        }
        return false;
    }

    private static boolean eval(String expression) {
//        ScriptEngineManager scriptEngineManager = new ScriptEngineManager(null);
//        ScriptEngine engine = scriptEngineManager.getEngineByName("JavaScript");
//        try {
//            return (boolean) engine.eval("true&&false");
//        } catch (ScriptException e) {
//            throw new RuntimeException(e);
//        }
        ScriptEngineManager sem = new ScriptEngineManager();
        List<ScriptEngineFactory> factories = sem.getEngineFactories();
        for (ScriptEngineFactory factory : factories)
            System.out.println(factory.getEngineName() + " " + factory.getEngineVersion() + " " + factory.getNames());
        if (factories.isEmpty()) System.out.println("No Script Engines found");
        return false;
    }

    public static void main(String[] args) {
//        System.out.println(simpleSAT("(a&b)|c"));        // Output: "yes"
//        System.out.println(simpleSAT("((a&c)&~a)"));     // Output: "no"
//        System.out.println(simpleSAT("(a&b&c)|~a"));    // Output: "yes"
//        System.out.println(simpleSAT("a&(b|c)&~b&~c")); // Output: "no"

        System.out.println(eval(""));
    }
}

