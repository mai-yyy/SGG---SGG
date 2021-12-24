#include "button.h"
//flash优化成结构体中间变量，结构体储存参数，发送结构体变量给实际的变量
//静态阈值，车库方向。。。。
int8   oled_page=0;    //页数
int8   oled_option=0;    //行数
int32  value=0;
uint32  write_value=0;
uint32 spkp=0;
uint32 spki=0;
uint8 my_start_carrr=0;
uint32 Higher_str_speed=0;
uint32 Higher_ben_speed=0;
uint32 Huandao_speed=0;
uint32 hope_speed_straight=0;
uint32 hope_speed=0;
uint8 start_car_flag=0;
//uint32 Flash1[64]={0};
volatile PAGE_NUM START_PAGE=Choose_and_no_debug;
volatile PRESS_STATUE Press_sta=NONE;

uint32 DataBuffer[512]={0};
uint32 DataTemp[512]={0};
//volatile PAGE_NUM ips_page;
struct PARAMGET         //假变量，真容器  (>>__<<)
{
  uint32 int01;
  uint32 int02;
  uint32 int03;
  uint32 int04;
  uint32 int05;
  uint32 int06;
  uint32 int07;
  uint32 int08;
  uint32 int09;
  uint32 int10;
  uint32 int11;
  uint32 int12;
  uint32 int13;
  uint32 int14;
  uint32 int15;
  uint32 int16;
  uint32 int17;
  uint32 int18;
  uint32 int19;
  uint32 int20;
  uint32 int21;
  uint32 int22;
  uint32 int23;
  uint32 int24;
  uint32 int25;
  uint32 int26;
  uint32 int27;
  uint32 int28;
  uint32 int29;
  uint32 int30;
  uint32 int31;
  uint32 int32;
  uint32 int33;
  uint32 int34;
  uint32 int35;
  uint32 int36;
  uint32 int37;
  uint32 int38;
  uint32 int39;
  uint32 int40;
  uint32 int41;
  uint32 int42;
  uint32 int43;
  uint32 int44;
  uint32 int45;
  uint32 int46;
  uint32 int47;
  uint32 int48;
  uint32 int49;
} ;


struct PARAMGET parameter  ;   //把结构体的参数传到这里面来   parameter:参数  用结构体传递参数

//uint32 s_to_b_max=0;
//
//uint32 s_to_b_min=0;
//uint32 s_to_ku_max=0;
//uint32 po_max_2=0;
//uint32 s_to_ku_min=0;
//uint32 qipao_max=0;
//
//uint32 s_to_huanR_max=0;
//uint32 s_to_huanL_max=0;
//uint32 huan_in_speed_R=0;
//uint32 huan_in_speed_L=0;
//uint32 po_max_1=0;
//
//uint32 s_to_ku_2=0;
//uint32 qipao_min=0;
//
uint32 variable_1=0;
uint32 variable_2=0;
uint32 variable_3=0;
uint32 variable_4=0;
//
//uint32 speed_up=0;
//uint32 speed_d_time=0;
//
//uint32 b_c_start=0;
//uint32 servoPoint=0;


void  buton_init()
{
  gpio_init(add_value, GPI, 0, PULLUP);
  gpio_init(reduce_value, GPI, 0, PULLUP);
//  gpio_init(add_page, GPI, 0, PULLUP);
//  gpio_init(reduce_page, GPI, 0, PULLUP);
  gpio_init(add_option, GPI, 0, PULLUP);
  gpio_init(reduce_option, GPI, 0, PULLUP);
}


