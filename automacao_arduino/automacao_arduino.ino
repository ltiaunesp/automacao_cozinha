#include "HX711.h"
#define DOUT  3
#define CLK  2

HX711 scale(DOUT, CLK);

const int buttonPin = 11;     // the number of the pushbutton pin
const int ledPin =  9;      // the number of the LED pin
int buttonState = 0;
int flagOperacoes = 0;      // nao tem cafe
int countOperacoes = 0;

float seed = -107.80;
float curWeight = 0;

int verificaSeAcabouCafe(){
  curWeight = scale.get_units(50);
  if(curWeight < 100){
    return 1;
  }
  return 0;
}

int verificaSeFoiColocadoCafe(){
  curWeight = scale.get_units(250);
  if(curWeight > 100){
    return 1;
  }
  return 0;
}

void acabouCafe(){
  flagOperacoes = 0; //Não tem cafe
  Serial.println("Quero cafe quero cafe quero cafe");
}

void cafeReposto(){
  flagOperacoes = 1; //Tem cafe
  Serial.println("mr rhubot avisa ai");
}

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);

  scale.set_scale(seed);

  scale.tare();
}

void loop() {
  if(flagOperacoes){ // se tiver cafe
    if(verificaSeAcabouCafe()){
      if(++countOperacoes == 5){
        acabouCafe();
        delay(5000);
      } 
      
    }
  }
  else{  // se nao tiver cafe
    countOperacoes = 0;
    if(verificaSeFoiColocadoCafe()){
      cafeReposto();
    }
  }      
]



        

}

