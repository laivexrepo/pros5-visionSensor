#include "main.h"
#include "portdef.h"
#include "globals.h"

/**
 * A callback functions go here
 */

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	// Initialize the vision sensor
	pros::Vision vision_sensor (VISION_PORT);
  vision_sensor.clear_led();										// clear the reporting LED state
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
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// Create the signatures used by vision sensor to detect objects
	pros::vision_signature_s_t RED_SIG =
		pros::Vision::signature_from_utility(1, 6807, 7693, 7250, -739, 231, -254, 3.000, 0);

	pros::vision_signature_s_t GREEN_SIG =
		pros::Vision::signature_from_utility(2, -5843, -4925, -5384, -1399, 431, -484, 3.000, 0);

	pros::vision_signature_s_t BLUE_SIG =
		pros::Vision::signature_from_utility(3, -3277, -2435, -2856, 9831, 11915, 10873, 3.000, 0);

	while (true) {

		pros::delay(20);
	}
}
