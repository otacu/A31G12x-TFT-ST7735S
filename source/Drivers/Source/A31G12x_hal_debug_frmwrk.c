/**
 *******************************************************************************
 * @file        A31G12x_hal_debug_frmwrk.c
 * @author      ABOV R&D Division
 * @brief       Debug Framework
 *
 * Copyright 2020 ABOV Semiconductor Co.,Ltd. All rights reserved.
 *
 * This file is licensed under terms that are found in the LICENSE file
 * located at Document directory.
 * If this file is delivered or shared without applicable license terms,
 * the terms of the BSD-3-Clause license shall be applied.
 * Reference: https://opensource.org/licenses/BSD-3-Clause
 ******************************************************************************/

/* Includes ----------------------------------------------------------------- */
//******************************************************************************
// Include
//******************************************************************************

#include <stdarg.h>
#include <stdio.h>
#include "A31G12x_hal_debug_frmwrk.h"
#include "A31G12x_hal_pcu.h"

//******************************************************************************
// Constant
//******************************************************************************

#define ASCII_BACKSPACE          (0x08)
#define ASCII_LINEFEED           (0x0A)
#define ASCII_CARRIAGE_RETURN    (0x0D)

#ifdef _DEBUG_MSG

//******************************************************************************
// Variable
//******************************************************************************

void ( *_db_msg )( UARTn_Type* UARTx, const void* s );
void ( *_db_msg_ )( UARTn_Type* UARTx, const void* s );
void ( *_db_char )( UARTn_Type* UARTx, uint8_t ch );
void ( *_db_dec )( UARTn_Type* UARTx, uint8_t decn );
void ( *_db_dec_16 )( UARTn_Type* UARTx, uint16_t decn );
void ( *_db_dec_32 )( UARTn_Type* UARTx, uint32_t decn );
void ( *_db_hex )( UARTn_Type* UARTx, uint8_t hexn );
void ( *_db_hex_16 )( UARTn_Type* UARTx, uint16_t hexn );
void ( *_db_hex_32 )( UARTn_Type* UARTx, uint32_t hexn );
uint8_t ( *_db_get_char )( UARTn_Type* UARTx );
uint8_t ( *_db_get_ch )( UARTn_Type* UARTx, uint8_t* ch );

/* Public Functions --------------------------------------------------------- */
//******************************************************************************
// Function
//******************************************************************************

#if 0
/*-------------------------------------------------------------------------*//**
 * @brief         Puts a character to file
 * @param[in]     ch
 *                   Character to put
 * @param[in]     f
 *                   Pointer to file
 * @return        character
 * @note          if you use IAR EWARM, select Full as Options/General Options/Library Configuration/Library.
 *//*-------------------------------------------------------------------------*/
int fputc( int ch, FILE* f )
{
   while( HAL_UART_CheckBusy( ( UARTn_Type* )DEBUG_UART_PORT ) );
   HAL_UART_TransmitByte( ( UARTn_Type* )DEBUG_UART_PORT, ch );

   return( ch );
}
#endif

/*-------------------------------------------------------------------------*//**
 * @brief         Puts a character to UART port
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @param[in]     ch
 *                   Character to put
 * @return        None
 *//*-------------------------------------------------------------------------*/
void UARTPutChar( UARTn_Type* UARTx, uint8_t ch )
{
   HAL_UART_Transmit( UARTx, &ch, 1, BLOCKING );
}

/*-------------------------------------------------------------------------*//**
 * @brief         Get a character to UART port
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @return        character value that returned
 *//*-------------------------------------------------------------------------*/
uint8_t UARTGetChar( UARTn_Type* UARTx )
{
   uint8_t     tmp = 0;

   HAL_UART_Receive( UARTx, &tmp, 1, BLOCKING );

   return( tmp );
}

/*-------------------------------------------------------------------------*//**
 * @brief         Get a character to UART port
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @param[in]     ch
 *                   Character to get
 * @return        if getting value, return '1'. if not, return '0'
 *//*-------------------------------------------------------------------------*/
uint8_t UARTGetCh( UARTn_Type* UARTx, uint8_t* ch )
{
   if( !( UARTx->LSR & UARTn_LSR_RDR ) )
   {
      *ch = 0;
      return( 0 );
   }
   else
   {
      *ch = HAL_UART_ReceiveByte( UARTx );
      return( 1 );
   }
}

/*-------------------------------------------------------------------------*//**
 * @brief         Puts a string to UART port
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @param[in]     str
 *                   String to put
 * @return        None
 *//*-------------------------------------------------------------------------*/
void UARTPuts( UARTn_Type* UARTx, const void* str )
{
   uint8_t*    s = ( uint8_t* )str;

   while( *s )
   {
      UARTPutChar( UARTx, *s++ );
   }
}

/*-------------------------------------------------------------------------*//**
 * @brief         Puts a string to UART port and print new line
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @param[in]     str
 *                   String to put
 * @return        None
 *//*-------------------------------------------------------------------------*/
