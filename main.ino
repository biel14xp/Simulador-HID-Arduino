#include <Joystick.h>

// Definição de pinos (Exemplo: Chave de Ignição e Botão de Start)
const int pinoChave = 2; 
const int pinoBotao = 3;

Joystick_ Joystick;

void setup() {
  pinMode(pinoChave, INPUT_PULLUP);
  pinMode(pinoBotao, INPUT_PULLUP);
  Joystick.begin();
}

void loop() {
  // Lê os botões (Invertido pelo INPUT_PULLUP)
  Joystick.setButton(0, !digitalRead(pinoChave));
  Joystick.setButton(1, !digitalRead(pinoBotao));
  
  delay(10); // Debounce para estabilidade
}
