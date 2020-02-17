import com.sun.org.apache.bcel.internal.generic.LADD;
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
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class VideoIgraGUI extends Application {

    private List<VideoIgra> igre = new ArrayList<>();

    private Button btnUcitaj, btnPrikazi, btnSortiraj, btnDodaj;
    private Label lblPlatforma, lblSortiraj, lblIme, lblCena, lblZanr, lblZahtevnost;
    private TextArea taIspis;
    private TextField tfIme, tfCena, tfZanr, tfZahtevnost;
    private RadioButton rbtnPC, rbtnPS4, rbtnXBoxOne, rbtnSve, rbtnIme, rbtnCena,
                        rbtnPC1, rbtnPS41, rbtnXBoxOne1;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        VBox root = new VBox();
        Scene scene = new Scene(root, 500, 600);

        kreirajGUI(root);

        ucitaj();
        prikazi();
        sortiraj();
        dodaj();

        primaryStage.setTitle("Video igre");
        primaryStage.setResizable(false);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void dodaj() {
        btnDodaj.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    String ime = tfIme.getText().trim();
                    int cena = Integer.parseInt(tfCena.getText().trim());
                    String zanr = tfZanr.getText().trim();

                    if (ime.isEmpty() || zanr.isEmpty()){
                        taIspis.setText("Greska pri unosu!");
                        return;
                    }

                    if (rbtnPC1.isSelected()){
                        int zahtevnost = Integer.parseInt(tfZahtevnost.getText().trim());
                        igre.add(new PCVideoIgra(ime, zanr, cena, zahtevnost));
                    }
                    else if (rbtnPS41.isSelected())
                        igre.add(new KonzolaVideoIgra(ime, zanr, cena, "ps4"));
                    else if (rbtnXBoxOne1.isSelected())
                        igre.add(new KonzolaVideoIgra(ime, zanr,cena, "xbone"));

                    taIspis.setText("Uspesno je dodata igra.");
                }
                catch (NumberFormatException e){
                    taIspis.setText("Greska pri unosu!");
                }
            }
        });
    }

    private void sortiraj() {
        btnSortiraj.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                if (rbtnIme.isSelected())
                    igre.sort(Comparator.comparing(VideoIgra::getIme));
                else if (rbtnCena.isSelected())
                    igre.sort(Comparator.comparing(VideoIgra::getCena));

                btnPrikazi.fire();
            }
        });
    }

    private void prikazi() {
        btnPrikazi.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                taIspis.clear();

                for (VideoIgra vi : igre){
                    boolean prikazi = false;
                    if (rbtnPC.isSelected() && vi.getPlatforma().equals("PC"))
                        prikazi = true;
                    if (rbtnPS4.isSelected() && vi.getPlatforma().equals("ps4"))
                        prikazi = true;
                    if (rbtnXBoxOne.isSelected() && vi.getPlatforma().equals("xbone"))
                        prikazi = true;
                    if (rbtnSve.isSelected())
                        prikazi = true;
                    if (!rbtnPC.isSelected() && !rbtnPS4.isSelected() && !rbtnXBoxOne.isSelected() && !rbtnSve.isSelected())
                        prikazi = true;

                    if (prikazi)
                        taIspis.appendText("* " + vi.toString() + "\n");
                }
            }
        });
    }

    private void ucitaj() {
        btnUcitaj.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                try {
                    List<String> linije = Files.readAllLines(Paths.get("igre.txt"));
                    if (linije.isEmpty())
                        taIspis.setText("Nema igara u datoteci.");

                    for (String l : linije){
                        String[] tokeni = l.split(", ");
                        String tip = tokeni[0].trim();
                        String ime = tokeni[1].trim();
                        String zanr = tokeni[2].trim();
                        int cena = Integer.parseInt(tokeni[3].trim());

                        if (tip.equals("pc")){
                            int zahtevnost = Integer.parseInt(tokeni[4].trim());
                            igre.add(new PCVideoIgra(ime, zanr, cena, zahtevnost));
                        }
                        else
                            igre.add(new KonzolaVideoIgra(ime, zanr, cena, tip));
                    }

                    taIspis.setText("Broj ucitanih igara: " + igre.size());

                } catch (IOException e) {
                    taIspis.setText("Neuspesno otvaranje datoteke!");
                }
            }
        });
    }

    private void kreirajGUI(VBox root) {

        // Gornji deo
        btnUcitaj = new Button("Ucitaj video igre");

        taIspis = new TextArea();
        taIspis.setEditable(false);

        VBox gornjiDeo = new VBox(10);
        gornjiDeo.getChildren().addAll(btnUcitaj, taIspis);
        gornjiDeo.setAlignment(Pos.CENTER);

        // Srednji deo - levo
        lblPlatforma = new Label("Platforma");

        rbtnPC = new RadioButton("PC");
        rbtnPS4 = new RadioButton("PS4");
        rbtnXBoxOne = new RadioButton("XBOX One");
        rbtnSve = new RadioButton("Sve");

        ToggleGroup tgRadio1 = new ToggleGroup();
        rbtnPC.setToggleGroup(tgRadio1);
        rbtnPS4.setToggleGroup(tgRadio1);
        rbtnXBoxOne.setToggleGroup(tgRadio1);
        rbtnSve.setToggleGroup(tgRadio1);

        btnPrikazi = new Button("Prikazi");

        VBox leviDeo = new VBox(10);
        leviDeo.getChildren().addAll(lblPlatforma, rbtnPC, rbtnPS4, rbtnXBoxOne, rbtnSve, btnPrikazi);

        // Srednji deo - centar
        lblSortiraj = new Label("Soriraj po:");

        rbtnIme = new RadioButton("Imenu");
        rbtnCena = new RadioButton("Ceni");

        ToggleGroup tgRadio2 = new ToggleGroup();
        rbtnIme.setToggleGroup(tgRadio2);
        rbtnCena.setToggleGroup(tgRadio2);

        btnSortiraj = new Button("Sortiraj");

        VBox centralniDeo = new VBox(10);
        centralniDeo.getChildren().addAll(lblSortiraj, rbtnIme, rbtnCena, btnSortiraj);

        // Srednji deo - desno
        lblIme = new Label("Ime:");
        tfIme = new TextField();

        lblCena = new Label("Cena:");
        tfCena = new TextField();

        lblZanr = new Label("Zanr:");
        tfZanr = new TextField();

        lblZahtevnost = new Label("Zahtevnost:");
        tfZahtevnost = new TextField();

        rbtnPC1 = new RadioButton("PC");
        rbtnPS41 = new RadioButton("PS4");
        rbtnXBoxOne1 = new RadioButton("XBOX One");

        ToggleGroup tgRadio3 = new ToggleGroup();
        rbtnPC1.setToggleGroup(tgRadio3);
        rbtnPS41.setToggleGroup(tgRadio3);
        rbtnXBoxOne1.setToggleGroup(tgRadio3);

        btnDodaj = new Button("Dodaj");

        VBox desniDeo = new VBox(10);
        desniDeo.getChildren().addAll(lblIme, tfIme, lblCena, tfCena, lblZanr, tfZanr,
                lblZahtevnost, tfZahtevnost, rbtnPC1, rbtnPS41, rbtnXBoxOne1, btnDodaj);

        // Srednji deo
        HBox srednjiDeo = new HBox(10);
        srednjiDeo.getChildren().addAll(leviDeo, centralniDeo, desniDeo);


        // Sve
        root.setPadding(new Insets(5));
        root.getChildren().addAll(gornjiDeo, srednjiDeo); // srednji = donji deo
    }
}
