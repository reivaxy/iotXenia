/**
 *  iotinator aquarium monitoring slave module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "XeniaModule.h"
 
XeniaModule::XeniaModule(XeniaConfigClass* config, int displayAddr, int displaySda, int displayScl):XIOTModule(config, displayAddr, displaySda, displayScl) {
  // Init pin with the level detector as input
  pinMode(LEVEL_PIN, INPUT);
  digitalWrite(LEVEL_PIN, HIGH); // Activate pullup resistor
    
  if (!ds.search(addr[0])) {
    _oledDisplay->setLine(2, "Addr 0 error.", TRANSIENT, NOT_BLINKING);
    ds.reset_search();
    delay(250);
  }
}

char* XeniaModule::_customData() {
  //  Serial.println("XeniaModule::_customData");
  // Dummy for now, just counting the number of calls to test updated in master's slave collection when module is pingged
  char* data = (char *)malloc(100);
  sprintf(data, "{}");
  return data;  
}

// This is called periodically from the main loop.
void XeniaModule::customLoop() {
  Serial.println("Xenia loop");
}