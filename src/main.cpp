#include "main.h"
#include "portdef.h"
#include "globals.h"
#include "vision.h"

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
	vision_sensor.set_wifi_mode(0);								// disable WiFi on sensor - defualt behavior!
																								// if connected to vision sensor via WiFi
																								// the V5 brain can not communicate with it!
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
	std::cout << "Entering OPCONTROL prior to signature initialization \n";

	// Create the signatures used by vision sensor to detect objects.  We created these
	// signatures, using the Vision Utility - these now need to be loaded back into the
	// vision sensor on program start
	pros::vision_signature_s_t RED_SIG =
		pros::Vision::signature_from_utility(RED_SIGNATURE, 6807, 7693, 7250, -739, 231, -254, 3.000, 0);

	pros::vision_signature_s_t GREEN_SIG =
		pros::Vision::signature_from_utility(GREEN_SIGNATURE, -5843, -4925, -5384, -1399, 431, -484, 3.000, 0);

	pros::vision_signature_s_t BLUE_SIG =
		pros::Vision::signature_from_utility(BLUE_SIGNATURE, -3277, -2435, -2856, 9831, 11915, 10873, 3.000, 0);

  // load detection signatures into the vision sensor for use.
	vision_sensor.set_signature(RED_SIGNATURE, &RED_SIG);
	vision_sensor.set_signature(GREEN_SIGNATURE, &GREEN_SIG);
	vision_sensor.set_signature(BLUE_SIGNATURE, &BLUE_SIG);


	while (true) {
		pros::vision_object_s_t rtn_red = vision_sensor.get_by_sig(0, RED_SIGNATURE);
    // Gets the largest object of the EXAMPLE_SIG signature
    std::cout << "sig: " << rtn_red.signature << " RED ";

		pros::vision_object_s_t rtn_green = vision_sensor.get_by_sig(0, GREEN_SIGNATURE);
    // Gets the largest object of the EXAMPLE_SIG signature
    std::cout << "sig: " << rtn_green.signature << " GREEN ";

		pros::vision_object_s_t rtn_blue = vision_sensor.get_by_sig(0, BLUE_SIGNATURE);
    // Gets the largest object of the EXAMPLE_SIG signature
    std::cout << "sig: " << rtn_blue.signature << " BLUE \n";

    // print the coordinates of the detected RED object
		std::cout << "RED -- Left: " << rtn_red.left_coord << " Top: " << rtn_red.top_coord;
		std::cout << " Width: " << rtn_red.width << " Height: " << rtn_red.height;
		std::cout << " x_middle: " << rtn_red.x_middle_coord;
		std::cout << " y_middle: " << rtn_red.y_middle_coord << " \n";

		// print the coordinates of the detected GREEN object
		std::cout << "GREEN -- Left: " << rtn_green.left_coord << " Top: " << rtn_green.top_coord;
		std::cout << " Width: " << rtn_green.width << " Height: " << rtn_green.height;
		std::cout << " x_middle: " << rtn_green.x_middle_coord;
		std::cout << " y_middle: " << rtn_green.y_middle_coord << " \n";

		// print the coordinates of the detected BLUE object
		std::cout << "BLUE -- Left: " << rtn_blue.left_coord << " Top: " << rtn_blue.top_coord;
		std::cout << " Width: " << rtn_blue.width << " Height: " << rtn_blue.height;
		std::cout << " x_middle: " << rtn_blue.x_middle_coord;
		std::cout << " y_middle: " << rtn_blue.y_middle_coord << " \n";

    // Prints "sig: 1"
		pros::delay(200);
	}
}
