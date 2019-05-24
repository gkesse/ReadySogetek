//===============================================
package com.elephant.app.manager;
//===============================================
public class GProcessJavaFX extends GProcess {
	//===============================================
	private static GProcessJavaFX m_instance = null;
	//===============================================
	public GProcessJavaFX() {

	}
	//===============================================
	public static GProcessJavaFX Instance() {
		if(m_instance == null) {
			m_instance = new GProcessJavaFX();
		}
		return m_instance;
	}
	//===============================================
	public void run(String[] args) {
		GPrint.Instance().print("[ JAVAFX ] Running...\n");
		GWindow lWindow = new GWindow();
	}
	//===============================================
}
//===============================================
