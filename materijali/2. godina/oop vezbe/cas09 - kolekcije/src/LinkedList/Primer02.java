package LinkedList;

import java.util.Iterator;
import java.util.LinkedList;

public class Primer02 {

    public static void main(String[] args) {

        LinkedList<String> imena = new LinkedList<>();

        imena.add("Zdravo");
        imena.add("svete");
        imena.add("kako");
        imena.add("si");
        imena.add("?");

        // kroz listu mozemo iterirati koristeci iterator
        Iterator<String> it = imena.iterator();
        while(it.hasNext()){
            String e = it.next();
            System.out.println(e);
        }
    }
}
