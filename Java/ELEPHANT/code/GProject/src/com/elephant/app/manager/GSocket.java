//===============================================
package com.elephant.app.manager;
//===============================================
import java.util.HashMap;
import java.util.Map;
//===============================================
public class GSocket {
	//===============================================
	private static GSocket m_instance = null; 
	Map<String, String> m_dataMap;
	//===============================================
	public GSocket() { 
		m_dataMap = new HashMap<String, String>();
	} 	
	//===============================================
	public static GSocket Instance() { 
		if(m_instance == null) { 
			m_instance = new GSocket(); 
		}
		return m_instance; 
	} 
	//===============================================
	public void setData(String key, String data) { 
        m_dataMap.put(key, data);
    } 
	//===============================================
	public String getData(String key) { 
        return m_dataMap.get(key);
    } 
	//===============================================
	public void showData() { 
		for(String key: m_dataMap.keySet()) {
            System.out.print(key + " = " + m_dataMap.get(key) + "\n");
		}
        System.out.print("\n");
	} 
	//===============================================
}
//===============================================
