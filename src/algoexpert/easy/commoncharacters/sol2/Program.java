//package algoexpert.easy.commoncharacters.sol2;
//
//import java.util.HashMap;
//import java.util.HashSet;
//import java.util.Set;
//import java.util.stream.Collectors;
//
//public class Program {
//    public String[] commonCharacters(String[] strings) {
//        if (strings.length == 0) {
//            return new String[]{};
//        }
//        var oldSet = strings[0]
//                .chars()
//                .mapToObj(c -> (char) c)
//                .collect(Collectors.toSet());
//        for (String string : strings) {
//            Set<Character> newSet = new HashSet<>();
//            for (char c : string.toCharArray()) {
//                if (oldSet.contains(c)) {
//                    newSet.add(c);
//                }
//            }
//            oldSet = newSet;
//        }
//        return oldSet.stream().map(String::valueOf)
//                .toArray(String[]::new);
//    }
//}
