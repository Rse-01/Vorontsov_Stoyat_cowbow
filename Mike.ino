//запомнить состояние экрана 
matrix{64}={
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
}


//вывести данные на экран 
void matrix_pokaz(){}

//заменить данные о пикселе на экране
//изсмользовать команду Replace
#include <PinButton.h>

// Создаём объект кнопки, слушающий на пине 5. [1](https://github.com/poelstra/arduino-multi-button)
PinButton myButton(5);

void setup() {
  // Инициализируем серийный порт с частотой 115200 бод. [1](https://github.com/poelstra/arduino-multi-button)
  Serial.begin(115200);
}
}
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  // Считываем аппаратный пин и преобразуем в события нажатия
  myButton.update();
  if (myButton.isSingleClick()) {
    // Срабатывает только при одиночном коротком нажатии (то есть не на первый клик двойного нажатия и не на длительное)
    Serial.println("single");
  }
  if (myButton.isDoubleClick()) {
    Serial.println("double");
  }
}
