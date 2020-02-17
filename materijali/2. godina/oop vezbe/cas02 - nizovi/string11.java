public class string11 {
    // Razlika u brzini konkatenacije stringova koristeci
    // String < StringBuilder

    static int TEST_SIZE = 100000;

    public static void main(String[] args) {
        long timeStr, timeStrBuilder;

        long t = System.nanoTime();
        runStringTest();
        timeStr = System.nanoTime() - t;

        t = System.nanoTime();
        runStringBuilderTest();
        timeStrBuilder = System.nanoTime() - t;

        System.out.println("String: " + timeStr);
        System.out.println("StringBUilder: " + timeStrBuilder);
    }

    static void runStringTest(){
        String tmp = "";
        String word = "test";
        for (int i = 0; i < TEST_SIZE; i++) {
            tmp += word;
            if(i % 10 == 0)
                System.out.println("String: " + i);
        }
    }

    static void runStringBuilderTest(){
        StringBuilder sb = new StringBuilder();
        String word = "test";
        for (int i = 0; i < TEST_SIZE; i++) {
            sb.append(word);
            if(i % 10 == 0)
                System.out.println("isb: " + i);
        }
    }
}
