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

public class PokemonArena extends Application {

    List<Pokemon> listaPokemona = new ArrayList<>();

    private static Pokemon pokemon1 = null;
    private static Pokemon pokemon2 = null;

    Button btnUcitaj, btnIzaberi, btnSimuliraj;
    TextArea taIspis1, taIspis2;
    RadioButton rbtnMagija1, rbtnMagija2;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        VBox root = new VBox(10);
        Scene scene = new Scene(root, 500, 500);

        kreirajGUI(root);

        ucitaj();
        izaberi();
        simuliraj();

        primaryStage.setTitle("Pokemoni");
        primaryStage.setResizable(false);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void simuliraj() {
        btnSimuliraj.setOnAction(event -> {
            if (pokemon1.getZivot() <= 0)
                taIspis2.appendText("Pobedio je CPU.\n");
            else if(pokemon2.getZivot() <= 0)
                taIspis2.appendText("Pobedio je Igrac.\n");
            else{
                pokemon1.baciMagiju(pokemon2);
                pokemon2.baciMagiju(pokemon1);
                taIspis2.appendText("[igrac] " + pokemon1 + " je bacio " + pokemon1.getPoslednjaBacena() + "\n");
                taIspis2.appendText("[cpu] " + pokemon2 + " je bacio " + pokemon2.getPoslednjaBacena() + "\n");
                taIspis2.appendText("[igrac] " + pokemon1.getZivot() + "%\n");
                taIspis2.appendText("[cpu] " + pokemon2.getZivot() + "%\n");
                taIspis2.appendText("----------------------------------------------------\n");
            }
        });
    }

    private void izaberi() {
        btnIzaberi.setOnAction(event -> {
            if (rbtnMagija1.isSelected()){
                ((IgracPokemon)pokemon1).setIzabranaMagija(1);
                taIspis2.appendText("[igrac] Bira magiju " + pokemon1.getMagija1() + "\n");
                taIspis2.appendText("----------------------------------------------------\n");
            }
            else if (rbtnMagija2.isSelected()){
                ((IgracPokemon)pokemon1).setIzabranaMagija(2);
                taIspis2.appendText("[igrac] Bira magiju " + pokemon1.getMagija2() + "\n");
                taIspis2.appendText("----------------------------------------------------\n");
            }
        });
    }

    private void ucitaj() {
        btnUcitaj.setOnAction(event -> {

            try {
                List<String> linije = Files.readAllLines(Paths.get("pokemoni.txt"));

                for (String l : linije){
                    String[] tokeni = l.split(", ");

                    char cijiJe = tokeni[0].charAt(0);
                    String ime = tokeni[1].trim();
                    int nivo = Integer.parseInt(tokeni[2].trim());
                    String imeMagija1 = tokeni[3].trim();
                    int snagaMagija1 = Integer.parseInt(tokeni[4].trim());
                    String imeMagija2 = tokeni[5].trim();
                    int snagaMagija2 = Integer.parseInt(tokeni[6].trim());

                    Magija m1 = new Magija(snagaMagija1, imeMagija1);
                    Magija m2 = new Magija(snagaMagija2, imeMagija2);

                    if (cijiJe == 'p'){
                        IgracPokemon iPokemon = new IgracPokemon(ime, nivo, m1, m2);
                        listaPokemona.add(iPokemon);
                    }
                    else if (cijiJe == 'n'){
                        CpuPokemon neprijatelj = new CpuPokemon(ime, nivo, m1, m2);
                        listaPokemona.add(neprijatelj);
                    }
                    else
                        System.out.println("Greska!");
                }

            } catch (IOException e) {
                taIspis1.setText("Neuspesno citanje datoteke.");
            }

            Collections.sort(listaPokemona);

            for (Pokemon p : listaPokemona)
                taIspis1.appendText(p.toString() + "\n");

            // --------------------------------

            pokemon1 = listaPokemona.get(0);
            for (Pokemon p : listaPokemona){
                if (p instanceof CpuPokemon){
                    pokemon2 = p;
                    break;
                }
            }

            if (pokemon2 == null)
                System.out.println("Ne sme da se desi!");

            rbtnMagija1.setText(pokemon1.getMagija1().toString());
            rbtnMagija2.setText(pokemon1.getMagija2().toString());

            taIspis1.appendText("\nIzabrani pokemoni:\n" + pokemon1 + "\n");
            taIspis1.appendText(pokemon2 + "\n");
        });
    }

    private void kreirajGUI(VBox root) {
        btnUcitaj = new Button("Ucitaj");

        taIspis1 = new TextArea();
        taIspis1.setEditable(false);

        taIspis2 = new TextArea();
        taIspis2.setEditable(false);

        rbtnMagija1 = new RadioButton("Magija 1");
        rbtnMagija2 = new RadioButton("Magija 2");
        ToggleGroup tgRadio = new ToggleGroup();
        rbtnMagija1.setToggleGroup(tgRadio);
        rbtnMagija2.setToggleGroup(tgRadio);
        rbtnMagija1.setSelected(true);

        btnIzaberi = new Button("Izaberi magiju");
        btnSimuliraj = new Button("Simuliraj");

        HBox hbDugmad = new HBox(10);
        hbDugmad.getChildren().addAll(btnIzaberi, btnSimuliraj);

        root.setPadding(new Insets(10));
        root.getChildren().addAll(btnUcitaj,taIspis1, taIspis2, rbtnMagija1, rbtnMagija2, hbDugmad);
    }
}
