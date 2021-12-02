#include "headfile.h"
#include  "common.h"

#define range_pid_ctl_H     3500       //8700
#define range_pid_ctl_L     0

//#define ABS(a)         (((a) < 0) ? (-(a)) : (a))//定义一个求绝对值的函数


//速度参数
//#define  hope_speed_straight   150  //360
//#define  hope_speed_20   460  //460
//#define  hope_speed   100  //430
//#define  differential_P  0.023//0.013--340

//#define  s_to_b_max   360  //280
////#define  speed_down_per   56
//#define  s_to_r_max   300
//
//#define  s_to_ku_max    350        //350
//#define  s_to_ku_min    150
//#define  qipao_max      350        //450
//
//
//#define s_to_huanR_max   250
//#define s_to_huanL_max   230   //250--7.7v     230--8.2v 满电
//#define huan_in_speed   370      //400--7.7v     360--8.2v 满电
//
//
//
//#define po_max_1 250        //270 上坡合适
   //#define po_max_2 540  //下坡
//#define po_out_speed 450

#define hope_speed_max  220
#define hope_speed_min  30

#define s_to_b_max  120
#define s_to_huanL_max   120
#define s_to_huanR_max   120
#define huan_in_speed_L  140
#define huan_in_speed_R  140

#define chalu_max 120

#define ruku_max  80
#define chuku_max 80
#define podao_max  120

extern unsigned char chalu_speed_low;
extern int16 teo_wheel_sp;
extern uint8 shouldgo;
extern float hopessp;
extern short int realspeed;
extern short int realspeed_l;
extern short int nowErr;
extern short int lastErr;
extern short int Err_prelast;
extern short int real_hope_speed;
extern float motorKp;
extern int16 debug_speed;
extern float motorKd;
extern float motorKi;
void real_hopespeed_count();
void speedUp();
void speedDown();
void speedStop();
void Dianji_pid_diff(int16 SpeedHope, uint16 MotorSpeed);
int  ercspe();
uint16 ABS(int16 a);


