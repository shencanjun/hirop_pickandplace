#include "hsr_grab_operation.h"

hsr_grab_operation::hsr_grab_operation()
{ 
}

int hsr_grab_operation::gripper_init()
{
    return serial_open("dev/ttyS0", 115200);
}

int hsr_grab_operation::gripper_open()
{
	return _gripper_open(500);
}

int hsr_grab_operation::gripper_close()
{
	return _gripper_close(600,500);
}

int hsr_grab_operation::serial_open(std::string serialNo,int baudrate)
{
	client_serialOpen = n_gripper.serviceClient<hsr_gripper_driver::serial_open_srv>("serial_open");
    hsr_gripper_driver::serial_open_srv serialOpen_srv;
    serialOpen_srv.request.serialNo = serialNo;
    serialOpen_srv.request.baudrate = baudrate;
    if(client_serialOpen.call(serialOpen_srv))
	{
		std::cout<<"Serial Port opened!!!"<<std::endl;
	}
	else
	{
		std::cout<<"Unable to open port!!!"<<std::endl;
	}	
}

int hsr_grab_operation::_gripper_open(int speed)
{
	client_gripperOpen = n_gripper.serviceClient<hsr_gripper_driver::open_srv>("gripper_open");
    hsr_gripper_driver::open_srv gripperOpen_srv;
	gripperOpen_srv.request.speed = speed;
	if(client_gripperOpen.call(gripperOpen_srv))
	{
		std::cout<<"Open the Gripper sucessful!!!"<<std::endl;
	}
	else
	{
		std::cout<<"Open the Gripper failed!!!"<<std::endl;
	}	
}

int hsr_grab_operation::_gripper_close(int speed, int force)
{
	client_gripperClose = n_gripper.serviceClient<hsr_gripper_driver::close_srv>("gripper_close");
    hsr_gripper_driver::close_srv gripperClose_srv;
				
	gripperClose_srv.request.speed = speed;
	gripperClose_srv.request.force = force;
				
	if(client_gripperClose.call(gripperClose_srv))
	{
		std::cout<<"Close the Gripper sucessful!!!"<<std::endl;

	}
	else
	{
		std::cout<<"Close the Gripper failed!!!"<<std::endl;
	}
}

 H_EXPORT_PLUGIN(hsr_grab_operation, "hsr_grab_operation", "1.0")