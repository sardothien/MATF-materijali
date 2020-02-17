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

public class SoftverGUI extends Application {

    TextArea taIspis;
    TextField tfUpis;
    Button btnSadrzaj, btnNajpopularniji, btnSoftverZaJezik, btnUkupnoZaJezik, btnUkupno;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        VBox root = new VBox(10);
        Scene scene = new Scene(root, 790, 470);

        kreirajGUI(root);

        SoftverskaMreza mreza = new SoftverskaMreza("HitGub");

        if (mreza.ucitajPodatke("softver.txt"))
            taIspis.setText("Ucitani su podaci.");
        else
            taIspis.setText("Neuspelo ucitavanje podatalka.");

        btnSadrzaj.setOnAction(event -> taIspis.setText(mreza.toString()));

        btnNajpopularniji.setOnAction(event -> taIspis.setText(mreza.najpopularnijiJezik()));

        btnSoftverZaJezik.setOnAction(event -> {
            String jezik = tfUpis.getText();

            if (jezik.isEmpty()){
                taIspis.setText("Unesite jezik u tekstualno polje.");
                return;
            }

            taIspis.setText("Softver za jezik " + jezik + "\n");
            for (Softver s : mreza.softverZaJezik(jezik))
                taIspis.appendText(" * " + s.toString() + "\n");
        });

        btnUkupnoZaJezik.setOnAction(event -> {
            String jezik = tfUpis.getText();

            if (jezik.isEmpty()){
                taIspis.setText("Unesite jezik u tekstualno polje.");
                return;
            }

            taIspis.setText("Ukupno linija koda za jezik " + jezik + ": " + mreza.ukupnoLInijaKodaZaJezik(jezik));
        });


        btnUkupno.setOnAction(event -> taIspis.setText("Ukupno linija koda: " + mreza.ukupnoLinijaKoda()));

        primaryStage.setTitle("SOftverska mreza");
        primaryStage.setResizable(false);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {

        taIspis = new TextArea();
        taIspis.setEditable(false);
        taIspis.setPrefHeight(300);

        tfUpis = new TextField();

        // Dugmici
        btnSadrzaj = new Button("Sadrzaj mreze");
        btnNajpopularniji = new Button("Najpopularniji jezik");
        btnSoftverZaJezik = new Button("Softver za jezik");
        btnUkupnoZaJezik = new Button("Ukupno linija koda za jezik");
        btnUkupno = new Button("Ukupno linija koda");

        HBox dugmici = new HBox(10);
        dugmici.getChildren().addAll(btnSadrzaj, btnNajpopularniji, btnSoftverZaJezik, btnUkupnoZaJezik, btnUkupno);
        dugmici.setAlignment(Pos.CENTER);

        root.setPadding(new Insets(10));
        root.getChildren().addAll(taIspis, tfUpis, dugmici);
    }
}