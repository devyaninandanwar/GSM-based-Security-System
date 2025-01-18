#include <Keypad.h>
#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial SIM900(2, 13); 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 0; 
int x=0;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define Password_Length 5 

int signalPin = 12;

char Data[Password_Length]; 
char Master[Password_Length] = "1234"; 
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;
int pos = 0;  

void setup(){
  SIM900.begin(2400);
  pinMode(A5, OUTPUT);
  digitalWrite(A5, LOW);
    Serial.begin(9600);
 Serial.println("Enter Password:");
  servo_test.attach(11);      // attach the signal pin of servo to pin9 of arduino
}

void loop(){
 Serial.println("Enter Password:");
 customKey = keypad.getKey();
  if (customKey){
    Data[data_count] = customKey; 
    data_count++; 
    }

  if(data_count == Password_Length-1){
    if(!strcmp(Data, Master)){
      Serial.println("Correct");
       for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(1000);
  
  for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 
    delay(1000);
      x=0;
      }
    else{
      Serial.println("Incorrect");
      Serial.println("Entered wrong text 1");
       digitalWrite(A5, HIGH);
       delay(1000);
       digitalWrite(A5, LOW);
      x=x+1;
      if(x==3)
      {
        SendMessage();
        Serial.println("Entered wrong text thrice");
        }
      delay(1000);
      }
    clearData();  
  }
}

void clearData(){
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  return;
}
 void SendMessage()
{
  Serial.println("Sending Msg");
SIM900.println("ATD + +919229285100;"); // Enter mobile number here to call
Serial.println("ATD + +919229285100;");
delay(100);
SIM900.println();
delay(3000); // wait for 30 seconds...
SIM900.println("ATH"); // disconnect after 30 second
Serial.println("ATH");
Serial.println("Message sent");
Serial.println("Not Safe");

}
