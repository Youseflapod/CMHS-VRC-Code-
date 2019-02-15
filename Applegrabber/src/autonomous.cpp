#include "main.h"
#include "robotstate.h"
#include "robotconfig.h"
#include "controllibrary.h"


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

  drive(18, 0.5, 1, 5, 200);
  drive(-18, 0.03, 1, 5, 200);

  //rotate(360, 0.5, 5, 15, 200);

}
