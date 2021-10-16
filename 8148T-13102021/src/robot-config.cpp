#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller;
competition Competition;
motor L1(PORT20, false);//topleft
motor L2(PORT19, true); //bottomleft
motor L3(PORT17, true); //backleft
motor_group l(L1, L2, L3);
motor R1(PORT11, true);//topright
motor R2(PORT12, false);//bottomright
motor R3(PORT14, false);//backright
motor_group r(R1, R2, R3);
motor fourbarl (PORT8, false);
motor fourbarr(PORT4, true);
motor_group fbar(fourbarl, fourbarr);
pneumatics mogo(Brain.ThreeWirePort.D);
pneumatics clamp(Brain.ThreeWirePort.C);
bumper fbarButton(Brain.ThreeWirePort.H);
bumper fbarButton2(Brain.ThreeWirePort.F);



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) 
{
  fourbarl.setBrake(hold);
  fourbarr.setBrake(hold);
  // Nothing to initialize
}