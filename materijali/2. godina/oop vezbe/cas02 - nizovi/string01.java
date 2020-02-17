public class string01 {
    public static void main(String[] args) {
        // String t = new String("tekst");
        String t = "hello world how are you today";
        ispisi("t", t);

        // String je klasni tip (ne poredimo sa ==)!
        // Stringove poredimo metodama equals ili equalsIgnoreCase

        String s = t + "?";
        ispisi("s", s);
        if(s.equals(t))
            System.out.println("s == t");
        else
            System.out.println("s != t");

        String s1 = "Hello world how are you TODAY" + "?";
        ispisi("s1", s1);
        if(s1.equals(s))
            System.out.println("s1 == s");
        else
            System.out.println("s1 != s");

        if(s1.equalsIgnoreCase(s))
            System.out.println("s1 == s");
        else
            System.out.println("s1 != s");

        // Leksikografsko poredjenje stringova
        int i = s.compareTo(s1);
        if(i == 0)
            System.out.println("s1 == s");
        else if(i < 0)
            System.out.println("s1 > s");
        else
            System.out.println("s1 < s");

        // Ako postoji vise istih Stringovnih konstanti, nece
        // se praviti zasebni objekti, vec ce postojati samo 1,
        // Zbog toga == za njih vraca true

        String s2 = "hello world how are you today";
        ispisi("s2", s2);
        if(s2 == t)
            System.out.println("s2 i t su isti string");
        else if(t.equals(s2))
            System.out.println("t == s2");
        else
            System.out.println("t != s2");
    }

    static void ispisi(String name, String value){
        System.out.println(name + " = \"" + value + "\"");
    }
}
