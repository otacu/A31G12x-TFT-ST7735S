/**
 *******************************************************************************
 * @file        A31G12x_PortInit.c
 * @author      ABOV R&D Division
 * @brief       Port Initialization Source File
 *
 * Copyright 2020 ABOV Semiconductor Co.,Ltd. All rights reserved.
 *
 * This file is licensed under terms that are found in the LICENSE file
 * located at Document directory.
 * If this file is delivered or shared without applicable license terms,
 * the terms of the BSD-3-Clause license shall be applied.
 * Reference: https://opensource.org/licenses/BSD-3-Clause
 ******************************************************************************/

#include "global.h"

/* Private typedef ---------------------------------------------------------- */
/* Private define ----------------------------------------------------------- */
/* Private macro ------------------------------------------------------------ */
/* Private variables -------------------------------------------------------- */
/* Private define ----------------------------------------------------------- */


/* Private function prototypes ---------------------------------------------- */

void Port_Init( void );


/* Private variables -------------------------------------------------------- */


/*-------------------------------------------------------------------------*//**
 * @brief         This function initializes all ports.
 * @param         None
 * @return        None
 *//*-------------------------------------------------------------------------*/
void Port_Init( void )
{
   // enable peripheral clock
   HAL_SCU_Peripheral_ClockConfig( 0x3f, 0x0 );   // enable all ports,

   // Port A
   PA->MOD     =  0
                  | ( 1 << PA_PA_MOD_MODE11_Pos )        // PA11           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE10_Pos )        // PA10           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE9_Pos )         // PA9            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE8_Pos )         // PA8            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE7_Pos )         // PA7            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE6_Pos )         // PA6            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE5_Pos )         // PA5            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE4_Pos )         // PA4            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE3_Pos )         // PA3            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE2_Pos )         // PA2            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE1_Pos )         // PA1            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PA_PA_MOD_MODE0_Pos )         // PA0            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  ;

   PA->TYP     =  0
                  | ( 0 << PA_PA_TYP_TYP11_Pos )         // PA11           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP10_Pos )         // PA10           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP9_Pos )          // PA9            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP8_Pos )          // PA8            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP7_Pos )          // PA7            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP6_Pos )          // PA6            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP5_Pos )          // PA5            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP4_Pos )          // PA4            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP3_Pos )          // PA3            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP2_Pos )          // PA2            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP1_Pos )          // PA1            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PA_PA_TYP_TYP0_Pos )          // PA0            0: Push-Pull Output     1: Open-Drain Output
                  ;

   PA->AFSR2   =  0
                  | ( 0 << PA_PA_AFSR2_AFSR11_Pos )      // PA11           0: ----        1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PA_PA_AFSR2_AFSR10_Pos )      // PA10           0: ----        1: ----        2: ----        3: AN13        4: ----
                  | ( 0 << PA_PA_AFSR2_AFSR9_Pos )       // PA9            0: ----        1: ----        2: ----        3: AN12        4: ----
                  | ( 0 << PA_PA_AFSR2_AFSR8_Pos )       // PA8            0: ----        1: ----        2: ----        3: AN11        4: ----
                  ;

   PA->AFSR1   =  0
                  | ( 0 << PA_PA_AFSR1_AFSR7_Pos )       // PA7            0: SEG42       1: ----        2: ----        3: AN7         4: AVREF
                  | ( 0 << PA_PA_AFSR1_AFSR6_Pos )       // PA6            0: SEG43       1: ----        2: ----        3: AN6         4: ----
                  | ( 0 << PA_PA_AFSR1_AFSR5_Pos )       // PA5            0: ----        1: T12OUT      2: T12CAP      3: AN5         4: ----
                  | ( 0 << PA_PA_AFSR1_AFSR4_Pos )       // PA4            0: ----        1: ----        2: ----        3: AN4         4: ----
                  | ( 0 << PA_PA_AFSR1_AFSR3_Pos )       // PA3            0: ----        1: ----        2: ----        3: AN3         4: ----
                  | ( 0 << PA_PA_AFSR1_AFSR2_Pos )       // PA2            0: ----        1: EC12        2: ----        3: AN2         4: ----
                  | ( 0 << PA_PA_AFSR1_AFSR1_Pos )       // PA1            0: ----        1: SCL1        2: ----        3: AN1         4: ----
                  | ( 0 << PA_PA_AFSR1_AFSR0_Pos )       // PA0            0: ----        1: SDA1        2: ----        3: AN0         4: ----
                  ;

   PA->PUPD    =  0
                  | ( 0 << PA_PA_PUPD_PUPD11_Pos )       // PA11           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD10_Pos )       // PA10           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD9_Pos )        // PA9            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD8_Pos )        // PA8            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD7_Pos )        // PA7            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD6_Pos )        // PA6            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD5_Pos )        // PA5            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD4_Pos )        // PA4            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD3_Pos )        // PA3            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD2_Pos )        // PA2            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD1_Pos )        // PA1            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PA_PA_PUPD_PUPD0_Pos )        // PA0            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  ;

   PA->OUTDR   =  0
                  | ( 0 << PA_PA_OUTDR_OUTDR11_Pos )     // PA11           0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR10_Pos )     // PA10           0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR9_Pos )      // PA9            0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR8_Pos )      // PA8            0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR7_Pos )      // PA7            0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR6_Pos )      // PA6            0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR5_Pos )      // PA5            0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR4_Pos )      // PA4            0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR3_Pos )      // PA3            0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR2_Pos )      // PA2            0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR1_Pos )      // PA1            0: Output Low     1: Output High
                  | ( 0 << PA_PA_OUTDR_OUTDR0_Pos )      // PA0            0: Output Low     1: Output High
                  ;

   // Port B
   PB->MOD     =  0
                  | ( 1 << PB_PB_MOD_MODE15_Pos )        // PB15           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE14_Pos )        // PB14           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE13_Pos )        // PB13           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE12_Pos )        // PB12           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE11_Pos )        // PB11           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE10_Pos )        // PB10           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE9_Pos )         // PB9            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE8_Pos )         // PB8            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE7_Pos )         // PB7            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE6_Pos )         // PB6            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 2 << PB_PB_MOD_MODE5_Pos )         // PB5   SWDIO    0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 2 << PB_PB_MOD_MODE4_Pos )         // PB4   SWCLK    0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE3_Pos )         // PB3   BOOT     0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE2_Pos )         // PB2            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE1_Pos )         // PB1            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PB_PB_MOD_MODE0_Pos )         // PB0            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  ;

   PB->TYP     =  0
                  | ( 0 << PB_PB_TYP_TYP15_Pos )         // PB15           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP14_Pos )         // PB14           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP13_Pos )         // PB13           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP12_Pos )         // PB12           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP11_Pos )         // PB11           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP10_Pos )         // PB10           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP9_Pos )          // PB9            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP8_Pos )          // PB8            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP7_Pos )          // PB7            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP6_Pos )          // PB6            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP5_Pos )          // PB5   SWDIO    0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP4_Pos )          // PB4   SWCLK    0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP3_Pos )          // PB3   BOOT     0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP2_Pos )          // PB2            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP1_Pos )          // PB1            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PB_PB_TYP_TYP0_Pos )          // PB0            0: Push-Pull Output     1: Open-Drain Output
                  ;

   PB->AFSR2   =  0
                  | ( 0 << PB_PB_AFSR2_AFSR15_Pos )      // PB15           0: SEG26       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PB_PB_AFSR2_AFSR14_Pos )      // PB14           0: SEG27       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PB_PB_AFSR2_AFSR13_Pos )      // PB13           0: SEG28       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PB_PB_AFSR2_AFSR12_Pos )      // PB12           0: SEG29       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PB_PB_AFSR2_AFSR11_Pos )      // PB11           0: SEG30       1: T15OUT      2: T15CAP      3: ----        4: ----
                  | ( 0 << PB_PB_AFSR2_AFSR10_Pos )      // PB10           0: SEG31       1: T16OUT      2: T16CAP      3: ----        4: ----
                  | ( 0 << PB_PB_AFSR2_AFSR9_Pos )       // PB9            0: SEG32       1: EC15        2: ----        3: ----        4: ----
                  | ( 0 << PB_PB_AFSR2_AFSR8_Pos )       // PB8            0: SEG33       1: EC16        2: ----        3: ----        4: ----
                  ;

   PB->AFSR1   =  0
                  | ( 0 << PB_PB_AFSR1_AFSR7_Pos )       // PB7            0: SEG34       1: RXD1        2: ----        3: ----        4: ----
                  | ( 0 << PB_PB_AFSR1_AFSR6_Pos )       // PB6            0: SEG35       1: TXD1        2: ----        3: ----        4: ----
                  | ( 2 << PB_PB_AFSR1_AFSR5_Pos )       // PB5   SWDIO    0: SEG36       1: RXD0        2: SWDIO       3: ----        4: ----
                  | ( 2 << PB_PB_AFSR1_AFSR4_Pos )       // PB4   SWCLK    0: SEG37       1: TXD0        2: SWCLK       3: ----        4: ----
                  | ( 0 << PB_PB_AFSR1_AFSR3_Pos )       // PB3   BOOT     0: SEG38       1: BOOT        2: SS10        3: ----        4: ----
                  | ( 0 << PB_PB_AFSR1_AFSR2_Pos )       // PB2            0: SEG39       1: ----        2: SCK10       3: AN10        4: ----
                  | ( 0 << PB_PB_AFSR1_AFSR1_Pos )       // PB1            0: SEG40       1: RXD10       2: MISO10      3: AN9         4: ----
                  | ( 0 << PB_PB_AFSR1_AFSR0_Pos )       // PB0            0: SEG41       1: TXD10       2: MOSI10      3: AN8         4: ----
                  ;

   PB->PUPD    =  0
                  | ( 0 << PB_PB_PUPD_PUPD15_Pos )       // PB15           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD14_Pos )       // PB14           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD13_Pos )       // PB13           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD12_Pos )       // PB12           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD11_Pos )       // PB11           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD10_Pos )       // PB10           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD9_Pos )        // PB9            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD8_Pos )        // PB8            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD7_Pos )        // PB7            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD6_Pos )        // PB6            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 1 << PB_PB_PUPD_PUPD5_Pos )        // PB5   SWDIO    0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 1 << PB_PB_PUPD_PUPD4_Pos )        // PB4   SWCLK    0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD3_Pos )        // PB3   BOOT     0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD2_Pos )        // PB2            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD1_Pos )        // PB1            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PB_PB_PUPD_PUPD0_Pos )        // PB0            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  ;

   PB->OUTDR   =  0
                  | ( 0 << PB_PB_OUTDR_OUTDR15_Pos )     // PB15           0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR14_Pos )     // PB14           0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR13_Pos )     // PB13           0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR12_Pos )     // PB12           0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR11_Pos )     // PB11           0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR10_Pos )     // PB10           0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR9_Pos )      // PB9            0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR8_Pos )      // PB8            0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR7_Pos )      // PB7            0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR6_Pos )      // PB6            0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR5_Pos )      // PB5   SWDIO    0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR4_Pos )      // PB4   SWCLK    0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR3_Pos )      // PB3   BOOT     0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR2_Pos )      // PB2            0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR1_Pos )      // PB1            0: Output Low     1: Output High
                  | ( 0 << PB_PB_OUTDR_OUTDR0_Pos )      // PB0            0: Output Low     1: Output High
                  ;

   // Port C
   PC->MOD     =  0
                  | ( 1 << PC_PC_MOD_MODE12_Pos )        // PC12           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE11_Pos )        // PC11           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE10_Pos )        // PC10           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE9_Pos )         // PC9            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE8_Pos )         // PC8            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE7_Pos )         // PC7            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE6_Pos )         // PC6            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE5_Pos )         // PC5            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE4_Pos )         // PC4            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE3_Pos )         // PC3            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE2_Pos )         // PC2            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE1_Pos )         // PC1            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PC_PC_MOD_MODE0_Pos )         // PC0            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  ;

   PC->TYP     =  0
                  | ( 0 << PC_PC_TYP_TYP12_Pos )         // PC12           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP11_Pos )         // PC11           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP10_Pos )         // PC10           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP9_Pos )          // PC9            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP8_Pos )          // PC8            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP7_Pos )          // PC7            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP6_Pos )          // PC6            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP5_Pos )          // PC5            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP4_Pos )          // PC4            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP3_Pos )          // PC3            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP2_Pos )          // PC2            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP1_Pos )          // PC1            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PC_PC_TYP_TYP0_Pos )          // PC0            0: Push-Pull Output     1: Open-Drain Output
                  ;

   PC->AFSR2   =  0
                  | ( 0 << PC_PC_AFSR2_AFSR12_Pos )      // PC12           0: SEG13       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PC_PC_AFSR2_AFSR11_Pos )      // PC11           0: SEG14       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PC_PC_AFSR2_AFSR10_Pos )      // PC10           0: SEG15       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PC_PC_AFSR2_AFSR9_Pos )       // PC9            0: SEG16       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PC_PC_AFSR2_AFSR8_Pos )       // PC8            0: SEG17       1: ----        2: ----        3: ----        4: ----
                  ;

   PC->AFSR1   =  0
                  | ( 0 << PC_PC_AFSR1_AFSR7_Pos )       // PC7            0: SEG18       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PC_PC_AFSR1_AFSR6_Pos )       // PC6            0: SEG19       1: SCL2        2: ----        3: ----        4: ----
                  | ( 0 << PC_PC_AFSR1_AFSR5_Pos )       // PC5            0: SEG20       1: SDA2        2: ----        3: ----        4: ----
                  | ( 0 << PC_PC_AFSR1_AFSR4_Pos )       // PC4            0: SEG21       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PC_PC_AFSR1_AFSR3_Pos )       // PC3            0: SEG22       1: EC21        2: ----        3: ----        4: ----
                  | ( 0 << PC_PC_AFSR1_AFSR2_Pos )       // PC2            0: SEG23       1: EC20        2: ----        3: ----        4: ----
                  | ( 0 << PC_PC_AFSR1_AFSR1_Pos )       // PC1            0: SEG24       1: T21OUT      2: T21CAP      3: ----        4: ----
                  | ( 0 << PC_PC_AFSR1_AFSR0_Pos )       // PC0            0: SEG25       1: T20OUT      2: T20CAP      3: ----        4: ----
                  ;

   PC->PUPD    =  0
                  | ( 0 << PC_PC_PUPD_PUPD12_Pos )       // PC12           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD11_Pos )       // PC11           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD10_Pos )       // PC10           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD9_Pos )        // PC9            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD8_Pos )        // PC8            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD7_Pos )        // PC7            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD6_Pos )        // PC6            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD5_Pos )        // PC5            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD4_Pos )        // PC4            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD3_Pos )        // PC3            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD2_Pos )        // PC2            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD1_Pos )        // PC1            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PC_PC_PUPD_PUPD0_Pos )        // PC0            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  ;

   PC->OUTDR   =  0
                  | ( 0 << PC_PC_OUTDR_OUTDR12_Pos )     // PC12           0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR11_Pos )     // PC11           0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR10_Pos )     // PC10           0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR9_Pos )      // PC9            0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR8_Pos )      // PC8            0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR7_Pos )      // PC7            0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR6_Pos )      // PC6            0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR5_Pos )      // PC5            0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR4_Pos )      // PC4            0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR3_Pos )      // PC3            0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR2_Pos )      // PC2            0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR1_Pos )      // PC1            0: Output Low     1: Output High
                  | ( 0 << PC_PC_OUTDR_OUTDR0_Pos )      // PC0            0: Output Low     1: Output High
                  ;

   // Port D
   PD->MOD     =  0
                  | ( 1 << PD_PD_MOD_MODE7_Pos )         // PD7            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PD_PD_MOD_MODE6_Pos )         // PD6            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PD_PD_MOD_MODE5_Pos )         // PD5            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PD_PD_MOD_MODE4_Pos )         // PD4            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PD_PD_MOD_MODE3_Pos )         // PD3            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PD_PD_MOD_MODE2_Pos )         // PD2            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PD_PD_MOD_MODE1_Pos )         // PD1            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PD_PD_MOD_MODE0_Pos )         // PD0            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  ;

   PD->TYP     =  0
                  | ( 0 << PD_PD_TYP_TYP7_Pos )          // PD7            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PD_PD_TYP_TYP6_Pos )          // PD6            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PD_PD_TYP_TYP5_Pos )          // PD5            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PD_PD_TYP_TYP4_Pos )          // PD4            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PD_PD_TYP_TYP3_Pos )          // PD3            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PD_PD_TYP_TYP2_Pos )          // PD2            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PD_PD_TYP_TYP1_Pos )          // PD1            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PD_PD_TYP_TYP0_Pos )          // PD0            0: Push-Pull Output     1: Open-Drain Output
                  ;

   // PD->AFSR2   =  0
   //                ;

   PD->AFSR1   =  0
                  | ( 0 << PD_PD_AFSR1_AFSR7_Pos )       // PD7            0: SEG5        1: EC10        2: ----        3: ----        4: ----
                  | ( 0 << PD_PD_AFSR1_AFSR6_Pos )       // PD6            0: SEG6        1: EC11        2: ----        3: ----        4: ----
                  | ( 0 << PD_PD_AFSR1_AFSR5_Pos )       // PD5            0: SEG7        1: ----        2: SS11        3: ----        4: ----
                  | ( 0 << PD_PD_AFSR1_AFSR4_Pos )       // PD4            0: SEG8        1: ----        2: SCK11       3: ----        4: ----
                  | ( 0 << PD_PD_AFSR1_AFSR3_Pos )       // PD3            0: SEG9        1: RXD11       2: MISO11      3: ----        4: ----
                  | ( 0 << PD_PD_AFSR1_AFSR2_Pos )       // PD2            0: SEG10       1: TXD11       2: MOSI11      3: ----        4: ----
                  | ( 0 << PD_PD_AFSR1_AFSR1_Pos )       // PD1            0: SEG11       1: SDA0        2: ----        3: ----        4: ----
                  | ( 0 << PD_PD_AFSR1_AFSR0_Pos )       // PD0            0: SEG12       1: SCL0        2: ----        3: ----        4: ----
                  ;

   PD->PUPD    =  0
                  | ( 0 << PD_PD_PUPD_PUPD7_Pos )        // PD7            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PD_PD_PUPD_PUPD6_Pos )        // PD6            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PD_PD_PUPD_PUPD5_Pos )        // PD5            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PD_PD_PUPD_PUPD4_Pos )        // PD4            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PD_PD_PUPD_PUPD3_Pos )        // PD3            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PD_PD_PUPD_PUPD2_Pos )        // PD2            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PD_PD_PUPD_PUPD1_Pos )        // PD1            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PD_PD_PUPD_PUPD0_Pos )        // PD0            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  ;

   PD->OUTDR   =  0
                  | ( 0 << PD_PD_OUTDR_OUTDR7_Pos )      // PD7            0: Output Low     1: Output High
                  | ( 0 << PD_PD_OUTDR_OUTDR6_Pos )      // PD6            0: Output Low     1: Output High
                  | ( 0 << PD_PD_OUTDR_OUTDR5_Pos )      // PD5            0: Output Low     1: Output High
                  | ( 0 << PD_PD_OUTDR_OUTDR4_Pos )      // PD4            0: Output Low     1: Output High
                  | ( 0 << PD_PD_OUTDR_OUTDR3_Pos )      // PD3            0: Output Low     1: Output High
                  | ( 0 << PD_PD_OUTDR_OUTDR2_Pos )      // PD2            0: Output Low     1: Output High
                  | ( 0 << PD_PD_OUTDR_OUTDR1_Pos )      // PD1            0: Output Low     1: Output High
                  | ( 0 << PD_PD_OUTDR_OUTDR0_Pos )      // PD0            0: Output Low     1: Output High
                  ;

   // Port E
   PE->MOD     =  0
                  | ( 1 << PE_PE_MOD_MODE15_Pos )        // PE15           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE14_Pos )        // PE14           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE13_Pos )        // PE13           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE12_Pos )        // PE12           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE11_Pos )        // PE11           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE10_Pos )        // PE10           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE9_Pos )         // PE9            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE8_Pos )         // PE8            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE7_Pos )         // PE7            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE6_Pos )         // PE6            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE5_Pos )         // PE5            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE4_Pos )         // PE4            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE3_Pos )         // PE3            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE2_Pos )         // PE2            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE1_Pos )         // PE1            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PE_PE_MOD_MODE0_Pos )         // PE0            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  ;

   PE->TYP     =  0
                  | ( 0 << PE_PE_TYP_TYP15_Pos )         // PE15           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP14_Pos )         // PE14           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP13_Pos )         // PE13           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP12_Pos )         // PE12           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP11_Pos )         // PE11           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP10_Pos )         // PE10           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP9_Pos )          // PE9            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP8_Pos )          // PE8            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP7_Pos )          // PE7            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP6_Pos )          // PE6            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP5_Pos )          // PE5            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP4_Pos )          // PE4            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP3_Pos )          // PE3            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP2_Pos )          // PE2            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP1_Pos )          // PE1            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PE_PE_TYP_TYP0_Pos )          // PE0            0: Push-Pull Output     1: Open-Drain Output
                  ;

   PE->AFSR2   =  0
                  | ( 0 << PE_PE_AFSR2_AFSR15_Pos )      // PE15           0: ----        1: ----        2: SS12        3: ----        4: ----
                  | ( 0 << PE_PE_AFSR2_AFSR14_Pos )      // PE14           0: ----        1: ----        2: SCK12       3: ----        4: ----
                  | ( 0 << PE_PE_AFSR2_AFSR13_Pos )      // PE13           0: ----        1: RXD12       2: MISO12      3: ----        4: ----
                  | ( 0 << PE_PE_AFSR2_AFSR12_Pos )      // PE12           0: ----        1: TXD12       2: MOSI12      3: ----        4: ----
                  | ( 0 << PE_PE_AFSR2_AFSR11_Pos )      // PE11           0: ----        1: ----        2: SS13        3: ----        4: ----
                  | ( 0 << PE_PE_AFSR2_AFSR10_Pos )      // PE10           0: ----        1: ----        2: SCK13       3: ----        4: ----
                  | ( 0 << PE_PE_AFSR2_AFSR9_Pos )       // PE9            0: ----        1: RXD13       2: MISO13      3: ----        4: ----
                  | ( 0 << PE_PE_AFSR2_AFSR8_Pos )       // PE8            0: ----        1: TXD13       2: MOSI13      3: ----        4: ----
                  ;

   PE->AFSR1   =  0
                  | ( 0 << PE_PE_AFSR1_AFSR7_Pos )       // PE7            0: COM7/SEG4   1: T11OUT      2: T11CAP      3: ----        4: ----
                  | ( 0 << PE_PE_AFSR1_AFSR6_Pos )       // PE6            0: COM6/SEG3   1: T10OUT      2: T10CAP      3: ----        4: ----
                  | ( 0 << PE_PE_AFSR1_AFSR5_Pos )       // PE5            0: COM5/SEG2   1: PWM30CB     2: ----        3: ----        4: ----
                  | ( 0 << PE_PE_AFSR1_AFSR4_Pos )       // PE4            0: COM4/SEG1   1: PWM30CA     2: ----        3: ----        4: ----
                  | ( 0 << PE_PE_AFSR1_AFSR3_Pos )       // PE3            0: COM3/SEG0   1: PWM30BB     2: ----        3: ----        4: ----
                  | ( 0 << PE_PE_AFSR1_AFSR2_Pos )       // PE2            0: COM2        1: PWM30BA     2: ----        3: ----        4: ----
                  | ( 0 << PE_PE_AFSR1_AFSR1_Pos )       // PE1            0: COM1        1: PWM30AB     2: ----        3: ----        4: ----
                  | ( 0 << PE_PE_AFSR1_AFSR0_Pos )       // PE0            0: COM0        1: PWM30AA     2: ----        3: ----        4: ----
                  ;

   PE->PUPD    =  0
                  | ( 0 << PE_PE_PUPD_PUPD15_Pos )       // PE15           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD14_Pos )       // PE14           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD13_Pos )       // PE13           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD12_Pos )       // PE12           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD11_Pos )       // PE11           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD10_Pos )       // PE10           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD9_Pos )        // PE9            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD8_Pos )        // PE8            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD7_Pos )        // PE7            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD6_Pos )        // PE6            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD5_Pos )        // PE5            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD4_Pos )        // PE4            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD3_Pos )        // PE3            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD2_Pos )        // PE2            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD1_Pos )        // PE1            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PE_PE_PUPD_PUPD0_Pos )        // PE0            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  ;

   PE->OUTDR   =  0
                  | ( 0 << PE_PE_OUTDR_OUTDR15_Pos )     // PE15           0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR14_Pos )     // PE14           0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR13_Pos )     // PE13           0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR12_Pos )     // PE12           0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR11_Pos )     // PE11           0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR10_Pos )     // PE10           0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR9_Pos )      // PE9            0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR8_Pos )      // PE8            0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR7_Pos )      // PE7            0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR6_Pos )      // PE6            0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR5_Pos )      // PE5            0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR4_Pos )      // PE4            0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR3_Pos )      // PE3            0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR2_Pos )      // PE2            0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR1_Pos )      // PE1            0: Output Low     1: Output High
                  | ( 0 << PE_PE_OUTDR_OUTDR0_Pos )      // PE0            0: Output Low     1: Output High
                  ;

   // Port F
   PF->MOD     =  0
                  | ( 1 << PF_PF_MOD_MODE11_Pos )        // PF11           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PF_PF_MOD_MODE10_Pos )        // PF10           0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PF_PF_MOD_MODE9_Pos )         // PF9            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PF_PF_MOD_MODE8_Pos )         // PF8            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PF_PF_MOD_MODE7_Pos )         // PF7            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PF_PF_MOD_MODE6_Pos )         // PF6            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PF_PF_MOD_MODE5_Pos )         // PF5            0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PF_PF_MOD_MODE4_Pos )         // PF4   CLKO     0: Input Mode     1: Output Mode    2: Alternative Function Mode
#ifdef USED_XSOSC
                  | ( 2 << PF_PF_MOD_MODE3_Pos )         // PF3   SXOUT    0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 2 << PF_PF_MOD_MODE2_Pos )         // PF2   SXIN     0: Input Mode     1: Output Mode    2: Alternative Function Mode
#else
                  | ( 1 << PF_PF_MOD_MODE3_Pos )         // PF3   SXOUT    0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PF_PF_MOD_MODE2_Pos )         // PF2   SXIN     0: Input Mode     1: Output Mode    2: Alternative Function Mode
#endif
#ifdef USED_XMOSC
                  | ( 2 << PF_PF_MOD_MODE1_Pos )         // PF1   XIN      0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 2 << PF_PF_MOD_MODE0_Pos )         // PF0   XOUT     0: Input Mode     1: Output Mode    2: Alternative Function Mode
#else
                  | ( 1 << PF_PF_MOD_MODE1_Pos )         // PF1   XIN      0: Input Mode     1: Output Mode    2: Alternative Function Mode
                  | ( 1 << PF_PF_MOD_MODE0_Pos )         // PF0   XOUT     0: Input Mode     1: Output Mode    2: Alternative Function Mode
#endif
                  ;

   PF->TYP     =  0
                  | ( 0 << PF_PF_TYP_TYP11_Pos )         // PF11           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP10_Pos )         // PF10           0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP9_Pos )          // PF9            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP8_Pos )          // PF8            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP7_Pos )          // PF7            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP6_Pos )          // PF6            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP5_Pos )          // PF5            0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP4_Pos )          // PF4   CLKO     0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP3_Pos )          // PF3   SXOUT    0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP2_Pos )          // PF2   SXIN     0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP1_Pos )          // PF1   XIN      0: Push-Pull Output     1: Open-Drain Output
                  | ( 0 << PF_PF_TYP_TYP0_Pos )          // PF0   XOUT     0: Push-Pull Output     1: Open-Drain Output
                  ;

   PF->AFSR2   =  0
                  | ( 0 << PF_PF_AFSR2_AFSR11_Pos )      // PF11           0: T14OUT      1: T14CAP      2: ----        3: ----        4: ----
                  | ( 0 << PF_PF_AFSR2_AFSR10_Pos )      // PF10           0: T13OUT      1: T13CAP      2: ----        3: ----        4: ----
                  | ( 0 << PF_PF_AFSR2_AFSR9_Pos )       // PF9            0: EC14        1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PF_PF_AFSR2_AFSR8_Pos )       // PF8            0: EC13        1: ----        2: ----        3: ----        4: ----
                  ;

   PF->AFSR1   =  0
                  | ( 0 << PF_PF_AFSR1_AFSR7_Pos )       // PF7            0: ----        1: ----        2: T30CAP      3: ----        4: ----
                  | ( 0 << PF_PF_AFSR1_AFSR6_Pos )       // PF6            0: ----        1: EC30        2: ----        3: ----        4: ----
                  | ( 0 << PF_PF_AFSR1_AFSR5_Pos )       // PF5            0: ----        1: BLNK        2: ----        3: ----        4: ----
                  | ( 0 << PF_PF_AFSR1_AFSR4_Pos )       // PF4   CLKO     0: CLKO        1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PF_PF_AFSR1_AFSR3_Pos )       // PF3   SXOUT    0: SXOUT       1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PF_PF_AFSR1_AFSR2_Pos )       // PF2   SXIN     0: SXIN        1: ----        2: ----        3: ----        4: ----
                  | ( 0 << PF_PF_AFSR1_AFSR1_Pos )       // PF1   XIN      0: XIN         1: (SDA1)      2: ----        3: ----        4: ----
                  | ( 0 << PF_PF_AFSR1_AFSR0_Pos )       // PF0   XOUT     0: XOUT        1: (SCL1)      2: ----        3: ----        4: ----
                  ;

   PF->PUPD    =  0
                  | ( 0 << PF_PF_PUPD_PUPD11_Pos )       // PF11           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD10_Pos )       // PF10           0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD9_Pos )        // PF9            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD8_Pos )        // PF8            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD7_Pos )        // PF7            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD6_Pos )        // PF6            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD5_Pos )        // PF5            0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD4_Pos )        // PF4   CLKO     0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD3_Pos )        // PF3   SXOUT    0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD2_Pos )        // PF2   SXIN     0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD1_Pos )        // PF1   XIN      0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  | ( 0 << PF_PF_PUPD_PUPD0_Pos )        // PF0   XOUT     0: Disable Pull-Up/Down    1: Enable Pull-Up    2: Enable Pull-Down
                  ;

   PF->OUTDR   =  0
                  | ( 0 << PF_PF_OUTDR_OUTDR11_Pos )     // PF11           0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR10_Pos )     // PF10           0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR9_Pos )      // PF9            0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR8_Pos )      // PF8            0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR7_Pos )      // PF7            0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR6_Pos )      // PF6            0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR5_Pos )      // PF5            0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR4_Pos )      // PF4   CLKO     0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR3_Pos )      // PF3   SXOUT    0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR2_Pos )      // PF2   SXIN     0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR1_Pos )      // PF1   XIN      0: Output Low     1: Output High
                  | ( 0 << PF_PF_OUTDR_OUTDR0_Pos )      // PF0   XOUT     0: Output Low     1: Output High
                  ;
}

