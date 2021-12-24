#ifndef _MY_FLASH_H__
#define _MY_FLASH_H__

#include "headfile.h"

#define   add_value       P22_0
#define   reduce_value    P22_1
//#define   add_page        B13
//#define   reduce_page     B14
#define   add_option      P22_3
#define   reduce_option   P22_2


typedef enum {
  Choose_and_no_debug=0,               //进入UI界面
  Fuzzy_debug,               //模糊规则表，舵机中值之类的
  Around_island_debug,         //环岛变量
  str_ben_debug,               //弯道，直道变量
  START_CAR,        //
  Speed_run_debug,
  Init_debug,
  PAGE_seven,
} PAGE_NUM;


typedef enum {                              //用于首界面
  PRESS_Confirm=0,
  PRESS_Cancel,
  NONE,
} PRESS_STATUE;



//extern uint32 Flash1[64];


extern volatile  PRESS_STATUE press_sta;
extern volatile PAGE_NUM START_PAGE;
extern struct PARAMGET parameter;
extern uint32 Higher_str_speed;
extern uint32 Higher_ben_speed;
extern uint32 DataBuffer[512];
extern uint32 spkp;
extern uint32 spki;
extern uint32 Huandao_speed;
//
extern uint32 hope_speed_straight;
//extern uint32 hope_speed_20;
extern uint32 hope_speed;
//extern uint32 s_to_b_max;
//
//extern uint32 s_to_b_min;
//extern uint32 s_to_ku_max;
//extern uint32 po_max_2;
//extern uint32 s_to_ku_min;
//extern uint32 qipao_max;
//
//extern uint32 s_to_huanR_max;
//extern uint32 s_to_huanL_max;
//extern uint32 huan_in_speed_R;
//extern uint32 huan_in_speed_L;
//extern uint32 po_max_1;
//
//extern uint32 s_to_ku_2;
//extern uint32 qipao_min;
//
extern uint32 variable_1;
extern uint32 variable_2;
extern uint32 variable_3;
extern uint32 variable_4;
//
extern uint8 start_car_flag;
extern uint8 my_start_carrr;
//
//extern uint32 speed_up;
//extern uint32 speed_d_time;
//
//extern uint32 b_c_start;
//extern uint32 servoPoint;
void InFoRealData();
void  buton_init();
void  button_opreation();
void Read_information(struct PARAMGET *p_param);
void Write_information(); 

#endif
