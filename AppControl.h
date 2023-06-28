/* インクルードガード */
#pragma once

#include "M5All-In-One-Gadget.h"
#include "MdDateTime.h"
#include "MdLcd.h"
#include "MdMeasureDistance.h"
#include "MdMusicPlayer.h"
#include "MdWBGTMonitor.h"

class AppControl // classの定義
{
private: // privateはクラス内からしかアクセスできない
    bool m_flag_btnA_is_pressed = false;
    bool m_flag_btnB_is_pressed = false;
    bool m_flag_btnC_is_pressed = false;
    int leftCard;// メンバ変数としてleftCardを宣言
    int rightCard;// メンバ変数としてrightCardを宣言
    bool result;


    /* State Machine */
    State m_state = TITLE;
    Action m_action = ENTRY;

    /* GUI State */
    FocusState m_focus_state = MENU_WBGT;

    

public: // publicはどこからでもアクセス可能
    State getState();
    void setState(State state);
    Action getAction();
    void setAction(Action action);
    FocusState getFocusState();
    void setFocusState(FocusState fs);

    void setBtnAFlg(bool flg);
    void setBtnBFlg(bool flg);
    void setBtnCFlg(bool flg);
    void setBtnAllFlgFalse();
    void setStateMachine(State state, Action action);
    void displayTitleInit();
    void displayMenuInit();
    void focusChangeImg(FocusState current_state, FocusState next_state);
    void displayWBGTInit();
    void displayTempHumiIndex();
    void displayMusicInit();
    void displayMusicStop();
    void displayMusicTitle();
    void displayNextMusic();
    void displayMusicPlay();
    void displayMeasureInit();
    void displayMeasureDistance();
    void displayDateInit();
    void displayDateUpdate();
    void controlApplication();
    void displayHigh_low_Init();
    int getHigh_low_heart();
    int getHigh_lose_win(bool selectbtn);
    void displayHigh_low_select();
    int getHigh_low_spade(); 
    int displayHigh_low_result();
    void displayHigh_low_record();
};
