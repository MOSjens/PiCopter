#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define shutdownButton 13
#define resetButton 26

int main(void)
{
	if(wiringPiSetupGpio() == -1)
	{
		printf("set up wiring Pi failed!");
		return 1;
	}
	printf("Setup Successful!");
	
	pinMode(shutdownButton, OUTPUT);
	pinMode(resetButton, OUTPUT);
	
	while(1)
	{
		if (digitalRead(shutdownButton) == HIGH)
		{
			// shutdown 
			system("sudo shutdown -h now");
			printf("button bressed!");
			
		}
		if (digitalRead(resetButton) == HIGH )
		{
			system("sudo shutdown -r now");
		}
		delay(1000);
	}
	
	
	return 0;
}
