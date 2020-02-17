import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class SistemZaPreporuke extends Application {

    private Button btnUcitaj, btnPreporuka, btnOceni;
    private TextArea taUcitaj, taPreporuke;
    private RadioButton rbtnIzvGlu, rbtnZanGod;
    private Label lblUslov, lblOcena, lblPreporuke;
    private TextField tfUslov, tfOcena;

    private static Random random = new Random();
    private Map<ZabavniSadrzaj, List<Integer>> zabavniSadrzaj = new TreeMap<>();
    private Korisnik korisnik = new Korisnik("mina");
    private List<ZabavniSadrzaj> preporuceno = new ArrayList<>();
    private int odabrano;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        VBox root = new VBox(10);
        Scene scene = new Scene(root, 500, 550);

        kreirajGUI(root);

        primaryStage.setResizable(false);
        primaryStage.setTitle("Zabavni sadrzaj");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {
        // Gornji deo
        btnUcitaj = new Button("Ucitaj");

        taUcitaj = new TextArea();
        taUcitaj.setEditable(false);

        rbtnIzvGlu = new RadioButton("Izvodjac/Glumac");
        rbtnZanGod = new RadioButton("Zanr/Godina");
        ToggleGroup tgRadio = new ToggleGroup();
        rbtnIzvGlu.setToggleGroup(tgRadio);
        rbtnZanGod.setToggleGroup(tgRadio);
        rbtnZanGod.setSelected(true);

        HBox hbRadio = new HBox(10);
        hbRadio.getChildren().addAll(rbtnIzvGlu, rbtnZanGod);
        hbRadio.setAlignment(Pos.CENTER);

        lblUslov = new Label("Unesite uslov pretrage:");
        tfUslov = new TextField();
        btnPreporuka = new Button("Preporuka");

        HBox hbUslov = new HBox(10);
        hbUslov.getChildren().addAll(lblUslov, tfUslov, btnPreporuka);
        hbUslov.setAlignment(Pos.CENTER);

        VBox gornjiDeo = new VBox(10);
        gornjiDeo.getChildren().addAll(btnUcitaj, taUcitaj, hbRadio, hbUslov);

        //--------------------------------------------

        // Donji deo
        lblPreporuke = new Label("Preporuke:");

        taPreporuke = new TextArea();
        taPreporuke.setEditable(false);

        lblOcena = new Label("Oceni sadrzaj:");
        tfOcena = new TextField();
        btnOceni = new Button("Oceni");

        HBox hbOceni = new HBox(10);
        hbOceni.getChildren().addAll(lblOcena, tfOcena, btnOceni);
        hbOceni.setAlignment(Pos.CENTER);

        VBox donjiDeo = new VBox(10);
        donjiDeo.getChildren().addAll(lblPreporuke, taPreporuke, hbOceni);

        //----------------------------------------------------------------

        ucitaj();
        preporuka();
        oceni();

        //----------------------------------------------------------------
        root.setPadding(new Insets(10));
        root.getChildren().addAll(gornjiDeo, donjiDeo);
    }

    private void oceni() {
        btnOceni.setOnAction(event -> {
            tfUslov.clear();

            if (preporuceno.size() == 0)
                return;

            try {
                int ocena = Integer.parseInt(tfOcena.getText());
                korisnik.oceniSadrzaj(preporuceno.get(odabrano), ocena);

                for (Map.Entry<ZabavniSadrzaj, List<Integer>> e : zabavniSadrzaj.entrySet())
                    taPreporuke.appendText(e.getKey().toString() + " " + e.getValue() + "\n");
            }
            catch (NumberFormatException e){
                taPreporuke.appendText("\nNeispravna vrednost za ocenu!\n");
                return;
            }

            preporuceno.clear();
            tfOcena.clear();
        });
    }

    private void preporuka() {
        btnPreporuka.setOnAction(event -> {

            int opcija;
            if (rbtnIzvGlu.isSelected())
                opcija = 1;
            else
                opcija = 2;

            String uslov = tfUslov.getText();

            taPreporuke.clear();
            preporuceno.clear();

            for (Map.Entry<ZabavniSadrzaj, List<Integer>> e : zabavniSadrzaj.entrySet()){
                if (e.getKey().zaPreporuku(uslov, opcija, korisnik.getOcenjenSadrzaj().keySet())){
                    taPreporuke.appendText(e.getKey().toString() + "\n");
                    preporuceno.add(e.getKey());
                }
            }

            if (preporuceno.size() > 0 ){
                odabrano = random.nextInt(preporuceno.size());
                taPreporuke.appendText("\n" + korisnik.getNadimak() + " je odabrala " + preporuceno.get(odabrano).getNaziv());
            }
            else
                taPreporuke.appendText("Nijedan sadrzaj ne zadovoljaba zadate uslove!");
        });
    }

    private void ucitaj() {
        btnUcitaj.setOnAction(event -> {
            try {
                List<String> linije = Files.readAllLines(Paths.get("zabava.txt"));

                for (String l : linije){
                    String[] tokeni = l.split(",");

                    if (tokeni[0].charAt(0) == 'f'){
                        String naziv = tokeni[1].trim();
                        int duzina = Integer.parseInt(tokeni[2].trim());
                        int godina = Integer.parseInt(tokeni[3].trim());
                        String glumac = tokeni[4].trim();
                        List<Integer> ocene = new ArrayList<>();
                        for (int i = 5; i < tokeni.length; i++)
                            ocene.add(Integer.valueOf(tokeni[i].trim()));

                        zabavniSadrzaj.put(new Film(naziv, duzina, glumac, godina), ocene);
                    }
                    else if (tokeni[0].charAt(0) == 'p'){
                        String naziv = tokeni[1].trim();
                        int duzina = Integer.parseInt(tokeni[2].trim());
                        String izvodjac = tokeni[3].trim();
                        String zanr = tokeni[4].trim();
                        List<Integer> ocene = new ArrayList<>();
                        for (int i = 5; i < tokeni.length; i++)
                            ocene.add(Integer.valueOf(tokeni[i].trim()));

                        zabavniSadrzaj.put(new Pesma(naziv, duzina, izvodjac, zanr), ocene);
                    }
                }

                for(Map.Entry<ZabavniSadrzaj, List<Integer>> e : zabavniSadrzaj.entrySet()){
                    Double prosek = e.getValue().stream()
                                                .mapToInt(a -> a)
                                                .average()
                                                .orElse(0.0);
                    taUcitaj.appendText(e.getKey().toString() + " " + Math.floor(prosek*100)/100 + "\n");
                }

            } catch (IOException e) {
                taUcitaj.setText("Neuspeno otvaranje datoteke.");
            }
        });
    }
}
