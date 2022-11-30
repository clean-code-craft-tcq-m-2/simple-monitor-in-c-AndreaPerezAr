#include <stdio.h>

#define MINTEMP 0
#define MAXTEMP 45
#define MINSOC 20
#define MAXSOC 80
#define MINCHARGE 0.8 

int compareOneLimit (float value, float limit);
int compareTwoLimits (float value, float minlimit, float uplimit);

int checkTemperature(float temperature);
int checkSoc(float soc);
int checkChargeRate(float chargeRate);

int batteryIsOk(float temperature, float soc, float chargeRate);
