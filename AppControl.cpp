#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>
#include <stdlib.h>

MdLcd mlcd;
MdWBGTMonitor mwbgt;
MdMusicPlayer mmplay;
MdMeasureDistance mmdist;
MdDateTime mdtime;


const char* g_str_orange[] = {
    COMMON_ORANGE0_IMG_PATH,
    COMMON_ORANGE1_IMG_PATH,
    COMMON_ORANGE2_IMG_PATH,
    COMMON_ORANGE3_IMG_PATH,
    COMMON_ORANGE4_IMG_PATH,
    COMMON_ORANGE5_IMG_PATH,
    COMMON_ORANGE6_IMG_PATH,
    COMMON_ORANGE7_IMG_PATH,
    COMMON_ORANGE8_IMG_PATH,
    COMMON_ORANGE9_IMG_PATH,
};

const char* g_str_blue[] = {
    COMMON_BLUE0_IMG_PATH,
    COMMON_BLUE1_IMG_PATH,
    COMMON_BLUE2_IMG_PATH,
    COMMON_BLUE3_IMG_PATH,
    COMMON_BLUE4_IMG_PATH,
    COMMON_BLUE5_IMG_PATH,
    COMMON_BLUE6_IMG_PATH,
    COMMON_BLUE7_IMG_PATH,
    COMMON_BLUE8_IMG_PATH,
    COMMON_BLUE9_IMG_PATH,
};

const char* g_str_heart [] = {
    TRUMP_HEART1_IMG_PATH,
    TRUMP_HEART2_IMG_PATH,
    TRUMP_HEART3_IMG_PATH,
    TRUMP_HEART4_IMG_PATH,
    TRUMP_HEART5_IMG_PATH,
    TRUMP_HEART6_IMG_PATH,
    TRUMP_HEART7_IMG_PATH,
    TRUMP_HEART8_IMG_PATH,
    TRUMP_HEART9_IMG_PATH,
};

const char* g_str_spade [] = {
    TRUMP_SPADE1_IMG_PATH,
    TRUMP_SPADE2_IMG_PATH,
    TRUMP_SPADE3_IMG_PATH,
    TRUMP_SPADE4_IMG_PATH,
    TRUMP_SPADE5_IMG_PATH,
    TRUMP_SPADE6_IMG_PATH,
    TRUMP_SPADE7_IMG_PATH,
    TRUMP_SPADE8_IMG_PATH,
    TRUMP_SPADE9_IMG_PATH,
};

void AppControl::setBtnAFlg(bool flg)
{
    m_flag_btnA_is_pressed = flg;
}

void AppControl::setBtnBFlg(bool flg)
{
    m_flag_btnB_is_pressed = flg;
}

void AppControl::setBtnCFlg(bool flg)
{
    m_flag_btnC_is_pressed = flg;
}

void AppControl::setBtnAllFlgFalse()
{
    m_flag_btnA_is_pressed = false;
    m_flag_btnB_is_pressed = false;
    m_flag_btnC_is_pressed = false;
}

State AppControl::getState()
{
    return m_state;
}

void AppControl::setState(State state)
{
    m_state = state;
}

Action AppControl::getAction()
{
    return m_action;
}

void AppControl::setAction(Action action)
{
    m_action = action;
}

void AppControl::setStateMachine(State state, Action action)
{
    setState(state);
    setAction(action);
}

FocusState AppControl::getFocusState()
{
    return m_focus_state;
}

void AppControl::setFocusState(FocusState fs)
{
    m_focus_state = fs;
}

void AppControl::displayTitleInit()
{
    mlcd.displayJpgImageCoordinate(TITLE_IMG_PATH, TITLE_X_CRD, TITLE_Y_CRD);
}

void AppControl::displayMenuInit()
{   
    mlcd.fillBackgroundWhite();			
    mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, COMMON_BUTTON_UP_X_CRD, COMMON_BUTTON_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, COMMON_BUTTON_DECIDE_X_CRD , COMMON_BUTTON_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, COMMON_BUTTON_DOWN_X_CRD , COMMON_BUTTON_DOWN_Y_CRD);
}

