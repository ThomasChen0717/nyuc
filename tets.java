// Online Java Compiler
// Use this editor to write, compile and run your Java code online

import java.util.stream.*;
class HelloWorld {
    public static void main(String[] args) {
     String str = "kayak"; 
    boolean result = IntStream.range(0, str.length()) .anyMatch(i -> str.charAt(i) != str.charAt(str.length() - i - 1));
    System.out.println(result);
    }
}