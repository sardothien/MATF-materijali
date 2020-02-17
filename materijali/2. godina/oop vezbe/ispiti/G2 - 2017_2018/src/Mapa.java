import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextArea;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Mapa extends Application {

    List<ObjekatIgre> objIgre = new ArrayList<>();
    private static int sakupljenoDragulja = 0;

    private Button btnUcitaj, btnSmer, btnSimuliraj;
    private TextArea taIspis1, taIspis2;
    private RadioButton rbtnDD, rbtnGL;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        VBox root = new VBox(10);
        Scene scene = new Scene(root, 500, 500);

        kreirajGUI(root);

        primaryStage.setTitle("Sakupljanje dragulja");
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {
        btnUcitaj = new Button("Ucitaj");

        taIspis1 = new TextArea();
        taIspis1.setEditable(false);
        taIspis2 = new TextArea();
        taIspis2.setEditable(false);

        rbtnDD = new RadioButton("Dole ili Desno (x++ ili y++)");
        rbtnGL = new RadioButton("Gore ili Levo (x-- ili y--)");
        ToggleGroup tgRadio = new ToggleGroup();
        rbtnDD.setToggleGroup(tgRadio);
        rbtnGL.setToggleGroup(tgRadio);
        rbtnDD.setSelected(true);

        btnSmer = new Button("Izaberi smer");
        btnSimuliraj = new Button("Simuliraj potez");

        HBox dugmad = new HBox(10);
        dugmad.getChildren().addAll(btnSmer, btnSimuliraj);

        ucitaj();
        izaberiSmer();
        simuliraj();

        root.setPadding(new Insets(10));
        root.getChildren().addAll(btnUcitaj, taIspis1, taIspis2, rbtnDD, rbtnGL, dugmad);
    }

    private void simuliraj() {
        btnSimuliraj.setOnAction(event -> {
            for (ObjekatIgre oi : objIgre)
                oi.izvrsiAkciju();

            for (ObjekatIgre oi : objIgre){
                if (oi instanceof Tragac){
                    Tragac t = (Tragac) oi;
                    for (ObjekatIgre o : objIgre){
                        if (o instanceof Rudnik && t.getX() == o.getX() && t.getY() == o.getY() && ((Rudnik) o).isOtvoren()){
                            if(t.pokupiDragulj((Rudnik) o)){
                                sakupljenoDragulja++;
                                taIspis2.appendText(t.getNaziv() + " je sakupio " + o.getNaziv() + "!\n");
                            }
                            else
                                taIspis2.appendText(t.getNaziv() + " ne moze da ponese " + o.getNaziv() + "!\n");
                        }
                    }
                }
            }

            taIspis2.appendText("Stanje table:\nSakupljeno dragulja: " + sakupljenoDragulja + "\n");
            for (ObjekatIgre oi : objIgre)
                taIspis2.appendText(oi + "\n");

            taIspis2.appendText("----------------------------------------------------------------\n");
        });
    }

    private void izaberiSmer() {
        btnSmer.setOnAction(event -> {
            if (rbtnDD.isSelected()){
                Tragac.setSmerKretanja("dd");
            }
            else if (rbtnGL.isSelected()){
                Tragac.setSmerKretanja("gl");
            }
        });
    }

    private void ucitaj() {
        btnUcitaj.setOnAction(event -> {

            try {
                List<String> linije = Files.readAllLines(Paths.get("objekti.txt"));

                for (String l : linije){
                    String[] tokeni = l.split(", ");

                    char tip = tokeni[0].charAt(0);
                    String ime = tokeni[1].trim();
                    int x = Integer.parseInt(tokeni[2].trim());
                    int y = Integer.parseInt(tokeni[3].trim());

                    if (tip == 't'){
                        int maxTezina = Integer.parseInt(tokeni[4].trim());
                        Tragac tragac = new Tragac(ime, x, y, new Ranac(maxTezina));
                        objIgre.add(tragac);
                    }
                    else if (tip == 'r'){
                        double tezinaDragulja = Double.parseDouble(tokeni[4].trim());
                        int otvorenJos = Integer.parseInt(tokeni[5].trim());
                        Rudnik rudnik = new Rudnik(ime, x, y, otvorenJos, tezinaDragulja);
                        objIgre.add(rudnik);
                    }

                }

            } catch (IOException e) {
                taIspis1.setText("Neuspesno citanje datoteke.");
            }

            Collections.sort(objIgre);

            for (ObjekatIgre oi : objIgre)
                taIspis1.appendText(oi.toString() + "\n");
        });
    }
}
