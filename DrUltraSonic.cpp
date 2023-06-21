#include "DrUltraSonic.h"
#include <Arduino.h>
#include <M5Stack.h>
#include "M5All-In-One-Gadget.h"



/*引数で与えられたピン番号を使ってECHOピンを入力、
TRIGGERピンを出力に設定する。*/
DrUltraSonic::DrUltraSonic(int echo_pin, int trig_pin){
    pinMode(echo_pin, INPUT);
    pinMode(trig_pin, OUTPUT);
}

/*超音波を発生させてから返ってくるまでの時間を変数 ｔ に格納する*/
    double DrUltraSonic::measureReturnTime()
    {
    digitalWrite(TRIG_PIN, HIGH); /* トリガ信号をHIGH（5V）に設定 */
    delayMicroseconds(10); /* 10マイクロ秒の間トリガ信号を保持 */
    digitalWrite(TRIG_PIN, LOW); /* トリガ信号をLOW（0V）に設定 */
    double t ;
    t = pulseIn(ECHO_PIN, HIGH);
    return t ;
    }
  

