
/****************************************************************************************************
//=========================================电源接线================================================//
//     LCD模块                STM32单片机
//      VCC          接        DC5V/3.3V      //电源
//      GND          接          GND          //电源地
//=======================================液晶屏数据线接线==========================================//
//本模块默认数据总线类型为SPI总线
//     LCD模块                STM32单片机    
//       SDI         接          PB15         //液晶屏SPI总线数据写信号
//=======================================液晶屏控制线接线==========================================//
//     LCD模块 					      STM32单片机 
//       LED         接          PB9          //液晶屏背光控制信号，如果不需要控制，接5V或3.3V
//       CLK         接          PB13         //液晶屏SPI总线时钟信号
//       RS          接          PB10         //液晶屏数据/命令控制信号
//       RST         接          PB12         //液晶屏复位控制信号
//       CS          接          PB11         //液晶屏片选控制信号
//=========================================触摸屏触接线=========================================//
//如果模块不带触摸功能或者带有触摸功能，但是不需要触摸功能，则不需要进行触摸屏接线
//	   LCD模块                STM32单片机 
//      T_IRQ        接          PC10         //触摸屏触摸中断信号
//      T_DO         接          PC2          //触摸屏SPI总线读信号
//      T_DIN        接          PC3          //触摸屏SPI总线写信号
//      T_CS         接          PC13         //触摸屏片选控制信号
//      T_CLK        接          PC0          //触摸屏SPI总线时钟信号
**************************************************************************************************/	
 /* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/	
#ifndef __LCD_H
#define __LCD_H		
#include "global.h"

//LCD重要参数集
typedef struct  
{										    
	uint16_t  width;			//LCD 宽度
	uint16_t  height;			//LCD 高度
	uint16_t  id;				//LCD ID
	uint8_t   dir;			    //横屏还是竖屏控制：0，竖屏；1，横屏。	
	uint16_t  wramcmd;		    //开始写gram指令
	uint16_t  setxcmd;		    //设置x坐标指令
	uint16_t  setycmd;		    //设置y坐标指令	
    uint8_t   xoffset;    
    uint8_t	  yoffset;
}_lcd_dev; 	

//LCD参数
extern _lcd_dev lcddev;	//管理LCD重要参数
/////////////////////////////////////用户配置区///////////////////////////////////	 
#define USE_HORIZONTAL  	 0 //定义液晶屏顺时针旋转方向 	0-0度旋转，1-90度旋转，2-180度旋转，3-270度旋转

//////////////////////////////////////////////////////////////////////////////////	  
//定义LCD的尺寸
#define LCD_W 128
#define LCD_H 128

//TFTLCD部分外要调用的函数		   
extern uint16_t  POINT_COLOR;//默认红色    
extern uint16_t  BACK_COLOR; //背景颜色.默认为白色

////////////////////////////////////////////////////////////////////
//-----------------LCD端口定义---------------- 
//#define GPIO_TYPE  GPIOB  //GPIO组类型
//#define LED      9        //背光控制引脚        PB9
//#define LCD_CS   11       //片选引脚            PB11
//#define LCD_RS   10       //寄存器/数据选择引脚 PB10 
//#define LCD_RST  12       //复位引脚            PB12


//QDtech全系列模块采用了三极管控制背光亮灭，用户也可以接PWM调节背光亮度
//#define	LCD_LED PBout(LED) //LCD背光    		 PB9
//如果使用官方库函数定义下列底层，速度将会下降到14帧每秒，建议采用我司推荐方法
//以下IO定义直接操作寄存器，快速IO操作，刷屏速率可以达到28帧每秒！ 

//GPIO置位（拉高）
//#define	LCD_CS_SET  GPIO_TYPE->BSRR=1<<LCD_CS    //片选端口  	PB11
//#define	LCD_RS_SET	GPIO_TYPE->BSRR=1<<LCD_RS    //数据/命令  PB10	  
//#define	LCD_RST_SET	GPIO_TYPE->BSRR=1<<LCD_RST   //复位			  PB12

//GPIO复位（拉低）							    
//#define	LCD_CS_CLR  GPIO_TYPE->BRR=1<<LCD_CS     //片选端口  	PB11
//#define	LCD_RS_CLR	GPIO_TYPE->BRR=1<<LCD_RS     //数据/命令  PB10	 
//#define	LCD_RST_CLR	GPIO_TYPE->BRR=1<<LCD_RST    //复位			  PB12

//画笔颜色
#define WHITE       0xFFFF
#define BLACK      	0x0000	  
#define BLUE       	0x001F  
#define BRED        0XF81F
#define GRED 			 	0XFFE0
#define GBLUE			 	0X07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define BROWN 			0XBC40 //棕色
#define BRRED 			0XFC07 //棕红色
#define GRAY  			0X8430 //灰色
#define GRAY0       0xEF7D 
#define GRAY1       0x8410      	//灰色1      00000 000000 00000
#define GRAY2       0x4208 
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	0X841F //浅绿色
#define LIGHTGRAY     0XEF5B //浅灰色(PANNEL)
#define LGRAY 			 		0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE      	0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE          0X2B12 //浅棕蓝色(选择条目的反色)
	    															  
void LCD_Init(void);
void LCD_DisplayOn(void);
void LCD_DisplayOff(void);
void LCD_Clear(uint16_t Color);	 
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
void LCD_DrawPoint(uint16_t x,uint16_t y);//画点
uint16_t  LCD_ReadPoint(uint16_t x,uint16_t y); //读点
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);		   
void LCD_SetWindows(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd);

uint16_t LCD_RD_DATA(void);//读取LCD数据									    
void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue);
void LCD_WR_DATA(uint8_t data);
uint16_t LCD_ReadReg(uint8_t LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(uint16_t RGB_Code);
uint16_t LCD_ReadRAM(void);		   
uint16_t LCD_BGR2RGB(uint16_t c);
void LCD_SetParam(void);
void Lcd_WriteData_16Bit(uint16_t Data);
void LCD_direction(uint8_t direction );
				  		 
#endif  
	 
	 



