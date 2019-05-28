//===============================================
package com.elephant.app.manager;
//===============================================
public class GProcessLabel extends GProcess {
	//===============================================
	private static GProcessLabel m_instance = null;
	//===============================================
	public GProcessLabel() {

	}
	//===============================================
	public static GProcessLabel Instance() {
		if(m_instance == null) {
			m_instance = new GProcessLabel();
		}
		return m_instance;
	}
	//===============================================
	public void run(String[] args) {
		GWindowLabel.launch(GWindowLabel.class, args);
	}
	//===============================================
}
//===============================================
