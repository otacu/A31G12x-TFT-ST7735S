#include "global.h"
#include "A31G12x_PortInit.h"
#include "A31G12x_SystemClock.h"
#include "delay.h"
#include "SPI.h"
#include "lcd.h"
#include "test.h"

/*-------------------------------------------------------------------------*//**
 * 
 * ��������TFT�������߼�lcd.c��SPI.c
 * - �ο� http://www.lcdwiki.com/zh/index.php?title=1.44inch_arduino_spi_module_st7735s_sku:mar1441&oldid=4417
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
	
	 //__enable_irq();  // �ж��ܿ���
	
	 while(1)
   {
				menu_test();     //3D�˵���ʾ����
				main_test(); 		//����������
				Test_Color();  		//��ˢ��������
				Test_FillRec();		//GUI���λ�ͼ����
				Test_Circle(); 		//GUI��Բ����
				Test_Triangle();    //GUI�����λ�ͼ����
				English_Font_test();//Ӣ������ʾ������
				Chinese_Font_test();//��������ʾ������
				Pic_test();			//ͼƬ��ʾʾ������
				Rotate_Test();   //��ת��ʾ����
	 }
   return 0;
}




