#include "hsr_grab_operation.h"

hsr_grab_operation::hsr_grab_operation()
{ 
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

int hsr_grab_operation::gripper_open_size(int grab_max,int grab_min)
{
	client_gripperOpenSize = n_gripper.serviceClient<hsr_gripper_driver::open_size_srv>("gripper_set_open_size");
    hsr_gripper_driver::open_size_srv gripperOpenSize_srv;

	gripperOpenSize_srv.request.max = grab_max;
	gripperOpenSize_srv.request.min = grab_min;
    if(client_gripperOpenSize.call(gripperOpenSize_srv)) 
	{
		std::cout<<"Set the open size of the Gripper sucessful!!!"<<std::endl;
	}
	else
	{
		std::cout<<"Set the open size of the Gripper failed!!!"<<std::endl;
	}	    
}

int hsr_grab_operation::gripper_open(int speed)
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

int hsr_grab_operation::gripper_close(int speed, int force)
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

int hsr_grab_operation::gripper_Stop()
{
	client_gripperStop = n_gripper.serviceClient<hsr_gripper_driver::stop_srv>("gripper_stop");
    hsr_gripper_driver::stop_srv gripperStop_srv;
				
	if(client_gripperStop.call(gripperStop_srv))
	{
		std::cout<<"Stop the Gripper sucessful!!!"<<std::endl;

	}
	else
	{
		std::cout<<"Stop the Gripper failed!!!"<<std::endl;
	}
}

 H_EXPORT_PLUGIN(hsr_grab_operation, "hsr_grab_operation", "1.0")