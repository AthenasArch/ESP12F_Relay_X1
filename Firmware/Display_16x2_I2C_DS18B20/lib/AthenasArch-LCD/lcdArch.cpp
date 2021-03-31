#include "lcdArch.h"
#include "lcdCustomChar.h"
#include "LiquidCrystal.h"
#include "LiquidCrystal_I2C.h"

#ifdef HARDWARE_H_
    #include "Hardware/hardware.h"
#endif /* */

#define LEN_STR_NUM_BUFF	4
char strNumBuffAux[LEN_STR_NUM_BUFF]="";

unsigned long oldTimeloading = 0;
unsigned char cntLoading = 0;
// static unsigned long backlightControl = 0;

/** @brief Define os pinos que serão utilizados para ligação ao display */
#ifndef USE_DISPLAY_I2C
    LiquidCrystal lcd(PIN_DISPLAY_RS, PIN_DISPLAY_EN, PIN_DISPLAY_D4, PIN_DISPLAY_D5, PIN_DISPLAY_D6, PIN_DISPLAY_D7);
#else
    LiquidCrystal_I2C lcd(0x27, 16, 2);
#endif /* */

/**
 * @brief Inicializa o modulo LCD
 * @warning escolha se deseja operar com I2C ou modo 4 Bits
 *
 * @param void
 *
 * @return void
 **/
void lcdArch_init(void){

#ifndef USE_DISPLAY_I2C
    lcd.begin(DISPLAY_QTDE_COLUMN, DISPLAY_QTDE_LINE);
    lcdArch_creatingChars();
    // LCD_print_CreatedChar();
    // LCD_print_test();
#else // se usar display I2C, entra aqui...

	lcd.begin(PIN_LCD_I2C_SDA, PIN_LCD_I2C_SCL); // Caso utilize pinos diferentes no I2C
    // lcd.begin(); // pinos padrao I2C

	// Turn on the blacklight and print a message.
	lcd.backlight();
#endif

}

/**
 * @brief imprime uma string na tela do display
 *
 * @param _position posicao inicial da String
 * @param _line Linha a ser printada
 * @param dataPrint String a ser impressa
 * 
 * @return void
 */
void lcdArch_print( const uint8_t _position, DISPLAY_LCD_16X2_LINE _line, const String dataPrint){
    // lcd.clear(); //Limpa a tela
    // .setCursor(J, I); lcd.print("                ");
    lcd.setCursor(_position, _line); lcd.print(dataPrint);
}

/**
 * @brief printa um caractere
 *
 * @param _position coluna de inicio
 * @param _line linha de inicio
 * @param dataPrint caractere que sera impresso
 *
 * @return void
 */
void lcdArch_printChar( const uint8_t _position, DISPLAY_LCD_16X2_LINE _line, char dataPrint){
    // lcd.clear(); //Limpa a tela
    // .setCursor(J, I); lcd.print("                ");
    lcd.setCursor(_position, _line); lcd.write(dataPrint);
}

/**
 * @brief printa um numero em uma determinada base
 *
 * @param _position coluna de inicio
 * @param _line linha de inicio
 * @param _byte byte que sera impresso
 * @param _base base que sera impresso
 *
 * @return void
 */
void lcdArch_printBase( const uint8_t _position, DISPLAY_LCD_16X2_LINE _line, const uint8_t _byte, const uint8_t _base){
    lcd.setCursor(_position, _line); lcd.print(_byte, _base);
}

/**
 * @brief
 * 
 * @param
 * 
 * @return
 **/
void lcdArch_printNum( const uint8_t _position, DISPLAY_LCD_16X2_LINE _line, const uint16_t _byte, const uint8_t _qttyZero){
    lcd.setCursor(_position, _line); lcd.print(lcdArch_numToStr(_byte, _qttyZero));
    // Serial.print("Num: "); Serial.print(_byte); Serial.print(" - \tstr Num: "); Serial.println(lcdArch_numToStr(_byte, _qttyZero));  
}

/**
 * @brief limpa linha ou todo o display
 * 
 * @param _line Opcional - linha que desejada para limpar.
 *              Se nao for colocado opcional, limpa toda tela.
 * @return void
 **/
