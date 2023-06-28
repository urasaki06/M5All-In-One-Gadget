/* インクルードガード */
#pragma once

// button gpio number
#define BTN_A_GPIO 39
#define BTN_B_GPIO 38
#define BTN_C_GPIO 37

// UltraSonic pin
#define ECHO_PIN 5
#define TRIG_PIN 2

// jpg image path
#define TITLE_IMG_PATH "/images/title/title.jpg"

#define MENU_WBGT_IMG_PATH "/images/menu/monitor.jpg"
#define MENU_WBGT_FOCUS_IMG_PATH "/images/menu/monitor_focus.jpg"
#define MENU_MUSIC_IMG_PATH "/images/menu/music.jpg"
#define MENU_MUSIC_FOCUS_IMG_PATH "/images/menu/music_focus.jpg"
#define MENU_MEASURE_IMG_PATH "/images/menu/measure.jpg"
#define MENU_MEASURE_FOCUS_IMG_PATH "/images/menu/measure_focus.jpg"
#define MENU_DATE_IMG_PATH "/images/menu/date.jpg"
#define MENU_DATE_FOCUS_IMG_PATH "/images/menu/date_focus.jpg"

#define WBGT_SAFE_IMG_PATH "/images/wbgt/safe.jpg"
#define WBGT_ATTENTION_IMG_PATH "/images/wbgt/attention.jpg"
#define WBGT_ALERT_IMG_PATH "/images/wbgt/alert.jpg"
#define WBGT_HIGH_ALERT_IMG_PATH "/images/wbgt/high_alert.jpg"
#define WBGT_DANGER_IMG_PATH "/images/wbgt/danger.jpg"
#define WBGT_TEMPERATURE_IMG_PATH "/images/wbgt/temperature.jpg"
#define WBGT_HUMIDITY_IMG_PATH "/images/wbgt/humidity.jpg"
#define WBGT_DEGREE_IMG_PATH "/images/wbgt/degree.jpg"
#define WBGT_PERCENT_IMG_PATH "/images/wbgt/percent.jpg"

#define MUSIC_NOWPLAYING_IMG_PATH "/images/music/nowplaying.jpg"
#define MUSIC_NOWSTOPPING_IMG_PATH "/images/music/nowstopping.jpg"

#define MEASURE_NOTICE_IMG_PATH "/images/measure/measure.jpg"
#define MEASURE_CM_IMG_PATH "/images/measure/cm.jpg"

#define DATE_NOTICE_IMG_PATH "/images/date/notice.jpg"
#define DATE_SLASH_IMG_PATH "/images/date/slash.jpg"
#define DATE_COLON_IMG_PATH "/images/date/colon.jpg"

#define COMMON_BUTTON_BACK_IMG_PATH "/images/common/button/back.jpg"
#define COMMON_BUTTON_DECIDE_IMG_PATH "/images/common/button/decide.jpg"
#define COMMON_BUTTON_DOWN_IMG_PATH "/images/common/button/down.jpg"
#define COMMON_BUTTON_NEXT_IMG_PATH "/images/common/button/next.jpg"
#define COMMON_BUTTON_PLAY_IMG_PATH "/images/common/button/play.jpg"
#define COMMON_BUTTON_STOP_IMG_PATH "/images/common/button/stop.jpg"
#define COMMON_BUTTON_UP_IMG_PATH "/images/common/button/up.jpg"
#define COMMON_BUTTON_FILLWHITE_IMG_PATH "/images/common/button/fillwhite.jpg"

#define COMMON_ORANGE1_IMG_PATH "/images/common/orange_number/1.jpg"
#define COMMON_ORANGE2_IMG_PATH "/images/common/orange_number/2.jpg"
#define COMMON_ORANGE3_IMG_PATH "/images/common/orange_number/3.jpg"
#define COMMON_ORANGE4_IMG_PATH "/images/common/orange_number/4.jpg"
#define COMMON_ORANGE5_IMG_PATH "/images/common/orange_number/5.jpg"
#define COMMON_ORANGE6_IMG_PATH "/images/common/orange_number/6.jpg"
#define COMMON_ORANGE7_IMG_PATH "/images/common/orange_number/7.jpg"
#define COMMON_ORANGE8_IMG_PATH "/images/common/orange_number/8.jpg"
#define COMMON_ORANGE9_IMG_PATH "/images/common/orange_number/9.jpg"
#define COMMON_ORANGE0_IMG_PATH "/images/common/orange_number/0.jpg"
#define COMMON_ORANGEDOT_IMG_PATH "/images/common/orange_number/dot.jpg"
#define COMMON_ORANGEFILLWHITE_IMG_PATH "/images/common/orange_number/fillwhite.jpg"

