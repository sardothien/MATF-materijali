import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;


public class KodiranjeGUI extends Application {

    private static Map<String, Integer> mBitovi = new HashMap<>();
    private static Map<String, Integer> cBitovi = new HashMap<>();
    private static Map<Integer, List<Integer>> cBitoviFormule = new HashMap<>();
    private static List<String> poruke;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        VBox root = new VBox(5);
        Scene scene = new Scene(root, 580, 280);

        kreirajGUI(root);

        primaryStage.setTitle("Kodiranje binarnih poruka");
        primaryStage.setResizable(false);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {
        TextArea taIspis = new TextArea();
        taIspis.setEditable(false);

        VBox gornjiDeo = new VBox();
        gornjiDeo.getChildren().addAll(taIspis);

        Button btnUcitajTablicu = new Button("Ucitaj i prikazi tablicu");
        Button btnPitanje = new Button("Kako se kodira?");
        Button btnUcitajPoruke = new Button("Ucitaj poruke i prikazi kontrolne bitove");

        HBox donjiDeo = new HBox(5);
        donjiDeo.getChildren().addAll(btnUcitajTablicu, btnPitanje, btnUcitajPoruke);

        ucitajTablicu(btnUcitajTablicu, taIspis);
        pitanje(btnPitanje, taIspis);
        ucitajPoruke(btnUcitajPoruke, taIspis);

        root.setPadding(new Insets(10));
        root.getChildren().addAll(gornjiDeo, donjiDeo);
    }

    private void ucitajPoruke(Button btnUcitajPoruke, TextArea taIspis) {
        btnUcitajPoruke.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                try {
                    poruke = Files.readAllLines(Paths.get("poruke.txt"));

                    if (poruke.isEmpty())
                        taIspis.appendText("Nema poruka u datoteci.");

                } catch (IOException e) {
                    System.out.println("Neuspesno otvaranje datoteke.");
                    System.exit(1);
                }

                taIspis.appendText("\nm8m7m6m5m4m3m2m1 : c4c3c2c1\n");
                taIspis.appendText("------------------------------------------\n");

                for (String m : poruke){
                    String cBitovi = "";
                    for (int i = 4; i >= 1; i--) {
                        List<Integer> mBitovi = cBitoviFormule.get(i);
                        int cBit = 0;
                        for (Integer mBit : mBitovi)
                            cBit += m.charAt(8-mBit) - '0';
                        cBit %= 2;
                        cBitovi += cBit;
                    }

                    taIspis.appendText(m + " : " + cBitovi + "\n");
                }
            }
        });
    }

    private void pitanje(Button btnPitanje, TextArea taIspis) {
        btnPitanje.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                for (int i = 1; i <= 4; i++){
                    int pozicijaJedinice = 4-i;
                    Set<String> kodoviZaM = mBitovi.keySet();
                    List<Integer> cFormula = new ArrayList<>();

                    for (String k : kodoviZaM){
                        if (k.charAt(pozicijaJedinice) == '1')
                            cFormula.add(mBitovi.get(k));
                    }

                    Collections.sort(cFormula);
                    cBitoviFormule.put(i, cFormula);
                }

                taIspis.appendText("\n");

                for (int i = 1; i <= 4; i++){
                    taIspis.appendText("c" + i + " = ");
                    List<Integer> mBitovi = cBitoviFormule.get(i);
                    Iterator<Integer> it = mBitovi.iterator();
                    while (it.hasNext()){
                        taIspis.appendText("m" + it.next() + "");
                        if (it.hasNext())
                            taIspis.appendText(" + ");
                    }
                    taIspis.appendText("\n");
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
                        taIspis.setText("Nema tablice u datoteci.");

                    for (String l : linije){
                        String[] delovi1 = l.split(", ");
                        String bit = delovi1[0];
                        String binarniKod = delovi1[1];

                        if (bit.charAt(0) == 'm'){
                            taIspis.appendText(binarniKod + "\t\t" + bit + "\n");
                            mBitovi.put(binarniKod, bit.charAt(1) - '0');
                        }
                        else {
                            taIspis.appendText(binarniKod + "  " + bit + "\n");
                            cBitovi.put(binarniKod, bit.charAt(1) - '0');
                        }
                    }

                } catch (IOException e) {
                    System.out.println("Neuspesno otvaranje datoteke");
                    System.exit(1);
                }
            }
        });
    }
}
