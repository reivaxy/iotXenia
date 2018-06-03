/**
 *  Definition of the config data structure for the iotinator aquarium monitoring slave 
 *  module and the class to persist it to EEPROM 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once

#include <XIOTConfig.h>
#include <XUtils.h>

#define CONFIG_VERSION 1
#define MODULE_NAME "Xenia"

// Two light schedules will be handled: one during which lights must be on, one during which lights must be off
// For each, min and max light levels will specify the ok value for the light sensor.
// If value is not within these limits during the specified interval, an alert will be sent
struct lightSchedule {
  byte startHour;           // Hour of the begining of the interval
  byte startMinute;         // Minute of the begining of the interval
  byte endHour;             // Hour of the ending of the interval
  byte endMinute;           // Minute of the ending of the interval
  int minAcceptableValue;   // Min value for light sensor considered ok for this schedule
  int maxAcceptableValue;   // Max value for light sensor considered ok for this schedule
};


// This is the structure that will be persisted into EEPROM
struct XeniaConfigStruct:ModuleConfigStruct {
  int temperatureAdjustment;     // Signed offset to add to temperature measure to adjust it
  int temperatureHighThreshold;  // Alert will be sent if temperature above this value (centiCelsius: 2550 is 25,50Â°)
  int temperatureLowThreshold;   // Alert will be sent if temperature below this value (centiCelsius: 2400 is 24Â°)
  lightSchedule lightOn;         // Interval during which lights should be on
  lightSchedule lightOff;        // Interval during which lights should be off
  int highLevelPinValue;         // Value (HIGH or LOW) on level pin when water level is ok
};


class XeniaConfigClass:public ModuleConfigClass {
public:
  XeniaConfigClass(unsigned int version, const char* name);
  void initFromDefault();
  const char* getDefaultUIClassName() override;


protected:
  XeniaConfigStruct* _getDataPtr(void);  
};
