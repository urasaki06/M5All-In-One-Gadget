/* インクルードガード */
#pragma once
#include "M5All-In-One-Gadget.h"
#include <Arduino.h>

class MdWBGTMonitor // classの定義
{
private: // privateはクラス内からしかアクセスできない
public: // publicはどこからでもアクセス可能
/*DrTHSensor::init()　を実行し温湿度センサーの初期化を行う。*/
void init();
/*温湿度を取得し、その値からWBGTを算出する。計算結果をもとにアラートの分類分けを行い	
SAFE～DANGERの値をindexのアドレスに格納する。	*/
void getWBGT(double* temperature, double* humidity, WbgtIndex* index);

};
