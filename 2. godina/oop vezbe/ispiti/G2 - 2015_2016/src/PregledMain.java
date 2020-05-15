import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
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

public class PregledMain extends Application {

    private static ArrayList<Pacijent> pacijenti = new ArrayList<>();

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        VBox root = new VBox(10);
        Scene scene = new Scene(root, 650, 430);

        kreirajGUI(root);

        primaryStage.setTitle("Nutricionisticki pregled");
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {

        Label lblStanje = new Label("Stanje u cekaonici:");

        TextArea taPregled = new TextArea();
        taPregled.setMaxWidth(630);
        taPregled.setPrefHeight(350);
        taPregled.setEditable(false);

        Button btnPregled = new Button("Pregled cekaonice");
        btnPregled.setPrefWidth(250);

        Button btnPregledKriterijum = new Button("Pregled uredjeno");
        btnPregledKriterijum.setPrefWidth(250);

        HBox hbDonjiSloj = new HBox(20);
        hbDonjiSloj.setPadding(new Insets(0, 0, 0, 50));
        hbDonjiSloj.getChildren().addAll(btnPregled, btnPregledKriterijum);

        btnPregledKriterijum.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                Collections.sort(pacijenti);
                StringBuilder sb = new StringBuilder();

                for (Pacijent p : pacijenti)
                    sb.append(p + "\n");

                taPregled.setText(sb.toString());
            }
        });

        btnPregled.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                List<String> linije = null;
                StringBuilder sb = new StringBuilder("DEO ZA PRAG:\n");
                Character pol;
                int godine;
                double tezina, visina;
                Aktivnost fizickaAktivnost;

                try {
                    linije = Files.readAllLines(Paths.get("cekaonica.txt"));
                    if (!linije.isEmpty()){
                        for (String linija : linije ){
                            try (Scanner sc = new Scanner(linija)){
                                sc.useDelimiter(", ");
                                pol = sc.next().charAt(0);
                                godine = sc.nextInt();
                                visina = sc.nextDouble();
                                tezina = sc.nextDouble();
                                fizickaAktivnost = Aktivnost.valueOf(sc.next());

                                Pacijent p = null;

                                if(pol == 'M')
                                    p = new Muskarac(tezina, visina, godine, fizickaAktivnost);
                                else
                                    p = new Zena(tezina, visina, godine, fizickaAktivnost);

                                pacijenti.add(p);
                            }
                            sb.append(linija).append('\n');
                        }
                        sb.append("---------------------------------------");
                    }
                    else
                        sb.append("Niko ne ceka u cekaonici.");

                    taPregled.setText(sb.toString());
                } catch (IOException e) {
                    System.err.println("Greska prilikom citanja iz cekaonica.txt");
                    System.exit(1);
                }
            }
        });

        root.setPadding(new Insets(10, 0, 0, 10));
        root.getChildren().addAll(lblStanje, taPregled, hbDonjiSloj);
    }
}
