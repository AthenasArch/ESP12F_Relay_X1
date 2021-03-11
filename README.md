# ESP12F_Relay_X1

Olá pessoal, aqui é mais um conteudo da Athenas Arch.

Link do canal para vídeos da placa em: https://www.youtube.com/channel/UCpN0rPQxaVmqBYqXyltqowQ

Redes Sociais:
   - Instagram: https://www.instagram.com/athenasarch/

   - YouTube: https://www.youtube.com/channel/UCpN0rPQxaVmqBYqXyltqowQ


* Pensando em facilitar o desenvolvimento de projetos, trouxemos a placa ESP12F_Relay_X1.

# A placa conta com:
    1 - Módulo ESP-12F WiFi estável integrado, com memória Flash de 4M Byte;
    
    2 - As portas I/O e a porta de download do programa (através da UART) estão com fácil acesso, para facilitar o desenvolvimento;

    3 - Placa possui circuito para alimentação AC-DC integrada, é possível alimentar a placa através de:
 	      a) Tensão alternada da rede (tomada) AC – de 90 a 250VAC;
         b) Fonte de alimentação DC 7 a 30VDC;
         c) Entrada por USB ou fonte de 5V;
    
    4 - O botão de reinicialização RST do módulo WiFi integrado;
   
    5 - ESP-12F oferece suporte a ferramentas de desenvolvimento como Eclipse / Arduino IDE e fornece programas de referência no ambiente de desenvolvimento Arduino;

    6 - Existem 1 relé de 5V na placa, que emite sinal de contato seco NA/NF/COM (Aberto, fechado e comum), adequados para controlar cargas cuja tensão de trabalho está dentro de AC 250V – 10A / DC30V - 10A;
   
    7 - Indicador de fonte integrado, 1 LED programável e indicador de relé;


# Organização de projetos
    - Os softwares são desenvolvidos utilizado as bibliotecas do Arduino com o Platformio (sim, os projetos devem rodar na intreface classica do arduino).
    - Na pasta "Hardware": Estão localizados os arquivos de desenho da placa.
    - Na pasta "Firmware": Estão lozalizados os codigos Arduino.
    - Na pasta "Documentos": Estão lozalizados os arquivos auxilizares necessários para um completo entendimento do projeto.
    - Na pasta "Codigos": Estão lozalizados apenas os codigos de exemplo utilizando a IDE do Arduino.

# Descrição dos pinos da placa

![image](https://user-images.githubusercontent.com/79209419/110711952-2a29ba80-81df-11eb-9e23-91c1d7102a50.png)

# PINOUT DA PLACA

      1 – L / N: (Fase/Neutro ou Fase/Fase) Fonte de alimentação 90 a 250VAC.
      
      2 – 90 a 250VAC, circuito fonte de alimentação para DC5V (Quando adotar a alimentação por corrente alternada/tomada, não toque aqui diretamente com a mão !!!).
      
      3 – VCC / GND: Fonte de alimentação 7 a 12VDC.
      
      4 - Micro USB: fonte de alimentação 5VDC – USB.
	 a) Tensão alternada da rede (tomada) AC – de 90 a 250VAC;
         b) Fonte de alimentação DC 7 a 30VDC;
         c) Entrada por USB ou fonte de 5V;
      
      5 - Botão de pressionar (6X6 mm), botão de reinicialização RST do ESP8266.
      
      6 - Porta de download do programa UART: ESP8266 GND, RX, TX, 5V, conectar separadamente Módulo serial TTL externo: GND, TX, RX, 5V, IO0 – Conectar o IO0 ao GND para fazer o download/gravação do ESP8266. 
      
      7 - Porta de pinagem GPIO.
      
      8 - Saída de relé (NA/COM/NF):
         - NO: Normalmente aberto (NA), este pino está aberto em relação ao comum até o relé ser acionado;
         - COM: Comum (COM), este pino pode ser usado com o NO ou com o NC;
         - NC: Normalmente fechado (NC), este pino está em curto com o comum até o relé ser acionado;
      
      10 - LED programável.
      
      11 - LED indicador de relé.
      
By: Leonardo HIlgemberg Lopes.
