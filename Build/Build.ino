/*Name: Daidipya Nayan Jadhav.
//Student i'd: 200428280.

//Name: Drashti Patel.
//student i'd: 200442218.
//Lie detector test.


 * Materials Required.
 * 1. Arduino uno - 1
 * 2. Breadboard - 1
 * 3. 560 Ohm Resistors
 * 4. Red led.
 * 5. Green led.
 * 6. white led.
 * 7. Piezo speaker.
 * 8. Led screen.
 * 9. Potentiometer.
 * 
 * The circuit.
 * 
 * 1. At first we will take all the required materials for constructing the circuit and will keep it aside.
 * 2. First of all, we will connect three leds that is red, white and green in the order .
 * 3. Then we will connect 560 ohm resitor to the led and will connect one leg of resistor to led and 
 *    another to the ground.
 * 4. We will take jumper wires and then will connect positive leg of led to the pins 9,10 and 11 respectively.   
 * 5. So here we will be done with our led set up.
 * 6. Now we will connect an lcd screen; so take one 16*2 lcd screen and connect anywhere in he srduino,
 *    now we have to follow some steps and connect wires with lcd.
 * 7. Now we will connect pin 1 of lcd to ground; now connect pin 2 of lcd to 5 volt.
 * 8. Connect the 3 pin of lcd to the potentiometer(we will first connect potentiometer with lcd so we can do some fluctuations and get the output).
 * 9. Now connect 4 pin of lcd to pin 2 on arduino then 5 pin of lcd to ground and the 6 pin of lcd to the pin 3 of arduino.
 * 10.Now will directly jump to the pin 16 of lcd and will connect pin 16 of lcd to the ground.
 * 11.After that we will connect pin 15 with 560 ohm resistor and one pin of resistor will go to pin 15 and another leg to the 5v.
 * 12.After that will connect pin 14,13,12 and 11 of the lcd to the pin 3,4,5 and 6 of the arduino respectively.
 * 13.Now we will connect a piezo speaker to the breadboard and one leg of it will go to the pin 13 of arduino and another leg will  
 *    go to ground.
 * 14.Now we have almost completed the circuit but we will check it once by uploading it to the arduino and we will set the potentiometer 
 *    as we can get the result printed on the lcd screen.
 * 15.Now we will connect the wire which we have connected to potentiometer with the lcd so that will get it printed on lcd.
 * 16.Atlast connect one wire to ground and another wire to the lcd and resistor and then attach a coil to it and will check 
 *    the reading we get by the hand. 
 * 
 */

//included necessary header files.

#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,7,6,5,4);   //LiquidCrystal lcd declared and the pin numbers are given.
int piezoPin =13;                 //int var piezopin is declared and is assigned 13.

//void setup
void setup()
{
  lcd.begin(16,2);               //lcd.begin(16,2) 16,2 describes 16*2 lcd.
  Serial.begin(9600);            //serial.begin starts printing on serial monitor/ploter.
  pinMode(9,OUTPUT);             //pin 9 to output.
  pinMode(10,OUTPUT);            //pin 10 to output.
  pinMode(11,OUTPUT);            //pin 11 to output.
  pinMode(13,OUTPUT);
  digitalWrite(9,HIGH);          //while setup we will digitalwrite 9 to HIGH .
  delay(500);                    //delay.
  digitalWrite(10,HIGH);         //digitalwrite 10 to HIGH.
  delay(500);                    //delay.
  digitalWrite(11,HIGH);         //digitalwrite 11 to high.
  delay(500);                    //delay.
 lcd.print(analogRead(A0));      //lcd.print analogRead A0 will be printed.
}

void loop()                      //loop starts.
{
  if(analogRead(A0)<50)         //if statement is used,that if analogRead(A0) reading is less then 50 then. 
  {
    digitalWrite(11,HIGH);              //digitalwrite 11 high.
    delay(500);                         //delay 500.
    digitalWrite(10,LOW);               //digitalWrite 10 low
    delay(500);                        //delay.
    digitalWrite(9,LOW);               //digitalwrite 9 low
    delay(500);                       //delay
    noTone(piezoPin);                //noTone does that no sound will be produce during this loop
    lcd.print("You are right");     //statement will be output in the lcd.
    delay(500);                     //delay
  }
  else                             //else will go through this
  {
     digitalWrite(11,LOW);        //digitalwrite 11 low.
  }
  if(analogRead(A0)>50)          //if analogread a0 > 50 the will go through this loop.
  {
     digitalWrite(9,HIGH);        //digitalwrite 9 high.
     delay(500);                 //delay
     digitalWrite(10,LOW);        //digitalwrite 10 low.
     digitalWrite(11,LOW);       //digitalwrite 11 low.
     tone(piezoPin,1000);        //if you are wrong piezo speaker will start buzzing.
    lcd.print("You are wrong");  //statement output on the screen.
    delay(500);
  }
  else                          //else will go through this.
  {
     digitalWrite(9,LOW);       //digitalwrite 9 low.
  }
  if(analogRead(A0)==50)         //if analogread a0 is greater then 90.
  {
     digitalWrite(10,HIGH);    //digitalwrite 10 high.
     digitalWrite(9,LOW);      //digitalwrite 9 low.
     digitalWrite(11,LOW);     //digitalwrite 11 low.
     tone(piezoPin,LOW);
     
  }
  else                        //else will go through this loop
  {
     digitalWrite(10,LOW);   //digitalwrite 10 low.
  }
  Serial.println(analogRead(A0));     //print to monitor
  delay(80);                         //delay
}

//end of the program.
