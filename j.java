import java.util.Scanner;

public class j {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

            double start;
            double end;
            double step;

            System.out.print("Please enter start: ");
            start = scan.nextDouble();
            System.out.print("Please enter end: ");
            end = scan.nextDouble();
            System.out.print("Please enter step size: ");
            step = scan.nextDouble();

            while (start != end) {
                System.out.println(start);
                start += step;
            }
    }

}