void  button_opreation()
{

//if(!gpio_get(add_page))
//{
//  oled_page++;
//  if(oled_page>11)
//  {
//    oled_page=0;
//  }
//  oled_fill(0x00);
//}
//else if(!gpio_get(reduce_page))
//{
//  oled_page--;
//  if(oled_page<0)
//  {
//    oled_page=11;
//  }
//  oled_fill(0x00);
//}
    ONE_OVER:                          //引入goto  goto标志位
    if(!gpio_get(add_option))
    {
      oled_option++;
      if(oled_option>16)
      {
       oled_option=0;
       if(oled_page>=16)
       {oled_page=16;}
       else{oled_page++;}
       ips200_clear(IPS200_BGCOLOR);
      }
      systick_delay_ms(STM0,100);
    }
    else if(!gpio_get(reduce_option))
    {
      oled_option--;
      if(oled_option<0)
      {
       oled_option=16;
       if(oled_page<=0)
       {oled_page=0;}
       else{  oled_page--;}
       ips200_clear(IPS200_BGCOLOR);
       systick_delay_ms(STM0,100);
      }
    }
    else if(!gpio_get(add_value)&&START_PAGE==Choose_and_no_debug)    //首界面作为enter键
    {
        Press_sta=PRESS_Confirm;
        systick_delay_ms(STM0,100);
    }
    else if(!gpio_get(reduce_value)&&START_PAGE==Choose_and_no_debug)
    {
        Press_sta=PRESS_Cancel;
        systick_delay_ms(STM0,100);
    }

else if(!gpio_get(add_value)&&START_PAGE!=Choose_and_no_debug)
{
  value=1;
  systick_delay_ms(STM0,100);
}  
else if(!gpio_get(reduce_value)&&START_PAGE!=Choose_and_no_debug)
{
  value=-1;
  systick_delay_ms(STM0,100);
}    
if(oled_page==0&&START_PAGE==Choose_and_no_debug)   //ui主界面
{
    if(oled_option==0) {
        Press_sta=NONE;
    uicolorget(50, 0, "Choose_and_no_debug", IPS200_PENCOLOR,0x001F);

      ips200_showstr(50,3,"Fuzzy_debug");

      ips200_showstr(50,6,"Around_island_debug");

      ips200_showstr(50,9,"str_ben_debug");

      ips200_showstr(50,12,"START_CAR");

      ips200_showstr(50,15,"Speed_run_debug");

      ips200_showstr(50,18,"Init_debug");
      }

    else if(oled_option==1)
    {
        ips200_showstr(50, 0, "Choose_and_no_debug");

        uicolorget(50,3,"Fuzzy_debug", IPS200_PENCOLOR,0x001F);

        ips200_showstr(50,6,"Around_island_debug");

            ips200_showstr(50,9,"str_ben_debug");

            ips200_showstr(50,12,"START_CAR");

            ips200_showstr(50,15,"Speed_run_debug");

            ips200_showstr(50,18,"Init_debug");
        if(Press_sta==PRESS_Confirm)
        {
            START_PAGE=Fuzzy_debug;
            ips200_clear(IPS200_BGCOLOR);
            oled_option=0;
            value=0;
        }
    }

    else if(oled_option==2)
       {
           ips200_showstr(50, 0, "Choose_and_no_debug");

           ips200_showstr(50,3,"Fuzzy_debug");

           uicolorget(50,6,"Around_island_debug", IPS200_PENCOLOR,0x001F);

           ips200_showstr(50,9,"str_ben_debug");

                       ips200_showstr(50,12,"START_CAR");

                       ips200_showstr(50,15,"Speed_run_debug");


                       ips200_showstr(50,18,"Init_debug");
           if(Press_sta==PRESS_Confirm)
           {
               START_PAGE=Around_island_debug;
               ips200_clear(IPS200_BGCOLOR);
               oled_option=0;
               value=0;
           }
       }

    else if(oled_option==3)
    {
               ips200_showstr(50, 0, "Choose_and_no_debug");

               ips200_showstr(50,3,"Fuzzy_debug");

               ips200_showstr(50,6,"Around_island_debug");

               uicolorget(50,9,"str_ben_debug", IPS200_PENCOLOR,0x001F);

               ips200_showstr(50,12,"START_CAR");

                                     ips200_showstr(50,15,"Speed_run_debug");

                                     ips200_showstr(50,18,"Init_debug");
               if(Press_sta==PRESS_Confirm)
               {
                   START_PAGE=str_ben_debug;
                   ips200_clear(IPS200_BGCOLOR);
                   oled_option=0;
                   value=0;
               }
           }
    else if(oled_option==4)
        {
                   ips200_showstr(50, 0, "Choose_and_no_debug");

                   ips200_showstr(50,3,"Fuzzy_debug");

                   ips200_showstr(50,6,"Around_island_debug");

                   ips200_showstr(50,9,"str_ben_debug");

                   uicolorget(50,12,"START_CAR", IPS200_PENCOLOR,0x001F);

                   ips200_showstr(50,15,"Speed_run_debug");


                   ips200_showstr(50,18,"Init_debug");
                   if(Press_sta==PRESS_Confirm)
                   {
                       START_PAGE=START_CAR;
                       ips200_clear(IPS200_BGCOLOR);
                       oled_option=0;
                       value=0;
                   }
               }

    else if(oled_option==5)
    {
        ips200_showstr(50, 0, "Choose_and_no_debug");

                         ips200_showstr(50,3,"Fuzzy_debug");

                         ips200_showstr(50,6,"Around_island_debug");

                         ips200_showstr(50,9,"str_ben_debug");
               ips200_showstr(50,12,"START_CAR");

               uicolorget(50,15,"Speed_run_debug", IPS200_PENCOLOR,0x001F);


               ips200_showstr(50,18,"Init_debug");
               if(Press_sta==PRESS_Confirm)
               {
                   START_PAGE=Speed_run_debug;
                   ips200_clear(IPS200_BGCOLOR);
                   oled_option=0;
                   value=0;
               }
           }
    else if(oled_option==6)
       {
           ips200_showstr(50, 0, "Choose_and_no_debug");

                            ips200_showstr(50,3,"Fuzzy_debug");

                            ips200_showstr(50,6,"Around_island_debug");

                            ips200_showstr(50,9,"str_ben_debug");
                  ips200_showstr(50,12,"START_CAR");

                  ips200_showstr(50,15,"Speed_run_debug");


                  uicolorget(50,18,"Init_debug", IPS200_PENCOLOR,0x001F);
                  if(Press_sta==PRESS_Confirm)
                  {
                      START_PAGE=Init_debug;
                      ips200_clear(IPS200_BGCOLOR);
                      oled_option=0;
                      value=0;
                  }
              }
    else if(oled_option>6)
    {oled_option=oled_option%5;}
}
//ui初始界面


//加载界面
if(START_PAGE==Fuzzy_debug)
{
      if(oled_option==0)    //第0行
    {

          DJ_fuzz_par.Fuzz_L_1=value+DJ_fuzz_par.Fuzz_L_1;
      value=0;
      uicolorget(0, 0, "Fuzz_L_1", IPS200_PENCOLOR,0x001F);
       ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
       ips200_showstr(0,1,"Fuzz_L_2");
       ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
       ips200_showstr(0,2,"Fuzz_L_3");
       ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
       ips200_showstr(0,3,"Fuzz_L_4");
       ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
       ips200_showstr(0,4,"Fuzz_L_5");
       ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
       ips200_showstr(0,5,"Fuzz_L_6");
       ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
       ips200_showstr(0,6,"Fuzz_L_7");
       ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
       ips200_showstr(0,7,"Fuzz_R_1");
       ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
       ips200_showstr(0,8,"Fuzz_R_2");
       ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
       ips200_showstr(0,9,"Fuzz_R_3");
       ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
       ips200_showstr(0,10,"Fuzz_R_4");
       ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
       ips200_showstr(0,11,"Fuzz_R_5");
       ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
       ips200_showstr(0,12,"Fuzz_R_6");
       ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
              ips200_showstr(0,13,"Fuzz_R_7");
              ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
              ips200_showstr(0,14,"return");
    }
      else if(oled_option==1)    //第0行
        {

              DJ_fuzz_par.Fuzz_L_2=value+DJ_fuzz_par.Fuzz_L_2;
          value=0;
          ips200_showstr(0, 0, "Fuzz_L_1");
           ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
           uicolorget(0,1,"Fuzz_L_2", IPS200_PENCOLOR,0x001F);
           ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
           ips200_showstr(0,2,"Fuzz_L_3");
                  ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                  ips200_showstr(0,3,"Fuzz_L_4");
                  ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                  ips200_showstr(0,4,"Fuzz_L_5");
                  ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                  ips200_showstr(0,5,"Fuzz_L_6");
                  ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                  ips200_showstr(0,6,"Fuzz_L_7");
                  ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                       ips200_showstr(0,7,"Fuzz_R_1");
                       ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                       ips200_showstr(0,8,"Fuzz_R_2");
                       ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                       ips200_showstr(0,9,"Fuzz_R_3");
                       ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                       ips200_showstr(0,10,"Fuzz_R_4");
                       ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                       ips200_showstr(0,11,"Fuzz_R_5");
                       ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                       ips200_showstr(0,12,"Fuzz_R_6");
                       ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                              ips200_showstr(0,13,"Fuzz_R_7");
                              ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                              ips200_showstr(0,14,"return");
        }


      else if(oled_option==2)
      {
          DJ_fuzz_par.Fuzz_L_3=value+DJ_fuzz_par.Fuzz_L_3;
                    value=0;
          ips200_showstr(0, 0, "Fuzz_L_1");
                  ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                  ips200_showstr(0,1,"Fuzz_L_2");
                  ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                  uicolorget(0,2,"Fuzz_L_3", IPS200_PENCOLOR,0x001F);
                         ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                         ips200_showstr(0,3,"Fuzz_L_4");
                         ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                         ips200_showstr(0,4,"Fuzz_L_5");
                         ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                         ips200_showstr(0,5,"Fuzz_L_6");
                         ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                         ips200_showstr(0,6,"Fuzz_L_7");
                         ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                              ips200_showstr(0,7,"Fuzz_R_1");
                              ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                              ips200_showstr(0,8,"Fuzz_R_2");
                              ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                              ips200_showstr(0,9,"Fuzz_R_3");
                              ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                              ips200_showstr(0,10,"Fuzz_R_4");
                              ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                              ips200_showstr(0,11,"Fuzz_R_5");
                              ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                              ips200_showstr(0,12,"Fuzz_R_6");
                              ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                     ips200_showstr(0,13,"Fuzz_R_7");
                                     ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                     ips200_showstr(0,14,"return");
      }
      else if(oled_option==3)
            {
          DJ_fuzz_par.Fuzz_L_4=value+DJ_fuzz_par.Fuzz_L_4;
                    value=0;
                ips200_showstr(0, 0, "Fuzz_L_1");
                        ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                        ips200_showstr(0,1,"Fuzz_L_2");
                        ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                        ips200_showstr(0,2,"Fuzz_L_3");
                               ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                               uicolorget(0,3,"Fuzz_L_4", IPS200_PENCOLOR,0x001F);
                               ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                               ips200_showstr(0,4,"Fuzz_L_5");
                               ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                               ips200_showstr(0,5,"Fuzz_L_6");
                               ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                               ips200_showstr(0,6,"Fuzz_L_7");
                               ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                    ips200_showstr(0,7,"Fuzz_R_1");
                                    ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                    ips200_showstr(0,8,"Fuzz_R_2");
                                    ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                    ips200_showstr(0,9,"Fuzz_R_3");
                                    ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                    ips200_showstr(0,10,"Fuzz_R_4");
                                    ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                    ips200_showstr(0,11,"Fuzz_R_5");
                                    ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                    ips200_showstr(0,12,"Fuzz_R_6");
                                    ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                           ips200_showstr(0,13,"Fuzz_R_7");
                                           ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                           ips200_showstr(0,14,"return");
            }

      else if(oled_option==4)
                  {
          DJ_fuzz_par.Fuzz_L_5=value+DJ_fuzz_par.Fuzz_L_5;
                    value=0;
                      ips200_showstr(0, 0, "Fuzz_L_1");
                              ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                              ips200_showstr(0,1,"Fuzz_L_2");
                              ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                              ips200_showstr(0,2,"Fuzz_L_3");
                                     ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                     ips200_showstr(0,3,"Fuzz_L_4");
                                     ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                     uicolorget(0,4,"Fuzz_L_5", IPS200_PENCOLOR,0x001F);
                                     ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                     ips200_showstr(0,5,"Fuzz_L_6");
                                     ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                     ips200_showstr(0,6,"Fuzz_L_7");
                                     ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                          ips200_showstr(0,7,"Fuzz_R_1");
                                          ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                          ips200_showstr(0,8,"Fuzz_R_2");
                                          ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                          ips200_showstr(0,9,"Fuzz_R_3");
                                          ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                          ips200_showstr(0,10,"Fuzz_R_4");
                                          ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                          ips200_showstr(0,11,"Fuzz_R_5");
                                          ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                          ips200_showstr(0,12,"Fuzz_R_6");
                                          ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                 ips200_showstr(0,13,"Fuzz_R_7");
                                                 ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                 ips200_showstr(0,14,"return");
                  }

      else if(oled_option==5)
                     {
          DJ_fuzz_par.Fuzz_L_6=value+DJ_fuzz_par.Fuzz_L_6;
                    value=0;
                         ips200_showstr(0, 0, "Fuzz_L_1");
                                 ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                                 ips200_showstr(0,1,"Fuzz_L_2");
                                 ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                                 ips200_showstr(0,2,"Fuzz_L_3");
                                        ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                        ips200_showstr(0,3,"Fuzz_L_4");
                                        ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                        ips200_showstr(0,4,"Fuzz_L_5");
                                        ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                        uicolorget(0,5,"Fuzz_L_6", IPS200_PENCOLOR,0x001F);
                                        ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                        ips200_showstr(0,6,"Fuzz_L_7");
                                        ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                             ips200_showstr(0,7,"Fuzz_R_1");
                                             ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                             ips200_showstr(0,8,"Fuzz_R_2");
                                             ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                             ips200_showstr(0,9,"Fuzz_R_3");
                                             ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                             ips200_showstr(0,10,"Fuzz_R_4");
                                             ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                             ips200_showstr(0,11,"Fuzz_R_5");
                                             ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                             ips200_showstr(0,12,"Fuzz_R_6");
                                             ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                    ips200_showstr(0,13,"Fuzz_R_7");
                                                    ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                    ips200_showstr(0,14,"return");
                     }

      else if(oled_option==6)
                        {
          DJ_fuzz_par.Fuzz_L_7=value+DJ_fuzz_par.Fuzz_L_7;
                    value=0;
                            ips200_showstr(0, 0, "Fuzz_L_1");
                                    ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                                    ips200_showstr(0,1,"Fuzz_L_2");
                                    ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                                    ips200_showstr(0,2,"Fuzz_L_3");
                                           ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                           ips200_showstr(0,3,"Fuzz_L_4");
                                           ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                           ips200_showstr(0,4,"Fuzz_L_5");
                                           ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                           ips200_showstr(0,5,"Fuzz_L_6");
                                           ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                           uicolorget(0,6,"Fuzz_L_7", IPS200_PENCOLOR,0x001F);
                                           ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                                ips200_showstr(0,7,"Fuzz_R_1");
                                                ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                                ips200_showstr(0,8,"Fuzz_R_2");
                                                ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                                ips200_showstr(0,9,"Fuzz_R_3");
                                                ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                                ips200_showstr(0,10,"Fuzz_R_4");
                                                ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                                ips200_showstr(0,11,"Fuzz_R_5");
                                                ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                                ips200_showstr(0,12,"Fuzz_R_6");
                                                ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                       ips200_showstr(0,13,"Fuzz_R_7");
                                                       ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                       ips200_showstr(0,14,"return");
                        }


      else if(oled_option==7)
                            {
          DJ_fuzz_par.Fuzz_R_1=value+DJ_fuzz_par.Fuzz_R_1;
                    value=0;
                                ips200_showstr(0, 0, "Fuzz_L_1");
                                        ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                                        ips200_showstr(0,1,"Fuzz_L_2");
                                        ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                                        ips200_showstr(0,2,"Fuzz_L_3");
                                               ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                               ips200_showstr(0,3,"Fuzz_L_4");
                                               ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                               ips200_showstr(0,4,"Fuzz_L_5");
                                               ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                               ips200_showstr(0,5,"Fuzz_L_6");
                                               ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                               ips200_showstr(0,6,"Fuzz_L_7");
                                               ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                               uicolorget(0,7,"Fuzz_R_1", IPS200_PENCOLOR,0x001F);
                                                    ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                                    ips200_showstr(0,8,"Fuzz_R_2");
                                                    ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                                    ips200_showstr(0,9,"Fuzz_R_3");
                                                    ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                                    ips200_showstr(0,10,"Fuzz_R_4");
                                                    ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                                    ips200_showstr(0,11,"Fuzz_R_5");
                                                    ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                                    ips200_showstr(0,12,"Fuzz_R_6");
                                                    ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                           ips200_showstr(0,13,"Fuzz_R_7");
                                                           ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                           ips200_showstr(0,14,"return");
                            }
      else if(oled_option==8)
                                 {
          DJ_fuzz_par.Fuzz_R_2=value+DJ_fuzz_par.Fuzz_R_2;
                              value=0;
                                     ips200_showstr(0, 0, "Fuzz_L_1");
                                             ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                                             ips200_showstr(0,1,"Fuzz_L_2");
                                             ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                                             ips200_showstr(0,2,"Fuzz_L_3");
                                                    ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                                    ips200_showstr(0,3,"Fuzz_L_4");
                                                    ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                                    ips200_showstr(0,4,"Fuzz_L_5");
                                                    ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                                    ips200_showstr(0,5,"Fuzz_L_6");
                                                    ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                                    ips200_showstr(0,6,"Fuzz_L_7");
                                                    ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                                    ips200_showstr(0,7,"Fuzz_R_1");
                                                         ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                                         uicolorget(0,8,"Fuzz_R_2", IPS200_PENCOLOR,0x001F);
                                                         ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                                         ips200_showstr(0,9,"Fuzz_R_3");
                                                         ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                                         ips200_showstr(0,10,"Fuzz_R_4");
                                                         ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                                         ips200_showstr(0,11,"Fuzz_R_5");
                                                         ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                                         ips200_showstr(0,12,"Fuzz_R_6");
                                                         ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                                ips200_showstr(0,13,"Fuzz_R_7");
                                                                ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                                ips200_showstr(0,14,"return");
                                 }
      else if(oled_option==9)
                                    {
          DJ_fuzz_par.Fuzz_R_3=value+DJ_fuzz_par.Fuzz_R_3;
                              value=0;
                                        ips200_showstr(0, 0, "Fuzz_L_1");
                                                ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                                                ips200_showstr(0,1,"Fuzz_L_2");
                                                ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                                                ips200_showstr(0,2,"Fuzz_L_3");
                                                       ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                                       ips200_showstr(0,3,"Fuzz_L_4");
                                                       ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                                       ips200_showstr(0,4,"Fuzz_L_5");
                                                       ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                                       ips200_showstr(0,5,"Fuzz_L_6");
                                                       ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                                       ips200_showstr(0,6,"Fuzz_L_7");
                                                       ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                                       ips200_showstr(0,7,"Fuzz_R_1");
                                                            ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                                            ips200_showstr(0,8,"Fuzz_R_2");
                                                            ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                                            uicolorget(0,9,"Fuzz_R_3", IPS200_PENCOLOR,0x001F);
                                                            ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                                            ips200_showstr(0,10,"Fuzz_R_4");
                                                            ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                                            ips200_showstr(0,11,"Fuzz_R_5");
                                                            ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                                            ips200_showstr(0,12,"Fuzz_R_6");
                                                            ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                                   ips200_showstr(0,13,"Fuzz_R_7");
                                                                   ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                                   ips200_showstr(0,14,"return");
                                    }

      else if(oled_option==10)
                                      {
          DJ_fuzz_par.Fuzz_R_4=value+DJ_fuzz_par.Fuzz_R_4;
                              value=0;
                                          ips200_showstr(0, 0, "Fuzz_L_1");
                                                  ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                                                  ips200_showstr(0,1,"Fuzz_L_2");
                                                  ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                                                  ips200_showstr(0,2,"Fuzz_L_3");
                                                         ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                                         ips200_showstr(0,3,"Fuzz_L_4");
                                                         ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                                         ips200_showstr(0,4,"Fuzz_L_5");
                                                         ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                                         ips200_showstr(0,5,"Fuzz_L_6");
                                                         ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                                         ips200_showstr(0,6,"Fuzz_L_7");
                                                         ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                                         ips200_showstr(0,7,"Fuzz_R_1");
                                                              ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                                              ips200_showstr(0,8,"Fuzz_R_2");
                                                              ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                                              ips200_showstr(0,9,"Fuzz_R_3");
                                                              ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                                              uicolorget(0,10,"Fuzz_R_4", IPS200_PENCOLOR,0x001F);
                                                              ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                                              ips200_showstr(0,11,"Fuzz_R_5");
                                                              ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                                              ips200_showstr(0,12,"Fuzz_R_6");
                                                              ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                                     ips200_showstr(0,13,"Fuzz_R_7");
                                                                     ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                                     ips200_showstr(0,14,"return");
                                      }

      else if(oled_option==11)
                                      {
          DJ_fuzz_par.Fuzz_R_5=value+DJ_fuzz_par.Fuzz_R_5;
                              value=0;
                                          ips200_showstr(0, 0, "Fuzz_L_1");
                                                  ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                                                  ips200_showstr(0,1,"Fuzz_L_2");
                                                  ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                                                  ips200_showstr(0,2,"Fuzz_L_3");
                                                         ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                                         ips200_showstr(0,3,"Fuzz_L_4");
                                                         ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                                         ips200_showstr(0,4,"Fuzz_L_5");
                                                         ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                                         ips200_showstr(0,5,"Fuzz_L_6");
                                                         ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                                         ips200_showstr(0,6,"Fuzz_L_7");
                                                         ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                                         ips200_showstr(0,7,"Fuzz_R_1");
                                                              ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                                              ips200_showstr(0,8,"Fuzz_R_2");
                                                              ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                                              ips200_showstr(0,9,"Fuzz_R_3");
                                                              ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                                              ips200_showstr(0,10,"Fuzz_R_4");
                                                              ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                                              uicolorget(0,11,"Fuzz_R_5", IPS200_PENCOLOR,0x001F);
                                                              ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                                              ips200_showstr(0,12,"Fuzz_R_6");
                                                              ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                                     ips200_showstr(0,13,"Fuzz_R_7");
                                                                     ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                                     ips200_showstr(0,14,"return");
                                      }
      else if(oled_option==12)
                                          {
          DJ_fuzz_par.Fuzz_R_6=value+DJ_fuzz_par.Fuzz_R_6;
                              value=0;
                                              ips200_showstr(0, 0, "Fuzz_L_1");
                                                      ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                                                      ips200_showstr(0,1,"Fuzz_L_2");
                                                      ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                                                      ips200_showstr(0,2,"Fuzz_L_3");
                                                             ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                                             ips200_showstr(0,3,"Fuzz_L_4");
                                                             ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                                             ips200_showstr(0,4,"Fuzz_L_5");
                                                             ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                                             ips200_showstr(0,5,"Fuzz_L_6");
                                                             ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                                             ips200_showstr(0,6,"Fuzz_L_7");
                                                             ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                                             ips200_showstr(0,7,"Fuzz_R_1");
                                                                  ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                                                  ips200_showstr(0,8,"Fuzz_R_2");
                                                                  ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                                                  ips200_showstr(0,9,"Fuzz_R_3");
                                                                  ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                                                  ips200_showstr(0,10,"Fuzz_R_4");
                                                                  ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                                                  ips200_showstr(0,11,"Fuzz_R_5");
                                                                  ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                                                  uicolorget(0,12,"Fuzz_R_6", IPS200_PENCOLOR,0x001F);
                                                                  ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                                         ips200_showstr(0,13,"Fuzz_R_7");
                                                                         ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                                         ips200_showstr(0,14,"return");
                                          }

      else if(oled_option==13)
                                              {
          DJ_fuzz_par.Fuzz_R_7=value+DJ_fuzz_par.Fuzz_R_7;
                              value=0;
                                                  ips200_showstr(0, 0, "Fuzz_L_1");
                                                          ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                                                          ips200_showstr(0,1,"Fuzz_L_2");
                                                          ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                                                          ips200_showstr(0,2,"Fuzz_L_3");
                                                                 ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                                                 ips200_showstr(0,3,"Fuzz_L_4");
                                                                 ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                                                 ips200_showstr(0,4,"Fuzz_L_5");
                                                                 ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                                                 ips200_showstr(0,5,"Fuzz_L_6");
                                                                 ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                                                 ips200_showstr(0,6,"Fuzz_L_7");
                                                                 ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                                                 ips200_showstr(0,7,"Fuzz_R_1");
                                                                      ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                                                      ips200_showstr(0,8,"Fuzz_R_2");
                                                                      ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                                                      ips200_showstr(0,9,"Fuzz_R_3");
                                                                      ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                                                      ips200_showstr(0,10,"Fuzz_R_4");
                                                                      ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                                                      ips200_showstr(0,11,"Fuzz_R_5");
                                                                      ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                                                      ips200_showstr(0,12,"Fuzz_R_6");
                                                                      ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                                      uicolorget(0,13,"Fuzz_R_7", IPS200_PENCOLOR,0x001F);
                                                                             ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                                             ips200_showstr(0,14,"return");
                                              }
      else if(oled_option==14)
      {
          ips200_showstr(0, 0, "Fuzz_L_1");
                                                                    ips200_showfloat(70,0,DJ_fuzz_par.Fuzz_L_1*0.01+1,1,2);
                                                                    ips200_showstr(0,1,"Fuzz_L_2");
                                                                    ips200_showfloat(70,1,DJ_fuzz_par.Fuzz_L_2*0.01+1,1,2);
                                                                    ips200_showstr(0,2,"Fuzz_L_3");
                                                                           ips200_showfloat(70,2,DJ_fuzz_par.Fuzz_L_3*0.01+1,1,2);
                                                                           ips200_showstr(0,3,"Fuzz_L_4");
                                                                           ips200_showfloat(70,3,DJ_fuzz_par.Fuzz_L_4*0.01+1,1,2);
                                                                           ips200_showstr(0,4,"Fuzz_L_5");
                                                                           ips200_showfloat(70,4,DJ_fuzz_par.Fuzz_L_5*0.01+1,1,2);
                                                                           ips200_showstr(0,5,"Fuzz_L_6");
                                                                           ips200_showfloat(70,5,DJ_fuzz_par.Fuzz_L_6*0.01+1,1,2);
                                                                           ips200_showstr(0,6,"Fuzz_L_7");
                                                                           ips200_showfloat(70,6,DJ_fuzz_par.Fuzz_L_7*0.01+1,1,2);
                                                                           ips200_showstr(0,7,"Fuzz_R_1");
                                                                                ips200_showfloat(70,7,DJ_fuzz_par.Fuzz_R_1*0.01+1,1,2);
                                                                                ips200_showstr(0,8,"Fuzz_R_2");
                                                                                ips200_showfloat(70,8,DJ_fuzz_par.Fuzz_R_2*0.01+1,1,2);
                                                                                ips200_showstr(0,9,"Fuzz_R_3");
                                                                                ips200_showfloat(70,9,DJ_fuzz_par.Fuzz_R_3*0.01+1,1,2);
                                                                                ips200_showstr(0,10,"Fuzz_R_4");
                                                                                ips200_showfloat(70,10,DJ_fuzz_par.Fuzz_R_4*0.01+1,1,2);
                                                                                ips200_showstr(0,11,"Fuzz_R_5");
                                                                                ips200_showfloat(70,11,DJ_fuzz_par.Fuzz_R_5*0.01+1,1,2);
                                                                                ips200_showstr(0,12,"Fuzz_R_6");
                                                                                ips200_showfloat(70,12,DJ_fuzz_par.Fuzz_R_6*0.01+1,1,2);
                                                                                ips200_showstr(0,13,"Fuzz_R_7");
                                                                                       ips200_showfloat(70,13,DJ_fuzz_par.Fuzz_R_7*0.01+1,1,2);
                                                                                       uicolorget(0,14,"return", IPS200_PENCOLOR,0x001F);

                                                   if(!gpio_get(add_value))   //return
                                                   {START_PAGE=Choose_and_no_debug;
                                                   oled_page=0;
                                                   oled_option=0;
                                                   ips200_clear(IPS200_BGCOLOR);
                                                   goto ONE_OVER;}   //写完发现妙啊，这一步，我是怎么想到的，O(∩_∩)O哈哈~

      }
      else if(oled_option>=15)
      {
          oled_option=0;
      }
}
else if(START_PAGE==Around_island_debug)
{
    oled_option=(oled_option<=0)  ?  0:oled_option;
    oled_option=(oled_option>=1)  ?  1:oled_option;
      if(oled_option==0) {
          Huandao_speed=value*5+Huandao_speed;
                       value=0;
          uicolorget(50, 8, "Hua_spe", IPS200_PENCOLOR,0x001F);
          ips200_showfloat(120,8,Huandao_speed,3,1);
          ips200_showstr(50,12,"return");
    }
      else  if(oled_option==1) {

          ips200_showstr(50, 8, "Hua_spe");
                    ips200_showfloat(120,8,Huandao_speed,3,1);
               uicolorget(50,12,"return", IPS200_PENCOLOR,0x001F);
               if(!gpio_get(add_value))   //return
                                                                  {START_PAGE=Choose_and_no_debug;
                                                                  oled_page=0;
                                                                  oled_option=0;
                                                                  ips200_clear(IPS200_BGCOLOR);
                                                                  goto ONE_OVER;}   //写完发现妙啊，这一步，我是怎么想到的，O(∩_∩)O哈哈~
         }



}

else if(START_PAGE==str_ben_debug)
{
      if(oled_option==0) {
          var_threshold=value+var_threshold;
             value=0;
             uicolorget(0, 0, "var_threshold", IPS200_PENCOLOR,0x001F);
              ips200_showfloat(130,0,var_threshold,2,2);
              ips200_showstr(70,2,"return");
      }
      else if(oled_option==1)
      {
          ips200_showstr(0, 0, "var_threshold");
                       ips200_showfloat(130,0,var_threshold,2,2);
                       uicolorget(70,2,"return", IPS200_PENCOLOR,0x001F);
                       if(!gpio_get(add_value))   //return
                                                                                         {START_PAGE=Choose_and_no_debug;
                                                                                         oled_page=0;
                                                                                         oled_option=0;
                                                                                         ips200_clear(IPS200_BGCOLOR);
                                                                                         goto ONE_OVER;}   //写完发现妙啊，这一步，我是怎么想到的，O(∩_∩)O哈哈~

      }
}
else if(START_PAGE==START_CAR)
{
     if(oled_option==0) {

                uicolorget(50, 3, "START!!! CAR!!!", IPS200_PENCOLOR,0x001F);
                ips200_showstr(50,5,"return");
                if(!gpio_get(add_value))   //return
                                                                                          {START_PAGE=Choose_and_no_debug;
                                                                                                                     oled_page=0;
                                                                                                                           oled_option=0;
                                                                                                                       ips200_clear(IPS200_BGCOLOR);
//                                                                                                                       buzzer(1);
                                                                                                                       systick_delay_ms(STM0,2000);


                                                                                                                       my_start_carrr=1;
                                                                                                                       start_car_flag=1;
                                                                                                                       }   //写完发现妙啊，这一步，我是怎么想到的，O(∩_∩)O哈哈~

       }
     else if(oled_option==1)
     {
         ips200_showstr(50, 3, "NOW_NO_THIS_PART");
         uicolorget(50,5,"return", IPS200_PENCOLOR,0x001F);
         if(!gpio_get(add_value))   //return
                                                                                                               {START_PAGE=Choose_and_no_debug;
                                                                                                               oled_page=0;
                                                                                                               oled_option=0;
                                                                                                               ips200_clear(IPS200_BGCOLOR);
                                                                                                               goto ONE_OVER;}   //写完发现妙啊，这一步，我是怎么想到的，O(∩_∩)O哈哈~

     }
}
else if(START_PAGE==Speed_run_debug)
{
     if(oled_option==0) {
         Higher_str_speed=value*5+Higher_str_speed;
                value=0;
                uicolorget(0, 0, "H_str_speed", IPS200_PENCOLOR,0x001F);
                 ips200_showfloat(120,0,Higher_str_speed,3,1);
                 ips200_showstr(0,1,"H_ben_speed");
                 ips200_showfloat(120,1,Higher_ben_speed,3,1);
                 ips200_showstr(120,5,"return");


       }

     else if(oled_option==1)
     {   Higher_ben_speed=value*5+Higher_ben_speed;
     value=0;
     ips200_showstr(0, 0, "H_str_speed");
      ips200_showfloat(120,0,Higher_str_speed,3,1);
      uicolorget(0,1,"H_ben_speed", IPS200_PENCOLOR,0x001F);
      ips200_showfloat(120,1,Higher_ben_speed,3,1);
      ips200_showstr(120,5,"return");}

     else if(oled_option==2)
     {
         ips200_showstr(0, 0, "H_str_speed");
               ips200_showfloat(120,0,Higher_str_speed,3,1);
               ips200_showstr(0,1,"H_ben_speed");
               ips200_showfloat(120,1,Higher_ben_speed,3,1);
               uicolorget(120,5,"return",IPS200_PENCOLOR,0x001F);
               if(!gpio_get(add_value))   //return
                                                                                                       {START_PAGE=Choose_and_no_debug;
                                                                                                       oled_page=0;
                                                                                                       oled_option=0;
                                                                                                       ips200_clear(IPS200_BGCOLOR);
                                                                                                       goto ONE_OVER;}   //写完发现妙啊，这一步，我是怎么想到的，O(∩_∩)O哈哈~

     }
     else if(oled_option>2)
        {oled_option%=3;}
}

else if(START_PAGE==Init_debug)
{
     if(oled_option==0) {
         variable_3=value+variable_3;
                value=0;
                uicolorget(0, 0, "dj_init", IPS200_PENCOLOR,0x001F);
                 ips200_showfloat(120,0,variable_3,3,1);

                 ips200_showstr(120,3,"return");


       }

     else if(oled_option==1)
     {

         ips200_showstr(0, 0, "dj_init");
                         ips200_showfloat(120,0,variable_3,3,1);

                         uicolorget(120,3,"return", IPS200_PENCOLOR,0x001F);


               if(!gpio_get(add_value))   //return
                                                                                                       {START_PAGE=Choose_and_no_debug;
                                                                                                       oled_page=0;
                                                                                                       oled_option=0;
                                                                                                       ips200_clear(IPS200_BGCOLOR);
                                                                                                       goto ONE_OVER;}   //写完发现妙啊，这一步，我是怎么想到的，O(∩_∩)O哈哈~

     }
     else if(oled_option>1)
        {oled_option%=2;}
}
//
else if(oled_page==0&&START_PAGE!=Choose_and_no_debug)    //第0页
{
if(oled_option==0)    //第0行
{  
  Kp_R_15=value+Kp_R_15;
  value=0;
  uicolorget(0, 0, "Kp_R_15", IPS200_PENCOLOR,0x001F);
   ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
   ips200_showstr(0,1,"Kd_R_15");
   ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
   ips200_showstr(0,2,"Kp_L_15");
   ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
   ips200_showstr(0,3,"Kd_L_15");
   ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
   ips200_showstr(0,4,"Kp_S");
   ips200_showfloat(70,4,0.1*Kp_S,1,1);
   ips200_showstr(0,5,"Kd_S");
   ips200_showfloat(70,5,0.1*Kd_S,1,1);
   ips200_showstr(0,6,"speed_straight");
   ips200_showuint16(70,6,hope_speed_straight);
   ips200_showstr(0,7,"speed_bend");
   ips200_showuint16(70,7,hope_speed);
   ips200_showstr(0,8,"spkp");
   ips200_showuint16(70,8,spkp);
   ips200_showstr(0,9,"spki");
   ips200_showuint16(70,9,spki);
   ips200_showstr(0,10,"variable_3");
   ips200_showuint16(70,10,variable_3);
   ips200_showstr(0,11,"variable_4");
   ips200_showuint16(70,11,variable_4);
}
else if(oled_option==1)
{
  Kd_R_15=value+Kd_R_15;
  value=0;

  ips200_showstr(0,0,"Kp_R_15");
  ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
  uicolorget(0,1,"Kd_R_15", IPS200_PENCOLOR,0x001F);
  ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
  ips200_showstr(0,2,"Kp_L_15");
  ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
  ips200_showstr(0,3,"Kd_L_15");
  ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
  ips200_showstr(0,4,"Kp_S");
  ips200_showfloat(70,4,0.1*Kp_S,1,1);
  ips200_showstr(0,5,"Kd_S");
  ips200_showfloat(70,5,0.1*Kd_S,1,1);
  ips200_showstr(0,6,"speed_straight");
  ips200_showuint16(70,6,hope_speed_straight);
  ips200_showstr(0,7,"speed_bend");
  ips200_showuint16(70,7,hope_speed);
  ips200_showstr(0,8,"spkp");
  ips200_showuint16(70,8,spkp);
  ips200_showstr(0,9,"spki");
  ips200_showuint16(70,9,spki);
  ips200_showstr(0,10,"variable_3");
  ips200_showuint16(70,10,variable_3);
  ips200_showstr(0,11,"variable_4");
  ips200_showuint16(70,11,variable_4);
}
else if(oled_option==2)
{
  Kp_L_15=value+Kp_L_15;
  value=0;
//  uicolorget(0, 0, "Kp_R_15", IPS200_PENCOLOR,0x001F);

   ips200_showstr(0,0,"Kp_R_15");
   ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
   ips200_showstr(0,1,"Kd_R_15");
   ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
   uicolorget(0,2,"Kp_L_15", IPS200_PENCOLOR,0x001F);
   ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
   ips200_showstr(0,3,"Kd_L_15");
   ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
   ips200_showstr(0,4,"Kp_S");
   ips200_showfloat(70,4,0.1*Kp_S,1,1);
   ips200_showstr(0,5,"Kd_S");
   ips200_showfloat(70,5,0.1*Kd_S,1,1);
   ips200_showstr(0,6,"speed_straight");
   ips200_showuint16(70,6,hope_speed_straight);
   ips200_showstr(0,7,"speed_bend");
   ips200_showuint16(70,7,hope_speed);
   ips200_showstr(0,8,"spkp");
   ips200_showuint16(70,8,spkp);
   ips200_showstr(0,9,"spki");
   ips200_showuint16(70,9,spki);
   ips200_showstr(0,10,"variable_3");
   ips200_showuint16(70,10,variable_3);
   ips200_showstr(0,11,"variable_4");
   ips200_showuint16(70,11,variable_4);
}
else if(oled_option==3)
{
  Kd_L_15=value+Kd_L_15;
  value=0;
  ips200_showstr(0,0,"Kp_R_15");
  ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
  ips200_showstr(0,1,"Kd_R_15");
  ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
  ips200_showstr(0,2,"Kp_L_15");
  ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
  uicolorget(0,3,"Kd_L_15", IPS200_PENCOLOR,0x001F);
  ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
  ips200_showstr(0,4,"Kp_S");
  ips200_showfloat(70,4,0.1*Kp_S,1,1);
  ips200_showstr(0,5,"Kd_S");
  ips200_showfloat(70,5,0.1*Kd_S,1,1);
  ips200_showstr(0,6,"speed_straight");
  ips200_showuint16(70,6,hope_speed_straight);
  ips200_showstr(0,7,"speed_bend");
  ips200_showuint16(70,7,hope_speed);
  ips200_showstr(0,8,"spkp");
  ips200_showuint16(70,8,spkp);
  ips200_showstr(0,9,"spki");
  ips200_showuint16(70,9,spki);
  ips200_showstr(0,10,"variable_3");
  ips200_showuint16(70,10,variable_3);
  ips200_showstr(0,11,"variable_4");
  ips200_showuint16(70,11,variable_4);
}
else if(oled_option==4)
{
  Kp_S=value+Kp_S;
  value=0;
  ips200_showstr(0,0,"Kp_R_15");
  ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
  ips200_showstr(0,1,"Kd_R_15");
  ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
  ips200_showstr(0,2,"Kp_L_15");
  ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
  ips200_showstr(0,3,"Kd_L_15");
  ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
  uicolorget(0,4,"Kp_S", IPS200_PENCOLOR,0x001F);
  ips200_showfloat(70,4,0.1*Kp_S,1,1);
  ips200_showstr(0,5,"Kd_S");
  ips200_showfloat(70,5,0.1*Kd_S,1,1);
  ips200_showstr(0,6,"speed_straight");
  ips200_showuint16(70,6,hope_speed_straight);
  ips200_showstr(0,7,"speed_bend");
  ips200_showuint16(70,7,hope_speed);
  ips200_showstr(0,8,"spkp");
  ips200_showuint16(70,8,spkp);
  ips200_showstr(0,9,"spki");
  ips200_showuint16(70,9,spki);
  ips200_showstr(0,10,"variable_3");
  ips200_showuint16(70,10,variable_3);
  ips200_showstr(0,11,"variable_4");
  ips200_showuint16(70,11,variable_4);
}
else if(oled_option==5)
{
  Kd_S=value+Kd_S;
  value=0;
  ips200_showstr(0,0,"Kp_R_15");
   ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
   ips200_showstr(0,1,"Kd_R_15");
   ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
   ips200_showstr(0,2,"Kp_L_15");
   ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
   ips200_showstr(0,3,"Kd_L_15");
   ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
   ips200_showstr(0,4,"Kp_S");
   ips200_showfloat(70,4,0.1*Kp_S,1,1);
   uicolorget(0,5,"Kd_S", IPS200_PENCOLOR,0x001F);
   ips200_showfloat(70,5,0.1*Kd_S,1,1);
   ips200_showstr(0,6,"speed_straight");
   ips200_showuint16(70,6,hope_speed_straight);
   ips200_showstr(0,7,"speed_bend");
   ips200_showuint16(70,7,hope_speed);
   ips200_showstr(0,8,"spkp");
   ips200_showuint16(70,8,spkp);
   ips200_showstr(0,9,"spki");
   ips200_showuint16(70,9,spki);
   ips200_showstr(0,10,"variable_3");
   ips200_showuint16(70,10,variable_3);
   ips200_showstr(0,11,"variable_4");
   ips200_showuint16(70,11,variable_4);

}
else if(oled_option==6)
{
  hope_speed_straight=value+hope_speed_straight;
  value=0;
  ips200_showstr(0,0,"Kp_R_15");
   ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
   ips200_showstr(0,1,"Kd_R_15");
   ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
   ips200_showstr(0,2,"Kp_L_15");
   ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
   ips200_showstr(0,3,"Kd_L_15");
   ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
   ips200_showstr(0,4,"Kp_S");
   ips200_showfloat(70,4,0.1*Kp_S,1,1);
   ips200_showstr(0,5,"Kd_S");
   ips200_showfloat(70,5,0.1*Kd_S,1,1);
   uicolorget(0,6,"speed_straight", IPS200_PENCOLOR,0x001F);
   ips200_showuint16(70,6,hope_speed_straight);
   ips200_showstr(0,7,"speed_bend");
   ips200_showuint16(70,7,hope_speed);
   ips200_showstr(0,8,"spkp");
   ips200_showuint16(70,8,spkp);
   ips200_showstr(0,9,"spki");
   ips200_showuint16(70,9,spki);
   ips200_showstr(0,10,"variable_3");
   ips200_showuint16(70,10,variable_3);
   ips200_showstr(0,11,"variable_4");
   ips200_showuint16(70,11,variable_4);
}
else if(oled_option==7)
{
    hope_speed=value+hope_speed;
  value=0;
  ips200_showstr(0,0,"Kp_R_15");
   ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
   ips200_showstr(0,1,"Kd_R_15");
   ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
   ips200_showstr(0,2,"Kp_L_15");
   ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
   ips200_showstr(0,3,"Kd_L_15");
   ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
   ips200_showstr(0,4,"Kp_S");
   ips200_showfloat(70,4,0.1*Kp_S,1,1);
   ips200_showstr(0,5,"Kd_S");
   ips200_showfloat(70,5,0.1*Kd_S,1,1);
   ips200_showstr(0,6,"speed_straight");
   ips200_showuint16(70,6,hope_speed_straight);
   uicolorget(0,7,"speed_bend", IPS200_PENCOLOR,0x001F);
   ips200_showuint16(70,7,hope_speed);
   ips200_showstr(0,8,"spkp");
   ips200_showuint16(70,8,spkp);
   ips200_showstr(0,9,"spki");
   ips200_showuint16(70,9,spki);
   ips200_showstr(0,10,"variable_3");
   ips200_showuint16(70,10,variable_3);
   ips200_showstr(0,11,"variable_4");
   ips200_showuint16(70,11,variable_4);
}
else if(oled_option==8)
{
    spkp=value+spkp;
  value=0;
  ips200_showstr(0,0,"Kp_R_15");
   ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
   ips200_showstr(0,1,"Kd_R_15");
   ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
   ips200_showstr(0,2,"Kp_L_15");
   ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
   ips200_showstr(0,3,"Kd_L_15");
   ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
   ips200_showstr(0,4,"Kp_S");
   ips200_showfloat(70,4,0.1*Kp_S,1,1);
   ips200_showstr(0,5,"Kd_S");
   ips200_showfloat(70,5,0.1*Kd_S,1,1);
   ips200_showstr(0,6,"speed_straight");
   ips200_showuint16(70,6,hope_speed_straight);
   ips200_showstr(0,7,"speed_bend");
   ips200_showuint16(70,7,hope_speed);
   uicolorget(0,8,"spkp", IPS200_PENCOLOR,0x001F);
   ips200_showuint16(70,8,spkp);
   ips200_showstr(0,9,"spki");
   ips200_showuint16(70,9,spki);
   ips200_showstr(0,10,"variable_3");
   ips200_showuint16(70,10,variable_3);
   ips200_showstr(0,11,"variable_4");
   ips200_showuint16(70,11,variable_4);
}
else if(oled_option==9)
{
    spki=value+spki;
  value=0;
  ips200_showstr(0,0,"Kp_R_15");
   ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
   ips200_showstr(0,1,"Kd_R_15");
   ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
   ips200_showstr(0,2,"Kp_L_15");
   ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
   ips200_showstr(0,3,"Kd_L_15");
   ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
   ips200_showstr(0,4,"Kp_S");
   ips200_showfloat(70,4,0.1*Kp_S,1,1);
   ips200_showstr(0,5,"Kd_S");
   ips200_showfloat(70,5,0.1*Kd_S,1,1);
   ips200_showstr(0,6,"speed_straight");
   ips200_showuint16(70,6,hope_speed_straight);
   ips200_showstr(0,7,"speed_bend");
   ips200_showuint16(70,7,hope_speed);
   ips200_showstr(0,8,"spkp");
   ips200_showuint16(70,8,spkp);
   uicolorget(0,9,"spki", IPS200_PENCOLOR,0x001F);
   ips200_showuint16(70,9,spki);
   ips200_showstr(0,10,"variable_3");
   ips200_showuint16(70,10,variable_3);
   ips200_showstr(0,11,"variable_4");
   ips200_showuint16(70,11,variable_4);
}
else if(oled_option==10)
{
    variable_3=value+variable_3;
  value=0;
  ips200_showstr(0,0,"Kp_R_15");
   ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
   ips200_showstr(0,1,"Kd_R_15");
   ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
   ips200_showstr(0,2,"Kp_L_15");
   ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
   ips200_showstr(0,3,"Kd_L_15");
   ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
   ips200_showstr(0,4,"Kp_S");
   ips200_showfloat(70,4,0.1*Kp_S,1,1);
   ips200_showstr(0,5,"Kd_S");
   ips200_showfloat(70,5,0.1*Kd_S,1,1);
   ips200_showstr(0,6,"speed_straight");
   ips200_showuint16(70,6,hope_speed_straight);
   ips200_showstr(0,7,"speed_bend");
   ips200_showuint16(70,7,hope_speed);
   ips200_showstr(0,8,"spkp");
   ips200_showuint16(70,8,spkp);
   ips200_showstr(0,9,"spki");
   ips200_showuint16(70,9,spki);
   uicolorget(0,10,"variable_3", IPS200_PENCOLOR,0x001F);
   ips200_showuint16(70,10,variable_3);
   ips200_showstr(0,11,"variable_4");
   ips200_showuint16(70,11,variable_4);
}
else if(oled_option==11)
{
    variable_4=value+variable_4;
  value=0;
  ips200_showstr(0,0,"Kp_R_15");
   ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
   ips200_showstr(0,1,"Kd_R_15");
   ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
   ips200_showstr(0,2,"Kp_L_15");
   ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
   ips200_showstr(0,3,"Kd_L_15");
   ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
   ips200_showstr(0,4,"Kp_S");
   ips200_showfloat(70,4,0.1*Kp_S,1,1);
   ips200_showstr(0,5,"Kd_S");
   ips200_showfloat(70,5,0.1*Kd_S,1,1);
   ips200_showstr(0,6,"speed_straight");
   ips200_showuint16(70,6,hope_speed_straight);
   ips200_showstr(0,7,"speed_bend");
   ips200_showuint16(70,7,hope_speed);
   ips200_showstr(0,8,"spkp");
   ips200_showuint16(70,8,spkp);
   ips200_showstr(0,9,"spki");
   ips200_showuint16(70,9,spki);
   ips200_showstr(0,10,"variable_3");
   ips200_showuint16(70,10,variable_3);
   uicolorget(0,11,"variable_4", IPS200_PENCOLOR,0x001F);
   ips200_showuint16(70,11,variable_4);
}
else if(oled_option==12)
{
  //  hope_speed=value+hope_speed;
  value=0;
  ips200_showstr(120,0," ");
  ips200_showstr(120,1," ");
  ips200_showstr(120,2," ");
  ips200_showstr(120,3," ");
  ips200_showstr(120,4," ");
  ips200_showstr(120,5," ");
  ips200_showstr(120,6," ");
  ips200_showstr(120,7," ");
  ips200_showstr(120,8," ");
  ips200_showstr(120,9," ");
  ips200_showstr(120,10," ");
  ips200_showstr(120,11," ");
  ips200_showstr(120,12,"1");
  ips200_showstr(120,13," ");
  ips200_showstr(120,14," ");
  ips200_showstr(120,15," ");
  ips200_showstr(120,16," ");
}
else if(oled_option==13)
{
   // hope_speed=value+hope_speed;
  value=0;
  ips200_showstr(120,0," ");
  ips200_showstr(120,1," ");
  ips200_showstr(120,2," ");
  ips200_showstr(120,3," ");
  ips200_showstr(120,4," ");
  ips200_showstr(120,5," ");
  ips200_showstr(120,6," ");
  ips200_showstr(120,7," ");
  ips200_showstr(120,8," ");
  ips200_showstr(120,9," ");
  ips200_showstr(120,10," ");
  ips200_showstr(120,11," ");
  ips200_showstr(120,12," ");
  ips200_showstr(120,13,"1");
  ips200_showstr(120,14," ");
  ips200_showstr(120,15," ");
  ips200_showstr(120,16," ");
}
else if(oled_option==14)
{
    //hope_speed=value+hope_speed;
  value=0;
  ips200_showstr(120,0," ");
  ips200_showstr(120,1," ");
  ips200_showstr(120,2," ");
  ips200_showstr(120,3," ");
  ips200_showstr(120,4," ");
  ips200_showstr(120,5," ");
  ips200_showstr(120,6," ");
  ips200_showstr(120,7," ");
  ips200_showstr(120,8," ");
  ips200_showstr(120,9," ");
  ips200_showstr(120,10," ");
  ips200_showstr(120,11," ");
  ips200_showstr(120,12," ");
  ips200_showstr(120,13," ");
  ips200_showstr(120,14,"1");
  ips200_showstr(120,15," ");
  ips200_showstr(120,16," ");
}
else if(oled_option==15)
{
 //   hope_speed=value+hope_speed;
  value=0;
  ips200_showstr(120,0," ");
  ips200_showstr(120,1," ");
  ips200_showstr(120,2," ");
  ips200_showstr(120,3," ");
  ips200_showstr(120,4," ");
  ips200_showstr(120,5," ");
  ips200_showstr(120,6," ");
  ips200_showstr(120,7," ");
  ips200_showstr(120,8," ");
  ips200_showstr(120,9," ");
  ips200_showstr(120,10," ");
  ips200_showstr(120,11," ");
  ips200_showstr(120,12," ");
  ips200_showstr(120,13," ");
  ips200_showstr(120,14," ");
  ips200_showstr(120,15,"1");
  ips200_showstr(120,16," ");
}
else if(oled_option==16)
{
    //hope_speed=value+hope_speed;
  value=0;
  ips200_showstr(120,0," ");
  ips200_showstr(120,1," ");
  ips200_showstr(120,2," ");
  ips200_showstr(120,3," ");
  ips200_showstr(120,4," ");
  ips200_showstr(120,5," ");
  ips200_showstr(120,6," ");
  ips200_showstr(120,7," ");
  ips200_showstr(120,8," ");
  ips200_showstr(120,9," ");
  ips200_showstr(120,10," ");
  ips200_showstr(120,11," ");
  ips200_showstr(120,12," ");
  ips200_showstr(120,13," ");
  ips200_showstr(120,14," ");
  ips200_showstr(120,15," ");
  ips200_showstr(120,16,"1");
}

//
//ips200_showstr(0,0,"Kp_R_15");
//ips200_showfloat(70,0,0.1*Kp_R_15,1,1);
//ips200_showstr(0,1,"Kd_R_15");
//ips200_showfloat(70,1,0.1*Kd_R_15,1,1);
//ips200_showstr(0,2,"Kp_L_15");
//ips200_showfloat(70,2,0.1*Kp_L_15,1,1);
//ips200_showstr(0,3,"Kd_L_15");
//ips200_showfloat(70,3,0.1*Kd_L_15,1,1);
//ips200_showstr(0,4,"Kp_S");
//ips200_showfloat(70,4,0.1*Kp_S,1,1);
//ips200_showstr(0,5,"Kd_S");
//ips200_showfloat(70,5,0.1*Kd_S,1,1);
//ips200_showstr(0,6,"speed_straight");
//ips200_showuint16(70,6,hope_speed_straight);
//ips200_showstr(0,7,"speed_bend");
//ips200_showuint16(70,7,hope_speed);
//ips200_showstr(0,8,"spkp");
//ips200_showuint16(70,8,spkp);
//ips200_showstr(0,9,"spki");
//ips200_showuint16(70,9,spki);
//ips200_showstr(0,10,"variable_3");
//ips200_showuint16(70,10,variable_3);
//ips200_showstr(0,11,"variable_4");
//ips200_showuint16(70,11,variable_4);
}
systick_delay_ms(STM0, 50);

}

