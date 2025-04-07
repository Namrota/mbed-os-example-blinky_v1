/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

#define EXTERNAL_LED1  PB_13
#define EXTERNAL_LED2  PB_14
#define EXTERNAL_LED3  PB_15

#define BUTTON_1     PC_5
#define BUTTON_2     PC_6
#define BUTTON_3     PC_10

int main()
{
    // Initialise the digital pin LED1 as an output
    
    //DigitalOut led(LED1);
    DigitalOut led1(EXTERNAL_LED1);
    DigitalOut led2(EXTERNAL_LED2);
    DigitalOut led3(EXTERNAL_LED3);

    DigitalIn  button1(BUTTON_1, PinMode:: PullUp);
    DigitalIn  button2(BUTTON_2, PinMode:: PullUp);
    DigitalIn  button3(BUTTON_3, PinMode:: PullUp);

    while (true) {
        if (!button1){
            led1 = !led2;
            led2 = !led2;
        }else if(!button2){
            led2= !led3;
            led3= !led3;
        }
        else{
            led3= !led1;
            led1= !led1;
        }
        
        ThisThread::sleep_for(BLINKING_RATE);
    } 
}
