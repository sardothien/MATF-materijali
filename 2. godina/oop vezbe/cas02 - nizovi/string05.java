public class string05 {

    public static void main(String[] args) {
        String t = "    hello world, how are you today ";
        ispisi("t", t);

        if(t.contains("hello world"))
            System.out.println("t sadrzi: \"hello world\"");
        else
            System.out.println("t ne sadrzi: \"hello world\"");

        ispisi("t.substring(17)", t.substring(17));
        ispisi("t.substring(10, 15)", t.substring(10, 15));

        prefiks(t, "hello");
        sufiks(t, "today");

        // uklanjamo vodece/zavrsne beline
        t = t.trim();
        prefiks(t, "hello");
        sufiks(t, "today");
    }

    static void ispisi(String name, String value){
        System.out.println(name + " = \"" + value + "\"");
    }

    static void prefiks(String t, String p){
        if(t.startsWith(p))
            System.out.println("Jeste prefiks");
        else
            System.out.println("Nije prefiks");
    }

    static void sufiks(String t, String s){
        if(t.endsWith(s))
            System.out.println("Jeste sufiks");
        else
            System.out.println("Nije sufiks");
    }
}