void Read_information(struct PARAMGET *p_param)
{
    if(flash_check(EEPROM_SECTOR_NUM-1, 0))   // 校验FLASH是否有数据
    {
    eeprom_page_program(EEPROM_SECTOR_NUM-1,12, &DJ_fuzz_par.Fuzz_L_1);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,1, &Kd_R_15);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,2, &Kp_L_15);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,3, &Kd_L_15);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,4, &Kp_S);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,5, &Kd_S);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,6, &hope_speed_straight);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,7, &hope_speed);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,8, &spkp);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,9, &spki);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,10, &variable_3);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,11, &variable_4);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,13, &DJ_fuzz_par.Fuzz_L_2);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,14, &DJ_fuzz_par.Fuzz_L_3);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,15, &DJ_fuzz_par.Fuzz_L_4);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,16, &DJ_fuzz_par.Fuzz_L_5);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,17, &DJ_fuzz_par.Fuzz_L_6);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,18, &DJ_fuzz_par.Fuzz_L_7);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,19, &DJ_fuzz_par.Fuzz_R_1);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,20, &DJ_fuzz_par.Fuzz_R_2);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,21, &DJ_fuzz_par.Fuzz_R_3);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,22, &DJ_fuzz_par.Fuzz_R_4);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,23, &DJ_fuzz_par.Fuzz_R_5);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,24, &DJ_fuzz_par.Fuzz_R_6);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,25, &DJ_fuzz_par.Fuzz_R_7);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,26, &var_threshold);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,27, &Higher_str_speed);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,28, &Higher_ben_speed);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,29, &Huandao_speed);

