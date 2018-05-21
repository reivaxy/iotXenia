/**
 *  iotinator Aquarium monitoring slave module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once 
#include "config.h"
#include <XIOTModule.h>
 
class XeniaModule:public XIOTModule {
public:
  XeniaModule(XeniaConfigClass* config, int displayAddr, int displaySda, int displayScl);
  
protected:
  char* _customData() override;
  int _counter = 0;
};