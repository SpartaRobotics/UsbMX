/*
    Example for moving at variable speeds on the Dynamixel MX28-AT series servos
    
	Serial:
	USB  UART: "/dev/ttyUSB0"
	
	*Moves the servo to the selected position (in degrees) at variable speed
	Position (180 to 0) moves on the left, 0 stops in the middle, (0 to -180) moves to the right
		UMX.moveSpeedDeg(ID, -180 to 180, 0->4095): 0->360 degrees
		
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

	control.setEndless(ID, OFF); // Sets the servo to "Servo" mode
    
    for(int i = 0; i < 3; i ++)
    {
    	control.moveSpeedDeg(ID, 180, 1023);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 150, 1023);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 120, 768);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 90, 512);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 60, 256);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 30, 128);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, 0, 0);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -30, 128);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -60, 256);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -90, 512);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -120, 768);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -150, 1023);
        usleep(2*SEC);
        
        control.moveSpeedDeg(ID, -180, 1023);
        usleep(2*SEC);
        
    }
    
    control.disconnect();
    return 0;
}