void UARTPuts_( UARTn_Type* UARTx, const void* str )
{
   UARTPuts( UARTx, str );
   UARTPuts( UARTx, "\n\r" );
}

/*-------------------------------------------------------------------------*//**
 * @brief         Puts a decimal number to UART port
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @param[in]     decnum
 *                   Decimal number (8-bit long)
 * @return        None
 *//*-------------------------------------------------------------------------*/
void UARTPutDec( UARTn_Type* UARTx, uint8_t decnum )
{
   uint8_t     c1 = decnum % 10;
   uint8_t     c2 = ( decnum / 10 ) % 10;
   uint8_t     c3 = ( decnum / 100 ) % 10;

   UARTPutChar( UARTx, '0' + c3 );
   UARTPutChar( UARTx, '0' + c2 );
   UARTPutChar( UARTx, '0' + c1 );
}

/*-------------------------------------------------------------------------*//**
 * @brief         Puts a decimal number to UART port
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @param[in]     decnum
 *                   Decimal number (8-bit long)
 * @return        None
 *//*-------------------------------------------------------------------------*/
void UARTPutDec16( UARTn_Type* UARTx, uint16_t decnum )
{
   uint8_t     c1 = decnum % 10;
   uint8_t     c2 = ( decnum / 10 ) % 10;
   uint8_t     c3 = ( decnum / 100 ) % 10;
   uint8_t     c4 = ( decnum / 1000 ) % 10;
   uint8_t     c5 = ( decnum / 10000 ) % 10;

   UARTPutChar( UARTx, '0' + c5 );
   UARTPutChar( UARTx, '0' + c4 );
   UARTPutChar( UARTx, '0' + c3 );
   UARTPutChar( UARTx, '0' + c2 );
   UARTPutChar( UARTx, '0' + c1 );
}

/*-------------------------------------------------------------------------*//**
 * @brief         Puts a decimal number to UART port
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @param[in]     decnum
 *                   Decimal number (8-bit long)
 * @return        None
 *//*-------------------------------------------------------------------------*/
void UARTPutDec32( UARTn_Type* UARTx, uint32_t decnum )
{
   uint8_t     c1 = decnum % 10;
   uint8_t     c2 = ( decnum / 10 ) % 10;
   uint8_t     c3 = ( decnum / 100 ) % 10;
   uint8_t     c4 = ( decnum / 1000 ) % 10;
   uint8_t     c5 = ( decnum / 10000 ) % 10;
   uint8_t     c6 = ( decnum / 100000 ) % 10;
   uint8_t     c7 = ( decnum / 1000000 ) % 10;
   uint8_t     c8 = ( decnum / 10000000 ) % 10;
   uint8_t     c9 = ( decnum / 100000000 ) % 10;
   uint8_t     c10 = ( decnum / 1000000000 ) % 10;

   UARTPutChar( UARTx, '0' + c10 );
   UARTPutChar( UARTx, '0' + c9 );
   UARTPutChar( UARTx, '0' + c8 );
   UARTPutChar( UARTx, '0' + c7 );
   UARTPutChar( UARTx, '0' + c6 );
   UARTPutChar( UARTx, '0' + c5 );
   UARTPutChar( UARTx, '0' + c4 );
   UARTPutChar( UARTx, '0' + c3 );
   UARTPutChar( UARTx, '0' + c2 );
   UARTPutChar( UARTx, '0' + c1 );
}

/*-------------------------------------------------------------------------*//**
 * @brief         Puts a hex number to UART port
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @param[in]     hexnum
 *                   Hex number (8-bit long)
 * @return        None
 *//*-------------------------------------------------------------------------*/
void UARTPutHex( UARTn_Type* UARTx, uint8_t hexnum )
{
   uint8_t     nibble, i;

   i = 1;
   do
   {
      nibble = ( hexnum >> ( 4 * i ) ) & 0x0F;
      UARTPutChar( UARTx, ( nibble > 9 ) ? ( 'A' + nibble - 10 ) : ( '0' + nibble ) );
   } while( i-- );
}

/*-------------------------------------------------------------------------*//**
 * @brief         Puts a hex number to UART port
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @param[in]     hexnum
 *                   Hex number (16-bit long)
 * @return        None
 *//*-------------------------------------------------------------------------*/
void UARTPutHex16( UARTn_Type* UARTx, uint16_t hexnum )
{
   uint8_t     nibble, i;

   i = 3;
   do
   {
      nibble = ( hexnum >> ( 4 * i ) ) & 0x0F;
      UARTPutChar( UARTx, ( nibble > 9 ) ? ( 'A' + nibble - 10 ) : ( '0' + nibble ) );
   } while( i-- );
}

