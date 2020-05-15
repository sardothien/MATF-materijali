import javafx.application.Application;
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
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class AmbulantaGUI extends Application {

    private static Red red = new Red();

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        VBox root = new VBox(5);
        Scene scene = new Scene(root, 542, 230);

        kreirajGUI(root);

        primaryStage.setTitle("Veterinarska ambulanta");
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {

        Label lblIme = new Label("Ime:");
        TextField tfIme = new TextField();
        Label lblStarost = new Label("Starost:");
        TextField tfStarost = new TextField();

        VBox leviDeo = new VBox();
        leviDeo.getChildren().addAll(lblIme, tfIme, lblStarost, tfStarost);

        TextArea taIspis = new TextArea();
        taIspis.setPrefWidth(320);
        taIspis.setEditable(false);

        HBox desniDeo = new HBox();
        desniDeo.getChildren().addAll(taIspis);

        HBox gornjiDeo = new HBox(30);
        gornjiDeo.getChildren().addAll(leviDeo, desniDeo);

        Button btnVidi = new Button("Vidi ko ceka");
        Button btnDodajMacku = new Button("Dodaj macku u red");
        Button btnDodajPsa = new Button("Dodaj psa u red");
        Button btnPozovi = new Button("Pozovi sldeceg");

        HBox donjiDeo = new HBox(5);
        donjiDeo.getChildren().addAll(btnVidi, btnDodajMacku, btnDodajPsa, btnPozovi);

        ucitavanje(btnVidi, taIspis);
        dodajMacku(tfIme, tfStarost, btnDodajMacku, taIspis);
        dodajPsa(tfIme, tfStarost, btnDodajPsa, taIspis);
        pozoviSledeceg(btnPozovi, taIspis);

        root.setPadding(new Insets(10, 0, 0, 10 ));
        root.getChildren().addAll(gornjiDeo, donjiDeo);
    }

    private void pozoviSledeceg(Button btnPozovi, TextArea taIspis) {
        btnPozovi.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                Ljubimac sledeci = red.prozoviSledeceg();
                StringBuffer sb = new StringBuffer();
                if (sledeci != null){
                    sb.append("Prozvan:\n" + sledeci + '\n');
                    sb.append("U redu:\n" + red.toString());
                }
                else
                    sb.append("Nema ljubimca u cekaonici!");
                taIspis.setText(sb.toString());
            }
        });
    }

    private void dodajPsa(TextField tfIme, TextField tfStarost, Button btnDodajPsa, TextArea taIspis) {
        btnDodajPsa.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                red.dodajURed(new Pas(tfIme.getText(), Integer.parseInt(tfStarost.getText())));
                taIspis.setText(red.toString());
            }
        });
    }

    private void dodajMacku(TextField tfIme, TextField tfStarost, Button btnDodajMacku, TextArea taIspis) {
        btnDodajMacku.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                red.dodajURed(new Macka(tfIme.getText(), Integer.parseInt(tfStarost.getText())));
                taIspis.setText(red.toString());
            }
        });
    }

    private void ucitavanje(Button btnVidi, TextArea taIspis) {
        btnVidi.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                int brMacaka = 0, brPasa = 0;
                List<String> linije;
                String[] podaci = new String[4];

                try {
                    linije = Files.readAllLines(Paths.get("baza.txt"));

                    for (String l : linije){
                        podaci = l.split(", ");
                        if (podaci[0].equals("P")){
                            brPasa++;
                            if (Pas.validnaID(podaci[3]))
                                red.dodajURed(new Pas(podaci[1],
                                        Integer.parseInt(podaci[2]), podaci[3]));
                        }
                        else if (podaci[0].equals("M")){
                            brMacaka++;
                            if (Macka.validnaID(podaci[3]))
                                red.dodajURed(new Macka(podaci[1],
                                        Integer.parseInt(podaci[2]), podaci[3]));
                        }
                    }

                    if (brMacaka != 0 || brPasa != 0)
                        taIspis.setText("U redu ceka " + brMacaka + " macaka i " +
                                brPasa + " pasa.");
                    else
                        taIspis.setText("U redu ne ceka ni jedan ljubimac.");
                } catch (IOException e) {
                    System.out.println("Neuspesno otvaranje datoteke");
                    System.exit(1);
                }
            }
        });
    }
}
