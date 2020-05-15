public class TestFajlSistem {

    public static void main(String[] args) {
        Datoteka datoteka = new Datoteka("mojfajl.txt", "-rwxr-xr-x", "lorem ipsum");
        Direktorijum direktorijum1 = new Direktorijum("dir1", "drwxr-xr-x");

        ElementFajlSistema[] elementi = {direktorijum1, datoteka};
        Direktorijum direktorijum2 = new Direktorijum("dir2", "drwxr-xr-x", elementi);

        ElementFajlSistema[] elem = {datoteka, direktorijum1, direktorijum2};
        for (ElementFajlSistema e: elem) {
            System.out.println(e);
            e.ispisiSadrzaj();
            System.out.println("--------------------------");
        }
    }
}
