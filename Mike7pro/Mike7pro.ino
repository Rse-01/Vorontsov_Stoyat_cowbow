#include <Wire.h> // Библиотека I2C
#include <Adafruit_GFX.h> // Графическая библиотека Adafruit
#include <Adafruit_SSD1306.h> // Библиотека OLED-дисплеев

// Пины подключения дисплея
#define SCREEN_WIDTH 64 // Ширина дисплея в пикселях
#define SCREEN_HEIGHT 64 // Высота дисплея в пикселях
#define OLED_RESET     -1 // Нет аппаратного сброса дисплея
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Пины подключения кнопок
const int buttonPinLeft = 2;   // Левая кнопка
const int buttonPinRight = 3;  // Правая кнопка

// Пины динамика
const int buzzerPin = 9;       // Динамик подключён к этому пину

// Переменные состояния игры
enum GameState { WAITING, PLAYING, RELOAD };
GameState currentState = WAITING;
unsigned long startTime;
bool leftPressed = false;
bool rightPressed = false;

void setup() {
  Serial.begin(9600);           // Инициализация последовательного порта для дебага
  
  pinMode(buttonPinLeft, INPUT_PULLUP); // Настройка пинов кнопок
  pinMode(buttonPinRight, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);      // Подключение динамика

  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println("SSD1306 allocation failed");
    for (;;) ;                      // Если дисплей не инициализирован, зависаем тут
  }
}

void loop() {
  switch(currentState){
    case WAITING:
      checkButtons();              // Проверяем обе кнопки одновременно
      break;
    
    case PLAYING:
      playGame();
      break;
    
    case RELOAD:
      reloadGame();
      break;
  }
}

void checkButtons(){
  bool btnL = digitalRead(buttonPinLeft);
  bool btnR = digitalRead(buttonPinRight);

  if(btnL==LOW && btnR==LOW){     // Обе кнопки нажаты?
    delay(100);                   // Небольшое задержка для предотвращения дребезга контактов
    if(digitalRead(buttonPinLeft)==LOW && digitalRead(buttonPinRight)==LOW){
      clearScreen();
      currentState=PLAYING;
      startTime=millis()+random(1000,5000); // Время старта игры после задержки от 1 до 5 сек
    }
  }
}

void playGame(){
  unsigned long now = millis();
  if(now >= startTime){
    fillRectRed();                 // Экран становится красным
    checkWhoWon();                 // Кто победил?
  }
}

void checkWhoWon(){
  while(true){
    bool btnL = digitalRead(buttonPinLeft);
    bool btnR = digitalRead(buttonPinRight);

    if(btnL==LOW || btnR==LOW){
      tone(buzzerPin, 1000, 100); // Звук победы
      
      if(btnL==LOW){
        showWinner('LEFT');
      } else {
        showWinner('RIGHT');
      }
      return;
    }
  }
}

void showWinner(char side[]){
  clearScreen();
  if(strcmp(side,"LEFT")==0){
    drawRectangleGreen(0,0,SCREEN_WIDTH/2,SCREEN_HEIGHT); // Победил левый игрок
    drawRectangleRed(SCREEN_WIDTH/2+1,0,SCREEN_WIDTH-SCREEN_WIDTH/2-1,SCREEN_HEIGHT);// Проиграл правый
  }else{
    drawRectangleGreen(SCREEN_WIDTH/2+1,0,SCREEN_WIDTH-SCREEN_WIDTH/2-1,SCREEN_HEIGHT);// Победил правый игрок
    drawRectangleRed(0,0,SCREEN_WIDTH/2,SCREEN_HEIGHT);                               // Проиграл левый
  }
  currentState=RELOAD;
}

void reloadGame(){
  if(leftPressed || rightPressed){
    checkButtons();                // Ждём повторного нажатия обеих кнопок
  }
}

void fillRectRed(){               // Заполняем весь экран красным
  display.clearDisplay();
  display.fillRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,WHITE);
  display.display();
}

void drawRectangleGreen(int x,int y,int w,int h){ // Рисует зеленый прямоугольник
  display.drawRect(x,y,w,h,GREEN);
  display.fillRect(x+1,y+1,w-2,h-2,GREEN);
  display.display();
}

void drawRectangleRed(int x,int y,int w,int h){   // Рисует красный прямоугольник
  display.drawRect(x,y,w,h,RED);
  display.fillRect(x+1,y+1,w-2,h-2,RED);
  display.display();
}

void clearScreen(){
  display.clearDisplay();
  display.display();
}