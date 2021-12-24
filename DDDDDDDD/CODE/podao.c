#include "podao.h"

uint16  M_podao_count=0;
uint8 zero_endline_count=0;
uint8 podao_up=0;


uint16 podao_flag=0;
uint16 podao_time=0;
uint16 podao_flag_1=0;


//uint16 po_count=0;
//uint16 po_time=0;
void podao_find()
{
uint8  M_podao_change=0;
M_podao_count=0;

 
   //入坡道
  for(uint8 i=59;i>endline;i--)
  {
    if(leftline[i]==0&&rightline[i]==158)
    {
      M_podao_count++;
    }
    else
    {
      M_podao_change=i;       //坡道结束点
      break;
    }
    
  }

 

if(!chuku_flag&&!podao_flag&&podao_time<=1&&!ku_L&&!qipao_flag&&!ku_R&&!huan_L_flag&&!huan_R_flag&&!L_crossroad&&!R_crossroad&&!s_to_b_1)
{ 
  if(M_podao_count>=30&&zero_endline_count>=15)
  {
//      buzzer(1);
      podao_flag=1;
  }
  
}

if(podao_flag==1)
{
    if(!(M_podao_count>=35&&zero_endline_count>=15))
    {
        podao_up++;
    }
    if(podao_up>=10)
    {
//        buzzer(0);
        podao_flag=2;
        podao_up=0;
    }
}

if(podao_flag==2)
{
    if(M_podao_count>=35&&zero_endline_count>=15)
    {
//        buzzer(1);
        podao_flag=3;
    }
}
if(podao_flag==3)
{
    if(!(M_podao_count>=35&&zero_endline_count>=15))
    {
        podao_up++;
    }
    if(podao_up>=10)
    {
//        buzzer(0);
        podao_flag=0;
        podao_up=0;
        podao_time++;
    }
}


}
