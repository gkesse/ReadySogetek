//===============================================
package com.elephant.app.manager;
//===============================================
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.layout.Region;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
//===============================================
public class GWindowLabel extends Application {
	@Override
	public void start(Stage stage) throws Exception {
		Group lGroup = new Group();
		Scene lScene = new Scene(lGroup, 500, 500, Color.rgb(9, 3, 91));
		GStyle.Instance().load(lScene, "/data/css/style.css");

		Label lLabel = new Label("RedHat");
		lLabel.setAlignment(Pos.CENTER);

		Label lLabel2 = new Label("CentOs");
		lLabel2.setAlignment(Pos.CENTER);

		Label lLabel3 = new Label("Debian");
		lLabel3.setAlignment(Pos.CENTER);


		Tab lTab = new Tab("RedHat");
		lTab.setContent(lLabel);
		lTab.setClosable(false);
		
		Tab lTab2 = new Tab("CentOs");
		lTab2.setContent(lLabel2);
		lTab2.setClosable(false);

		Tab lTab3 = new Tab("Debian");
		lTab3.setContent(lLabel3);
		lTab3.setClosable(false);

		TabPane lTabPane = new TabPane();
		lTabPane.getTabs().add(lTab);
		lTabPane.getTabs().add(lTab2);
		lTabPane.getTabs().add(lTab3);
		lTabPane.setMinSize(Region.USE_PREF_SIZE, Region.USE_PREF_SIZE);
		lTabPane.prefWidthProperty().bind(stage.widthProperty().subtract(20));
		lTabPane.prefHeightProperty().bind(stage.heightProperty().subtract(40));
        
		lGroup.getChildren().add(lTabPane);
		
		stage.setScene(lScene);
		stage.setTitle("ELEPHANT | SOGETEK");
		stage.show();
	}

}
//===============================================
