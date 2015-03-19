#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, in2,    lightSensor,     sensorReflection)
#pragma config(Sensor, dgtl1,  rangeFinder,       sensorSONAR_mm)
#pragma config(Motor,  port1,           flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           servoGate1,  tmotorServoStandard, openLoop)
#pragma config(Motor,  port3,           servoGate2, tmotorServoStandard, openLoop, reversed)
#pragma config(Motor,  port4,           servoCups, tmotorServoStandard, openLoop)

task main(){
  
  turnFlashlightOn(flashlight, 127);
  int marbleCount = 0;
  wait(0.1);
  int distance = SensorValue(rangeFinder);
  
  while(distance <= SensorValue(rangeFinder) + 2 && distance >= SensorValue(rangeFinder) - 2)
  {waitInMilliseconds(1);}
  
  while(marbleCount < 15){
  
    setServo(servoGate1, 60);
    wait(0.3);
    setServo(servoGate1, 0);
    wait(0.3);
    
    if(SensorValue(lightSensor) > 500){
      
      if(SensorValue(lineFollower) < 1000){ //metal
        setServo(servoCups, 0); //redundant
        //wait(0.1);
      }
      else{ //white
        setServo(servoCups, 120);
        wait(0.1);
      }
    }
    
    else{ //clear
      setServo(servoCups, -127);
      wait(0.1);
    }
    
    setServo(servoGate2, 75);
    wait(0.2);
    setServo(servoGate2, 0);
    wait(0.2);
    
    setServo(servoCups, 0);
    
    marbleCount++;
  } //end of loop
} //end
