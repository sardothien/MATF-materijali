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

public class PredmetiGUI extends Application {

    private PlanNastave planNastave = new PlanNastave();
    private TextArea taIspis;
    private Button btnUcitaj, btnPrikazi;
    private RadioButton rbtnSvi, rbtnObavezni, rbtnIzborni;
    private String opseg;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        VBox root = new VBox(20);
        Scene scene = new Scene(root, 600, 300);

        kreirajGUI(root);

        primaryStage.setTitle("Nastavni predmeti");
        primaryStage.setResizable(false);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {

        btnUcitaj = new Button("Ucitaj podatke iz datoteka");

        taIspis = new TextArea();
        taIspis.setEditable(false);

        // Donji deo
        btnPrikazi = new Button("Prikazi predmete");

        rbtnSvi = new RadioButton("Svi");
        rbtnObavezni = new RadioButton("Obavezni");
        rbtnIzborni = new RadioButton("Izborni");
        ToggleGroup tgRadio = new ToggleGroup();
        rbtnSvi.setToggleGroup(tgRadio);
        rbtnObavezni.setToggleGroup(tgRadio);
        rbtnIzborni.setToggleGroup(tgRadio);

        HBox donjiDeo = new HBox(20);
        donjiDeo.getChildren().addAll(btnPrikazi, rbtnSvi, rbtnObavezni, rbtnIzborni);

        btnUcitaj.setOnAction(event -> {
            if (!planNastave.ucitajPredmete("predmeti.txt"))
                taIspis.setText("Neuspesno otvaranje datoteke 'predmeti.txt'.");
            if (!planNastave.ucitajUslovne("uslovni.txt"))
                taIspis.setText("Neuspesno otvaranje datoteke 'predmeti.txt'.");
            else
                taIspis.setText("Podaci su uspesno ucitani.");
        });

        btnPrikazi.setOnAction(event -> {
            if (planNastave.predmeti.isEmpty()){
                taIspis.setText("Nema podataka o predmetima.");
                return;
            }

            if (rbtnSvi.isSelected())
                opseg = "SVI";
            else if (rbtnObavezni.isSelected())
                opseg = "OBAVEZNI";
            else if (rbtnIzborni.isSelected())
                opseg = "IZBORNI";

            taIspis.setText(planNastave.ispisi(opseg));
        });

        root.setPadding(new Insets(10));
        root.getChildren().addAll(btnUcitaj, taIspis, donjiDeo);
    }
}
