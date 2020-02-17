import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;


public class GreskeGUI extends Application {

    private static Map<String, Integer> mBitovi = new HashMap<>();
    private static Map<String, Integer> cBitovi = new HashMap<>();
    private static Map<Integer, List<Integer>> cPrimBitovi = new HashMap<>();
    private static List<KodiranaPoruka> poruke = new ArrayList<KodiranaPoruka>();

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        VBox root = new VBox();
        Scene scene = new Scene(root, 520, 280);

        kreirajGUI(root);

        primaryStage.setTitle("Otkrivanje gresaka u kodiranim binarnim porukama");
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {

        TextArea taIspis = new TextArea();
        taIspis.setEditable(false);
        taIspis.setMaxWidth(300);

        VBox leviDeo = new VBox();
        leviDeo.getChildren().addAll(taIspis);

        Button btnUcitajPoruke = new Button("Ucitaj i prikazi poruke");
        Button btnUcitajTablicu = new Button("Ucitaj tablicu");
        Button btnPitanje = new Button("Kako se dekodira?");
        Button btnProveri = new Button("Proveri ispravnost poruka");

        VBox desniDeo = new VBox(10);
        desniDeo.getChildren().addAll(btnUcitajPoruke, btnUcitajTablicu, btnPitanje, btnProveri);
        desniDeo.setAlignment(Pos.CENTER_LEFT);

        HBox sve = new HBox(10);
        sve.getChildren().addAll(leviDeo, desniDeo);

        ucitajPoruke(btnUcitajPoruke, taIspis);
        ucitajTablicu(btnUcitajTablicu, taIspis);
        dekodiranje(btnPitanje, taIspis);
        ispravnost(btnProveri, taIspis);

        root.setPadding(new Insets(10));
        root.getChildren().addAll(sve);
    }

    private void ispravnost(Button btnProveri, TextArea taIspis) {
        btnProveri.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                taIspis.appendText("\n\nm8m7m6m5m4m3m2m1 : c4c3c2c1 + c4'c3'c2'c1'\n");
                taIspis.appendText("-------------------------------------------------------\n");

                for (KodiranaPoruka kp : poruke) {
                    String m = kp.getmBitovi();
                    String c = kp.getcBitovi();
                    String cPrim = "";

                    for (int i = 4; i >= 1; i--) {
                        List<Integer> mBitovi = cPrimBitovi.get(i);
                        int cP = 0;
                        for (Integer mBit : mBitovi)
                            cP += m.charAt(8-mBit) - '0';
                        cP %= 2;
                        cPrim += cP;
                    }

                    taIspis.appendText(kp + " + " + cPrim + '\n');

                    String sindrom = "";
                    for (int i = 0; i < 4; i++)
                        sindrom += (c.charAt(i) + cPrim.charAt(i)) % 2;

                    taIspis.appendText("s4s3s2s1: " + sindrom);
                    boolean greska_m = false;
                    boolean greska_c = false;
                    for(String kljuc : mBitovi.keySet())
                        if(sindrom.equals(kljuc)) {
                            taIspis.appendText(" => Poruka je neispravna, greska je u bitu m" + mBitovi.get(kljuc) + "\n");
                            greska_m = true;
                            break;
                        }

                    if(!greska_m)
                        for(String kljuc : cBitovi.keySet())
                            if(sindrom.equals(kljuc)) {
                                taIspis.appendText(" => Poruka je ispravna, greska je u bitu c" + cBitovi.get(kljuc) + "\n");
                                greska_c = true;
                                break;
                            }
                    if(!greska_m && !greska_c)
                        taIspis.appendText(" => Poruka je ispravna\n");
                }
            }
        });
    }

    private void dekodiranje(Button btnPitanje, TextArea taIspis) {
        btnPitanje.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                try {
                    List<String> linije = Files.readAllLines(Paths.get("formule.txt"));

                    if (linije.isEmpty())
                        taIspis.appendText("Nema formula u datoteci");

                    for (String l : linije){
                        taIspis.appendText("\n" + l);
                        String[] delovi = l.split(" = ");
                        Integer cPrim = delovi[0].charAt(1) - '0';
                        String[] mBitovi = delovi[1].split(" \\+ ");

                        List<Integer> cFormula = new ArrayList<>();
                        for (int i = 0; i < mBitovi.length; i++)
                            cFormula.add(mBitovi[i].charAt(1) - '0');

                        cPrimBitovi.put(cPrim, cFormula);
                    }

                } catch (IOException e) {
                    System.err.println("Neuspesno citanje datoteke");
                    System.exit(1);
                }
            }
        });
    }

    private void ucitajTablicu(Button btnUcitajTablicu, TextArea taIspis) {
        btnUcitajTablicu.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                try {
                    List<String> linije = Files.readAllLines(Paths.get("tablica.txt"));

                    if (linije.isEmpty())
                        taIspis.appendText("Nema tablice u datoteci");

                    for (String l : linije){
                        Scanner sc = new Scanner(l);
                        String binarniKod = sc.next();
                        String bit = sc.next();

                        if (bit.charAt(0) == 'm')
                            mBitovi.put(binarniKod, bit.charAt(1) - '0');
                        else
                            cBitovi.put(binarniKod, bit.charAt(1) - '0');

                        sc.close();
                    }

                    taIspis.appendText("\nTablica je uspesno ucitana!\n");

                } catch (IOException e) {
                    System.err.println("Neuspesno otvaranje datoteke");
                    System.exit(1);
                }
            }
        });
    }

    private void ucitajPoruke(Button btnUcitajPoruke, TextArea taIspis) {
        btnUcitajPoruke.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                taIspis.appendText("\nm8m7m6m5m4m3m2m1 : c4c3c2c1\n");
                taIspis.appendText("----------------------------------------\n");

                try {
                    List<String> linije = Files.readAllLines(Paths.get("poruke.txt"));

                    if (linije.isEmpty())
                        taIspis.appendText("Nema poruka u datoteci.");

                    for (String l : linije){
                        String m = l.substring(0, 8);
                        String c = l.substring(8);
                        taIspis.appendText(m + " : " + c + '\n');

                        KodiranaPoruka p = new KodiranaPoruka(m, c);
                        poruke.add(p);
                    }

                } catch (IOException e) {
                    System.err.println("Neuspesno citanje datoteke.");
                    System.exit(1);
                }
            }
        });
    }
}
