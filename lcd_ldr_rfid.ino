
#define ledPin=47;
#define Ledpin2=46;

#include <LiquidCrystal.h>
const int rs = 30, en = 12, d4 = 11, d5 = 40, d6 = 3, d7 = 42;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int const IrSensor=A1;

const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data
boolean newData = false;

#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 53
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);

const int distance=6;
const int dis2=7;

void setup() {
  lcd.begin(16, 2);

  Serial.begin(9600);        // Initialize serial communications with the PC  
 pinMode(2,OUTPUT);
 pinMode(distance,INPUT);
pinMode(47,OUTPUT);
pinMode(dis2,INPUT);
pinMode(46,OUTPUT);
SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  //Serial.println("Approximate your card to the reader...");
  //Serial.println();

  
}

void loop() {

  digitalWrite(2,HIGH);
  if (digitalRead(distance)==HIGH){
    digitalWrite(47,HIGH);
    Serial.print("1");
  }
  else{
    digitalWrite(47,LOW);
    Serial.print("0");
  }
   if(digitalRead(dis2)==HIGH){
    digitalWrite(46,HIGH);
    Serial.print("2");
   }
    else{
      digitalWrite(46,LOW);
      Serial.print("9");
    }
    Serial.println();

    //lcd.clear();
    //lcd.setCursor(0,0);
    //lcd.write("Free Slots: ");
    //while (Serial.available()>0){
    //lcd.write(Serial.read());
    //}
    delay(1000);
    
//Serial.println(analogRead(IrSensor));


    if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  //lcd.clear();
  //lcd.print("ID:");
  String content= "";
  byte letter;
  Serial.print("ID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     //lcd.setCursor(0,1);
     //lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //lcd.print(mfrc522.uid.uidByte[i], HEX);
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  lcd.clear();
  delay(1500);
    lcd.setCursor(0,0);
    //lcd.print("Hello ");
    if (Serial.available()){
      while(Serial.available()){
      lcd.write(Serial.read());
    }}
    
    delay(1000);
    
    lcd.setCursor(0,1);
    if (Serial.available()){
      while(Serial.available()){
      lcd.write(Serial.read());
    }
    }
 
 
    delay(4000);
    while(Serial.available()){Serial.read();}
    lcd.clear();
   
  
}
  
 