/*-----------------------------------------------------------------*/
void AppControl::focusChangeImg(FocusState current_state, FocusState next_state)
{
    if(current_state == MENU_WBGT){
        mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    }
    setFocusState(next_state);
    if(current_state == MENU_WBGT && next_state == MENU_MUSIC){
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    }
    else if(current_state == MENU_WBGT && next_state == MENU_DATE){
        mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD); 
        mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    }
    else if(current_state == MENU_MUSIC && next_state == MENU_MEASURE){
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    }
    else if(current_state == MENU_MUSIC && next_state == MENU_WBGT){
        mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    }
    else if(current_state == MENU_MEASURE && next_state == MENU_DATE){
        mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    }
    else if(current_state == MENU_MEASURE && next_state == MENU_MUSIC){
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    }
    else if(current_state == MENU_DATE && next_state == MENU_WBGT){
        mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    }
    else if(current_state == MENU_DATE && next_state == MENU_MEASURE){
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    }
}
/*-----------------------------------------------------------------------*/
/*熱中症モニタの画面を描画し、 関数 displayTempHumiIndex()を呼び出す	*/
void AppControl::displayWBGTInit()
{
    mlcd.fillBackgroundWhite();
    displayTempHumiIndex();	
    mlcd.displayJpgImageCoordinate(WBGT_TEMPERATURE_IMG_PATH, WBGT_TEMPERATURE_X_CRD, WBGT_TEMPERATURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_HUMIDITY_IMG_PATH, WBGT_HUMIDITY_X_CRD, WBGT_HUMIDITY_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_DEGREE_IMG_PATH, WBGT_DEGREE_X_CRD, WBGT_DEGREE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_PERCENT_IMG_PATH, WBGT_PERCENT_X_CRD, WBGT_PERCENT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, WBGT_BACK_X_CRD, WBGT_BACK_Y_CRD);	    
}

