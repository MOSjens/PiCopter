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
	
	int regsiter[14];
	double values[7]; // ACC X Y Z, Temp, GYRO XYZ
	
	printf("write: %i \n", wiringPiI2CWriteReg8(fd, 107, 0));
	printf("write: %i \n", wiringPiI2CReadReg8(fd, 107));
	
	while (1)
	{
		for (int i = 59; i <= 72; i++)
		{
			regsiter[i - 59] = wiringPiI2CReadReg8(fd, i);
			//printf("%i: value: %i \n", i, regsiter[i - 59]);
		}
		
		for (int i = 0; i < 7; i++)
		{
			short int temp = regsiter[i * 2] << 8;
			temp += regsiter[i * 2 + 1];
			values[i] = temp;
			printf("Value at %i: %lf \n",i ,values[i] );
		}
		
    
		// Look at datasheet
		double dTemp = (values[3] / 340.0) + 36.53;
		printf("Temp: %lf \n", dTemp);
    
		delay(100);
	}
	
	return 0;
}