#define COMMON_BLUE1_IMG_PATH "/images/common/blue_number/1.jpg"
#define COMMON_BLUE2_IMG_PATH "/images/common/blue_number/2.jpg"
#define COMMON_BLUE3_IMG_PATH "/images/common/blue_number/3.jpg"
#define COMMON_BLUE4_IMG_PATH "/images/common/blue_number/4.jpg"
#define COMMON_BLUE5_IMG_PATH "/images/common/blue_number/5.jpg"
#define COMMON_BLUE6_IMG_PATH "/images/common/blue_number/6.jpg"
#define COMMON_BLUE7_IMG_PATH "/images/common/blue_number/7.jpg"
#define COMMON_BLUE8_IMG_PATH "/images/common/blue_number/8.jpg"
#define COMMON_BLUE9_IMG_PATH "/images/common/blue_number/9.jpg"
#define COMMON_BLUE0_IMG_PATH "/images/common/blue_number/0.jpg"
#define COMMON_BLUEDOT_IMG_PATH "/images/common/blue_number/dot.jpg"
#define COMMON_BLUEFILLWHITE_IMG_PATH "/images/common/blue_number/fillwhite.jpg"

#define TRUMP_TITLE_IMG_PATH  "/images/trump/title.jpg"  //トランプ画像のファイルパス：タイトル画面  
#define TRUMP_START_IMG_PATH "/images/trump/start.jpg"    //トランプ画像のファイルパス：タイトル画面の「開始」 
#define TRUMP_RECORD_IMG_PATH "/images/trump/record.jpg"    //トランプ画像のファイルパス：タイトル画面の「戦績」 
#define TRUMP_BACK_IMG_PATH "/images/trump/back.jpg"   //トランプ画像のファイルパス：バトル画面(選択)の「BACK」  
#define TRUMP_HIGH_IMG_PATH "/images/trump/high.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「HIGH」  
#define TRUMP_LOW_IMG_PATH "/images/trump/low.jpg"     //トランプ画像のファイルパス：バトル画面(選択)の「LOW」 
#define TRUMP_HIGHANDLOW_IMG_PATH "/images/trump/highandlow.jpg"    //トランプ画像のファイルパス：バトル画面(選択)の「HIGH　AND　LOW？？」  
#define TRUMP_HEART1_IMG_PATH "/images/trump/heart/heart1.jpg" //トランプ画像のファイルパス：バトル画面(選択)の「HEART1」  
#define TRUMP_HEART2_IMG_PATH "/images/trump/heart/heart2.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「HEART2」  
#define TRUMP_HEART3_IMG_PATH "/images/trump/heart/heart3.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「HEART3」  
#define TRUMP_HEART4_IMG_PATH "/images/trump/heart/heart4.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「HEART4」  
#define TRUMP_HEART5_IMG_PATH "/images/trump/heart/heart5.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「HEART5」  
#define TRUMP_HEART6_IMG_PATH "/images/trump/heart/heart6.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「HEART6」  
#define TRUMP_HEART7_IMG_PATH "/images/trump/heart/heart7.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「HEART7」  
#define TRUMP_HEART8_IMG_PATH "/images/trump/heart/heart8.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「HEART8」  
#define TRUMP_HEART9_IMG_PATH "/images/trump/heart/heart9.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「HEART9」  
#define TRUMP_SPADE1_IMG_PATH "/images/trump/spade/spade1.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE1」  
#define TRUMP_SPADE2_IMG_PATH "/images/trump/spade/spade2.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE2」  
#define TRUMP_SPADE3_IMG_PATH "/images/trump/spade/spade3.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE3」  
#define TRUMP_SPADE4_IMG_PATH "/images/trump/spade/spade4.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE4」  
#define TRUMP_SPADE5_IMG_PATH "/images/trump/spade/spade5.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE5」  
#define TRUMP_SPADE6_IMG_PATH "/images/trump/spade/spade6.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE6」  
#define TRUMP_SPADE7_IMG_PATH "/images/trump/spade/spade7.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE7」  
#define TRUMP_SPADE8_IMG_PATH "/images/trump/spade/spade8.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE8」  
#define TRUMP_SPADE9_IMG_PATH "/images/trump/spade/spade9.jpg"  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE9」  
#define TRUMP_ONMORE_IMG_PATH "/images/trump/onmore.jpg"  //トランプ画像のファイルパス：バトル画面(結果敗北・勝利)の「もう一回」 
#define TRUMP_WIN_IMG_PATH "/images/trump/win.jpg"   //トランプ画像のファイルパス：バトル画面(結果・勝利)の「WIN」  
#define TRUMP_LOSE_IMG_PATH "/images/trump/lose.jpg"  //トランプ画像のファイルパス：バトル画面(結果・敗北)の「LOSE」

