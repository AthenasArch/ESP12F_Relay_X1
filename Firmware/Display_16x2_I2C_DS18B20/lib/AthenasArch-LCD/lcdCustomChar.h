#ifndef LCD_CUSTOM_CHAR_H
#define LCD_CUSTOM_CHAR_H

#include <stdio.h>
#include <stdlib.h>

enum SPECIAL_CHARACTERS{

    CUSTOM_CHAR_DEGREES = 0,
    CUSTOM_CHAR_SETA_CIMA,
    CUSTOM_CHAR_SETA_BAIXO,
    CUSTOM_CHAR_SETA_DIREITA,
    CUSTOM_CHAR_SETA_ESQUERDA,
    CUSTOM_CHAR_SETA_CIMA_BAIXO,
    CUSTOM_CHAR_BAT_BAR_1_LOW,
    CUSTOM_CHAR_BAT_BAR_1_FULL,
    CUSTOM_CHAR_BAT_BAR_2_LOW,
    CUSTOM_CHAR_BAT_BAR_2_FULL,
    CUSTOM_CHAR_BAT_BAR_3_LOW,
    CUSTOM_CHAR_BAT_BAR_3_FULL,
    CUSTOM_CHAR_BAT_BAR_4_LOW,
    CUSTOM_CHAR_BAT_BAR_4_FULL
};

//Array simbolo grau
byte lcdCustomChar_grau[8] =
{
    B00001100,
    B00010010,
    B00010010,
    B00001100,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
};

byte lcdCustomChar_SetaCima[8] =
{
    B00000000,
    B00000100,
    B00001110,
    B00010101,
    B00000100,
    B00000100,
    B00000000,
    B00000000,
};

byte lcdCustomChar_SetaBaixo[8] =
{
    B00000000,
    B00000000,
    B00000100,
    B00000100,
    B00010101,
    B00001110,
    B00000100,
    B00000000,
};

byte lcdCustomChar_SetaDireita[8] =
{
    B00000000,
    B00000100,
    B00000010,
    B00011111,
    B00000010,
    B00000100,
    B00000000,
    B00000000,
};

byte lcdCustomChar_SetaEsquerda[8] =
{
    B00000000,
    B00000100,
    B00001000,
    B00011111,
    B00001000,
    B00000100,
    B00000000,
    B00000000,
};

byte lcdCustomChar_SetaCimaBaixo[8] =
{
    B00000100,
    B00001110,
    B00011111,
    B00000100,
    B00000100,
    B00011111,
    B00001110,
    B00000100,
};

////////////////////////////////////////////////////////////////////////////////
////
////    Controle de nivel de bateria
////
////

byte lcdCustomChar_BatBar1_low[] = {
    B11111,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B11111
};

byte lcdCustomChar_BatBar1_full[] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
};

byte lcdCustomChar_BatBar2_low[] = {
    B11111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111
};

byte lcdCustomChar_BatBar2_full[] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
};

byte lcdCustomChar_BatBar3_low[] = {
    B11111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111
};

byte lcdCustomChar_BatBar3_full[] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
};

byte lcdCustomChar_BatBar4_low[] = {
    B11100,
    B00100,
    B00111,
    B00001,
    B00001,
    B00111,
    B00100,
    B11100
};

byte lcdCustomChar_BatBar4_full[] = {
    B11100,
    B11100,
    B11111,
    B11111,
    B11111,
    B11111,
    B11100,
    B11100
};


#endif  /* LCD_CUSTOM_CHAR_H */
