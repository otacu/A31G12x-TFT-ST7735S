# A31G12x-TFT-ST7735S

ABOV现代MCU A31G12x连接TFT ST7735S的例程

软件模拟方式实现SPI，也就是不使用MCU对SPI的封装，无视MCU内部自带的对SPI的硬件支持，把SPI相关引脚当作普通引脚，或者用其它引脚，用直接设置引脚值的方式来实现SPI协议传输。