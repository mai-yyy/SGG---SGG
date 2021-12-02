#include"mm.h"
int lose_flag=0;
int dde=0;
int lose_r=0;
int dlevel=0;
int lose_l=0;


void JJUD()
{
    int cen=80;
    int num1=0,num2=0;
    int dde=0;
     for(int i=59;i>0;i--)
     {//H 60,W 160
      if(image_data[i][cen]&&!image_data[i-1][cen])       //跳变点出现,丢线
//         if(!image_data[i-1][cen])
      {
          dde=i;
          if(dde>55)
          { dlevel=1;
          lose_flag=1;
          break;
          }

          else if(dlevel>0)
          {  dlevel=0;
              lose_flag=0;
              break;
          }
          else
              break;
     }
     }
     if(!lose_r&&!lose_l)
     {
     if(lose_flag)
     {
          for(int k=80;k>0;k--)
                  {
                      if(image_data[dde][k])
                      {
                          num1++;
                      }
                  }
                  for(int k=80;k<160;k++)
                           {
                               if(image_data[dde][k])
                               {
                                   num2++;
                               }
                           }
                  if(num2>num1)
                           {
                   //   gpio_set(P33_10,1);
                      lose_r=1;
                           }
                           else
                           {
                             //  gpio_set(P33_10,1);
                                 lose_l=1;
                           }
     }
     }
      else
      {
          lose_r=0;
          lose_l=0;
          lose_flag=0;
          gpio_set(P33_10,0);
      }
      }


void JJUD_dc()
{
if(AD[0]<240||AD[1]<240)
{
    lose_flag=1;
}

if(!lose_r&&!lose_l)
   {
   if(lose_flag)
   {
       if(AD[0]-AD[1]>1000)
       {
           lose_r=1;
       }

       else if(AD[1]-AD[0]>1000)
       {
           lose_l=1;
       }
       else
           lose_flag=0;
   }
   else
              {
                  lose_r=0;
                  lose_l=0;
                  lose_flag=0;
                     }

   }


}

