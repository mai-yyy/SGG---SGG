#include "headfile.h"


#define base_p saidao.center[BOTTOM]
#define    MID 79
#define   search_bus  15
#define ONE_End (int16)(MT9V032_H * 0.2) //第一段结束行
#define TWO_End (int16)(MT9V032_H * 0.9) //第二段结束行
extern unsigned char out_flag;
extern short int leftline[Row];
extern short int rightline[Row];
extern short int midline[Row];
extern short int endline;
extern float differ;
extern int16 final_Optimalpoint_get;
extern  uint8 TrainglrNum;
extern float WeightSum;
extern uint8 box_right;
extern uint8 box_left;
extern uint8 remember;
extern uint8 remind;
extern float MidSum;
extern uint8 ShangForkDir;
extern float MidValue;
extern short int error[Row];
extern float weight[60];
extern unsigned char s_to_b_1;
extern unsigned char s_to_b_2;
extern uint8 straightFlag;
extern uint8 bendFlag;
extern unsigned char bend_count;
extern unsigned char differ_C;
extern float variance;
extern float variance_acc;  //方差
extern uint8 type_str;
extern uint32 var_threshold;
typedef enum {
  Normol=3,       //无任何特征
  str,     ////直道
  Bend,          //弯道   后期区别   入弯加d，出弯减d；
  Straighttobend,   //直线入弯
  Cross,        ////十字
  Ramp,         //坡道
  LeftCirque,   ////左圆环
  RightCirque,  ////右圆环
  Forkin,       //岔路进口
  Forkout,      //岔路出口
  Barn_out,     //出库
  Barn_in,      //入库
  Cross_ture,
  Cross_road_flag,//十字丢线标志位  不一定为真正的十字

} RoadType_e;

typedef enum
{
    straight = 0,
    long_str,
    short_str,
    straight_shizi,
    run_to_left,
    run_to_right,
    out_left,
    out_right,
    in_left,
    in_right,
    cross_rode,
    not_straight,
}WAY_STATUS;

typedef enum
{
  T,
  Z,
}Line_Staue;

typedef struct image_info_2_dimensional_point       //二维点的结构体
{
        int16  my_x;
        int16 my_y;
} Maiy_2_dimensional;



//边线结构体
typedef struct info_characteristic_point
{
        Maiy_2_dimensional miay_left_line[MT9V032_H+15]; /*左边边线数组*/
        Maiy_2_dimensional miay_right_line[MT9V032_H+15]; /*右边边线数组*/
        Maiy_2_dimensional miay_mid_line[MT9V032_H+15]; /*中线数组*/

        RoadType_e Road_type;

        Maiy_2_dimensional m_stLMaxPoint; /*左边最大点,在正常情况下,最大点不应该出现在边线的中间,只会出现在边线结束,出现在中间,那么这个最大点应该就*/
        Maiy_2_dimensional m_stRMinPoint;

        uint32 m_u32LAllArea;                /*左边白色点总面积*/
        uint32 m_u32RAllArea;

        Maiy_2_dimensional my_final_tOptimalPoint;
        Maiy_2_dimensional my_left_LOptimalPoint;
        Maiy_2_dimensional my_right_OptimalPoint;
        Maiy_2_dimensional m_stCenterLinePoint; /*图像中间优所在的最优点*/

        uint16 mylinest[MT9V032_W];  //一列白点向上的个数
        float Left_slope ; //左边线  延伸斜率
        float Right_slope ;//右边线 延伸斜率
        uint16 L_lost_cnt ;
        uint16 R_lost_cnt ;//左、右丢单边线（点）次数
        uint16 L_R_lost_cnt;//左右边界同时丢线次数
        uint8 Left_line_lost[MT9V032_H+15]; //存储边线的搜索情况 1为丢，未找到
        uint8 Right_line_lost[MT9V032_H+15];//存储对应行右边线的 搜索情况 1 为丢未找到

} Maiy_characteristic_point;


