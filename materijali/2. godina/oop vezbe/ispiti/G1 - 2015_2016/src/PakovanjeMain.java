import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
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
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class PakovanjeMain extends Application {

    private static LinkedList<Paket> paketi = new LinkedList<>();
    private static List<String> linije = null;

    public static void main(String[] args) {
        ucitajPaket();
        launch(args);
    }

    private static void ucitajPaket() {
        try {
            linije = Files.readAllLines(Paths.get("paketi.txt"));

            for (String linija : linije){
                try (Scanner sc = new Scanner(linija)){
                    sc.useDelimiter(", ");
                    char vrsta = sc.next().charAt(0);
                    if(vrsta == 'V'){
                        double a = sc.nextDouble();
                        double h = sc.nextDouble();
                        paketi.add(new Valjak(a, h));
                    }
                    else{
                        double a = sc.nextDouble();
                        double b = sc.nextDouble();
                        double c = sc.nextDouble();
                        paketi.add(new Kutija(a, b, c));
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("Greska prilikom ucitavanja paketa.");
            System.exit(1);
        }
    }

    @Override
    public void start(Stage primaryStage) {

        VBox root = new VBox();
        Scene scene = new Scene(root, 250, 420);

        kreirajGUI(root);

        primaryStage.setTitle("Paketi");
        primaryStage.setResizable(false);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void kreirajGUI(VBox root) {
        Button btnPregledPaketa = new Button("Pregled paketa");

        TextArea taPregled = new TextArea();
        taPregled.setEditable(false);

        VBox top = new VBox(10);
        top.setPadding(new Insets(10, 10, 0, 10));
        top.getChildren().addAll(btnPregledPaketa, taPregled);

        Label lblCena = new Label("Cena zastitne folije");

        TextField tfCena = new TextField();
        tfCena.setMaxWidth(90);
        tfCena.setPrefHeight(40);

        TextArea taKutije = new TextArea();
        taKutije.setEditable(false);

        Button btnKutije = new Button("Izracunaj cenu dodatnog pakovanja");

        HBox bottom1 = new HBox(10);
        bottom1.setAlignment(Pos.CENTER_LEFT);
        bottom1.getChildren().addAll(lblCena, tfCena);

        VBox bottom = new VBox(10);
        bottom.setPadding(new Insets(10, 10, 10, 10));
        bottom.getChildren().addAll(bottom1, taKutije, btnKutije);

        // Ucitavanje podataka iz ulazne datoteke paketi.txt i prikaz
        btnPregledPaketa.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                StringBuilder sb = new StringBuilder();
                sb.append("DEO ZA PRAG: \n");
                for (String linija : linije)
                    sb.append(linija + '\n');
                sb.append("---------------------------------------------\n");
                for (Paket paket : paketi)
                    sb.append(paket + "\n");
                if (!sb.equals(""))
                    taPregled.setText(sb.toString());
                else
                    taKutije.setText("Prazan spisak paketa.");
            }
        });

        // Ispis spiska kutije zajedno sa podacima o povrsinama
        btnKutije.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                double ukupnaPovrsina = 0;
                double povrsina;
                StringBuilder sb = new StringBuilder();

                for (Paket p : paketi){
                    if (p instanceof Kutija){
                        povrsina = ((Kutija) p).povrsina();
                        sb.append(p + ", P = " + String.format("%.2f", povrsina) + '\n');
                        ukupnaPovrsina += povrsina;
                    }
                }

                if (!sb.toString().equals("")){
                    System.out.println(sb);
                    sb.append("-----------------------------------------------\n");
                    sb.append("Ukupna povrsina: " + String.format("%.2f", ukupnaPovrsina) + '\n');

                    String cena = tfCena.getText();
                    if (!tfCena.getText().equals("")) {
                        sb.append("Ukupna cena: " + String.format("%.2f",
                                ukupnaPovrsina * Double.parseDouble(cena)));
                    }
                    else
                        sb.append("Nije uneta cena.");
                    taKutije.setText(sb.toString());
                }
                else
                    taKutije.setText("Nema kutija medju paketima.");
            }
        });

        root.getChildren().addAll(top, bottom);
    }
}