void lcdArch_clear( DISPLAY_LCD_16X2_LINE _line ){
    // lcd.clear(); //Limpa a tela
    // .setCursor(J, I); lcd.print("                ");
    if(_line==LCD_LINE_1){
        lcd.setCursor(0, LCD_LINE_1); lcd.print("                ");
    }else if (_line==LCD_LINE_2){
        lcd.setCursor(0, LCD_LINE_2); lcd.print("                ");
    }else{
        lcd.clear(); //Limpa a tela
    }
}

/**
 * @brief
 * 
 * @param
 *
 * @return void
 **/
void lcdArch_printCustomChar(const uint8_t _position, DISPLAY_LCD_16X2_LINE _line, const int _customChar){
    lcd.setCursor(_position, _line); lcd.write(_customChar);
}

/**
 * @brief
 * 
 * @param
 *
 * @return void
 **/
void lcdArch_backlightControl(const int mode){
    // desativa brilho da tela
//    if(mode){
//        digitalWrite(PIN_DISPLAY_BACKLIGHT, 0);
//    }else{
//        digitalWrite(PIN_DISPLAY_BACKLIGHT, 1);
//    }
}


// void LCD_backlightControl(void){
//
//     // desativa brilho da tela
//     if((millis()-backlightControl)>DELAY_BACKLIGHT)
//     {
//         digitalWrite(PIN_DISPLAY_BACKLIGHT, 0);
//     }else{
//         digitalWrite(PIN_DISPLAY_BACKLIGHT, 1);
//     }
//
//     if(digitalRead(PIN_BUT_HORARIO_VERAO))
//         backlightControl = millis();
//
//     if(digitalRead(PIN_BUT_BAIXO))
//         backlightControl = millis();
//
//     if(digitalRead(PIN_BUT_CIMA))
//         backlightControl = millis();
//
//     if(digitalRead(PIN_BUT_ESQUERDA))
//         backlightControl = millis();
//
//     if(digitalRead(PIN_BUT_DIREITA))
//         backlightControl = millis();
//
//     if(LCD_oldModoPLaca != modoPlaca)
//     {
//         LCD_oldModoPLaca = modoPlaca;
//         backlightControl = millis();
//     }
// }

/**
 * @brief
 * 
 * @param
 *
 * @return void
 **/
void lcdArch_creatingChars(void){

    lcd.createChar(CUSTOM_CHAR_DEGREES, lcdCustomChar_grau);
    lcd.createChar(CUSTOM_CHAR_SETA_CIMA, lcdCustomChar_SetaCima);
    lcd.createChar(CUSTOM_CHAR_SETA_BAIXO, lcdCustomChar_SetaBaixo);
    lcd.createChar(CUSTOM_CHAR_SETA_DIREITA, lcdCustomChar_SetaDireita);
    lcd.createChar(CUSTOM_CHAR_SETA_ESQUERDA, lcdCustomChar_SetaEsquerda);
    lcd.createChar(CUSTOM_CHAR_SETA_CIMA_BAIXO, lcdCustomChar_SetaCimaBaixo);
    lcd.createChar(CUSTOM_CHAR_BAT_BAR_1_LOW, lcdCustomChar_BatBar1_low);
    lcd.createChar(CUSTOM_CHAR_BAT_BAR_1_FULL, lcdCustomChar_BatBar1_full);
    lcd.createChar(CUSTOM_CHAR_BAT_BAR_2_LOW, lcdCustomChar_BatBar2_low);
    lcd.createChar(CUSTOM_CHAR_BAT_BAR_2_FULL, lcdCustomChar_BatBar2_full);
    lcd.createChar(CUSTOM_CHAR_BAT_BAR_3_LOW, lcdCustomChar_BatBar3_low);
    lcd.createChar(CUSTOM_CHAR_BAT_BAR_3_FULL, lcdCustomChar_BatBar3_full);
    lcd.createChar(CUSTOM_CHAR_BAT_BAR_4_LOW, lcdCustomChar_BatBar4_low);
    lcd.createChar(CUSTOM_CHAR_BAT_BAR_4_FULL, lcdCustomChar_BatBar4_full);
}

