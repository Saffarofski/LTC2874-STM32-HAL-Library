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

2- And then add Src file to:
Project ==> Properties ==> C/C++ General ==> Paths and Symbol ==> Source Location ==> Link Folder 
![alt text](https://github.com/Saffarofski/LTC2874-STM32-HAL-Library/blob/master/Pics/4.webp?raw=true)

After that , all you need to do is to make a struct initialization from LTC2874_InitTypeDef type and put the required objects in it.Then pass it to "LTC2874_Init()" function to get started with library.
This part of code should be placed after calling the SPI and GPIO initialization functions.
Like the example below:
```c++
	//  Initialize LTC2874
	LTC2874_InitTypeDef myLtc2874;
	myLtc2874.CS_GPIO_PORT = LTC2874_CS_GPIO_Port;
	myLtc2874.CS_GPIO_Pin = LTC2874_CS_Pin;
	myLtc2874.SPI_Handler = &hspi1;
	LTC2874_Init(&myLtc2874);
```
now you are ready to use all functions of library which are defined in LTC2874_STM32_HAL_Library.h 🙂

for understanding the functions , you can take a look at datasheet :

https://www.analog.com/media/en/technical-documentation/data-sheets/2874fb.pdf

*Note that this library only handles the spi functions of the chip.
Other functions like uart channels or tx-enable pins hast to be handled by user

Since this is my first public library , it may contain alot of bugs or Incompleteness.
I'd be greateful if you help me improve this library and resolve problems.
