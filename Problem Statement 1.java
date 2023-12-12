public class MathOperation {
    int integerValue;
    double doubleValue;
    String stringValue;

    public void printCalculatedSum(int number1, int number2) {
        int sum = number1 + number2;
        System.out.println("Sum: " + sum);
    }

    public void printStringIntoUppercase(String oldString) {
        String uppercaseString = oldString.toUpperCase();
        System.out.println("String: " + uppercaseString);
    }
}

public class MainProgram {
    public static void main(String[] args) {
        MathOperation mathOperation = new MathOperation();

        mathOperation.integerValue = 10;
        mathOperation.doubleValue = 20.5;
        mathOperation.stringValue = "hello";
        
        mathOperation.printCalculatedSum(mathOperation.integerValue, 5);

        mathOperation.printStringIntoUppercase("world");
    }
}
