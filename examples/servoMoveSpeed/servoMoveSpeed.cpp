/*
    Example for moving at variable speeds on the Dynamixel MX28-AT series servos
    
	Serial:
	USB  UART: "/dev/ttyUSB0"

	*Moves the servo to a selected position at the desired speed
		UMX.moveSpeed(ID, 0->4095, 0->1023): 0->360 degrees
*/

#include<iostream>
#include "UsbMX.h"

#define ID 1        // ID for singl servo
#define SEC 1000000 // 1 Second in micro second units for delay
#define MSEC 1000	// 1 milli second in micro second units for delay

using namespace std;

int main()
{
    UsbMX control;

	control.begin("/dev/ttyUSB0", B1000000);
    
    control.setEndless(ID, OFF);
    
    for(int i = 0; i < 3; i++)
    {
		control.moveSpeed(ID, 0, 1023);
		usleep(2*SEC);
		control.moveSpeed(ID, 1024, 100);
		usleep(2*SEC);
		control.moveSpeed(ID, 2048, 300);
		usleep(2*SEC);
		control.moveSpeed(ID, 3072, 256);
		usleep(2*SEC);
		control.moveSpeed(ID, 4095, 768);
		usleep(2*SEC);
		control.moveSpeed(ID, 3072, 256);
		usleep(2*SEC);
		control.moveSpeed(ID, 2048, 50);
		usleep(2*SEC);
		control.moveSpeed(ID, 1024, 512);
		usleep(2*SEC);

    }
    
    control.disconnect();
    return 0;
}

