//===============================================
package com.elephant.app.manager;
//===============================================
abstract public class GProcess {
	//===============================================
	public static GProcess Instance() {
		String lKey = GConfig.Instance().getData("PROCESS");
		if(lKey.equals("JAVAFX")) return GProcessJavaFX.Instance();
		if(lKey.equals("SOCKET")) return GProcessSocket.Instance();
		return GProcessJavaFX.Instance();
	}
	//===============================================
	abstract public void run(String[] args);
	//===============================================
}
//===============================================
