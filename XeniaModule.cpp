/**
 *  iotinator aquarium monitoring slave module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "XeniaModule.h"
 
XeniaModule::XeniaModule(XeniaConfigClass* config, int displayAddr, int displaySda, int displayScl):XIOTModule(config, displayAddr, displaySda, displayScl) {
}

char* XeniaModule::_customRegistrationData() {
  //  Serial.println("XeniaModule::_customRegistrationData");
  // Dummy for now
//  char* data = (char *)malloc(100);
//  sprintf(data, "{\"autoWake\":%d}", ((XeniaConfigClass*)_config)->getAutoWake());
  return NULL;  
}