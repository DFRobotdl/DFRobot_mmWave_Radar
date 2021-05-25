/*!
   @file DFRobot_mmWave_Radar.ino
   @ Read whether there is people or object moving in the detection range of the sensor. 
   @ The sensor detection range and output delay time can be configured. Also you can restore the sensor to factory default settings. 
   @n Experimental phenomenon: When the sensor starts successfully, 0 or 1 will be printed on the serial monitor. 
   @ 0 means that there is no human or object moving in sensing area, 1 means the oppposite. 
   @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [huyujie](yujie.hu@dfrobot.com)
   @version  V1.0
   @date  2020-3-25
   @https://github.com/DFRobot
*/


#include <SoftwareSerial.h>

#include "DFRobot_mmWave_Radar.h"

SoftwareSerial mySerial(3, 2);
DFRobot_mmWave_Radar sensor(&mySerial);

int ledPin = 13;

void setup()
{
  Serial.begin(115200);
  mySerial.begin(115200);
  pinMode(ledPin, OUTPUT);
  
  sensor.factoryReset();    //Restore to the factory settings 
  sensor.DetRangeCfg(0, 9);    //The detection range is as far as 9m
  sensor.OutputLatency(0, 0);
}

void loop()
{
  int val = sensor.readPresenceDetection();
  digitalWrite(ledPin, val);
  Serial.println(val);


}
