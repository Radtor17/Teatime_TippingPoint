/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\vic07                                            */
/*    Created:      Wed Oct 13 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void drive(int vel, int time){
  l.spin(fwd, vel, pct);
  r.spin(fwd, vel, pct);
  wait(time, msec);
  l.stop();
  r.stop();
}

void turn(int vel, int time){
  l.spin(fwd, vel, pct);
  r.spin(fwd, -vel, pct);
  wait(time, msec);
  l.stop();
  r.stop();
}

void fourbar(int vel, int time){
  fbar.spin(fwd, vel, pct);
  for(int i = 0; i < time;i += 5){
    if(fbarButton2.pressing()){break;}
    wait(5,msec);
  }
  fbar.stop();
}

void fourbardown(){
  fbar.spin(fwd, -50, pct);
  while(!fbarButton.pressing()){wait(20,msec);}
  fbar.stop();
}

void auton(){
  fourbar(50, 600);
  drive(40, 1000);
  wait(1000,msec);
  turn(25, 605);
  wait(1000,msec);
  drive(50,3250);
  drive(75, 600);
  clamp.close();
  drive(100,150);
  drive(-100,150);
  drive(100,150);
  drive(-100,150);
  drive(100,150);
  drive(-100,150);
  drive(100,150);
  drive(-100,150);
  drive(-50,1000);
  fourbardown();
  drive(100,1250);
  clamp.open();
  drive(-100, 750);
  clamp.close();
  drive(-100, 500);
}

void opcontrol(){

  while(true){
    l.spin(fwd, Controller.Axis3.value() + Controller.Axis4.value(), pct);
    r.spin(fwd, Controller.Axis3.value() - Controller.Axis4.value(), pct);
    if (Controller.ButtonA.pressing()){
      clamp.open();
    }
    if (Controller.ButtonB.pressing()){
      clamp.close();
    }
    if (Controller.ButtonL1.pressing()){
      mogo.open();
    }
    if (Controller.ButtonL2.pressing()){
      mogo.close();
    }
    fbar.spin(fwd, 100*((!fbarButton2.pressing())*Controller.ButtonR1.pressing() - (!fbarButton.pressing())*Controller.ButtonR2.pressing()), pct);
    wait(20, msec);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  clamp.open();
  mogo.open();
  Competition.autonomous(auton);
  Competition.drivercontrol(opcontrol);
}
