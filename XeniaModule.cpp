/**
 *  iotinator aquarium monitoring slave module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "XeniaModule.h"
 
XeniaModule::XeniaModule(XeniaConfigClass* config, int displayAddr, int displaySda, int displayScl):XIOTModule(config, displayAddr, displaySda, displayScl) {
}

char* XeniaModule::_customData() {
  //  Serial.println("XeniaModule::_customData");
  // Dummy for now, just counting the number of calls to test updated in master's slave collection when module is pingged
  char* data = (char *)malloc(100);
  sprintf(data, "{\"counter\":%d}", _counter++);
  return data;  
}