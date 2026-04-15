// --- CONFIGURAÇÃO DOS PINOS ---
const int pinIgnition   = 2; // Vermelho
const int pinHorn       = 3; // Laranja
const int pinHighBeam   = 4; // Amarelo (1)
const int pinSlowBeam   = 5; // Amarelo (2)
const int pinHazard     = 6; // Branco
const int pinLeftArrow  = 7; // Verde (1)
const int pinRightArrow = 8; // Verde (2)
const int pinCleaner    = 9; // Azul

void setup() {
  Serial.begin(9600);
  Serial.println("--- Sistema de Simulador: Online ---");

  // Configura todos os pinos de 2 a 9 como INPUT_PULLUP
  for (int i = 2; i <= 9; i++) {
    pinMode(i, INPUT_PULLUP);
  }
}

void loop() {
  // Verificação Individual de cada Botão
  if (digitalRead(pinIgnition) == LOW)   { enviarComando("IGNICAO ATIVADA"); }
  if (digitalRead(pinHorn) == LOW)       { enviarComando("BUZINA"); }
  if (digitalRead(pinHighBeam) == LOW)   { enviarComando("FAROL ALTO"); }
  if (digitalRead(pinSlowBeam) == LOW)   { enviarComando("FAROL BAIXO"); }
  if (digitalRead(pinHazard) == LOW)     { enviarComando("PISCA-ALERTA"); }
  if (digitalRead(pinLeftArrow) == LOW)  { enviarComando("SETA ESQUERDA"); }
  if (digitalRead(pinRightArrow) == LOW) { enviarComando("SETA DIREITA"); }
  if (digitalRead(pinCleaner) == LOW)    { enviarComando("LIMPADOR"); }
}

// Função para evitar repetição infinita no Monitor Serial
void enviarComando(String mensagem) {
  Serial.println("Comando detectado: " + mensagem);
  delay(300); // Debounce: tempo de espera para o próximo clique
}
