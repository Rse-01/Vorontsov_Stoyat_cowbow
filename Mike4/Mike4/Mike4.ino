#include "Adafruit_NeoPixel.h"
#define LED_COUNT 64
#define LED_PIN 10
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int k[8]={0,0,0,0,0,0,0,0};

void debug(long a){
  Serial.println(a);
}

//запомнить состояние экрана 
//1=
//2=
//

int matrix[64]={
1,0,1,1,1,0,1,0,
1,1,0,1,1,0,1,0,
1,0,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,1,
};
int t_comb[4]={0,0,0,0};
int p1_comb[4]={0,0,0,0};

void zarad()


void pix(a,b){
  matrix[a]=b
}




//вывести данные на экран 
//---------knop pin 2-9---------------------
void knop(int a){ 
    //debug(digitalRead(a+1));  
  k[a]=digitalRead(a+1);
}

void reset(){
    //debug(digitalRead(a+1));  
  k[a]=0;
}

void ochist(){

}
void stav_cel(){
  
}
void matrix_pokaz(){
    for (byte i=0; i<=5; i++){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
}

  
}

void setup() {{
 int s=0
  Serial.begin(9600);}
  
  // Инициализируем серийный порт с частотой 115200 бод. [1](https://github.com/poelstra/arduino-multi-button)
    pinMode(2, INPUT_PULLUP);  // включаем внутренний подтягивающий резистор
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
}

void loop() {
//триггеры
for (a=1; a<#k ;a++){
  if (k[a]==1){
    s=1;
    reset();
  }
} 
  for (a=1; a<#k ;a++){
    if (k[a]==1){
      s=1
    }
  }


// 1,0,1,1,1,0,1,0,      1, 2, 3, 4, 5, 6, 7, 8, 
// 1,1,0,1,1,0,1,0,      9, 10, 11, 12, 13, 14, 15, 16,
// 1,0,1,1,1,1,1,1,      17, 18, 19, 20, 21, 22, 23, 24,
// 0,0,0,0,0,0,0,0,      25, 26, 27, 28, 29, 30, 31, 32,
// 1,0,0,0,0,0,0,1,      33, 34, 35, 36, 37, 38, 39, 40,
// 1,0,0,0,0,0,0,1,      41, 42, 43, 44, 45, 46, 47, 48,
// 1,0,0,0,0,0,0,0,      49, 50, 51, 52, 53, 54, 55, 56,
// 1,0,0,0,0,0,0,1,      57, 58, 59, 60, 61, 62, 63, 64,


//-------------------
//реакции
// 0.ожидание
  if (s==0){
    
  }
// 1.игра  
  if (s==1){
     matrica_pokaz()
     pix()

  }
// 2.подщёт резултатов
  if (s==2){
    knop()
    matrica_pokaz()
  }
// 3.разряжено
  if (s==3){
    zarad()
    
  }
  

}