// TITLE jpg image coordinate
#define TITLE_X_CRD 0
#define TITLE_Y_CRD 0

// MENU jpg image coordinate
#define MENU_WBGT_X_CRD 0
#define MENU_WBGT_Y_CRD 0
#define MENU_MUSIC_X_CRD 0
#define MENU_MUSIC_Y_CRD 50
#define MENU_MEASURE_X_CRD 0
#define MENU_MEASURE_Y_CRD 100
#define MENU_DATE_X_CRD 0
#define MENU_DATE_Y_CRD 150
#define COMMON_BUTTON_UP_X_CRD 0
#define COMMON_BUTTON_UP_Y_CRD 200 
#define COMMON_BUTTON_DECIDE_X_CRD 120
#define COMMON_BUTTON_DECIDE_Y_CRD 200
#define COMMON_BUTTON_DOWN_X_CRD 240
#define COMMON_BUTTON_DOWN_Y_CRD 200

// WBGT jpg image coordinate
#define WBGT_TEMPERATURE_X_CRD 0
#define WBGT_TEMPERATURE_Y_CRD 0
#define WBGT_HUMIDITY_X_CRD 0
#define WBGT_HUMIDITY_Y_CRD 50
#define WBGT_T2DIGIT_X_CRD 120
#define WBGT_T2DIGIT_Y_CRD 0
#define WBGT_T1DIGIT_X_CRD 153
#define WBGT_T1DIGIT_Y_CRD 0
#define WBGT_TDOT_X_CRD 186
#define WBGT_TDOT_Y_CRD 0
#define WBGT_T1DECIMAL_X_CRD 220
#define WBGT_T1DECIMAL_Y_CRD 0
#define WBGT_DEGREE_X_CRD 253
#define WBGT_DEGREE_Y_CRD 0
#define WBGT_H2DIGIT_X_CRD 120
#define WBGT_H2DIGIT_Y_CRD 50
#define WBGT_H1DIGIT_X_CRD 153
#define WBGT_H1DIGIT_Y_CRD 50
#define WBGT_HDOT_X_CRD	186
#define WBGT_HDOT_Y_CRD 50
#define WBGT_H1DECIMAL_X_CRD 220
#define WBGT_H1DECIMAL_Y_CRD 50
#define WBGT_PERCENT_X_CRD 253
#define WBGT_PERCENT_Y_CRD 50
#define WBGT_NOTICE_X_CRD 0
#define WBGT_NOTICE_Y_CRD 100
#define WBGT_BACK_X_CRD 120
#define WBGT_BACK_Y_CRD 200

// Music jpg image coordinate
#define MUSIC_NOTICE_X_CRD	0
#define MUSIC_NOTICE_Y_CRD	0
#define MUSIC_TITLE_X_CRD 10
#define MUSIC_TITLE_Y_CRD 120
#define MUSIC_PLAY_X_CRD 0	
#define MUSIC_PLAY_Y_CRD 200	
#define MUSIC_BACK_X_CRD 120	
#define MUSIC_BACK_Y_CRD 200
#define MUSIC_NEXT_X_CRD 240	
#define MUSIC_NEXT_Y_CRD 200	
#define MUSIC_STOP_X_CRD 0	
#define MUSIC_STOP_Y_CRD 200	

// Measure jpg image coordinate
#define MEASURE_NOTICE_X_CRD 0	
#define MEASURE_NOTICE_Y_CRD 0			
#define MEASURE_DIGIT3_X_CRD 10		
#define MEASURE_DIGIT3_Y_CRD 100			
#define MEASURE_DIGIT2_X_CRD 53		
#define MEASURE_DIGIT2_Y_CRD 100			
#define MEASURE_DIGIT1_X_CRD 96			
#define MEASURE_DIGIT1_Y_CRD 100			
#define MEASURE_DOT_X_CRD 139			
#define MEASURE_DOT_Y_CRD 100			
#define MEASURE_DECIMAL_X_CRD 182			
#define MEASURE_DECIMAL_Y_CRD 100			
#define MEASURE_CM_X_CRD 240		
#define MEASURE_CM_Y_CRD 100			
#define MEASURE_BACK_X_CRD 120		
#define MEASURE_BACK_Y_CRD 200		

// Date jpg image coordinate
#define DATE_NOTICE_X_CRD 0	//時刻表示画面の「時刻表示」画像のx座標	
#define DATE_NOTICE_Y_CRD 0		//時刻表示画面の「時刻表示」画像のy座標	
#define DATE_YYYYMMDD_X_CRD 10	//時刻表示画面の「日付」のx座標	
#define DATE_YYYYMMDD_Y_CRD 100	//時刻表示画面の「日付」のy座標	
#define DATE_HHmmSS_X_CRD 40		//時刻表示画面の「時刻」のx座標	
#define DATE_HHmmSS_Y_CRD 150		//時刻表示画面の「時刻」のy座標	
#define DATE_BACK_X_CRD 120		//時刻表示画面の「戻るボタン」画像のx座標	
#define DATE_BACK_Y_CRD 200		//時刻表示画面の「戻るボタン」画像のy座標	

