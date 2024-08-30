#include "global.h"
#include "A31G12x_PortInit.h"
#include "A31G12x_SystemClock.h"
#include "delay.h"
#include "SPI.h"
#include "lcd.h"
#include "test.h"

/*-------------------------------------------------------------------------*//**
 * 
 * 测试连接TFT屏，连线见lcd.c和SPI.c
 * - 参考 http://www.lcdwiki.com/zh/index.php?title=1.44inch_arduino_spi_module_st7735s_sku:mar1441&oldid=4417
 * 
 *//*-------------------------------------------------------------------------*/
int main(void)
{
	 uint32_t    idx, len;
   uint8_t     buffer[10];
	
	 /* Initialize all port */
   Port_Init();

   /* Configure the system clock to HSI 40MHz */
   SystemClock_Config();
	
	 delay_init();
	
	 LCD_Init();
	
	 //__enable_irq();  // 中断总开关
	
	 while(1)
   {
				menu_test();     //3D菜单显示测试
				main_test(); 		//测试主界面
				Test_Color();  		//简单刷屏填充测试
				Test_FillRec();		//GUI矩形绘图测试
				Test_Circle(); 		//GUI画圆测试
				Test_Triangle();    //GUI三角形绘图测试
				English_Font_test();//英文字体示例测试
				Chinese_Font_test();//中文字体示例测试
				Pic_test();			//图片显示示例测试
				Rotate_Test();   //旋转显示测试
	 }
   return 0;
}




