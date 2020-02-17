import java.util.Scanner;

public class zadatak05 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        String word = sc.next();
        while(!word.equals("EXIT")){
            sb.append(word.toUpperCase() + "\n");
            word = sc.next();
        }
        System.out.print(sb);
    }
}
