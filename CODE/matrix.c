//
//  matrix.c
//  
//
//  Created by yoyojacky on 14-10-6.
//
//

#include <stdio.h>
#include <wiringPi.h>
#include <sr595.h>

void unblue_setled(int line){
    digitalWrite(124 + line, LOW);
};

void blue_setled(int line, unsigned char data){
	digitalWrite(100,data&0x80);
	digitalWrite(101,data&0x40);
	digitalWrite(102,data&0x20);
	digitalWrite(103,data&0x10);
	digitalWrite(104,data&0x08);
	digitalWrite(105,data&0x04);
	digitalWrite(106,data&0x02);
	digitalWrite(107,data&0x01);
    
    digitalWrite(124 + line, HIGH);
}

void red_setled(int line, unsigned char data){
	digitalWrite(116,data&0x80);
	digitalWrite(117,data&0x40);
	digitalWrite(118,data&0x20);
	digitalWrite(119,data&0x10);
	digitalWrite(120,data&0x08);
	digitalWrite(121,data&0x04);
	digitalWrite(122,data&0x02);
	digitalWrite(123,data&0x01);
    
    digitalWrite(124 + line, HIGH);
}
void green_setled(int line, unsigned char data){
	digitalWrite(108,data&0x80);
	digitalWrite(109,data&0x40);
	digitalWrite(110,data&0x20);
	digitalWrite(111,data&0x10);
	digitalWrite(112,data&0x08);
	digitalWrite(113,data&0x04);
	digitalWrite(114,data&0x02);
	digitalWrite(115,data&0x01);
    
    digitalWrite(124 + line, HIGH);
}
void testled(){
	char ledpoint[8] = {
        0xFF,0xc9,0xb6,0xbe,0xdd,0xeb,0xf7,0xff
    };
	for (int point=0; point<=7; point++){
        blue_setled(point,ledpoint[point]);
        delay(0.8);
        unblue_setled(point);
    }
};

int main(int argc, char *argv[])
{
    int j;
    long long k;
    wiringPiSetup();
    sr595Setup(100, 32, 12, 14, 10);
    for(j = 0; j < 32; j++)
    {
        pinMode(100 + j, OUTPUT);
    }
    for(j = 0; j < 8; j++)
    {
        digitalWrite(100 + j, 1);
    }
    for(j = 0; j < 8; j++)
    {
        digitalWrite(116 + j, 1);
    }
    for(j = 0; j < 8; j++)
    {
        digitalWrite(108 + j, 1);
    }
    
    for(;;){
        testled();
	}
}