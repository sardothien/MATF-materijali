import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.util.Random;


public class RadioDugmici extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    private int sirinaProzora = 450, visinaProzora = 450;
    private int sirina = 400, visina = 400, velicina = 150;

    @Override
    public void start(Stage primaryStage) {
        VBox root = new VBox(10);
        root.setAlignment(Pos.CENTER);

        Canvas canvas = new Canvas(sirina, visina);
        GraphicsContext gc = canvas.getGraphicsContext2D();

        HBox hb = new HBox(10);
        hb.setAlignment(Pos.CENTER);
        ToggleGroup toggleGroup = new ToggleGroup();
        RadioButton rKvadrat = new RadioButton("Kvadrat");
        RadioButton rKrug = new RadioButton("Krug");

        rKvadrat.setToggleGroup(toggleGroup);
        rKrug.setToggleGroup(toggleGroup);

        Button bCitaj = new Button("Citaj");
        Button bBrisi = new Button("Brisi");
        Button bRand = new Button("Nasumicno");

        hb.getChildren().addAll(rKvadrat, rKrug, bCitaj, bBrisi, bRand);

        Random rand = new Random();

        // Dugmici
        bCitaj.setOnAction(event -> {
            if(rKrug.isSelected()){
                gc.setFill(Color.RED);
                gc.fillOval(sirina/2 - velicina/2, visina/2 - velicina/2, velicina/2, velicina/2);
            }
            else if(rKvadrat.isSelected()){
                gc.setFill(Color.BLUE);
                gc.fillRect(sirina/2 - velicina/2, visina/2 - velicina/2, velicina/2, velicina/2);
            }
        });

        bBrisi.setOnAction(event -> gc.clearRect(0, 0, sirina, visina));

        bRand.setOnAction(event -> {
            int x = rand.nextInt(sirina);
            int y = rand.nextInt(visina);

            int a = rand.nextInt(sirina/2);
            int b = rand.nextInt(visina/2);

            // nasumicna boja
            gc.setFill(Color.color(rand.nextDouble(), rand.nextDouble(), rand.nextDouble()));

            if(rand.nextBoolean())
                gc.fillOval(x, y, a, b);
            else
                gc.fillRect(x, y, a, b);
        });

        root.getChildren().addAll(hb, canvas);

        Scene scene = new Scene(root, sirinaProzora, visinaProzora);
        primaryStage.setTitle("Hello Radio and Canvas");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}