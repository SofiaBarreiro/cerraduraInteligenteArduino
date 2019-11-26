#include <LiquidCrystal.h>
#define BTN_RIGHT  0
#define BTN_UP     1
#define BTN_DOWN   2
#define BTN_LEFT   3
#define BTN_SELECT 4
#define BTN_NONE   5


//LiquidCrystal lcd(8,9,4,5,6,7); //PARA PLACA
LiquidCrystal lcd(4, 5, 6, 7, 8, 9); // PARA SIMULADOR
int estado;


byte up[8] = {
  B00000,
  B00100,
  B01110,
  B11111,
  B01110,
  B01110,
  B01110,
};

byte down[8] = {
  B01110,
  B01110,
  B01110,
  B11111,
  B01110,
  B00100,
  B00000,
};

byte right[8] = {
  B00000,
  B00100,
  B11110,
  B11111,
  B11110,
  B00100,
  B00000,
};

byte left[8] = {
  B00000,
  B00100,
  B01111,
  B11111,
  B01111,
  B00100,
  B00000,
};


// funcion que devuelve el estado de la botonera
int readButton()
{

  int value = analogRead(A0);
  Serial.println(value);

  if (value < 72)
    return BTN_RIGHT;
  if (value < 237)
    return BTN_UP;
  if (value < 419)
    return BTN_DOWN;
  if (value < 625)
    return BTN_UP;
  if (value < 883)
    return BTN_LEFT;
  return BTN_NONE;

}


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  //  lcd.backlight();
  lcd.setCursor(0, 0);

  lcd.createChar(6, right);
  lcd.createChar(7, down);
  lcd.createChar(8, up);
  lcd.createChar(9, left);


  lcd.print("INGRESE CODIGO");
  analogWrite(A5, 0);

}


void loop()
{

  estado = readButton();

  if (estado != 5 && estado != 4) {
    lcd.clear();
    mostrarEstados(estado);
    delay(50);
  }

}


int mostrarEstados(int estado1) {
  if (estado1 == BTN_RIGHT)
    lcd.write((byte)6);
  
  if (estado1 == BTN_DOWN)
    lcd.write((byte)7);
 
  if (estado1 == BTN_UP)
    lcd.write((byte)8);
  
  if (estado1 == BTN_LEFT)
    lcd.write((byte)9);
 

}
