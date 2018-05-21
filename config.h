/**
 *  Definition of the config data structure for the iotinator aquarium monitoring slave 
 *  module and the class to persist it to EEPROM 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once

#include <XIOTConfig.h>
#include <XUtils.h>

#define CONFIG_VERSION 30
#define CONFIG_NAME "Xenia"

#define DEFAULT_AUTOWAKE_VALUE 0

struct XeniaConfigStruct:ModuleConfigStruct {
  // Add config fields needed if any
};

class XeniaConfigClass:public ModuleConfigClass {
public:
  XeniaConfigClass(unsigned int version, const char* name);
  void initFromDefault();
  const char* getDefaultUIClassName() override;


protected:
  XeniaConfigStruct* _getDataPtr(void);  
};
