#include "MdWBGTMonitor.h"
#include <M5Stack.h>
#include "DrTHSensor.h"

DrTHSensor dthsen;

/*DrTHSensor::init()　を実行し温湿度センサーの初期化を行う。*/
void MdWBGTMonitor::init()
{
    dthsen.init();
}

void MdWBGTMonitor::getWBGT(double* temperature, double* humidity, WbgtIndex* index)
{
    double temp = 0;
    double hum = 0;
    dthsen.getTempHumi(&temp, &hum);

/*熱中症アラートの基準値計算には次の式で計算する*/
int calc_index = 0.68 * temp + 0.12 * hum;

*temperature = temp;
*humidity = hum; 

if(calc_index <= 15) {
        *index = SAFE;
    } else if (calc_index <= 25) {
        *index = ATTENTION;
    } else if (calc_index <= 27) {
        *index = ALERT;
    }else if (calc_index <= 30) {
        *index = HIGH_ALERT;      
    }  else {
        *index = DANGER;   
    }
   
}




