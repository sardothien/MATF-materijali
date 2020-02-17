package Kalkulator;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.scene.paint.Color;

import java.util.ArrayList;
import java.util.List;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) {
        VBox root = new VBox(10);
        root.setPadding(new Insets(10, 10, 10, 10));

        // VBox organizujemo:
        HBox hTop = new HBox(10);
        Label lRezultat = new Label("Rezultat:");
        TextField tfIzlaz = new TextField();
        Label lGreska = new Label();
        lGreska.setTextFill(Color.RED);
        lGreska.setText("");
        root.getChildren().addAll(hTop, lRezultat, tfIzlaz, lGreska);

        // hTop organizujemo:
        VBox vLevi = new VBox(10);
        VBox vDesni = new VBox(10);
        vDesni.setPadding(new Insets(40, 0, 0, 10));
        hTop.getChildren().addAll(vLevi, vDesni);

        // vLevi
        Label lOperand1 = new Label("Prvi operand:");
        TextField tfOperand1 = new TextField();
        Label lOperand2 = new Label("Drugi operand:");
        TextField tfOperand2 = new TextField();
        vLevi.getChildren().addAll(lOperand1, tfOperand1, lOperand2, tfOperand2);

        // vDesni
        HBox hDugmici1 = new HBox(10);
        HBox hDugmici2 = new HBox(10);
        vDesni.getChildren().addAll(hDugmici1, hDugmici2);

        // hDugmici1
        Button bPlus = new Button("+");
        Button bMinus = new Button("-");
        Button bPuta = new Button("*");
        hDugmici1.getChildren().addAll(bPlus, bMinus, bPuta);

        // hDugmici2
        Button bPodeljeno = new Button("/");
        Button bKoren = new Button("√");
        Button bC = new Button("C");
        hDugmici2.getChildren().addAll(bPodeljeno, bKoren, bC);


        // Obrada za dugmice
        bPlus.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String rez = izvrsiOperaciju(tfOperand1, tfOperand2, lGreska, Operacija.SABIRANJE);
                if(!rez.isEmpty())
                    tfIzlaz.setText(rez);
            }
        });

        bMinus.setOnAction(event -> {
            String rez = izvrsiOperaciju(tfOperand1, tfOperand2, lGreska, Operacija.ODUZIMANJE);
            if(!rez.isEmpty())
                tfIzlaz.setText(rez);
        });

        bPodeljeno.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String rez = izvrsiOperaciju(tfOperand1, tfOperand2, lGreska, Operacija.DELJENJE);
                if(!rez.isEmpty())
                    tfIzlaz.setText(rez);
            }
        });

        bPuta.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String rez = izvrsiOperaciju(tfOperand1, tfOperand2, lGreska, Operacija.MNOZENJE);
                if(!rez.isEmpty())
                    tfIzlaz.setText(rez);
            }
        });

        bKoren.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String rez = izvrsiOperaciju(tfOperand1, tfOperand2, lGreska, Operacija.KOREN);
                if(!rez.isEmpty())
                    tfIzlaz.setText(rez);
            }
        });

        bC.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                tfIzlaz.clear();
                tfOperand1.clear();
                tfOperand2.clear();
                lGreska.setText("");
            }
        });

        Scene scene = new Scene(root, 340, 240);

        primaryStage.setTitle("Kalkulator");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private static String izvrsiOperaciju(TextField tOp1, TextField tOp2, Label lGreska, Operacija op){
        List<Double> operandi = unesiOperande(tOp1, tOp2, lGreska);
        if(operandi.isEmpty())
            return "";
        Izraz i = new Izraz(operandi.get(0), operandi.get(1), op);
        return i.toString();
    }

    private static List<Double> unesiOperande(TextField tOp1, TextField tOp2, Label lGreska) {
        List<Double> brojevi = new ArrayList<>();

        try {
            double a = Double.parseDouble(tOp1.getText());
            double b = Double.parseDouble(tOp2.getText());
            brojevi.add(a);
            brojevi.add(b);
        }
        catch (NumberFormatException e){
            lGreska.setText("Operandi nisu u odgovarajucem formatu!");
        }

        return brojevi;
    }

    public static void main(String[] args) {
        launch(args);
    }
}
