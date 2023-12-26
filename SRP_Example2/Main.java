public class Main {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle(5.0, 3.0);

        // Calculate area
        double area = AreaCalculator.calculateArea(rectangle);
        System.out.println("Calculated Area: " + area);

        // Save area to a file
        FileWriterUtil.writeToFile("area.txt", "Area: " + area);
    }
}
