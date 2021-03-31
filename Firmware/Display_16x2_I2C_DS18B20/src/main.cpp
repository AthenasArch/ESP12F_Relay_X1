/**
 * @brief Arquivo exemplo de utilizacao de Display LCD - Sensor de temperatura e Rele.
 * @name 
 * @version | 1.0                   |
 * @date    | 09/03/2021            |
 * @author  | athenasarch@gmail.com |
 * @file    | main.cpp              |
 **/
#include <Arduino.h> // biblioteca padrao do Arduino.
#include <lcdArch.h> // biblioteca da AthenasArch para LCD.
#include <Ds18b20.h>

#define DEGREES_SERIAL  "\xC2\xB0"
#define DEGREES_LCD     char(0xDF)

#define TEMP_ACTIVE_RELAY 30.0 // Se passar dos 30, ativa o rele.

#define TIME_ACTIVE_RELAY 3000 // 3 segundos de intervalo entre ligar/desligar rele

#define PIN_RELAY  5 // pino que esta localizado o Rele.

// pino usado para o sensor de temperatura e o IO12!

#define RELAY_ON    1 // Rele ligado.
#define RELAY_OFF   0 // Rele Desligado

void relayAndTempSensor( const float temperatureActiveRelay ); // inicializa funcao de intervalo do rele.
void printMenuAthenasArch( void );

/**
 * @brief Funcao Init.
 **/
void setup() {

    Serial.begin(115200); // inicia a comunicacao serial - Velocidade 115200.
    pinMode(PIN_RELAY, OUTPUT); // seta pino do rele como saida.
    lcdArch_init(); // inicia display LCD 16x2 I2C

    printMenuAthenasArch(); // imprime o menu da AthenasArch
    DS18b20_init();

    lcdArch_clear(LCD_CLR); // limpa tela do display...
    lcdArch_print(0, LCD_LINE_1, "ESP12F-RELAY-X1");
}

/**
 * @brief Funcao Loop infinito. 
 **/
void loop() {

    relayAndTempSensor(TEMP_ACTIVE_RELAY);
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
void relayAndTempSensor( const float temperatureActiveRelay ){

    static float oldTemperature = 0.0;
    String strTemp = "";
    float currTemp = 0.0;

    currTemp = getTemperature_DS18B20();

    // Se a nova temperatura for diferente da ultima temperatura lida, atualiza os dados...
    if(oldTemperature != currTemp){
        oldTemperature = currTemp;

        // imprime a temperatura na serial
        Serial.print("Temperatura atual = ");
        Serial.print(currTemp);
        Serial.print(DEGREES_SERIAL);
        Serial.println("C");

        strTemp = "TEMP: " + String(currTemp) + DEGREES_LCD + "C   "; // Monta a string para jogar no display 
        lcdArch_print(0, LCD_LINE_1, strTemp);          // escreve no display.
        
        // se a temperatura atual, for maior do que a setada, entao ativa o rele e imprime no display.
        if(currTemp > temperatureActiveRelay){
            lcdArch_print(0, LCD_LINE_2, "RELAY: ON ");
            digitalWrite(PIN_RELAY, RELAY_ON);
        } else { // se nao, fica com rele desligado.
            lcdArch_print(0, LCD_LINE_2, "RELAY: OFF");
            digitalWrite(PIN_RELAY, RELAY_OFF);
        }
    }
}

