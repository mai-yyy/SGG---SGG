#ifndef __speed_H__
#define __speed_H__
#include "headfile.h"



/********速度全局变量***********/
extern int16 real_speed;      //实时速度
extern int16 aim_speed;    //目标速度
extern int16 All_PWM;     //左轮PWM
extern int16 Speed_PWM;       //速度环
extern int16 Last_Speed_PWM;

extern int32   Left_High_Speed;//左电机PID设定值
extern int32   Right_High_Speed;//右电机PID设定值
extern int32 distance;  //车子所跑路程
extern float deb_delt_p;
extern float deb_delt_i;

/******速度函数声明*********/
void encoder_init(void);
void speed_measure(void);//测速
void init_PWM(void);//电机初始化
void go_motor (int16 PWM_Duty1,int16 PWM_Duty2);     //电机控制
float Speed_P_I_Control(float *PID, int16 speed, int16 set_speed);//因为角度变化小，需要是浮点型
void DJPID_init();
void Delta_PID(float Actuall,int type);
void Bin_Image_Filter (void);
void sengfl(float m1,float m2);
void HDDJPID_init();
void HDDelta_PID(float Actuall,int type);
uint8 otsuThreshold(uint8 *image, uint16 col, uint16 row);   //大津法二值化求阈值  需优化
void CS_control(int16 realdj,int16 High_Speed );
void CSRDJPID_init();
void CSLDJPID_init();
void CSLDelta_PID(float Actuall,int type);
void CSRDelta_PID(float Actuall,int type);
#endif
