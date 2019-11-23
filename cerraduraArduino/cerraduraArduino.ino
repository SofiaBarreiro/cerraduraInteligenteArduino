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

int 



// funcion que devuelve el estado de la botonera
int readButton()
{

  int value = analogRead(A0);
  if (value < 72)
    return BTN_RIGHT;
  if (value < 237)
    return BTN_UP;
  if (value < 419)
    return BTN_DOWN;
  if (value < 625)
    return BTN_LEFT;
  if (value < 883)
    return BTN_SELECT;
  return BTN_NONE;

}

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("INGRESE CODIGO");
  analogWrite(A5, 0);

  


  
}



void loop()
{

  lcd.setCursor(0, 0);
  estado = readButton();
  Serial.println(estado);
  delay(50);


}