/**
 * @brief Imprime texto fixo de teste
 * 
 * @param
 *
 * @return void
 **/
void lcdArch_printTest(void){

    lcd.clear(); //Limpa a tela
    // .setCursor(J, I); lcd.print("                ");
    lcd.setCursor(0, LCD_LINE_1); lcd.print(F(" DISPLAY  TESTE "));
    lcd.setCursor(0, LCD_LINE_2); lcd.print(F("    LCD 16x2    "));
}

/**
 * @brief
 * 
 * @param
 *
 * @return void
 **/
void lcdArch_printCreatedChar(void){

    lcd.clear(); //Limpa a tela
    // .setCursor(J, I); lcd.print("                ");
    lcd.setCursor(0, LCD_LINE_1); lcd.print("DISPLAY NEW CHAR");
    lcd.setCursor(0, LCD_LINE_2);
    lcd.write(CUSTOM_CHAR_SETA_CIMA);
    lcd.write(CUSTOM_CHAR_SETA_BAIXO);
    lcd.write(CUSTOM_CHAR_SETA_DIREITA);
    lcd.write(CUSTOM_CHAR_SETA_ESQUERDA);
    lcd.write(CUSTOM_CHAR_SETA_CIMA_BAIXO);
}

/**
 * @brief
 * 
 * @param
 *
 * @return void
 **/
void lcdArch_printATMEng(void){

    lcd.clear(); //Limpa a tela
    // .setCursor(J, I); lcd.print("                ");
    lcd.setCursor(0, LCD_LINE_1); lcd.print(" ATM ENGENHARIA ");
    lcd.setCursor(0, LCD_LINE_2); lcd.write(CUSTOM_CHAR_SETA_CIMA);
    lcd.setCursor(1, LCD_LINE_2); lcd.print("  PLACA SIFE  ");
    lcd.setCursor(15, LCD_LINE_2); lcd.write(CUSTOM_CHAR_SETA_DIREITA);
}

/**
 * @brief
 * 
 * @param
 *
 * @return void
 **/
void lcdArch_batteryCharg(uint8_t batLevel, uint16_t _nMin, uint8_t _nMax, uint8_t _position, DISPLAY_LCD_16X2_LINE line,  uint8_t batLevelNumEn){

    uint8_t lvBatt = map(batLevel, _nMin, _nMax, 0, 4);
    switch(lvBatt){
        case 0: // 20
            lcd.setCursor(_position, line); lcd.write(CUSTOM_CHAR_BAT_BAR_1_LOW);
            lcd.setCursor(_position+1, line); lcd.write(CUSTOM_CHAR_BAT_BAR_2_LOW);
            lcd.setCursor(_position+2, line); lcd.write(CUSTOM_CHAR_BAT_BAR_3_LOW);
            lcd.setCursor(_position+3, line); lcd.write(CUSTOM_CHAR_BAT_BAR_4_LOW);
        break;
        case 1: // 40
            lcd.setCursor(_position, line); lcd.write(CUSTOM_CHAR_BAT_BAR_1_FULL);
            lcd.setCursor(_position+1, line); lcd.write(CUSTOM_CHAR_BAT_BAR_2_LOW);
            lcd.setCursor(_position+2, line); lcd.write(CUSTOM_CHAR_BAT_BAR_3_LOW);
            lcd.setCursor(_position+3, line); lcd.write(CUSTOM_CHAR_BAT_BAR_4_LOW);
        break;
        case 2: // 60
            lcd.setCursor(_position, line); lcd.write(CUSTOM_CHAR_BAT_BAR_1_FULL);
            lcd.setCursor(_position+1, line); lcd.write(CUSTOM_CHAR_BAT_BAR_2_FULL);
            lcd.setCursor(_position+2, line); lcd.write(CUSTOM_CHAR_BAT_BAR_3_LOW);
            lcd.setCursor(_position+3, line); lcd.write(CUSTOM_CHAR_BAT_BAR_4_LOW);
        break;
        case 3: // 80
            lcd.setCursor(_position, LCD_LINE_1); lcd.write(CUSTOM_CHAR_BAT_BAR_1_FULL);
            lcd.setCursor(_position+1, LCD_LINE_1); lcd.write(CUSTOM_CHAR_BAT_BAR_2_FULL);
            lcd.setCursor(_position+2, LCD_LINE_1); lcd.write(CUSTOM_CHAR_BAT_BAR_3_FULL);
            lcd.setCursor(_position+3, LCD_LINE_1); lcd.write(CUSTOM_CHAR_BAT_BAR_4_LOW);
        break;
        case 4: // 100
            lcd.setCursor(_position, LCD_LINE_1); lcd.write(CUSTOM_CHAR_BAT_BAR_1_FULL);
            lcd.setCursor(_position+1, LCD_LINE_1); lcd.write(CUSTOM_CHAR_BAT_BAR_2_FULL);
            lcd.setCursor(_position+2, LCD_LINE_1); lcd.write(CUSTOM_CHAR_BAT_BAR_3_FULL);
            lcd.setCursor(_position+3, LCD_LINE_1); lcd.write(CUSTOM_CHAR_BAT_BAR_4_FULL);
        break;
    }

    if(batLevelNumEn){
        lcd.setCursor(15, LCD_LINE_2); lcd.print("%");
        if(batLevel<10){
            lcd.setCursor(12, LCD_LINE_2); lcd.print("  ");
            lcd.setCursor(14, LCD_LINE_2); lcd.print(String(batLevel));
        }else if (batLevel>9 && batLevel<100){
            lcd.setCursor(12, LCD_LINE_2); lcd.print(" ");
            lcd.setCursor(13, LCD_LINE_2); lcd.print(String(batLevel));
        }else{
            lcd.setCursor(12, LCD_LINE_2); lcd.print("100");
        }
    }
}

