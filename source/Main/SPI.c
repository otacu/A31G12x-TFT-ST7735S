#include "global.h"

void SPI_MOSI_CLR()
{
	 HAL_GPIO_ClearPin( ( Pn_Type* )PB, _BIT( 0 ) );  //MOSI10  SPIд�����PB0
}

void SPI_MOSI_SET()
{
   HAL_GPIO_SetPin( ( Pn_Type* )PB, _BIT( 0 ) );    //MOSI10  SPIд�����PB0
}

void SPI_SCLK_CLR()
{
	 HAL_GPIO_ClearPin( ( Pn_Type* )PB, _BIT( 2 ) );  //SCK10   SPIʱ������PB2
}

void SPI_SCLK_SET()
{
   HAL_GPIO_SetPin( ( Pn_Type* )PB, _BIT( 2 ) );    //SCK10   SPIʱ������PB2
}

void SPIv_WriteData(uint8_t Data)
{
	unsigned char i=0;
	for(i=8;i>0;i--)
	{
	  if(Data&0x80)	
		  SPI_MOSI_SET(); //�������
    else
		  SPI_MOSI_CLR();
	   
    SPI_SCLK_CLR();       
    SPI_SCLK_SET();
    Data<<=1; 
	}
}