//for(uint16 i=0;i<512;i++)
//{
//    {
//        eeprom_page_program(EEPROM_SECTOR_NUM-1,500+i, (DataBuffer+i));
//    }
//}

    //从flash里读数据存到结构体里面去
    //再从结构体中读出数据
    p_param->int01=flash_read(EEPROM_SECTOR_NUM-1,12,uint32);     //尽量用最后面的扇区，确保安全,否则疯狂清零，麻了
    p_param->int02=flash_read(EEPROM_SECTOR_NUM-1,1,uint32);
    p_param->int03=flash_read(EEPROM_SECTOR_NUM-1,2,uint32);
    p_param->int04=flash_read(EEPROM_SECTOR_NUM-1,3,uint32);
    p_param->int05=flash_read(EEPROM_SECTOR_NUM-1,4,uint32);
    p_param->int06=flash_read(EEPROM_SECTOR_NUM-1,5,uint32);
    p_param->int07=flash_read(EEPROM_SECTOR_NUM-1,6,uint32);
    p_param->int08=flash_read(EEPROM_SECTOR_NUM-1,7,uint32);
    p_param->int09=flash_read(EEPROM_SECTOR_NUM-1,8,uint32);
    p_param->int10=flash_read(EEPROM_SECTOR_NUM-1,9,uint32);
    p_param->int11=flash_read(EEPROM_SECTOR_NUM-1,10,uint32);
    p_param->int12=flash_read(EEPROM_SECTOR_NUM-1,11,uint32);
    p_param->int13=flash_read(EEPROM_SECTOR_NUM-1,13,uint32);
    p_param->int14=flash_read(EEPROM_SECTOR_NUM-1,14,uint32);
    p_param->int15=flash_read(EEPROM_SECTOR_NUM-1,15,uint32);
    p_param->int16=flash_read(EEPROM_SECTOR_NUM-1,16,uint32);
    p_param->int17=flash_read(EEPROM_SECTOR_NUM-1,17,uint32);
    p_param->int18=flash_read(EEPROM_SECTOR_NUM-1,18,uint32);
    p_param->int19=flash_read(EEPROM_SECTOR_NUM-1,19,uint32);
    p_param->int20=flash_read(EEPROM_SECTOR_NUM-1,20,uint32);
    p_param->int21=flash_read(EEPROM_SECTOR_NUM-1,21,uint32);
    p_param->int22=flash_read(EEPROM_SECTOR_NUM-1,22,uint32);
    p_param->int23=flash_read(EEPROM_SECTOR_NUM-1,23,uint32);
    p_param->int24=flash_read(EEPROM_SECTOR_NUM-1,24,uint32);
    p_param->int25=flash_read(EEPROM_SECTOR_NUM-1,25,uint32);
    p_param->int26=flash_read(EEPROM_SECTOR_NUM-1,26,uint32);
    p_param->int27=flash_read(EEPROM_SECTOR_NUM-1,27,uint32);
    p_param->int28=flash_read(EEPROM_SECTOR_NUM-1,28,uint32);

    p_param->int29=flash_read(EEPROM_SECTOR_NUM-1,29,uint32);