/*-------------------------------------------------------------------------*//**
 * @brief         Puts a hex number to UART port
 * @param[in]     UARTx
 *                   Pointer to the target UART
 *                   -  UART0 ~ UART1
 * @param[in]     hexnum
 *                   Hex number (32-bit long)
 * @return        None
 *//*-------------------------------------------------------------------------*/
void UARTPutHex32( UARTn_Type* UARTx, uint32_t hexnum )
{
   uint8_t     nibble, i;

   i = 7;
   do
   {
      nibble = ( hexnum >> ( 4 * i ) ) & 0x0F;
      UARTPutChar( UARTx, ( nibble > 9 ) ? ( 'A' + nibble - 10 ) : ( '0' + nibble ) );
   } while( i-- );
}

/*-------------------------------------------------------------------------*//**
 * @brief         print function that supports format as same as printf() function of <stdio.h> library
 * @param[in]     format
 *                   formatted string to be print
 * @return        None
 *//*-------------------------------------------------------------------------*/
void cprintf( const char* format, ... )
{
   char        buffer[512 + 1];
   va_list     vArgs;

   va_start( vArgs, format );
   vsprintf( ( char* )buffer, ( char const* )format, vArgs );
   va_end( vArgs );

   _DBG( buffer );
}

/*-------------------------------------------------------------------------*//**
 * @brief         Initializes Debug Framework through initializing UARTn
 * @param         None
 * @return        None
 *//*-------------------------------------------------------------------------*/
void debug_frmwrk_init( void )
{
   UARTn_CFG_Type    UARTn_Config;

#if (USED_UART_DEBUG_PORT == 0)

   // Initialize UART0 pin connect
   HAL_GPIO_ConfigOutput( ( Pn_Type* )PB, 5, ALTERN_FUNC );    // PB5   SWDIO    0: SEG36       1: RXD0        2: SWDIO       3: ----        4: ----
   HAL_GPIO_ConfigFunction( ( Pn_Type* )PB, 5, AFSRx_AF1 );

   HAL_GPIO_ConfigOutput( ( Pn_Type* )PB, 4, ALTERN_FUNC );    // PB4   SWCLK    0: SEG37       1: TXD0        2: SWCLK       3: ----        4: ----
   HAL_GPIO_ConfigFunction( ( Pn_Type* )PB, 4, AFSRx_AF1 );

#elif (USED_UART_DEBUG_PORT == 1)

   // Initialize UART1 pin connect
   HAL_GPIO_ConfigOutput( ( Pn_Type* )PB, 7, ALTERN_FUNC );    // PB7            0: SEG34       1: RXD1        2: ----        3: ----        4: ----
   HAL_GPIO_ConfigFunction( ( Pn_Type* )PB, 7, AFSRx_AF1 );

   HAL_GPIO_ConfigOutput( ( Pn_Type* )PB, 6, ALTERN_FUNC );    // PB6            0: SEG35       1: TXD1        2: ----        3: ----        4: ----
   HAL_GPIO_ConfigFunction( ( Pn_Type* )PB, 6, AFSRx_AF1 );

#endif

   /* Initialize UART Configuration parameter structure to default state:
    * Baudrate = 38400bps
    * 8 data bit
    * no parity
    * 1 stop bit
    */
   HAL_UART_ConfigStructInit( &UARTn_Config );
   UARTn_Config.Baudrate = 38400;

   // Initialize DEBUG_UART_PORT peripheral with given to corresponding parameter
   HAL_UART_Init( ( UARTn_Type* )DEBUG_UART_PORT, &UARTn_Config );

   _db_msg  = UARTPuts;
   _db_msg_ = UARTPuts_;
   _db_char = UARTPutChar;
   _db_hex = UARTPutHex;
   _db_hex_16 = UARTPutHex16;
   _db_hex_32 = UARTPutHex32;
   _db_dec = UARTPutDec;
   _db_dec_16 = UARTPutDec16;
   _db_dec_32 = UARTPutDec32;
   _db_get_char = UARTGetChar;
   _db_get_ch = UARTGetCh;
}

/*-------------------------------------------------------------------------*//**
 * @brief         Get a character to UART port
 * @param         None
 * @return        character value that returned
 *//*-------------------------------------------------------------------------*/
uint8_t getstring( void )
{
   uint8_t     ch;

   ch = UARTGetChar( ( UARTn_Type* )UART1 );

   if( ch > 0 )
   {
      if( InCount < 80 )
      {
         if( InCount == 0 && ch < 0x20 )
         {
            InData[0] = 0;
            return ch;
         }

         UARTPutChar( ( UARTn_Type* )UART1, ch );
         if( ch == ASCII_BACKSPACE )
         {
            InCount--;
            return ch;
         }

         if( ch == ASCII_CARRIAGE_RETURN )
         {
            InData[InCount] = 0;
            InFlag = 1;
            return ch;
         }

         InData[InCount++] = ch;
      }
   }

   return 0;
}

#endif   /* _DEBUG_MSG */