/**
 * @brief
 * 
 * @param
 *
 * @return void
 **/
void lcdArch_printLoading(const unsigned int _timeLoading){

    if(cntLoading > 3)
        cntLoading = 0;

    if((millis()-oldTimeloading)>_timeLoading)
    {
        oldTimeloading = millis();

        lcd.clear(); //Limpa a tela
        lcd.setCursor(0, LCD_LINE_1); lcd.print(" ATM ENGENHARIA ");

        switch(cntLoading)
        {
            case 0: lcd.setCursor(0, LCD_LINE_2); lcd.print("LOADING"); break;
            case 1: lcd.setCursor(0, LCD_LINE_2); lcd.print("LOADING."); break;
            case 2: lcd.setCursor(0, LCD_LINE_2); lcd.print("LOADING.."); break;
            case 3: lcd.setCursor(0, LCD_LINE_2); lcd.print("LOADING..."); break;
        }

        cntLoading++;
    }
}

/**
 * @brief
 * 
 * @param
 *
 * @return void
 **/
String lcdArch_twoCharNumDisplay(const unsigned int _DATA_TO_CONVERT_){

    String _strDataTime = "";

    if(_DATA_TO_CONVERT_ < 10)
    {
        _strDataTime += "0";
        _strDataTime += _DATA_TO_CONVERT_;
    }else{
        _strDataTime += _DATA_TO_CONVERT_;
    }

    return _strDataTime;
}

/**
 * @brief transforma numeros em char array
 * 
 * @param number a ser convertido.
 * @param qttyZero qtde de zeros a esquerda do numero
 *
 * @return Quantidade de caracteres do num
 **/
char*lcdArch_numToStr(unsigned long number, unsigned char qttyZero){
	memset(strNumBuffAux, 0, sizeof(strNumBuffAux));
	switch(qttyZero){
		case 2:
			sprintf(strNumBuffAux,"%02li",number);
			break;
		case 3:
			sprintf(strNumBuffAux,"%03li",number);
			break;
        case 4:
			sprintf(strNumBuffAux,"%04li",number);
			break;
        case 5:
			sprintf(strNumBuffAux,"%05li",number);
			break;
        case 6:
			sprintf(strNumBuffAux,"%06li",number);
			break;
        case 7:
			sprintf(strNumBuffAux,"%07li",number);
			break;
        case 8:
			sprintf(strNumBuffAux,"%08li",number);
			break;
		default:
            sprintf(strNumBuffAux,"%li",number);
			break;
	}
    return strNumBuffAux;
}