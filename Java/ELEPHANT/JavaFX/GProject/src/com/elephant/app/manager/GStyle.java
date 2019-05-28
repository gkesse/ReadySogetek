//===============================================
package com.elephant.app.manager;
//===============================================
import javafx.scene.Scene;
//===============================================
public class GStyle {
	//===============================================
	private static GStyle m_instance = null; 
	//===============================================
	public GStyle() { 

	} 	
	//===============================================
	public static GStyle Instance() { 
		if(m_instance == null) { 
			m_instance = new GStyle(); 
		}
		return m_instance; 
	} 
	//===============================================
	public void load(Scene scene, String file) {
		System.out.print("[ STYLE ] loading...\n");
		scene.getStylesheets().add(file);
	} 
	//===============================================
}
//===============================================
