#ifndef LCD_ARCH_H_
#define LCD_ARCH_H_

/**
 * @brief Biblioteca de interface de displays de cristal liquido. (Possui interface I2C)
 * @name 
 * @version | 1.0                   |
 * @date    | 25/03/2021            |
 * @author  | athenasarch@gmail.com |
 * @file    | lcdArch.cpp           |
 *
 * Biblioteca ja testada nos: ARDUINO MEGA || ARDUINO UNO || ESP8266
 **/

#include <Arduino.h>
#include <String.h>
#include <stdio.h>

#define USE_DISPLAY_I2C

/** @brief Display 16x2 */
#define DISPLAY_QTDE_COLUMN 16
#define DISPLAY_QTDE_LINE   2

#define DELAY_BACKLIGHT 60000 // Delay utilizado quando o backligh possui controle.

#ifndef USE_DISPLAY_I2C
    // #define USE_EXTERNAL_PINS_DISPLAY // descomente esta linha para utilizar os pinos do display em outro arquivo
    #ifndef USE_EXTERNAL_PINS_DISPLAY
        #define PIN_DISPLAY_RS          8  // pino display 16x2
        #define PIN_DISPLAY_EN          3  // pino display 16x2
        #define PIN_DISPLAY_D4          4  // pino display 16x2
        #define PIN_DISPLAY_D5          5  // pino display 16x2
        #define PIN_DISPLAY_D6          6  // pino display 16x2
        #define PIN_DISPLAY_D7          7  // pino display 16x2
        // #define PIN_DISPLAY_BACKLIGHT     // pino display backLiht enable
    #endif /* */
#else // caso utilize display I2C
    // #define USE_DISPLAY_SDA
    // #define USE_DISPLAY_SCL
    #define PIN_LCD_I2C_SDA 0
    #define PIN_LCD_I2C_SCL 2
#endif /* */

typedef enum{
    LCD_LINE_1 = 0, LCD_LINE_2, LCD_CLR 
}DISPLAY_LCD_16X2_LINE;

void lcdArch_init(void);
void lcdArch_printTest(void);
void lcdArch_printCreatedChar(void);
void lcdArch_creatingChars(void);
void lcdArch_printATMEng(void);
void lcdArch_printLoading(const unsigned int _timeLoading = 1000);
void lcdArch_backlightControl(const int mode=0);
String lcdArch_twoCharNumDisplay(const unsigned int _DATA_TO_CONVERT_);
void lcdArch_batteryCharg(uint8_t batLevel, uint16_t _nMin, uint8_t _nMax, uint8_t _position, DISPLAY_LCD_16X2_LINE line,  uint8_t batLevelNumEn);
char*lcdArch_numToStr(unsigned long number, unsigned char qttyZero);

void lcdArch_printBase( const uint8_t _position, DISPLAY_LCD_16X2_LINE _line, const uint8_t _byte, const uint8_t _base);
void lcdArch_print( const uint8_t _position, DISPLAY_LCD_16X2_LINE _line, const String dataPrint);
void lcdArch_printChar( const uint8_t _position, DISPLAY_LCD_16X2_LINE _line, char dataPrint);
void lcdArch_clear( DISPLAY_LCD_16X2_LINE _line=LCD_CLR);
void lcdArch_printCustomChar(const uint8_t _position, DISPLAY_LCD_16X2_LINE _line, const int _customChar);
void lcdArch_printNum( const uint8_t _position, DISPLAY_LCD_16X2_LINE _line, const uint16_t _byte, const uint8_t _qttyZero);

#endif  /* LCD_ARCH_H_ */
