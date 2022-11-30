#include <stdio.h>
#include <assert.h>
#include "checker.h"

int compareOneLimit (float value, float limit){
    int retval=1;
    if(value > limit) {
        printf("out of range!\n");
        retval = 0;
    }
    else {
        printf("OK!\n");
    }
    return retval;
}

int compareTwoLimits (float value, float minlimit, float uplimit){
    int retval=1;
    if(value < minlimit || value > uplimit) {
        printf("out of range!\n");
        retval = 0;
    }
    else {
        printf("OK!\n");
    }
    return retval;
}

int checkTemperature(float temperature) {
    printf("Temperature ");
    return compareTwoLimits (temperature, MINTEMP, MAXTEMP);
}
int checkSoc(float soc) {
    printf("SOC ");
    return compareTwoLimits (soc, MINSOC, MAXSOC);
}
int checkChargeRate(float chargeRate){
    printf("Charge Rate ");
    return compareOneLimit (chargeRate, MINCHARGE);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return ((checkTemperature(temperature))&&(checkSoc(soc))&&(checkChargeRate(chargeRate)));
}

int main() {
  printf("ASSERT 1\n");
  assert(batteryIsOk(25, 70, 0.7)==1);          //All passed
  printf("ASSERT 2\n");
  assert(batteryIsOk(50, 85, 0)==0);            //Temp not OK
  printf("ASSERT 3\n");
  assert(batteryIsOk(0, 50, 0.5)==1);           //Test Min Temperature
  printf("ASSERT 4\n");
  assert(batteryIsOk(-1, 50, 0.5)==0);          //Test Min Temperature not OK
  printf("ASSERT 5\n");
  assert(batteryIsOk(45, 50, 0.5)==1);          //Test Max Temperature
  printf("ASSERT 6\n");
  assert(batteryIsOk(46, 50, 0.5)==0);          //Test Max Temperature not OK

  printf("ASSERT 7\n");
  assert(batteryIsOk(20, 90, 0.2)==0);          //SOC not OK
  printf("ASSERT 8\n");
  assert(batteryIsOk(20, 20, 0.2)==1);          //Test Min SOC
  printf("ASSERT 9\n");
  assert(batteryIsOk(20, 19, 0.2)==0);          //Test Min SOC not OK
  printf("ASSERT 10\n");
  assert(batteryIsOk(20, 80, 0.2)==1);          //Test Max SOC
  printf("ASSERT 11\n");
  assert(batteryIsOk(20, 81, 0.2)==0);          //Test Max SOC not OK

  printf("ASSERT 12\n");
  assert(batteryIsOk(30, 60, 2)==0);            //Charge Rate not OK
  printf("ASSERT 13\n");
  assert(batteryIsOk(30, 60, 0.8)==1);          //Test Min Charge Rate
  printf("ASSERT 14\n");
  assert(batteryIsOk(30, 60, 0.9)==0);          //Test Min Charge Rate not OK
}
