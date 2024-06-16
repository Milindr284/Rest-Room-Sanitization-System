//COMPUTER CONTROLLED ROBOT 24/10/2016 
// LCD PINS FOR MOTOR : 7,8,9,10
#include<LiquidCrystal.h>
#include <Servo.h>
int sens1 = 0;//switch
int sens2 = 1;//ir
int RELAY1 = 2;
int RELAY2 = 3;
int RELAY3 = 4;
int RELAY4 = 5;
int mot    = 6;
Servo MG995_Servo;
//int Sensor4Pin = 3;
//PC TX = 0;
//PC RX = 1;
int rs = 7;
int enable = 8;
int d0 = 9;
int d1 = 10;
int d2 = 11;
int d3 = 12;
bool a = false;
int rows =2;
int cols =16;
LiquidCrystal lcd (7,8,9,10,11,12);

int incommingByte;

void setup() 
{
pinMode (rs,OUTPUT);
pinMode (enable,OUTPUT);
pinMode (d0,OUTPUT);
pinMode (d1,OUTPUT);
pinMode (d2,OUTPUT);
pinMode (d3,OUTPUT);
pinMode (RELAY1,OUTPUT);
pinMode (RELAY2,OUTPUT);
pinMode (RELAY3,OUTPUT);
pinMode (RELAY4,OUTPUT);
pinMode (mot,OUTPUT);
lcd.begin(cols,rows);
lcd.clear();
Serial.begin(9600);
lcd.setCursor(0,0);
lcd.print("Toilet Hygiene  ");
lcd.setCursor(0,1);
lcd.print("System");
delay(3000);
}

//----------------------------------------------------------------------------    
void loop() 
{           
 a=false;                                   
 int tempValue1 = 5.0 * analogRead(sens1)* 100.0/1024.0;
 int tempValue2 = 5.0 * analogRead(sens2)* 100.0/1024.0;
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("SW=");
  lcd.print(tempValue1);
  lcd.setCursor(8,1);
  lcd.print("IR=");
  lcd.print(tempValue2);
  lcd.setCursor(0,0);
  lcd.print("Seat Vacat");
  digitalWrite(RELAY3,LOW);
  digitalWrite(RELAY4,LOW); 
  delay(1000);
   
    if (tempValue1 < 100) //must be less than < 100 
  {
    
        lcd.clear();
        digitalWrite(RELAY3,LOW);
        digitalWrite(RELAY4,HIGH);
        lcd.setCursor(0,0);
        lcd.print("UV OFF");
        delay(15000);
        tempValue1 = 5.0 * analogRead(sens1)* 100.0/1024.0;      
              tempValue2 = 5.0 * analogRead(sens2)* 100.0/1024.0;
                while (tempValue2 < 100)
                {
                  tempValue2 = 5.0 * analogRead(sens2)* 100.0/1024.0;
                  a=true;
                  digitalWrite(RELAY3,LOW);
                  digitalWrite(RELAY4,HIGH);
                  lcd.setCursor(0,0);
                  lcd.print("PERSON IN");
                  }
                 delay(15000);// person getting out of the room 10 sec delay
                 tempValue1 = 5.0 * analogRead(sens1)* 100.0/1024.0;
                 tempValue2 = 5.0 * analogRead(sens2)* 100.0/1024.0;

            if (tempValue1 < 100) {   
              
           if (tempValue1 > 100 && tempValue2 > 150 && a==true)
              {
                
                lcd.clear();
                digitalWrite(RELAY3,LOW);
               digitalWrite(RELAY4,LOW);
               lcd.setCursor(0,0);
              lcd.print("PERSON out");
                delay(1000);
          
                      lcd.clear();
                        lcd.setCursor(0,0);
                    lcd.print("STERLIZATION..");
                    lcd.setCursor(0,1);
                    lcd.print("WAIT DONTCOME IN");
      delay(1000);
                      digitalWrite(RELAY3,HIGH);
                       digitalWrite(RELAY4,LOW);
             
                                lcd.clear();
                        lcd.setCursor(0,0);
                    lcd.print("FLUSH STARTED..");
                    lcd.setCursor(0,1);
                    lcd.print("WAIT DONTCOME IN");
                   
                    
                    Serial.println("0");// You can display on the serial the signal value
                    MG995_Servo.write(0); //Turn clockwise at high speed
                    delay(400);
                    MG995_Servo.detach();//Stop. You can use deatch function or use write(x), as x is the middle of 0-180 which is 90, but some lack of precision may change this value
                    delay(1000);
                    MG995_Servo.attach(mot);//Always use attach function after detach to re-connect your servo with the board
                    Serial.println("0");//Turn left high speed
                    MG995_Servo.write(170);
                    delay(2000);
                    MG995_Servo.detach();//Stop
                    delay(2000);
                    MG995_Servo.attach(mot);

                    
//                     analogWrite(mot, 70);
//                   delay(1000);
//                   analogWrite(mot, 250);
//                    delay(1000);
//                           analogWrite(mot, 70);
//                   delay(1000);
//                   analogWrite(mot, 250);
//                    delay(1000);
//                     analogWrite(mot, 70);
//                   delay(1000);
//                   analogWrite(mot, 250);
//                    delay(1000);

                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("FLUSH COMPLETED..");
              
                      delay(60000);//60 sec uv is on 
                       lcd.clear();
                        lcd.setCursor(0,0);
                    lcd.print("STERLIZATION..");
                  //   lcd.setCursor(0,1);
                    lcd.print("DONE");
                     digitalWrite(RELAY3,LOW);
                    digitalWrite(RELAY4,LOW); 
                   
                    
                  
//              }
        }
            }
  

      

  
  
  }
}