//    for(uint8 j=0;j<512;j++)
//    {
//        DataTemp[j]=flash_read(EEPROM_SECTOR_NUM-1,500+j,uint32);
//    }




    DJ_fuzz_par.Fuzz_L_1=(p_param->int01);//从结构体中读数据存到相应的变量中
    Kd_R_15=(p_param->int02);
    Kp_L_15=(p_param->int03);
    Kd_L_15=(p_param->int04);
    Kp_S=(p_param->int05);
    Kd_S=(p_param->int06);
    hope_speed_straight=(p_param->int07);
    hope_speed=(p_param->int08);
    spkp=(p_param->int09);
    spki=(p_param->int10);
    variable_3=(p_param->int11);
    variable_4=(p_param->int12);
    DJ_fuzz_par.Fuzz_L_2=(p_param->int13);
    DJ_fuzz_par.Fuzz_L_3=(p_param->int14);
    DJ_fuzz_par.Fuzz_L_4=(p_param->int15);
    DJ_fuzz_par.Fuzz_L_5=(p_param->int16);
    DJ_fuzz_par.Fuzz_L_6=(p_param->int17);
    DJ_fuzz_par.Fuzz_L_7=(p_param->int18);
    DJ_fuzz_par.Fuzz_R_1=(p_param->int19);
    DJ_fuzz_par.Fuzz_R_2=(p_param->int20);
    DJ_fuzz_par.Fuzz_R_3=(p_param->int21);
    DJ_fuzz_par.Fuzz_R_4=(p_param->int22);
    DJ_fuzz_par.Fuzz_R_5=(p_param->int23);
    DJ_fuzz_par.Fuzz_R_6=(p_param->int24);
    DJ_fuzz_par.Fuzz_R_7=(p_param->int25);
    var_threshold=(p_param->int26);
    Higher_str_speed=(p_param->int27);
    Higher_ben_speed=(p_param->int28);
    Huandao_speed=(p_param->int29);

