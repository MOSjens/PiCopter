/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int reg65 = 235;
    int reg66 = 208;
    
    short int temp = reg65 << 8;
    temp += reg66;
    
    // Look at datasheet
    double dTemp = (temp / 340.0) + 36.53;
    
    printf("Temp: %lf", dTemp);

    return 0;
}
