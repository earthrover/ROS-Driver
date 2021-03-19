#include <roboteq_motor_controller_driver/roboteq_motor_controller_driver_node.h>






int main(int argc, char** argv){
	ros::init(argc, argv, "roboteq_motor_controller_driver");

	roboteq::Driver driver;
	driver.connect();
	driver.roboteq_services();

	ROS_INFO_STREAM("LOADING MANUAL PROFILE");
	bool loaded = driver.load_manual_profile();
	if (loaded)
		ROS_INFO("LOADED PROFILE!");
	else
		ROS_WARN("COULD NOT LOAD MANUAL PROFILE");

	driver.run();

        ros::AsyncSpinner spinner(4);

	spinner.start();




	ros::waitForShutdown();
	//spinner.stop();

	return 0;


}