//    for(uint8 k=0;k<512;k++)
//        {
//            DataBuffer[k]=DataTemp[k];
//        }

}

}
void Write_information(struct PARAMGET *p_param)    //把结构体中的数据存到flash里面去
{
    eeprom_erase_sector(EEPROM_SECTOR_NUM-1);  //擦除扇区，如果扇区已经有数据则必须擦除扇区之后才能再次写入新的数据
    systick_delay_ms(STM0,10);
    (p_param->int01)=DJ_fuzz_par.Fuzz_L_1;
       (p_param->int02)=Kd_R_15;
       (p_param->int03)=Kp_L_15;
       (p_param->int04)=Kd_L_15;
       (p_param->int05)=Kp_S;
       (p_param->int06)=Kd_S;
       (p_param->int07)=hope_speed_straight;
       (p_param->int08)=hope_speed;
       (p_param->int09)=spkp;
       (p_param->int10)=spki;
       (p_param->int11)=variable_3;
       (p_param->int12)=variable_4;
       (p_param->int13)=DJ_fuzz_par.Fuzz_L_2;
       (p_param->int14)=DJ_fuzz_par.Fuzz_L_3;
       (p_param->int15)=DJ_fuzz_par.Fuzz_L_4;
       (p_param->int16)=DJ_fuzz_par.Fuzz_L_5;
       (p_param->int17)=DJ_fuzz_par.Fuzz_L_6;
       (p_param->int18)=DJ_fuzz_par.Fuzz_L_7;
       (p_param->int19)=DJ_fuzz_par.Fuzz_L_1;
       (p_param->int20)=DJ_fuzz_par.Fuzz_L_2;
       (p_param->int21)=DJ_fuzz_par.Fuzz_L_3;
       (p_param->int22)=DJ_fuzz_par.Fuzz_L_4;
       (p_param->int23)=DJ_fuzz_par.Fuzz_L_5;
       (p_param->int24)=DJ_fuzz_par.Fuzz_L_6;
       (p_param->int25)=DJ_fuzz_par.Fuzz_L_7;
       (p_param->int26)=var_threshold;
       (p_param->int27)=Higher_str_speed;
       (p_param->int28)=Higher_ben_speed;
       (p_param->int29)=Huandao_speed;


    eeprom_page_program(EEPROM_SECTOR_NUM-1,12, &DJ_fuzz_par.Fuzz_L_1);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,1, &Kd_R_15);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,2, &Kp_L_15);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,3, &Kd_L_15);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,4, &Kp_S);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,5, &Kd_S);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,6, &hope_speed_straight);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,7, &hope_speed);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,8, &spkp);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,9, &spki);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,10, &variable_3);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,11, &variable_4);
    eeprom_page_program(EEPROM_SECTOR_NUM-1,13, &DJ_fuzz_par.Fuzz_L_2);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,14, &DJ_fuzz_par.Fuzz_L_3);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,15, &DJ_fuzz_par.Fuzz_L_4);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,16, &DJ_fuzz_par.Fuzz_L_5);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,17, &DJ_fuzz_par.Fuzz_L_6);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,18, &DJ_fuzz_par.Fuzz_L_7);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,19, &DJ_fuzz_par.Fuzz_R_1);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,20, &DJ_fuzz_par.Fuzz_R_2);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,21, &DJ_fuzz_par.Fuzz_R_3);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,22, &DJ_fuzz_par.Fuzz_R_4);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,23, &DJ_fuzz_par.Fuzz_R_5);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,24, &DJ_fuzz_par.Fuzz_R_6);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,25, &DJ_fuzz_par.Fuzz_R_7);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,26, &var_threshold);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,27, &Higher_str_speed);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,28, &Higher_ben_speed);
        eeprom_page_program(EEPROM_SECTOR_NUM-1,29, &Huandao_speed);
}

void InFoRealData()
{
    eeprom_erase_sector(EEPROM_SECTOR_NUM-1);  //擦除扇区，如果扇区已经有数据则必须擦除扇区之后才能再次写入新的数据
    systick_delay_ms(STM0,10);
   for(uint8 i=0;i<512;i++)
   {
       DataTemp[i]=DataBuffer[i];
   }

//   for(uint8 j=0;j<512;j++)
//   {
//        eeprom_page_program(EEPROM_SECTOR_NUM-1,500+j, &(DataBuffer+j));
//   }
}

