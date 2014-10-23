/* My Led with JoyStick code */
//
//  LedWithJoyStick.c
//  LedWithJoystick
//
//  Created by yoyojacky on 14-10-7.
//  Copyright (c) 2014年 yoyojacky.vicp.net. All rights reserved.
//

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <pcf8591.h>


int main(){
    
    int y;
    int x;
    wiringPiSetupPhys();
    
    pinMode(7,INPUT);
    pinMode(16,OUTPUT);
    
    pcf8591Setup(100,0x48);
    softPwmCreate(11, 0,100);
    softPwmCreate(12, 0,100);
    
    for(;;){
        y = analogRead(100)/2.55;
        x = analogRead(101)/2.55;
        printf("JoyStick Y = %d\n",y);
        printf("JoyStick X = %d\n",x);
        softPwmWrite(11,y);
        softPwmWrite(12,x);
        digitalWrite(16,digitalRead(7));
        
    }
}
