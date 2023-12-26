public class AreaPrinter {
    public static void printArea(Rectangle rectangle) {
        double area = AreaCalculator.calculateArea(rectangle);
        System.out.println("Area: " + area);
    }
}