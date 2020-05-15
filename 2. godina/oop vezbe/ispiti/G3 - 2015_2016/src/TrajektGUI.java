import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;

public class TrajektGUI extends Application {

    private static List<String> linije = null;
    private static Trajekt trajekt = null;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        VBox root = new VBox();
        Scene scene = new Scene(root, 250, 333);

        kreirajGUI(root);

        primaryStage.setTitle("Trajekt");
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {

        Button btnUcitaj = new Button("Ucitaj");

        TextArea taUcitaj = new TextArea();
        taUcitaj.setEditable(false);
        taUcitaj.setPrefHeight(140);

        VBox top = new VBox(5);
        top.setPadding(new Insets(5, 5, 0, 5));
        top.getChildren().addAll(btnUcitaj, taUcitaj);

        TextField tfIzmena = new TextField();

        Button btnIzvezi = new Button("Izvezi");

        HBox bottom1 = new HBox(5);
        bottom1.setAlignment(Pos.CENTER_LEFT);
        bottom1.getChildren().addAll(tfIzmena, btnIzvezi);

        TextArea taNovo = new TextArea();
        taNovo.setEditable(false);
        taNovo.setPrefHeight(130);

        VBox bottom = new VBox(5);
        bottom.setPadding(new Insets(5, 5, 0, 5));
        bottom.getChildren().addAll(bottom1, taNovo);

        btnUcitaj.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                ucitajVozila();

                StringBuffer sb = new StringBuffer();
                // DEO ZA PRAG
                for (String linija : linije)
                    sb.append(linija + "\n");
                // ---------------------------
                if (!sb.equals(""))
                    taUcitaj.setText(sb.toString());
                else
                    taUcitaj.setText("Nema trajekta.");
            }
        });

        btnIzvezi.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                if (trajekt == null)
                    taNovo.setText("Nema trajekta.");
                else{
                    String izmena = tfIzmena.getText();
                    if (!izmena.equals(""))
                        trajekt.izvezi(Integer.parseInt(izmena));
                    taNovo.setText(trajekt.toString() + "----------------\n" +
                            "Ukupan prihod: " + trajekt.prihod());
                }
            }
        });

        root.getChildren().addAll(top, bottom);
    }

    private static void ucitajVozila() {
        try {
            linije = Files.readAllLines(Paths.get("trajekt.txt"));

            for (String l : linije){
                try (Scanner sc = new Scanner(l)){
                    sc.useDelimiter(", ");
                    char vrsta = sc.next().charAt(0);
                    if (vrsta == 'T'){
                        int brMesta = sc.nextInt();
                        double maxTezina = sc.nextDouble();
                        double cena = sc.nextDouble();
                        trajekt = new Trajekt(brMesta, maxTezina, cena);
                    }
                    else if (vrsta == 'A'){
                        double tezina = sc.nextDouble();
                        int kapacitet = sc.nextInt();
                        int mesto = sc.nextInt();

                        Autobus a = new Autobus(tezina, kapacitet);
                        trajekt.uvezi(a, mesto);
                    }
                    else if (vrsta == 'K'){
                        double tezina = sc.nextDouble();
                        double nosivost = sc.nextDouble();
                        int mesto = sc.nextInt();

                        Kamion k = new Kamion(tezina, nosivost);
                        trajekt.uvezi(k, mesto);
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("Greska prilikom ucitavanja vozila.");
            System.exit(1);
        }
    }
}