//特征结构体
typedef struct
{

   int8  center_row[46];         //终点列坐标
   int8  row_width[46];          //行宽
   int16  center[60];               //midline[60]改为它
   int8  stop_flag_gt;//起跑线停止线检测标志
   uint8 r_lost_start;//右边界开始丢界
   uint8 l_lost_start;//左边界开始丢线
   uint8 stop_flag_a;//停车标志参数a
   uint8 zhangai_dir; //方向 1左 2右
   uint8 podao;
   int8  center2;
   int8  deep_h;//初步检测直线的延展深度
   int8  deep_h1;//精确检测直线的延展性（当  deep_h>deep_h1多半是十字出弯）
   int8  k_c;//标记检索策略
   int16 Cross_road_cnt;//十字丢线次数
   int16 row ;//行数
   int16 Left_line_search[MT9V032_H];//扫线边界限制，根据本行的数值，预判下一行扫线位置，减小处理行数
   int16 Right_line_search[MT9V032_H];//扫线边界限制，根据本行的数值，预判下一行扫线位置，减小处理行数
   uint8 Found_left_flag;//1行判断找到但异常，该行左、右边线黑点寻找标志位 1为找到
   uint8 Found_right_flag;//找到但异常1行判断，该行左、右边线黑点寻找标志位 1为找到
   uint16      L_R_lost_row;//记录一场图像最后一次两边同时丢线的行
   uint16 L_last_lost_row ;//记录一场图像左边最后一次丢线的所在行
   uint16  R_last_lost_row;//记录一场图像右边最后一次丢线的所在行
   uint8 ues_left_slo;  //斜率能不能使用
   uint8 ues_right_slo;
   int16 earily_lose_hang_L;
          int16 earily_lose_hang_R;
          uint8 have_valid_line_l;
          uint8 have_valid_line_r;
          int16 have_valid_line_l_num;
          int16 have_valid_line_r_num;
          uint16 start_slo_L;//开始斜率补线行
          uint16 start_slo_R;
          uint16 end_slo_L;//结束斜率补线行
          uint16 end_slo_R;

} saidao_tezhen;





typedef struct
{
        Maiy_2_dimensional MAX;    //最大横坐标
        Maiy_2_dimensional MIN;    //最小横坐标

  uint8 OVER_base_y;             //基础动态前瞻行        画在屏幕上
  uint8 OVER_base_y_straight;     // 左右20的直道前瞻
  uint8 OVER_base_y_straight3;    //左右4的前瞻行
  uint8 c_valid_line;               //用其他变量表明了
  uint8 F_line;
  float k;//0 远 1 中 2 近
  uint8 z_line;
  uint8 start_line;
}center_C;

extern double Lenth;
extern int16 RealSpe_L;
extern int16 RealSpe_R;
extern int16 RealSpe;
extern int16 dt_code;
extern uint8 r_t_o;
extern uint8 Island_flag;
extern uint8 Big_island_flag;
extern int16 Island_time;
extern int16 Island_change_time;
extern  Maiy_characteristic_point  real_char;
extern volatile WAY_STATUS  way;
extern int blackColLeftCnt;
extern int blackColRightCnt;

extern int blackColLeftCntx ;
extern int blackColRightCntx ;
extern     int blackColLeftCnty;
extern     int blackColRightCnty;
extern uint8 IsBottomRightJupm;
extern uint8 IsBottomLeftJupm;
extern int16 WidthROWNum;
extern int16 OutWidthStart;
extern int16   OutWidthEnd;
extern int16 OutWidthROWNum; //严重
extern Maiy_2_dimensional L_Temp ;  //左边线找到线的最“远”点（图像上部分）
extern   Maiy_2_dimensional R_Temp ; //右边线找到线的最“远”点（图像上部分）
//  小麦温馨提示 : volatile修饰符的主要目的是提示编译器，该对象的值可能在编译器未检测到的情况下被改变。
//因此编译器不能武断的对引用这些对象的代码作优化处理,不然出bug还不知道怎么回事，(*^▽^*)；
// 否则编译器可能在未检测该变量时对其进行随机赋值.....
extern unsigned char low_endline_count;
extern center_C center_calu;
extern uint8 c_shizhiflag;
extern saidao_tezhen saidao;
extern  Line_Staue LeftLineStaue[60];
extern Line_Staue RightLineStaue[60];
void get_bottom_line();
void get_rest_line();
void  get_endline_R() ;
void get_middle(Maiy_characteristic_point * deal_2_way);
void get_differ(void);
void get_td();
void chujie();
void danbianhuandao_bx();
void GetMaxPnt();
void Optimalpoint();
void  road_type(Maiy_characteristic_point *tptp);
void bu_xian();
void optimal_v20_get();
void get_rest_line_test2();
void get_bottom_line_test2()   ;
void get_rest_line_dy_test_2();
float Middle_Err_Filter(float middle_err);
void Straightacc_Test(void);
void Straight_Test_2(void);
void Boundary_init();
void TEST3();
void get_rest_line_2();
void get_rest_line_dy();
Maiy_2_dimensional GettangoP(int ST,int EN,int sequence);
void get_midline_bc(void);
uint8 Get_Angle(Maiy_2_dimensional A,Maiy_2_dimensional B,Maiy_2_dimensional C);
void GlobalAnglePoint();
void GlobalAnglePoint_TWO() ;
void FlowerPoint();
