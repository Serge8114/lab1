
package GUI;

import Core.DataProcessor;
import Core.DataProcessor2;
import Core.DataProcessor3;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class WindowApp extends Application {

    private DataProcessor processor1 = new DataProcessor();
    private DataProcessor2 processor2 = new DataProcessor2();
    private DataProcessor3 processor3 = new DataProcessor3();
    private TextArea inputArea = new TextArea();
    private ListView<String> resultList = new ListView<>();
    private Label statsLabel = new Label("Количество чисел: 0");
    private ComboBox<String> variantComboBox = new ComboBox<>();
    
    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Лабораторная работа №4 - Варианты 13, 14, 15");
        
        inputArea.setPromptText("Введите целые числа, каждое на новой строке\n\nПример для варианта 13:\n-1\n2\n-3\n4\n5\n6\n-7\n8\n9");
        inputArea.setPrefHeight(350);
        
        resultList.setPrefHeight(350);
        
        variantComboBox.setItems(FXCollections.observableArrayList(
            "Вариант 13: Чередование + и -",
            "Вариант 14: Поиск пропущенных чисел",
            "Вариант 15: Удаление дубликатов"
        ));
        variantComboBox.setValue("Вариант 13: Чередование + и -");
        
        HBox topBox = new HBox(10);
        topBox.setPadding(new Insets(10));
        topBox.getChildren().addAll(new Label("Выберите вариант обработки:"), variantComboBox);
        
        VBox leftBox = new VBox(10);
        leftBox.setPadding(new Insets(10));
        leftBox.getChildren().addAll(
            new Label("Входные данные:"),
            inputArea
        );
        
        VBox rightBox = new VBox(10);
        rightBox.setPadding(new Insets(10));
        rightBox.getChildren().addAll(
            new Label("Результат:"),
            resultList,
            statsLabel
        );
        
        Button processButton = new Button("Обработать");
        processButton.setStyle("-fx-font-size: 14px; -fx-padding: 8px;");
        processButton.setOnAction(e -> processData());
        
        VBox bottomBox = new VBox(10);
        bottomBox.setPadding(new Insets(10));
        bottomBox.getChildren().add(processButton);
        
        Label infoLabel = new Label("Вариант 13: чередование + и - | Вариант 14: поиск пропущенных чисел | Вариант 15: удаление дубликатов");
        infoLabel.setStyle("-fx-font-size: 10px; -fx-text-fill: gray;");
        bottomBox.getChildren().add(infoLabel);
        
        HBox centerBox = new HBox(10);
        centerBox.getChildren().addAll(leftBox, rightBox);
        
        BorderPane root = new BorderPane();
        root.setTop(topBox);
        root.setCenter(centerBox);
        root.setBottom(bottomBox);
        
        Scene scene = new Scene(root, 950, 600);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    
    private void processData() {
        try {
            String text = inputArea.getText();
            if (text == null || text.trim().isEmpty()) {
                showAlert("Ошибка", "Введите данные для обработки");
                return;
            }
            
            String[] lines = text.split("\\r?\\n");
            java.util.ArrayList<String> validLines = new java.util.ArrayList<>();
            for (String line : lines) {
                if (!line.trim().isEmpty()) {
                    validLines.add(line.trim());
                }
            }
            
            if (validLines.isEmpty()) {
                showAlert("Ошибка", "Не найдено данных для обработки");
                return;
            }
            
            String[] inputData = validLines.toArray(new String[0]);
            String[] results = null;
            
            String selected = variantComboBox.getValue();
            
            if (selected.equals("Вариант 13: Чередование + и -")) {
                results = processor1.processPipeline(inputData);
                statsLabel.setText("Количество чисел: " + results.length + " (чередование + и -)");
            } else if (selected.equals("Вариант 14: Поиск пропущенных чисел")) {
                results = processor2.processPipeline(inputData);
                statsLabel.setText("Количество пропущенных чисел: " + results.length);
            } else if (selected.equals("Вариант 15: Удаление дубликатов")) {
                results = processor3.processPipeline(inputData);
                statsLabel.setText("Количество уникальных чисел: " + results.length);
            }
            
            if (results != null) {
                resultList.setItems(FXCollections.observableArrayList(results));
            }
            
        } catch (Exception e) {
            showAlert("Ошибка обработки", e.getMessage());
            e.printStackTrace();
        }
    }
    
    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
    
    public static void main(String[] args) {
        launch(args);
    }
}
