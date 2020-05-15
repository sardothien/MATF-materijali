import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.util.Random;

public class anagram extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        VBox root = new VBox(10);
        HBox hTop = new HBox(10);
        VBox vLevi = new VBox(10);
        VBox vDesni = new VBox(10);

        vLevi.setPadding(new Insets(10, 0, 0, 10));
        vDesni.setPadding(new Insets(10, 10, 0, 0));
        hTop.getChildren().addAll(vLevi, vDesni);

        Label lIme = new Label("Unesite vase ime:");
        TextField tfUnos = new TextField();
        vLevi.getChildren().addAll(lIme, tfUnos);

        Button bUnos = new Button("Potvrdi");
        Button bOcisti = new Button("Ocisti");
        Button bIzadji = new Button("Izadji");
        vDesni.getChildren().addAll(bUnos, bOcisti, bIzadji);

        Label lIspis = new Label("Ispis: ");
        TextArea taIspis = new TextArea();
        Label lPoruka = new Label();
        lPoruka.setTextFill(Color.RED);

        root.getChildren().addAll(hTop, lIspis, taIspis, lPoruka);

        Scene scene = new Scene(root, 400, 400);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Anagrami");

        bUnos.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String korisnikUnosi = tfUnos.getText();
                if(korisnikUnosi.isEmpty()){
                    lPoruka.setText("Unesite neki tekst.");
                    return;
                }
                String anagram = izracunajAnagram(korisnikUnosi);
                taIspis.setText("Vas anagram je: " + anagram);
                lPoruka.setText("");
            }
        });

        bOcisti.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                tfUnos.clear();
                lPoruka.setText("");
                taIspis.clear();
            }
        });

        bIzadji.setOnAction(e -> Platform.exit());

        primaryStage.show();
    }

    private static String izracunajAnagram(String s) {
        char[] tmp = s.toCharArray();

        Random rand = new Random();
        for (int i = 0; i < tmp.length; i++){
            int k = rand.nextInt(tmp.length);
            char pom = tmp[i];
            tmp[i] = tmp[k];
            tmp[k] = pom;
        }

        return String.valueOf(tmp);
    }
}
