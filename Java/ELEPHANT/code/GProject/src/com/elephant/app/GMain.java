//===============================================
package com.elephant.app;
//===============================================
import com.elephant.app.manager.GProcess;
import com.elephant.app.manager.GSetting;
//===============================================
public class GMain {
  public static void main(String[] args){
  	GSetting.Instance().load("data/config/config.txt");
      GProcess.Instance().run(args);
  }
}
//===============================================