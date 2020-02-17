package primer01;

public class Main {

    public static void main(String[] args) {
        Student s1 = new Student("M", "Matematic", "mm0012016", 10.0);
        Student s2 = new Student("N", "Numerovic", "mn3142014", 9.5);
        Student s3 = new Student("V", "Verovatnic", "mv3142015", 8.5);
        Student s4 = new Student("N", "Nastavnic", "ml3142014", 9.5);
        Student s5 = new Student("R", "Racunalo", "mr3142017", 9.7);
        Student s6 = new Student("I", "Informatikovic", "mi3142015", 9.7);
        Student s7 = new Student("A", "Afikic", "af3142014", 8.5);
        Student s8 = new Student("A", "Ainformatikovic", "ai3142014", 8.5);

        Student[] studenti = {s1, s2, s3, s4, s5, s6, s7, s8};
        for (Student student: studenti)
            System.out.println(student);

        Student x = new Student("Testiranje", "Validacije", "ai3142014", 8.5);
        x.setIndeks("mp123123");
        x.setIndeks("mp1a3123");
        x.setIndeks("mp163a3");
    }
}
