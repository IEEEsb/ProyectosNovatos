
//definiciones 

#define PRESS_MIN 100    // tiempo minimo presionando el boton (ms) (evita falsas pulsaciones)

#define BUZZ_PIN 11     // Pin del buzzer

#define Y_PIN 3         // Pines de los leds (Y->amarillo, R-> rojo, B->azul, G-> verde)
#define R_PIN 4
#define B_PIN 5
#define G_PIN 6

#define Y_BUTTON  7     //Pines de los botones asociados a los leds
#define R_BUTTON  8
#define B_BUTTON  9
#define G_BUTTON  10

#define Y_FREQ  400     // Tablas de tonos asociados a los leds
#define R_FREQ  600
#define B_FREQ  800
#define G_FREQ  1000

//constantes 

const uint8_t leds[4] ={ Y_PIN, R_PIN, B_PIN, G_PIN };              
const uint8_t buttons[4] = { Y_BUTTON, R_BUTTON, B_BUTTON, G_BUTTON };
const uint8_t freq[4} = { Y_FREQ, R_FREQ, B_FREQ, G_FREQ };

//variables

uint8_t elements[255];      //alamacena las posiciones de los elementos
uint8_t index;              //Indica el ultimo valor añadido a elements[]
int s_peed;                 // NOT USED YET
bool started;               //Indica si hay una partida en curso


/* Configuración inicial */
void setup() {
  //iniciamos las variables
  index = 0;
  s_peed = 0;
  started = false;

  //iniciamos el hardware

  pinMode(Y_PIN, OUTPUT);
  pinMode(R_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);


  pinMode(Y_BUTTON, INPUT_PULLUP);
  pinMode(R_BUTTON, INPUT_PULLUP);
  pinMode(B_BUTTON, INPUT_PULLUP);
  pinMode(G_BUTTON, INPUT_PULLUP);
  
  
}

void loop() {

  if( starded == false){
    if(keyPress() != -1){
        stated = true;
      }
    return;
    }
  
  //Creamos un valor aleatorio y lo añadimos
  elements[index] = random(0,3);
  index++;
  
  //mostramos elementos

  for(int i = 0; i < index ; i++){
      uint8_t n = elements[i];
      tone(BUZZ_PIN, freq[n])
      digitalWrite( leds[n] , HIGH);
      delay(300);
      digitalWrite(leds[n] , LOW);
      delay(300);
      noTone(BUZZ_PIN);
    }

    //comprobamos elementos

    for(int i = 0; i < index ; i++){
       uint8_t aux = -1;
       while (aux == -1){
          aux = keyPress();
        }
       if(aux != elements[i]){
          clearData();
          tone(BUZZ_PIN, 300, 1000);
          return;
        }
        tone(BUZZ_PIN, freq[n])
        digitalWrite( leds[n] , HIGH);
        delay(300);
        digitalWrite(leds[n] , LOW);
        delay(300);
        noTone(BUZZ_PIN);
    
      }   

}
/**
 *  Detecta si hay un boton presionado. Si lo esta, devuelve el indice asociado al boton
 */
int keyPress(){
  long tmp = 0;
  for(int i = 0; i < 4; i++){
      tmp = millis();
      while(!digitalRead(buttons[i]){}
      if(millis() - tmp > PRESS_MIN)
        return i;
    }
    return -1;
}
/**
 *  Limpia las variables para una nueva partida
 */
void clearData(){
    index = 0;
    started = false;

    for(int i = 0; i <255; i++){
        elements[i] = 0;
      }
  }
