import java.util.Scanner;

public class TestDosije {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        /*
        System.out.print("ime osobe: ");
        String ime = sc.next();
        System.out.print("prezime osobe: ");
        String prezime = sc.next();
        System.out.print("jmbg: ");
        String jmbg = sc.next();
        System.out.println();

        StringBuilder sb = new StringBuilder();
        sb.append(ime).append(" ").append(prezime);

        Dosije dosije = new Dosije(sb.toString(), jmbg);
        System.out.println(dosije); */

        System.out.println("Podaci o studentu:");
        System.out.println("--------------------------------");

        System.out.print("Ime_Prezime: ");
        String imePrezime = sc.next();
        imePrezime = imePrezime.replace('_', ' ');
        System.out.print("jmbg: ");
        String jmbg = sc.next();
        Dosije d1 = new Dosije(imePrezime, jmbg);
        while (!d1.jesteJmbg(jmbg)) {
            System.out.print("jmbg: ");
            jmbg = sc.next();
        }
        System.out.print("broj indeksa: ");
        int indeks = sc.nextInt();
        System.out.print("godina upisa: ");
        int godina = sc.nextInt();
        System.out.print("studije (0 - Osnovne, 1 - MSc, 2 - PhD): ");
        int studije = sc.nextInt();
        System.out.println();

        Student student = new Student(imePrezime, jmbg, indeks, godina, studije);

        System.out.println("Podaci o nastavniku:");
        System.out.println("--------------------------------");

        System.out.print("Ime_Prezime: ");
        imePrezime = sc.next();
        imePrezime = imePrezime.replace('_', ' ');
        System.out.print("jmbg: ");
        jmbg = sc.next();
        Dosije d2 = new Dosije(imePrezime, jmbg);
        while (!d2.jesteJmbg(jmbg)) {
            System.out.print("jmbg: ");
            jmbg = sc.next();
        }
        System.out.print("radni odnos: ");
        int radniOdnos = sc.nextInt();
        System.out.print("zvanje (docent, vanredni, redovni): ");
        String zvanje = sc.next();
        while (!Nastavnik.ispravnoZvanje(zvanje)){
            System.out.println("zvanje (docent, vanredni, redovni): ");
            zvanje = sc.next();
        }

        Nastavnik nastavnik = new Nastavnik(imePrezime, jmbg, radniOdnos, zvanje);
        System.out.println();

        System.out.println(student);
        System.out.println();
        System.out.println(nastavnik);
        System.out.println();

        System.out.println("Broj studenata: " + Student.getBrojStudenata());
        System.out.println();

        System.out.println("studije (0 - Osnovne, 1 - MSc, 2 - PhD): ");
        studije = sc.nextInt();
        Student s1 = new Student(student);
        s1.setProfilStudija(studije);
        System.out.println();
        System.out.println(s1);

        System.out.println();
        System.out.println("Broj studenata: " + Student.getBrojStudenata());

        sc.close();
    }
}
