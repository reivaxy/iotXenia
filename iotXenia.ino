/**
 *  iotinator aquarium monitoring slave module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 

#include <stdio.h>
#include "XeniaModule.h"

#include "config.h"

#define API_VERSION "1.0"    // modules can check API version to make sure they are compatible...

// Global object to store config
XeniaConfigClass *config;
XeniaModule* module;

void setup(){
  Serial.begin(9600);
  delay(200);
  
  config = new XeniaConfigClass((unsigned int)CONFIG_VERSION, (char*)MODULE_NAME);
  config->init();
  
  module = new XeniaModule(config, 0x3C, 14, 12);
  
     
}

/*********************************
 * Main Loop
 *********************************/
void loop() {
  // Mandatory periodic call, to refresh display, Clock, check requests
  // on the http API, ...
  module->loop();
  delay(20);  
}

