/**
 *  Class to persist the iotXenia module configuration data structure to EEPROM 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "config.h"


XeniaConfigClass::XeniaConfigClass(unsigned int version, const char* name):ModuleConfigClass(version, name, sizeof(XeniaConfigStruct)) {
}

/**
 * Reset the config data structure to the default values.
 * This is done each time the data structure version is different from the one saved in EEPROM
 * NB: version and name are handled by base class 
 */
void XeniaConfigClass::initFromDefault() {
  ModuleConfigClass::initFromDefault(); // handles version and name init, ssid and pwd

}

const char* XeniaConfigClass::getDefaultUIClassName() {
  Serial.println("XeniaConfigClass::getDefaultUIClassName");
  return "xeniaUIClass";
}

/**
 * Return the typed data structure object
 *
 */
XeniaConfigStruct* XeniaConfigClass::_getDataPtr(void) {
  return (XeniaConfigStruct*)ModuleConfigClass::_getDataPtr();
}