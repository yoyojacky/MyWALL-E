int i,val;
char a[3];
boolean display;
#include <Servo.h> 
Servo servo1;
 
void setup()
{
  Serial.begin(9600);
  servo1.attach(4);//舵機一接pin4
}
 
void loop()
{
  if (Serial.available()){        //如果有数据输入.....
    delay(30);                    //等待30毫秒让所有输入数据从串口传输完毕.....
    if (Serial.available() <= 3){ //如果输入数据位数'<=3'.....
      while (Serial.available()){ //开始读取数据直到[串口输入缓存被清空]
        a[i++] = Serial.read();   //读取数据到[数组"a"]
      }
      display = 1;                    //数据读取完毕以后'打开'显示输出开关
    }
    else {                        //如果输入数据位数'>3'.....
      Serial.flush();             //刷新串口输入缓存
    }
  }
/*======================直接通过串口返回输入数值模块======================
  if (display)                    //如果[显示输出开关]被'打开'则显示[数组"a"]的数据
  {
    for (i = 0; i <= sizeof(a); i++)
    {
     Serial.print("a[");
     Serial.print(i);
     Serial.print("]= ");
      Serial.print(a[i]);
      Serial.print(" | ");
    }
    Serial.println();
    display = 0;                  //显示完毕'关闭'显示输出开关
    Serial.flush();               //刷新串口输入缓存
    for (i = 0; i <= 3; i++)      //重置[数组"a"]
    {
      a[i] = 0;
    }
    i = 0;                        //重置"计数变量"[i]
  }
//=======================通过加减符号控制舵机增减一度转动=================*/
if (a[0] == 43 && display){
val++;
servo1.write(val);
Serial.println(val);
    display = 0;                  //显示完毕'关闭'显示输出开关
    Serial.flush();               //刷新串口输入缓存
    for (i = 0; i <= 3; i++)      //重置[数组"a"]
    {
      a[i] = 0;
    }
    i = 0;                        //重置"计数变量"[i]
}
if (a[0] == 45 && display){
val--;
servo1.write(val);
Serial.println(val);
    display = 0;                  //显示完毕'关闭'显示输出开关
    Serial.flush();               //刷新串口输入缓存
    for (i = 0; i <= 3; i++)      //重置[数组"a"]
    {
      a[i] = 0;
    }
    i = 0;                        //重置"计数变量"[i]
}
 
//========================判断及修正输入数据位数模块======================
if (display)                    //如果[显示输出开关]被'打开'则显示[数组"a"]的数据
  {
   if (!a[2]){ //如果输入数据为两位数(最后一位空)
   if (!a[1]){ //如果输入数据为一位数(最后两位空)
   a[2] = a[0];
   a[1] = 48;
   a[0] = 48;
   }
   else { 
   a[2] = a[1];
   a[1] = a[0];
   a[0] = 48;
   }
   }
//==============转换变量类型后输出给舵机且通过串口返回结果值==============
for (i=0;i<=3;i++){ //变量类型:char to int (48为0的ASCII)
a[i] -= 48;
}
val = 100*a[0] + 10*a[1] + a[2];
// Serial.print("val: ");
servo1.write(val);
Serial.println(val);
 
/* int val2 = random(50); //int型变量加法测试
val += val2;
Serial.print("+");
Serial.print(val2);
Serial.print("=");
Serial.println(val);
*/
    display = 0;                  //显示完毕'关闭'显示输出开关
    Serial.flush();               //刷新串口输入缓存
    for (i = 0; i <= 3; i++)      //重置[数组"a"]
    {
      a[i] = 0;
    }
    i = 0;                        //重置"计数变量"[i]
//    val = 0;
}
}