// Date jpg image coordinate
#define TRUMP_TITLE_X_CRD  0 //トランプ画像のファイルパス：タイトル画像のx座標  
#define TRUMP_TITLE_Y_CRD  0 //トランプ画像のファイルパス：タイトル画像のｙ座標  
#define TRUMP_START_X_CRD  0//トランプ画像のファイルパス：タイトル画面の「開始」のx座標 
#define TRUMP_START_Y_CRD 200 //トランプ画像のファイルパス：タイトル画面の「開始」のｙ座標 
#define TRUMP_RECORD_X_CRD 240 //トランプ画像のファイルパス：タイトル画面の「戦績」のx座標 
#define TRUMP_RECORD_Y_CRD 200    //トランプ画像のファイルパス：タイトル画面の「戦績」のｙ座標 
#define TRUMP_BACK_X_CRD  200  //トランプ画像のファイルパス：バトル画面(選択)の「BACK」のｘ座標  
#define TRUMP_BACK_Y_CRD 0 //トランプ画像のファイルパス：バトル画面(選択)の「BACK」のｙ座標  
#define TRUMP_HIGH_X_CRD 0  //トランプ画像のファイルパス：バトル画面(選択)の「HIGH」のx座標  
#define TRUMP_HIGH_Y_CRD 200   //トランプ画像のファイルパス：バトル画面(選択)の「HIGH」のｙ座標  
#define TRUMP_LOW_X_CRD 240   //トランプ画像のファイルパス：バトル画面(選択)の「LOW」のx座標 
#define TRUMP_LOW_Y_CRD 200  //トランプ画像のファイルパス：バトル画面(選択)の「LOW」のｙ座標 
#define TRUMP_HIGHANDLOW_X_CRD 20    //トランプ画像のファイルパス：バトル画面(選択)の「HIGH　AND　LOW？？」のx座標  
#define TRUMP_HIGHANDLOW_Y_CRD 150   //トランプ画像のファイルパス：バトル画面(選択)の「HIGH　AND　LOW？？」のｙ座標  
#define TRUMP_HEART_X_CRD 50   //トランプ画像のファイルパス：バトル画面(選択)の「HEART」のx座標  
#define TRUMP_HEART_Y_CRD 0   //トランプ画像のファイルパス：バトル画面(選択)の「HEART」のｙ座標  
#define TRUMP_SPADE_X_CRD 200  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE」のｘ座標  
#define TRUMP_SPADE_Y_CRD 0  //トランプ画像のファイルパス：バトル画面(選択)の「SPADE」のｙ座標  
#define TRUMP_ONMORE_X_CRD 0   //トランプ画像のファイルパス：バトル画面(結果敗北・勝利)の「もう一回」のｘ座標 
#define TRUMP_ONMORE_Y_CRD 200   //トランプ画像のファイルパス：バトル画面(結果敗北・勝利)の「もう一回」のｙ座標 
#define TRUMP_WIN_X_CRD 100  //トランプ画像のファイルパス：バトル画面(結果・勝利)の「WIN」のｘ座標  
#define TRUMP_WIN_Y_CRD 150  //トランプ画像のファイルパス：バトル画面(結果・勝利)の「WIN」のｙ座標  
#define TRUMP_LOSE_X_CRD 100    //トランプ画像のファイルパス：バトル画面(結果・敗北)の「LOSE」のｘ座標 
#define TRUMP_LOSE_Y_CRD 150   //トランプ画像のファイルパス：バトル画面(結果・敗北)の「LOSE」のｙ座標 
#define TRUMP_COMMON_BUTTON_BACK_X_CRD 120		//時刻表示画面の「戻るボタン」画像のx座標	
#define TRUMP_COMMON_BUTTON_BACK_Y_CRD 200	

typedef enum {
    TITLE,
    MENU,
    WBGT,
    MUSIC_STOP,
    MUSIC_PLAY,
    MEASURE,
    DATE,
    BATTLE_TITLE,
    BATTLE_SELECTION,
    BATTLE_RESULT,
    BATTLE_RECORD
} State;

typedef enum {
    ENTRY,
    DO,
    EXIT
} Action;

typedef enum {
    MENU_WBGT,
    MENU_MUSIC,
    MENU_MEASURE,
    MENU_DATE
} FocusState;

typedef enum {
    SAFE,
    ATTENTION,
    ALERT,
    HIGH_ALERT,
    DANGER
} WbgtIndex;



