/**
 *  iotinator Aquarium monitoring slave module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once 

#include "config.h"
#include <XIOTModule.h>
#include <OneWire.h>
#include <Wire.h>

// TODO check pin numbers
#define LIGHT_PIN 0
#define TEMPERATURE_PIN 4
#define LEVEL_PIN 11
 
#define MAX_DS1820_SENSORS 1
#define TEMPERATURE_CHECK_PERIOD 5000
#define LIGHT_CHECK_PERIOD 5000
#define LEVEL_CHECK_PERIOD 5000

/* DS18B20 Temperature chip i/o */
OneWire  ds(TEMPERATURE_PIN);
#define MAX_DS1820_SENSORS 1

class XeniaModule:public XIOTModule {
public:
  XeniaModule(XeniaConfigClass* config, int displayAddr, int displaySda, int displayScl);
  char* _customData() override;
  void customLoop();
  
  // This is the data that will be available on the UI
  struct measureData {
    int light = 0;
    boolean lightAlert = false;
    int powerLevel = 0;
    boolean powerAlert = false;
    int temperature; // decadegrees: 2500 for 25.00°
    boolean temperatureAlert = false;
    boolean waterLevelAlert = false;
    boolean oneAlert = false;
  } measures;
  
  byte addr[MAX_DS1820_SENSORS][8];
  unsigned long lastTemperatureCheck = millis();
  unsigned long lastLightCheck = lastTemperatureCheck;
  unsigned long lastLevelCheck = lastTemperatureCheck;      

};