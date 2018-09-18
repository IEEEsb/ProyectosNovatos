#define PIN_LED 13
#define PIN_BUTTON 10

void encenderLed(int pin);
void apagarLed(int pin);
uint8_t leerPin(int pin);

int botones[7];
int leds[7];

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);

  //Rellenar Array
  botones[0] = PIN_BOTON0;
  botones[1] = PIN_BOTON0;
  botones[2] = PIN_BOTON0;
  botones[3] = PIN_BOTON0;
  botones[4] = PIN_BOTON0;
  botones[5] = PIN_BOTON0;
  botones[6] = PIN_BOTON0;
  botones[7] = PIN_BOTON0;
}

void loop() {
  //Definicion para leer boton
  //if(leerPin(Condicion)){
  //    Accion1
  //} else {
  //  Accion2
  //}
  int i;
  int boton_presionado;
    int led_encendido;
  
  for(i = 0; i < 7; i++){
      if(leerPin(botones[i])){
        boton_presionado = botones[i];
        led_encendido = leds[i];
        break;
      }
      if(i == 6){
        return;
      }
  }

        encenderLed(led_encendido);
        delay(TIEMPO_NOTA);
        apagarLed(led_encendido);

}

void encenderLed(int pin)
{
  digitalWrite(pin, HIGH);
}


void apagarLed(int pin)
{
  digitalWrite(pin, LOW);
}


uint8_t leerPin(int pin)
{
  return digitalRead(pin);
}

