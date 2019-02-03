#include "main.h"
#include "robotstate.h"
#include "robotconfig.h"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

Motor mFrontLeft(1);
Motor mFrontRight(2, true);
Motor mBackLeft(3);
Motor mBackRight(4, true);

Motor mIntake(5);
Motor mPuncher(6);
Motor mFlippy(18, true);
Motor mLift(8, true);

Controller controlMaster(CONTROLLER_MASTER);
Controller controlPartner(CONTROLLER_PARTNER);

bool hasCalibrated;

void startTask();

void initialize() {
	#include "robotconfig.h"
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	pros::lcd::register_btn1_cb(on_center_button);

	hasCalibrated = false;
	startTask();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}