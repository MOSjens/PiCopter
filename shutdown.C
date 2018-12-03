#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define shutdownButton 13
#define resetButton 26


unsigned long resetTime = 1000;
unsigned long shutdownTime = 1000;
unsigned long lastChangeTimeShutdown;
unsigned long lastChangeTimeReset;
int reading;

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
	
	bool a = true;
	bool b = true;
	
	while(1)
	{
		if (digitalRead(shutdownButton) == HIGH)
		{
			if (b)
			{
				b = false;
				lastChangeTimeShutdown = millis();
			}
			if (millis() - lastChangeTimeShutdown > shutdownTime)
			{
				// shutdown 
				system("sudo shutdown -h now");
			}
			
		}
		if (digitalRead(resetButton) == HIGH )
		{
			if (a)
			{
				a = false;
				lastChangeTimeReset = millis();
			}
			if (millis() - lastChangeTimeReset > resetTime)
			{
				// reset
				system("sudo shutdown -r now");
			}
		}
		delay(5000);
	}
	
	
	return 0;
}
