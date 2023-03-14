import processing.serial.*;

Serial puertoSerie; // Variable para la comunicación serial
String valorPotenciometro; // Variable para almacenar el valor recibido

void setup() {
  size(400, 200); // Tamaño de la ventana de Processing
  puertoSerie = new Serial(this, "COM6", 9600); // Inicia la comunicación serial con Arduino
}

void draw() {
  background(255); // Fondo blanco
  fill(0); // Texto en negro
  textSize(24); // Tamaño de letra
  text("Valor del potenciómetro: " + valorPotenciometro, 50, 100); // Muestra el valor del potenciómetro
}

void serialEvent(Serial puertoSerie) {
  valorPotenciometro = puertoSerie.readStringUntil('\n'); // Lee el valor enviado por Arduino
}
