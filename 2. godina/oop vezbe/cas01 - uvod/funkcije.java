public class funkcije {
    static int saberi(int x, int y){
        return x+y;
    }

    static void ispisi(int x, int y){
        System.out.printf("%d + %d = %d\n", x, y, saberi(x,y));
    }

    public static void main(String[] args) {
        int a = 20, b = 30;
        int c = saberi(a, b);

        System.out.println(c);
        System.out.println(a + " + " + b + " = " + c);
        System.out.println(a + " + " + b + " = " + (a+b));
        System.out.println(a + " + " + b + " = " + saberi(a,b));

        System.out.printf("%d + %d = %d\n", a, b, (a+b));
        System.out.format("%d + %d = %d\n", a, b, saberi(a,b));
        ispisi(a,b);
    }
}
