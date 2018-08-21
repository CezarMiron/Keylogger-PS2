#include <PS2Keyboard.h> // https://playground.arduino.cc/Main/PS2Keyboard
#include <SD.h>

const int DataPin = 3; 
const int IRQpin =  2;  
const int chipSelect = 10;
File myFile; 

PS2Keyboard keyboard;

void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);  


  keyboard.begin(DataPin, IRQpin);                                                
  Serial.println("Keyboard Test:");

}

void loop()
{
  if(keyboard.available())
  {
    char c = keyboard.read();
    Serial.print(c);
    
    while(!(myFile = SD.open("new.txt", FILE_WRITE))); 

    myFile.print(c);
    myFile.close();
    
  }  

  else;
   
}

