/**
 * @brief Arquivo exemplo de utilizacao de rele com ESP8266.
 * @name 
 * @version | 1.0                   |
 * @date    | 09/03/2021            |
 * @author  | athenasarch@gmail.com |
 * @file    | main.cpp              |
 **/
#include <Arduino.h> // biblioteca padrao do Arduino.
#include <lcdArch.h> // biblioteca da AthenasArch para LCD.

#define TOGGLE_DATA(DATA) ((DATA)?DATA=0:DATA=1) // utilizado para inverter estado de variavel.

#define TIME_ACTIVE_RELAY 3000 // 3 segundos de intervalo entre ligar/desligar rele

#define PIN_RELAY  5 // pino que esta localizado o Rele.

#define RELAY_ON    1 // Rele ligado.
#define RELAY_OFF   0 // Rele Desligado

void timerRelay( unsigned long timeInterval ); // inicializa funcao de intervalo do rele.
void printMenuAthenasArch( void );

/**
 * @brief Funcao Init.
 **/
void setup() {

    Serial.begin(115200); // inicia a comunicacao serial - Velocidade 115200.
    pinMode(PIN_RELAY, OUTPUT); // seta pino do rele como saida.
    lcdArch_init(); // inicia display LCD 16x2 I2C

    printMenuAthenasArch(); // imprime o menu da AthenasArch

    lcdArch_clear(LCD_CLR); // limpa tela do display...
    lcdArch_print(0, LCD_LINE_1, "ESP12F-RELAY-X1");
}

/**
 * @brief Funcao Loop infinito. 
 **/
void loop() {

    timerRelay(TIME_ACTIVE_RELAY);
}

/**
 * @brief Apenas imprime o menu da AthenasArch.
 * 
 * @param void.
 * 
 * @return void.
**/
void printMenuAthenasArch( void ){
    
    const char MENU_TITLE[] = 
"\r\n\t\
|------------------------------------------|\r\n\t\
|                                          |\r\n\t\
|        AthenarArch - From Brazil         |\r\n\t\
|                                          |\r\n\t\
|------------------------------------------|\r\n\r\n";

    Serial.println(MENU_TITLE); // imprime o menu Serial
    lcdArch_clear(LCD_CLR); // limpa tela do display
    lcdArch_print(0, LCD_LINE_1, "  AthenasArch  ");
    lcdArch_print(0, LCD_LINE_2, "     BRAZIL    ");
    delay(5000);
}

/**
 * @brief Ativa e desativa o rele a cada intervalo de tempo e mprime no display.
 * 
 * @param timeInterval Tempo de acionamento do rele.
 * 
 * @return void
**/
void timerRelay( unsigned long timeInterval ){

    static unsigned long timerRelay = 0;
    static uint8_t toogleRelay=0;

    // funcao executada a cada 1000ms
    if(millis() - timerRelay > timeInterval){

        timerRelay = millis();
        
        Serial.print("CNT: "); Serial.println( millis() / timeInterval);

        TOGGLE_DATA(toogleRelay);
        
        lcdArch_clear(LCD_LINE_2);
        if(toogleRelay == RELAY_ON){
            lcdArch_print(0, LCD_LINE_2, "RELAY: ON");
        } else {
            lcdArch_print(0, LCD_LINE_2, "RELAY: OFF");
        }
        digitalWrite(PIN_RELAY, toogleRelay);
    }
}

