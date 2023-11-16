package interview;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Collections;
import java.util.function.BinaryOperator;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class FileReversing {


    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        usingStreamParallel();
        long end = System.currentTimeMillis();
        long elapsedTime = end - start;
        System.out.println(elapsedTime);
        start = System.currentTimeMillis();
        usingStreamSequential();
        end = System.currentTimeMillis();
        elapsedTime = end - start;
        System.out.println(elapsedTime);
        start = System.currentTimeMillis();
        reverseFileContent();
        end = System.currentTimeMillis();
        elapsedTime = end - start;
        System.out.println(elapsedTime);
    }

    public static void usingStreamParallel() {
        try (Stream<String> lines = Files.lines(Paths.get("src", "interview", "file.txt"))) {
            String file = lines.parallel()
                    .map(line -> {
                        String[] words = line.split(" ");
                        Collections.reverse(Arrays.asList(words));
                        return Arrays.stream(words).sequential().collect(Collectors.joining(" "));
                    })
                    .collect(Collectors.joining("\n"));
            System.out.println(file);
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public static void usingStreamSequential() {
        try (Stream<String> lines = Files.lines(Paths.get("src", "interview", "file.txt"))) {
            String file = lines
                    .map(line -> {
                        String[] words = line.split(" ");
                        Collections.reverse(Arrays.asList(words));
                        return Arrays.stream(words).sequential().collect(Collectors.joining(" "));
                    })
                    .collect(Collectors.joining("\n"));
            System.out.println(file);
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public static void reverseFileContent() {
        StringBuilder builder = new StringBuilder();
        try (Stream<String> lines = Files.lines(Paths.get("src", "interview", "file.txt"))) {
            StringBuilder stringBuilder = lines.map(line -> {
                        builder.setLength(0);
                        return builder.append(line).reverse().toString();
                    })
                    .reduce(new StringBuilder(), (acc, curr) -> {
                        acc.append(curr);
                        return acc;
                    }, (StringBuilder::append));
            System.out.println(stringBuilder.reverse().toString());
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
