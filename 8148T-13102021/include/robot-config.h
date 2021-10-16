using namespace vex;

extern brain Brain;
extern controller Controller;
extern motor_group l;
extern motor_group r;
extern motor_group fbar;
extern pneumatics mogo;
extern pneumatics clamp;
extern competition Competition;
extern bumper fbarButton;
extern bumper fbarButton2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
