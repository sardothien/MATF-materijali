import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class PosiljkaGUI extends Application {

    private static List<Posiljka> posiljke = new ArrayList<>();

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        VBox root = new VBox(10);
        Scene scene = new Scene(root, 600, 320);

        kreirajGUI(root);

        primaryStage.setTitle("Postanske posiljke");
        primaryStage.setResizable(false);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {

        TextArea taIspis = new TextArea();
        taIspis.setEditable(false);

        Button btnPregledPosiljke = new Button("Pregledaj posiljke");
        Button btnPregledUredjeno = new Button("Pregledaj uredjeno");
        RadioButton rbtnPisma = new RadioButton("Pisma");
        RadioButton rbtnPaketi = new RadioButton("Paketi");
        RadioButton rbtnEkspres = new RadioButton("Ekspres");

        ToggleGroup tgRadio = new ToggleGroup();
        rbtnPisma.setToggleGroup(tgRadio);
        rbtnPaketi.setToggleGroup(tgRadio);
        rbtnEkspres.setToggleGroup(tgRadio);

        HBox dugmici = new HBox(20);
        dugmici.getChildren().addAll(btnPregledPosiljke, btnPregledUredjeno);

        HBox radioDugmici = new HBox(5);
        radioDugmici.getChildren().addAll(rbtnPisma, rbtnPaketi, rbtnEkspres);

        HBox dugmad = new HBox(5);
        dugmad.getChildren().addAll(dugmici, radioDugmici);

        Button btnOtpremi = new Button("Otpremi");

        Label laIDPosiljke = new Label("Broj/id posiljke:");
        TextField tfIDPosiljke = new TextField();
        Button btnPronadji = new Button("Pronadji");

        HBox donjiDeo = new HBox(5);
        donjiDeo.getChildren().addAll(laIDPosiljke, tfIDPosiljke, btnPronadji);

        pregledajPosiljke(btnPregledPosiljke, taIspis);
        pregledajUredjeno(btnPregledUredjeno, taIspis, rbtnEkspres, rbtnPaketi, rbtnPisma);
        otpremi(btnOtpremi, taIspis);
        pronadji(btnPronadji, tfIDPosiljke, taIspis);

        root.setPadding(new Insets(5));
        root.getChildren().addAll(taIspis, dugmad, btnOtpremi, donjiDeo);
    }

    private void pronadji(Button btnPronadji, TextField tfIDPosiljke, TextArea taIspis) {
        btnPronadji.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                try {
                    int id = Integer.parseInt(tfIDPosiljke.getText());
                    taIspis.clear();

                    for (Posiljka p : posiljke) {
                        if (id == p.getId()) {
                            taIspis.appendText("----------------------------\n" + p);
                            return;
                        }
                    }
                    taIspis.appendText("-----------------------------\nNema posiljke sa datim brojem!");
                }
                catch (NumberFormatException e){
                    taIspis.setText("Niste uneli ceo broj!");
                }
            }
        });
    }

    private void otpremi(Button btnOtpremi, TextArea taIspis) {
        btnOtpremi.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                taIspis.setText("");

                for (Posiljka p : posiljke){
                    if (p instanceof Ekspres){
                        if (((Ekspres) p).getTip() != EkspresUsluga.SUTRA_19)
                            if (!p.isStatusPosiljke())
                                p.setStatusPosiljke(true);
                    }
                    else if (p instanceof Pismo){
                        if (((Pismo) p).isPreporuceno())
                            if (!p.isStatusPosiljke())
                                p.setStatusPosiljke(true);
                    }

                    taIspis.appendText(p + "\n");
                }
            }
        });
    }

    private void pregledajUredjeno(Button btnPregledUredjeno, TextArea taIspis, RadioButton rbtnEkspres,
                                   RadioButton rbtnPaketi, RadioButton rbtnPisma) {
        btnPregledUredjeno.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                taIspis.setText("");
                Collections.sort(posiljke);

                boolean pregled;

                for (Posiljka p : posiljke){
                    pregled = false;

                    if (rbtnPisma.isSelected()){
                        if (p instanceof Pismo)
                            pregled = true;
                    }
                    else if (rbtnPaketi.isSelected()){
                        if (p instanceof Paket)
                            pregled = true;
                    }
                    else if (rbtnEkspres.isSelected()){
                        if (p instanceof Ekspres)
                            pregled = true;
                    }
                    else
                        pregled = true;

                    if (pregled)
                        taIspis.appendText(p + "\n");
                }
            }
        });
    }

    private void pregledajPosiljke(Button btnPregledPosiljke, TextArea taIspis) {
        btnPregledPosiljke.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                StringBuilder sb = new StringBuilder();

                try {
                    List<String> linije = Files.readAllLines(Paths.get("posiljke.txt"));

                    if (linije.isEmpty())
                        sb.append("Nema posiljki u datoteci.");

                    for (String l : linije){

                        Posiljka p = null;
                        try (Scanner sc = new Scanner(l)){
                            String primalac = sc.next() + " " + sc.next();
                            int brPoste = sc.nextInt();
                            String tip = sc.next();

                            if (tip.equals("PSM")){
                                boolean preporuceno = sc.hasNext();
                                p = new Pismo(primalac, brPoste, preporuceno);
                            }
                            else if (tip.equals("PAK")){
                                p = new Paket(primalac, brPoste, sc.next());
                            }
                            else if (tip.equals("PE")){
                                String kada = sc.next().toUpperCase();
                                if (kada.equals("SUTRA")) {
                                    p = new Ekspres(primalac, brPoste,
                                            EkspresUsluga.valueOf(kada + "_" + sc.next()));
                                }
                                else{
                                    p = new Ekspres(primalac, brPoste,
                                            EkspresUsluga.valueOf(kada));
                                }
                            }

                            posiljke.add(p);
                        }
                        sb.append(p + "\n");
                    }

                } catch (IOException e) {
                    taIspis.setText("Neuspesno citanje datoteke.");
                }

                taIspis.setText(sb.toString());
            }
        });
    }
}
