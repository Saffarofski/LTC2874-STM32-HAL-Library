# LTC2874-STM32-HAL-Library
This is a translation from https://github.com/analogdevicesinc/Linduino/blob/master/LTSketchbook/libraries/LTC2874/LTC2874.h library to stm32 HAL functions.


# HOW TO USE?
It's very easy to use this library.
First of all define the spi channel which is connected to LTC2874 chip :

![alt text](https://github.com/Saffarofski/LTC2874-STM32-HAL-Library/blob/master/Pics/1.webp?raw=true)

Then define the cs pin of chip as "GPIO - push pull"

![alt text](https://github.com/Saffarofski/LTC2874-STM32-HAL-Library/blob/master/Pics/2.webp?raw=true)

After building the project , you have to add library files to your project as the following steps :
1- Add Inc file to "Project ==> Properties ==> C/C++ General ==> Paths and Symbol==> Includes ==> GNU C
![alt text](https://github.com/Saffarofski/LTC2874-STM32-HAL-Library/blob/master/Pics/3.webp?raw=true)

2- And for linker to know where your .c file located(), you need to add the folder to Link Folder add Src file to:
Project ==> Properties ==> C/C++ General ==> Paths and Symbol ==> Source Location ==> Link Folder 
![alt text](https://github.com/Saffarofski/LTC2874-STM32-HAL-Library/blob/master/Pics/4.webp?raw=true)

