#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>

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
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();			
    mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, COMMON_BUTTON_UP_X_CRD, COMMON_BUTTON_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, COMMON_BUTTON_DECIDE_X_CRD , COMMON_BUTTON_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, COMMON_BUTTON_DOWN_X_CRD , COMMON_BUTTON_DOWN_Y_CRD);
}


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


void AppControl::displayMusicInit()
{
}

void AppControl::displayMusicStop()
{
}

void AppControl::displayMusicTitle()
{
}

void AppControl::displayNextMusic()
{
}

void AppControl::displayMusicPlay()
{
}

void AppControl::displayMeasureInit()
{
}

void AppControl::displayMeasureDistance()
{
}

void AppControl::displayDateInit()
{
}

void AppControl::displayDateUpdate()
{
}

void AppControl::controlApplication()
{
    mmplay.init();

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
                setStateMachine(MENU, ENTRY); 
                break;

            default:
                break;
            }
            setBtnAllFlgFalse();
            break;

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
                displayMenuInit();
                focusChangeImg(MENU_WBGT,MENU_WBGT);
                setStateMachine(MENU, DO);
            }
            setBtnAllFlgFalse();
                break;

            case EXIT:
            Serial.println("WBGT EXIT");
                break;

            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction()) {
            case ENTRY:
            Serial.println("MUSIC_STOP ENTRY");
                break;

            case DO:
            Serial.println("MUSIC_STOP DO");
                break;

            case EXIT:
            Serial.println("MUSIC_STOP EXIT");
                break;

            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction()) {
            case ENTRY:
            Serial.println("MUSIC_PLAY ENTRY");
                break;

            case DO:
            Serial.println("MUSIC_PLAY DO");
                break;

            case EXIT:
            Serial.println("MUSIC_PLAY EXIT");
                break;

            default:
                break;
            }

            break;

        case MEASURE:

            switch (getAction()) {
            case ENTRY:
            Serial.println("MEASURE ENTRY");
                break;

            case DO:
            Serial.println("MEASURE DO");
                break;

            case EXIT:
            Serial.println("MEASURE EXIT");
                break;

            default:
                break;
            }

            break;

        case DATE:

            switch (getAction()) {
            case ENTRY:
            Serial.println("DATE ENTRY");
                break;

            case DO:
            Serial.println("DATE DO");
                break;

            case EXIT:
            Serial.println("DATE EXIT");
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}
