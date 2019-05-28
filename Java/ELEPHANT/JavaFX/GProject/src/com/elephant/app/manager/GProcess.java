//===============================================
package com.elephant.app.manager;
//===============================================
abstract public class GProcess {
	//===============================================
	public static GProcess Instance() {
		String lKey = GConfig.Instance().getData("PROCESS");
		if(lKey.equals("LABEL")) return GProcessLabel.Instance();
		if(lKey.equals("SOCKET")) return GProcessSocket.Instance();
		return GProcessLabel.Instance();
	}
	//===============================================
	abstract public void run(String[] args);
	//===============================================
}
//===============================================