void AppControl::displayTempHumiIndex()
{
    Serial.println("WBGT ENTRY");
    mwbgt.init();
    double temp = 0.0;
    double hum = 0.0;
    WbgtIndex ind = SAFE;
    mwbgt.getWBGT((double*)&temp, (double*)&hum, (WbgtIndex*)&ind);
    Serial.print(temp);
    Serial.println("[℃]");
    Serial.print(hum);
    Serial.println("[%]");
    Serial.print(ind);
    Serial.println("[アラート]");

    /*温度を1つずつ取り出す 二桁目*/
    int t2DIGIT = temp / 10;
    mlcd.displayJpgImageCoordinate(g_str_orange[t2DIGIT], WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
    
    /*温度を取り出す　一桁目*/
    int t1DIGIT = (int)temp % 10;
    mlcd.displayJpgImageCoordinate(g_str_orange[t1DIGIT], WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);

    /*ドット*/
    mlcd.displayJpgImageCoordinate(COMMON_ORANGEDOT_IMG_PATH, WBGT_TDOT_X_CRD, WBGT_TDOT_Y_CRD);

    /* 温度の小数部分を取得 */
    int tempDec = (int)(temp * 10) % 10;
    mlcd.displayJpgImageCoordinate(g_str_orange[tempDec], WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
    /* 二桁目の数字がない場合は白塗りの画像を表示 */
    if(t2DIGIT == 0 ){
    mlcd.displayJpgImageCoordinate(COMMON_ORANGEFILLWHITE_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
    }

    /*湿度を1つずつ取り出す　二桁目*/
    int h2DIGIT = hum /10;
    mlcd.displayJpgImageCoordinate(g_str_blue[h2DIGIT], WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);

    /*条件式を書く　湿度を取り出す　一桁目*/
    int h1DIGIT = (int)hum % 10;
    mlcd.displayJpgImageCoordinate(g_str_blue[h1DIGIT], WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);

     /*ドット*/
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, WBGT_HDOT_X_CRD, WBGT_HDOT_Y_CRD);


 /* 湿度の小数部分を取得 */
    int humDec = (int)(hum * 10) % 10;
     mlcd.displayJpgImageCoordinate(g_str_blue[humDec], WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);

    /* 二桁目の数字がない場合は白塗りの画像を表示 */
    if(h2DIGIT == 0 ){
    mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
    }
/*条件式を書く　アラート*/
    if(ind == SAFE){
        mlcd.displayJpgImageCoordinate(WBGT_SAFE_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
    }
    else if(ind == ATTENTION){
        mlcd.displayJpgImageCoordinate(WBGT_ATTENTION_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
    }
    else if(ind == ALERT){
        mlcd.displayJpgImageCoordinate(WBGT_ALERT_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
    }  
    else if(ind == HIGH_ALERT){
    mlcd.displayJpgImageCoordinate(WBGT_HIGH_ALERT_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD); 
    }
    else{
    mlcd.displayJpgImageCoordinate(WBGT_DANGER_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
    }
    delay(100);
}
/*--------------------------------------------------------------*/
/*音楽停止画面を描画し、displayMusicTitle()を呼出して音楽ファイルのファイル名を描画する。*/
void AppControl::displayMusicInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_PLAY_X_CRD, MUSIC_PLAY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
    displayMusicTitle();
}
/*音楽停止画面を描画する*/
void AppControl::displayMusicStop()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_PLAY_X_CRD, MUSIC_PLAY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
    displayMusicTitle();
}
/*関数 MdMusicPlayer::getTitle()により音楽ファイルのファイル名を取得し、それを描画する*/
void AppControl::displayMusicTitle()
{
    mmplay.getTitle();
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);			
}
/*関数 MdMusicPlayer::selectNextMusic()により次の音楽ファイルを開き、displayMusicTitle()でそのファイル名を描画する*/
void AppControl::displayNextMusic()
{
    mmplay.selectNextMusic();
    displayMusicTitle();
}

/*音楽再生画面を描画する*/
void AppControl::displayMusicPlay()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWPLAYING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_STOP_IMG_PATH, MUSIC_PLAY_X_CRD, MUSIC_PLAY_Y_CRD);
    displayMusicTitle();
}
/*-------------------------------------------------------------*/
/*距離測定画面の初期画面を描画する。
関数 displayMeasureDistance()を呼出し現在の測定距離を描画する*/
void AppControl::displayMeasureInit()
{
    mlcd.fillBackgroundWhite();
    displayMeasureDistance();
    mlcd.displayJpgImageCoordinate(MEASURE_NOTICE_IMG_PATH, MEASURE_NOTICE_X_CRD, MEASURE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_CM_X_CRD, MEASURE_CM_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_BACK_X_CRD, MEASURE_BACK_Y_CRD);
   
}
/*関数 MdMeasureDistance::getDistance() で距離を取得し、その値を描画する*/
void AppControl::displayMeasureDistance()
{
    double distance = mmdist.getDistance();
    Serial.print(distance);
    Serial.println("[cm]");
    /*距離の百の位の数字を取り出す*/
    int DIGIT3 = (int)distance /100;
     if(DIGIT3 == 0 ){
        mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
    }
    else{
        mlcd.displayJpgImageCoordinate(g_str_blue[DIGIT3], MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
    }

     /*距離の十の位の数字を取り出す*/
    int DIGIT2 =  (int)distance / 10;
    if(DIGIT2 == 0 ){
    mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
    }
    else{
    mlcd.displayJpgImageCoordinate(g_str_blue[DIGIT2], MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
    }
    /*距離の一の位の数字を取り出す*/
    int DIGIT1 = (int)distance % 10;
    mlcd.displayJpgImageCoordinate(g_str_blue[DIGIT1], MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);

    /*ドット*/
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, MEASURE_DOT_X_CRD, MEASURE_DOT_Y_CRD);

    /* 距離の小数部分を取得 */
    int disDec = (int)distance % 10;
    mlcd.displayJpgImageCoordinate(g_str_blue[disDec], MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
}
/*-----------------------------------------------------------------*/
/*時刻表示画面の初期画面を描画する。関数 displayDateUpdate() で現在日時を描画する。*/
void AppControl::displayDateInit()
{
    mlcd.fillBackgroundWhite();
    displayDateUpdate();
    mlcd.displayJpgImageCoordinate(DATE_NOTICE_IMG_PATH, DATE_NOTICE_X_CRD, DATE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(DATE_SLASH_IMG_PATH, DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD);
    mlcd.displayJpgImageCoordinate(DATE_COLON_IMG_PATH, DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, DATE_BACK_X_CRD, DATE_BACK_Y_CRD);
}
/*関数 MdDateTime::readDate()とMdDateTime::readTime()により現在の日時を取得し、描画する*/
void AppControl::displayDateUpdate()
{
    mdtime.readDate();
    mdtime.MdDateTime::readTime();
    mlcd.displayDateText(mdtime.readDate(),DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD );
    mlcd.displayDateText(mdtime.MdDateTime::readTime(), DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD );
    delay(100);
}
/*------------------------------------------------------------------*/
/*HIGH_AND_LOW画面のタイトル（初期画面）を描画する*/
void AppControl::displayHigh_low_Init()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(TRUMP_TITLE_IMG_PATH, TRUMP_TITLE_X_CRD, TRUMP_TITLE_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_START_IMG_PATH, TRUMP_START_X_CRD, TRUMP_START_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, TRUMP_COMMON_BUTTON_BACK_X_CRD, TRUMP_COMMON_BUTTON_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_RECORD_IMG_PATH, TRUMP_RECORD_X_CRD, TRUMP_RECORD_Y_CRD);

}
/*-----------------------------------------------------------------*/
/*HEART(左)トランプをランダムに表示*/
int AppControl::getHigh_low_heart()
{
    int leftCard;
	//左用ランダム数値の取得表示
    leftCard = rand() % 9 + 1;
    return leftCard;
}
/*-------------------------------------------------------------------------------*/
/*SPADEトランプをランダムに表示*/
int AppControl::getHigh_low_spade()
{
    getHigh_low_heart();
    int rightCard ;
    do {
	rightCard = rand() % 9 + 1;
	} while (leftCard == rightCard);
    return rightCard;
}
/*--------------------------------------------------------------------------------*/
/*HIGH_AND_LOW画面のバトル画面(選択)を描画する*/
void AppControl::displayHigh_low_select()
{
    mlcd.fillBackgroundWhite();
    leftCard = getHigh_low_heart();
    mlcd.displayJpgImageCoordinate(TRUMP_BACK_IMG_PATH, TRUMP_BACK_X_CRD, TRUMP_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(g_str_heart[leftCard], TRUMP_HEART_X_CRD, TRUMP_HEART_Y_CRD );
    mlcd.displayJpgImageCoordinate(TRUMP_HIGHANDLOW_IMG_PATH, TRUMP_HIGHANDLOW_X_CRD, TRUMP_HIGHANDLOW_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_HIGH_IMG_PATH, TRUMP_HIGH_X_CRD, TRUMP_HIGH_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_LOW_IMG_PATH, TRUMP_LOW_X_CRD, TRUMP_LOW_Y_CRD);
}
/*--------------------------------------------------------------------------------*/
int AppControl::getHigh_lose_win(bool selectbtn)
{
    int rightCard = getHigh_low_spade();
	bool result ;
    
    //勝敗判断
    if (leftCard < rightCard) {
		result = true;
	}
	else if (leftCard > rightCard) {
		result = false;
	}
	else {
		// ここに来ることはありえないが念のため記述
		result = true;
	}
    return result;
}
/*---------------------------------------------------------------------------------------------------*/
    /*もしHEART(左)のカードよりSPADE(右)のカードのほうがHIGHであれば”勝利”を,HEART(左)のカードよりSPADE(右)のカードのほうがLOWであれば”敗北”を描画する*/
int AppControl::displayHigh_low_result()
{
    getHigh_lose_win(result);
    if (result == true) {
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(g_str_spade[rightCard], TRUMP_SPADE_X_CRD, TRUMP_SPADE_Y_CRD);
    mlcd.displayJpgImageCoordinate(g_str_heart[leftCard], TRUMP_HEART_X_CRD, TRUMP_HEART_Y_CRD );
    mlcd.displayJpgImageCoordinate(TRUMP_WIN_IMG_PATH, TRUMP_WIN_X_CRD, TRUMP_WIN_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_ONMORE_IMG_PATH, TRUMP_ONMORE_X_CRD, TRUMP_ONMORE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, TRUMP_COMMON_BUTTON_BACK_X_CRD, TRUMP_COMMON_BUTTON_BACK_Y_CRD);
    }
    else{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(g_str_spade[rightCard], TRUMP_SPADE_X_CRD, TRUMP_SPADE_Y_CRD);
    mlcd.displayJpgImageCoordinate(g_str_heart[leftCard], TRUMP_HEART_X_CRD, TRUMP_HEART_Y_CRD );
    mlcd.displayJpgImageCoordinate(TRUMP_LOSE_IMG_PATH, TRUMP_LOSE_X_CRD, TRUMP_LOSE_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_ONMORE_IMG_PATH, TRUMP_ONMORE_X_CRD, TRUMP_ONMORE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, TRUMP_COMMON_BUTTON_BACK_X_CRD, TRUMP_COMMON_BUTTON_BACK_Y_CRD);
    }
    return 0;
 
}
/*-------------------------------------------------------------------------------------------------------*/
/*HIGH_AND_LOW画面のバトル画面(戦績)を描画する*/
void AppControl::displayHigh_low_record()
{
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, TRUMP_COMMON_BUTTON_BACK_X_CRD, TRUMP_COMMON_BUTTON_BACK_Y_CRD);
}

/*------------------------------------------------------------------*/
void AppControl::controlApplication()
{
    mmplay.init();
    bool userSelect;
    bool result;
    while (1) {

        switch (getState()) {
        case TITLE:
            switch (getAction()) {
            case ENTRY:
                /*
                ** まずはここにタイトル画面の表示処理を呼び出してみよう。
                ** タイトル画面表示の関数はdisplayTitleInit()である。
                ** この関数の中身はまだ何もないので、この関数にタイトル画面表示処理を書いてみよう。
                */
                Serial.println("TITLE ENTRY");
                displayTitleInit();
                setStateMachine(TITLE, DO);


                break;

            case DO:
                Serial.println("TITLE DO");
                if(m_flag_btnA_is_pressed == true || m_flag_btnB_is_pressed == true || m_flag_btnC_is_pressed == true){
                setStateMachine(TITLE, EXIT); 
            }
                break;

            case EXIT:
                Serial.println("TITLE EXIT");
                //setStateMachine(MENU, ENTRY); 
                setStateMachine(BATTLE_TITLE, ENTRY);  
                break;

            default:
                break;
            }
            setBtnAllFlgFalse();
            break;
/*------------------------------------------------------------*/
        case MENU:

            switch (getAction()) {
            case ENTRY:
                Serial.println("MENU ENTRY");
                displayMenuInit();
                focusChangeImg(MENU_WBGT,MENU_WBGT);
                setStateMachine(MENU, DO); 
                break;

            case DO:
            Serial.println("MENU DO");
            if(m_flag_btnA_is_pressed == true){
                if(getFocusState() == MENU_WBGT){
                    focusChangeImg(MENU_WBGT, MENU_DATE);  
                }
                else if(getFocusState() == MENU_MUSIC){
                    focusChangeImg(MENU_MUSIC, MENU_WBGT);     
                }
                else if(getFocusState() == MENU_MEASURE){
                    focusChangeImg(MENU_MEASURE, MENU_MUSIC);
                }
                else if(getFocusState() == MENU_DATE){
                    focusChangeImg(MENU_DATE, MENU_MEASURE);
                }
                setBtnAllFlgFalse();
            }
            else if(m_flag_btnC_is_pressed == true){
                if(getFocusState() == MENU_WBGT){
                    focusChangeImg(MENU_WBGT, MENU_MUSIC);
                }
                else if(getFocusState() == MENU_MUSIC){
                    focusChangeImg(MENU_MUSIC, MENU_MEASURE);
                }
                else if(getFocusState() == MENU_MEASURE){
                    focusChangeImg(MENU_MEASURE, MENU_DATE);
                }
                else if(getFocusState() == MENU_DATE){
                    focusChangeImg(MENU_DATE, MENU_WBGT);
                }
                setBtnAllFlgFalse();
            }
            
            else if(m_flag_btnB_is_pressed == true){
                if(getFocusState() == MENU_WBGT){
                    setStateMachine(WBGT, ENTRY);
                }
                else if(getFocusState() == MENU_MUSIC){
                    setStateMachine(MUSIC_STOP, ENTRY);
                }
                else if(getFocusState() == MENU_MEASURE){
                    setStateMachine(MEASURE, ENTRY);
                }
                else if(getFocusState() == MENU_DATE){
                    setStateMachine(DATE, ENTRY);
                }
                
            }
            setBtnAllFlgFalse();
            
                //setStateMachine(MENU, EXIT);
                break;

            case EXIT:
            Serial.println("MENU EXIT");
            setStateMachine(WBGT, ENTRY);

            default:
                break;
        }

            break;
/*-----------------------------------------------------*/
        case WBGT:

            switch (getAction()) {
            case ENTRY:
            displayWBGTInit();
            displayTempHumiIndex();
            setStateMachine(WBGT, DO);
                break;

            case DO:
            Serial.println("WBGT DO");
            displayTempHumiIndex();
            if(m_flag_btnB_is_pressed == true){
                focusChangeImg(MENU_WBGT,MENU_WBGT);
                setStateMachine(WBGT, EXIT);
            }
            setBtnAllFlgFalse();
                break;

            case EXIT:
            Serial.println("WBGT EXIT");
            setStateMachine(MENU, ENTRY);
            
                break;

            default:
                break;
            }

            break;
/*-------------------------------------------------------------------*/
        case MUSIC_STOP:
            switch (getAction()) {
            case ENTRY:
            Serial.println("MUSIC_STOP ENTRY");
            displayMusicInit();
            setStateMachine(MUSIC_STOP, DO);
                break;

            case DO:
            Serial.println("MUSIC_STOP DO");
            if(m_flag_btnA_is_pressed == false || m_flag_btnB_is_pressed == false || m_flag_btnC_is_pressed == false){
            setStateMachine(MUSIC_STOP, DO);
            }
            
            if(m_flag_btnA_is_pressed == true){
                Serial.println("test1");
                setStateMachine(MUSIC_PLAY, ENTRY);
                Serial.println("test2");
            }
            else if(m_flag_btnB_is_pressed == true){
                Serial.println("test3");
                setStateMachine(MENU, ENTRY);
                Serial.println("test4");
            }
            else if(m_flag_btnC_is_pressed == true){
                Serial.println("test5");
                displayNextMusic();
                Serial.println("test6");
            }
            setBtnAllFlgFalse();
            Serial.println("test7");

                break;

            case EXIT:
            Serial.println("MUSIC_STOP EXIT");
    
                break;

            default:
                break;
            }

            break;
/*-----------------------------------------------------------------*/
        case MUSIC_PLAY:

            switch (getAction()) {
            case ENTRY:
            Serial.println("再生中");
            Serial.println("MUSIC_PLAY ENTRY");
            mmplay.prepareMP3();
            setStateMachine(MUSIC_PLAY, DO);
            Serial.println("再生中test1");
                break;

            case DO:
            Serial.println("MUSIC_PLAY DO");
            displayMusicPlay();
            while(mmplay.playMP3() && m_flag_btnA_is_pressed == false){}
            Serial.println("再生中test2");
            mmplay.stopMP3();
            displayMusicStop();
            Serial.println("再生中test3");
            setBtnAllFlgFalse();
            setStateMachine(MUSIC_PLAY, EXIT);
            
                break;

        case EXIT:
            Serial.println("MUSIC_PLAY EXIT");
            setStateMachine(MUSIC_STOP,ENTRY);
                break;

            default:
                break;
            }

            break;
/*----------------------------------------------------------------*/
        case MEASURE:

            switch (getAction()) {
            case ENTRY:
            Serial.println("MEASURE ENTRY");
            displayMeasureInit();
            
            setStateMachine(MEASURE, DO);
                break;

            case DO:
            Serial.println("MEASURE DO");
            displayMeasureDistance();
            delay(250);
            if(m_flag_btnB_is_pressed == true){
                setStateMachine(MEASURE, EXIT);
            }
            setBtnAllFlgFalse();
                break;

            case EXIT:
            Serial.println("MEASURE EXIT");
            setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;
/*----------------------------------------------------------------*/
        case DATE:

            switch (getAction()) {
            case ENTRY:
            Serial.println("DATE ENTRY");
            displayDateInit();
            setStateMachine(DATE, DO);
                break;

            case DO:
            Serial.println("DATE DO");
            displayDateUpdate();
             if(m_flag_btnB_is_pressed == true){
                setStateMachine(DATE, EXIT);
            }
            setBtnAllFlgFalse();
                break;

            case EXIT:
            Serial.println("DATE EXIT");
            setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;
/*------------------------------------------------------*/
        case BATTLE_TITLE:
            switch (getAction()) {
            case ENTRY:
            setStateMachine(BATTLE_TITLE, DO);
            displayHigh_low_Init();
            break;

            case DO:
            Serial.println("BATTLE_TITLE DO");
            if (m_flag_btnA_is_pressed == true) {
                Serial.println("test1");
                setStateMachine(BATTLE_SELECTION, ENTRY);
                Serial.println("test2");
            }
            else if (m_flag_btnB_is_pressed == true) {
                Serial.println("test3");
                setStateMachine(MENU, ENTRY);
                Serial.println("test4");
            }
            else if (m_flag_btnC_is_pressed == true) {
                Serial.println("test5");
                setStateMachine(BATTLE_RECORD, ENTRY);
                Serial.println("test6");
            }

            setBtnAllFlgFalse();
            break;

            case EXIT:
            Serial.println("BATTLE_TITLE EXIT");
            break;

            default:
                break;
             }
            break;
/*------------------------------------------------------------------------------*/
        case BATTLE_SELECTION:
            switch (getAction()) {
             case ENTRY:
            Serial.println("BATTLE_SELECTION ENTRY");
            displayHigh_low_select();
            setStateMachine(BATTLE_SELECTION, DO);
            break;

            case DO:
            Serial.println("BATTLE_SELECTION DO");
            if (m_flag_btnA_is_pressed == true) {
                Serial.println("test7");
                userSelect = true; // ユーザーが HIGH を選択したことを示す処理
                getHigh_lose_win(userSelect);
                setStateMachine(BATTLE_RESULT, ENTRY);
                Serial.println("test8");
            }
            else if (m_flag_btnC_is_pressed == true) {
                Serial.println("test9");
                userSelect = false; // ユーザーが LOW を選択したことを示す処理
                getHigh_lose_win(userSelect);
                setStateMachine(BATTLE_RESULT, ENTRY);
                Serial.println("test10");
            }
            setBtnAllFlgFalse();
            break;

            case EXIT:
            Serial.println("BATTLE_SELECTION EXIT");
            break;

            default:
                break;
            }
             break;
/*---------------------------------------------------------------------------------------*/
        case BATTLE_RESULT:
            switch (getAction()) {
            case ENTRY:
            Serial.println("BATTLE_RESULT ENTRY");
            displayHigh_low_result();
            setStateMachine(BATTLE_RESULT, DO);
            break;

            case DO:
            Serial.println("BATTLE_RESULT DO");
            if (m_flag_btnA_is_pressed == true) {
                Serial.println("test1");
                setStateMachine(BATTLE_SELECTION, ENTRY);
                Serial.println("test2");
            }
            else if (m_flag_btnB_is_pressed == true) {
                Serial.println("test3");
                setStateMachine(BATTLE_TITLE, ENTRY);
                Serial.println("test4");
            }
            setBtnAllFlgFalse();
            break;

            case EXIT:
            Serial.println("BATTLE_RESULT EXIT");
            //setStateMachine(BATTLE_RECORD, ENTRY);
            break;

            default:
                break;
             }
            break;
/*----------------------------------------------------------------*/
        case BATTLE_RECORD:
            switch (getAction()) {
            case ENTRY:
            Serial.println("BATTLE_RECORD ENTRY");
            setStateMachine(BATTLE_RECORD, DO);
            break;

            case DO:
            Serial.println("BATTLE_RECORD DO");
            if (m_flag_btnB_is_pressed == true) {
                Serial.println("test3");
                setStateMachine(MENU, ENTRY);
                Serial.println("test4");
            }
            setStateMachine(BATTLE_RECORD, EXIT);
            break;

            case EXIT:
            Serial.println("BATTLE_RECORD EXIT");
            break;

            default:
                break;
            }
            break;
             }
        }

}