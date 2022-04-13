# MPU9250-RPi
Ported [hideakitai's Arduino MPU9250](https://github.com/hideakitai/MPU9250) library to run on the Raspberry Pi.

This library has been tested on a Raspberry Pi 4B with 8 GB RAM, running Ubuntu Server 20.04.

## Wiring
Connect the MPU9250 to the Pi's I2C bus. GPIO2 corresponds to SDA and GPIO3 corresponds to SCL.

| RPi | MPU |
| --- | --- |
| 5V  | 5V  |
| GND | GND |
| GPIO2 | SDA |
| GPIO3 | SCL |

Verify the connection by using the ```i2cdetect``` tool.

```
sudo apt install i2c-tools
i2cdetect -y 1
```

It should show the following output, indicating that the MPU9250 at address 0x68 and the AK8963 magnetometer at 0x0C.
```
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- 0c -- -- -- 
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
60: -- -- -- -- -- -- -- -- 68 -- -- -- -- -- -- -- 
70: -- -- -- -- -- -- -- --                         
```

## Installation
Follow the commands to install the library and run the example:

```
sudo apt install libi2c-dev
git clone https://github.com/sdfcl-iitk/MPU9250-RPi
cd MPU9250-Rpi
mkdir build
cd build
cmake ..
make
./simple_rpy
```

The simple example prints the roll pitch yaw from the IMU:
```
MPU9250 WHO AM I = 0x71
AK8963 WHO AM I = 0x48
Mag Factory Calibration Values: 
X-Axis sensitivity offset value 1.207
Y-Axis sensitivity offset value 1.219
Z-Axis sensitivity offset value 1.164
Mag Factory Calibration Values: 
X-Axis sensitivity offset value 1.207
Y-Axis sensitivity offset value 1.219
Z-Axis sensitivity offset value 1.164
Mag Calibration: Wave device in a figure eight until done!
mag x min/max: 0 377
mag y min/max: -106 0
mag z min/max: 0 346
Mag Calibration done!
AK8963 mag biases (mG) 340.244, -96.851, 301.951
AK8963 mag scale (mG) 0.722, 2.562, 0.816
Mag Factory Calibration Values: 
X-Axis sensitivity offset value 1.207
Y-Axis sensitivity offset value 1.219
Z-Axis sensitivity offset value 1.164
 0.000 -0.000 -7.510
 0.000 -0.000 -7.510
 0.000 -0.000 -7.510
 0.000 -0.000 -7.510
 0.000 -0.000 -7.510
-0.193  0.349 -7.296
-0.193  0.349 -7.296
-0.193  0.349 -7.296
-0.309  0.552 -7.168
-0.309  0.552 -7.168
-0.309  0.552 -7.168
```