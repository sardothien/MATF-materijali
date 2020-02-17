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
import java.util.*;

public class FarmaRacunara extends Application {

    private Korisnik korisnik = new Korisnik("Mina", 5);
    private static Random random = new Random();
    private Racunar izabrani = null;
    private Map<Racunar, List<Integer>> racunari = new TreeMap<>();

    Button btnUcitaj, btnObracunaj, btnKoristi;
    TextArea taUcitaj, taLog;
    RadioButton rbStandardni, rbVip;
    Label laPrioritet, laLog, laVreme, laIme, laDugovanja;
    TextField tfIme, tfVreme;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        VBox root = new VBox(10);
        Scene scene = new Scene(root, 600, 520);

        kreirajGUI(root);

        primaryStage.setTitle("Forma racunara");
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {
        // Gornji deo
        btnUcitaj = new Button("Ucitaj");

        taUcitaj = new TextArea();

        VBox gornjiDeo = new VBox(10);
        gornjiDeo.getChildren().addAll(btnUcitaj, taUcitaj);

        //-----------------------------------

        // Centralni deo

        laPrioritet = new Label("Prioritet");

        rbStandardni = new RadioButton("Standardni");
        rbVip = new RadioButton("VIP");
        ToggleGroup tgRadio = new ToggleGroup();
        rbStandardni.setToggleGroup(tgRadio);
        rbVip.setToggleGroup(tgRadio);
        rbStandardni.setSelected(true);

        HBox hbPrioritet = new HBox(10);
        hbPrioritet.getChildren().addAll(laPrioritet, rbStandardni, rbVip);

        laIme = new Label("Ime");
        tfIme = new TextField();

        laVreme = new Label("Vreme");
        tfVreme = new TextField();

        btnKoristi = new Button("Koristi");

        HBox hbKoristi = new HBox(10);
        hbKoristi.getChildren().addAll(laIme, tfIme, laVreme, tfVreme, btnKoristi);

        VBox srednjiDeo = new VBox(10);
        srednjiDeo.getChildren().addAll(hbPrioritet, hbKoristi);

        // -------------------------------------------

        // Donji deo

        laLog = new Label("Log:");

        taLog = new TextArea();

        btnObracunaj = new Button("Obracunaj dugovanja");

        laDugovanja = new Label("Ukupno dugovanja:");

        VBox donjiDeo = new VBox(10);
        donjiDeo.getChildren().addAll(laLog, taLog, btnObracunaj, laDugovanja);

        //-------------------------------------------------

        ucitaj();
        koristi();
        obracunaj();

        root.setPadding(new Insets(10));
        root.getChildren().addAll(gornjiDeo, srednjiDeo, donjiDeo);
    }

    private void obracunaj() {
        btnObracunaj.setOnAction(event -> {
            taLog.appendText("------------Obracun dugovanja po racunaru:\n");
            double dug = 0;
            for (Map.Entry<Racunar, List<Integer>> r : racunari.entrySet()){
                dug = r.getKey().izracunajCenu(r.getValue());
                korisnik.azurirajDug(r.getKey(), dug);
                taLog.appendText(r.getKey().getIme() + " " + dug + "\n");
            }

            laDugovanja.setText("Ukupna dugovanja korisnika " + korisnik.getKorisnickoIme()
                            + ": " + korisnik.ukupanDug());

        });
    }

    private void koristi() {
        btnKoristi.setOnAction(event -> {

            int prioritet, vreme;
            String ime;

            if (rbStandardni.isSelected())
                prioritet = 1;
            else
                prioritet = 2;

            if (tfIme.getText().equals(""))
                taLog.appendText("Unesite ime!\n");
            else if (tfVreme.getText().equals(""))
                taLog.appendText("Unesite vreme!\n");
            else {
                ime = tfIme.getText();
                vreme = Integer.parseInt(tfVreme.getText());

                for (Racunar r : racunari.keySet())
                    if (r.getIme().equals(ime))
                        izabrani = r;

                if (izabrani == null)
                    taLog.appendText("Ne postoji racunar sa datim imenom!\n");
                else{
                    if (prioritet == 1){
                        if (random.nextBoolean()){
                            taLog.appendText(izabrani.getIme() + " je uspesno iskoriscen!\n");
                            racunari.get(izabrani).add(vreme);
                        }
                        else
                            taLog.appendText(izabrani.getIme() + " je trenutno zauzet.\n");
                    }
                    else {
                        if (korisnik.getVipKrediti() > 0){
                            korisnik.umanjiVipKredite();
                            taLog.appendText("[VIP] " + izabrani.getIme() + " je iskoriscen.\n");
                            racunari.get(izabrani).add(vreme);
                        }
                        else
                            taLog.appendText("Nemate dovoljno VIP kredita!\n");
                    }
                }
            }
        });
    }

    private void ucitaj() {
        btnUcitaj.setOnAction(event -> {

            try {
                List<String> linije = Files.readAllLines(Paths.get("racunari.txt"));

                for (String l : linije){
                    String[] tokeni = l.split(", ");
                    char tip = tokeni[0].charAt(0);
                    String naziv = tokeni[1].trim();
                    double cenovniKoef = Double.parseDouble(tokeni[2].trim());
                    List<Integer> trajanje = new ArrayList<>();

                    if (tip == 'c'){
                        int velicinaDiska = Integer.parseInt(tokeni[3].trim());
                        String bup = tokeni[4].trim();
                        boolean backup = bup.equals("da");
                        for (int i = 5; i < tokeni.length; i++)
                            trajanje.add(Integer.parseInt(tokeni[i].trim()));

                        RacunarZaCuvanje rc = new RacunarZaCuvanje(naziv, cenovniKoef, velicinaDiska, backup);
                        racunari.put(rc, trajanje);
                        korisnik.dodajRacunar(rc);
                    }
                    else if (tip == 'o'){
                        int brojProcesora = Integer.parseInt(tokeni[3].trim());
                        for (int i = 4; i < tokeni.length; i++)
                            trajanje.add(Integer.parseInt(tokeni[i].trim()));

                        RacunarZaObradu ro = new RacunarZaObradu(naziv, cenovniKoef, brojProcesora);
                        racunari.put(ro, trajanje);
                        korisnik.dodajRacunar(ro);
                    }
                }

                for(Map.Entry<Racunar, List<Integer>> e : racunari.entrySet())
                    taUcitaj.appendText(e.toString() + "\n");


            } catch (IOException e) {
                taUcitaj.setText("Neuspesno otvaranje datoteke.");
            }
        });
    }
}
