package VisestrukiCatchIzuzeci;

public class primer01 {
    public static void main(String[] args) {
        try {
            testiranje(1);
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.err.println(e.getMessage());
        }
        catch (ArithmeticException e){
            System.err.println(e.getMessage());
        }
        catch (NullPointerException e){
            System.err.println(e.getMessage());
        }

        // Drugi nacin
        try {
            testiranje(1);
        }
        catch (ArrayIndexOutOfBoundsException | ArithmeticException | NullPointerException e){
            System.err.println(e.getMessage());
        }
    }

    public static void testiranje(int x) {
        if(x == 1)
            throw new ArrayIndexOutOfBoundsException("x = 1");
        else if(x == 2)
            throw new ArithmeticException("x = 2");
        else if(x == 3)
            throw new NullPointerException("x = 3");
    }
}
