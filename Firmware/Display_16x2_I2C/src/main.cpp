/**
 * @brief Arquivo exemplo de utilizacao de rele com ESP8266.
 * @name 
 * @version | 1.0                   |
 * @date    | 09/03/2021            |
 * @author  | athenasarch@gmail.com |
 * @file    | main.cpp              |
 **/

#include <Arduino.h>

#define TOGGLE_DATA(DATA) ((DATA)?DATA=0:DATA=1) // utilizado para inverter estado de variavel.

#define PIN_RELAY 5 // pino que esta localizado o Rele.

void timerRelay( unsigned long timeInterval ); // inicializa funcao de intervalo do rele.

/**
 * @brief Funcao Init.
 **/
void setup() {

    Serial.begin(115200); // inicia a comunicacao serial.
    pinMode(PIN_RELAY, OUTPUT); // seta pino do rele como saida.

    Serial.println("\r\r\n\nESP8266 - Serial INIT\r\r\n\n"); // imprime algo na porta serial.
}

/**
 * @brief Funcao Loop infinito. 
 **/
void loop() {

    timerRelay(1000);
}

/**
 * @brief Ativa e desativa o rele a cada intervalo de tempo.
 * 
 * @param
 * 
 * @return 
**/
void timerRelay( unsigned long timeInterval ){

    static unsigned long timerRelay = 0;
    static uint8_t toogleRelay=0;

    // funcao executada a cada 1000ms
    if(millis() - timerRelay > timeInterval){
        
        timerRelay = millis();
        
        Serial.print("CNT: "); Serial.println( millis() / timeInterval);

        TOGGLE_DATA(toogleRelay);
        
        digitalWrite(PIN_RELAY, toogleRelay);
    }
}