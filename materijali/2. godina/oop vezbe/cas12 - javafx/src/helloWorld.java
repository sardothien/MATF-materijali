import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class helloWorld extends Application {

    public static void main(String[] args) {
        launch(args);
    }


    @Override
    public void start(Stage primaryStage) {
        VBox root = new VBox(10);

        root.setPadding(new Insets(10, 10, 10, 10));

        Button bKlikni = new Button("Klikni!");
        Button bObrisi = new Button("Brisi!");

        Label lTekst = new Label("");
        lTekst.setTextFill(Color.RED);

        // stablo nasih komponenti
        root.getChildren().addAll(lTekst, bKlikni, bObrisi);

        bKlikni.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                lTekst.setText("Zdravo svete!");
            }
        });

        bObrisi.setOnAction(e -> {
            lTekst.setText("");
        });

        Scene scene = new Scene(root, 200, 200);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Hello world!");
        primaryStage.show();
    }
}
