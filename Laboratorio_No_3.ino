const int LedBlanco = 2;
const int LedRojo = 3;
const int LedVerde = 4;
const int pb1 = 10;
const int pb2 = 9;
const int pb3 = 8;
const int potenciometro = A3;

// Declaración de variables
int valorPotenciometro;

void setup() {
  // Configuración de los pines
  pinMode(LedBlanco, OUTPUT);
  pinMode(LedRojo, OUTPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(pb1, INPUT_PULLUP);
  pinMode(pb2, INPUT_PULLUP);
  pinMode(pb3, INPUT_PULLUP);
  Serial.begin(9600); // I  nicia la comunicación serial
}

void loop() {
  if (digitalRead(pb1) == LOW) {
    digitalWrite(LedBlanco, HIGH);
  } else {
    digitalWrite(LedBlanco, LOW);
  }
  if (digitalRead(pb2) == LOW) {
    digitalWrite(LedRojo, HIGH);
  } else {
    digitalWrite(LedRojo, LOW);
  }
  if (digitalRead(pb3) == LOW) {
    digitalWrite(LedVerde, HIGH);
  } else {
    digitalWrite(LedVerde, LOW);
  }

  // Lee el valor del potenciómetro y lo envía a Processing a través del puerto serie
  valorPotenciometro = analogRead(potenciometro);
  Serial.println(valorPotenciometro);
  delay(200); // Pequeña pausa para evitar una transmisión muy rápida de datos por el puerto serie
}