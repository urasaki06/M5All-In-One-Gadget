#include "MdMeasureDistance.h"
#include <Arduino.h>
#include "DrUltraSonic.h"
#include "M5All-In-One-Gadget.h"

DrUltraSonic drul = DrUltraSonic(ECHO_PIN, TRIG_PIN);	


/*変数distanceに超音波センサーから取得した値を距離(cm単位)に変換して格納する。distanceを返す。*/
double MdMeasureDistance::getDistance()
{
    double distance;
    double t =  drul.measureReturnTime();
    if(t > 0){
    distance = (340.0/1000000) * t * 0.5 * 100;//m→cmなので100倍する
    }else{
    distance = 0; 
    }
    if(distance >= 400){
    distance = 0;    
    }
    return distance;
}	
