# LTC2874-STM32-HAL-Library
This is a translation from https://github.com/analogdevicesinc/Linduino/blob/master/LTSketchbook/libraries/LTC2874/LTC2874.h library to stm32 HAL functions.


# HOW TO USE?
It's very easy to use this library.
First of all define the spi channel which is connected to LTC2874 chip :

![alt text](https://github.com/Saffarofski/LTC2874-STM32-HAL-Library/blob/master/Pics/1.webp?raw=true)

Then define the cs pin of chip as "GPIO - push pull"

![alt text](https://github.com/Saffarofski/LTC2874-STM32-HAL-Library/blob/master/Pics/2.webp?raw=true)

after building the project , you have to add library files to your project as the following steps :
