//===============================================
package com.elephant.app.manager;
//===============================================
public class GProcessSocket extends GProcess {
	//===============================================
	private static GProcessSocket m_instance = null;
	//===============================================
	public GProcessSocket() {

	}
	//===============================================
	public static GProcessSocket Instance() {
		if(m_instance == null) {
			m_instance = new GProcessSocket();
		}
		return m_instance;
	}
	//===============================================
	public void run(String[] args) {
		GPrint.Instance().print("[ SOCKET ] Running...\n");
	}
	//===============================================
}
//===============================================
