#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>


int main(void)
{
	if(wiringPiSetupGpio() == -1)
	{
		printf("set up wiring Pi failed!");
		return 1;
	}
	printf("Setup Successful!\n");
	
	int fd = wiringPiI2CSetup(0x68);
	
	printf("%i\n", fd);
	
	while (1)
	{
		int val = wiringPiI2CReadReg8(fd, 65);
		printf("value: %i \n", val);
		delay(100);
	}
	
	
	return 0;
}
