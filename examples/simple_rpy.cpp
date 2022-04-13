/* Simple example that prints the roll pitch and yaw measurements from the IMU */

#include "MPU9250.h"
#include <cstdio>

MPU9250 mpu;

int main() {
    mpu.verbose(true); // verbose mode to print debug messages
    mpu.setup(0x68);
    
    mpu.calibrateAccelGyro();
    mpu.calibrateMag();

    while(true) {
        mpu.update();
        printf("% .3f % .3f % .3f\n", mpu.getRoll(), mpu.getPitch(), mpu.getYaw());
        sleep(0.1);
    }
}