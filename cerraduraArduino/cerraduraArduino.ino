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
int banderaTitulo = 0;
int posicion = 0;
int cantAciertos =0;
int password[4] = {
0,
1,
2,
3,
};




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


byte robot[8]= {
B00000,
B01010,
B01010,
B01010,
B00000,
B10001,
B01110,
B00000
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

  lcd.createChar(6, right);
  lcd.createChar(7, down);
  lcd.createChar(8, up);
  lcd.createChar(9, left);
  lcd.createChar(10, robot);

 
  analogWrite(A5, 0);

}


void loop()
{
 lcd.setCursor(1, 0);
  
  
  if(cantAciertos == 4){
  
  	analogWrite(A5, 1);
     lcd.setCursor(2,0);
    lcd.print("INGRESE");
    
    lcd.setCursor(6,1);
  	lcd.write((byte)10); 
    delay(1000);
    cantAciertos = 0;
  
  }else{
  
  if(banderaTitulo == 0){
    lcd.print("INGRESE CODIGO");
  }
 	estado = readButton();

  
  if (estado != 5 && estado != 4) {
    
    if(posicion == 0){
      lcd.clear();
    }
    if(posicion == 4){
    
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("ERROR");
     posicion = 0;
     banderaTitulo = 0;
     delay(300);
     
    }else{
      
    posicion = setPosicion(posicion);
    
    mostrarEstados(estado, posicion);
   
    banderaTitulo = 1;
    
    }
    
    delay(50);
  }
  
  
  }
  
    
}


int mostrarEstados(int estado1, int posicion) {
      lcd.setCursor(posicion, 0);
  if (estado1 == BTN_RIGHT)

    lcd.write((byte)6);
  
  if (estado1 == BTN_DOWN)
    
    lcd.write((byte)7);
 
  if (estado1 == BTN_UP)
  
    lcd.write((byte)8);
  
  if (estado1 == BTN_LEFT)
  
    lcd.write((byte)9);
 

}


int setPosicion(int posicionAnterior){

  if(posicionAnterior == 0)
    return 1;
  if(posicionAnterior == 1)
    return 2;
  if(posicionAnterior == 2)
    return 3;
  if(posicionAnterior == 3)
    return 4;

}