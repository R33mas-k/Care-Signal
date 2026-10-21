//////////////////////////////////////////////////////////////////////////////////

//led pins
int RedLED = 2;
int GreenLED = 3;

//buttons pins
int btn_food = 4;
int btn_bath = 5;
int btn_help = 6;

// ir snensor and ldr pin and threshold ( can be changed when see the value on serial monitor )
int IR_Sensor = 7;
int LDRPin = A0;
int lightThreshold = 450;

//////////////////////////////////////////////////////////////////////////////////////
#include <SoftwareSerial.h>
SoftwareSerial sim(8, 9);  // gsm tx to 8 , gsm rx to 9
String recipientNumber= "+966500000000";  // replace with the caregiver's phone number

void setup() {
  
  Serial.begin(9600);

  //gsm config
  sim.begin(9600);

  //led as output
  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);

  //buttons as input
  pinMode(btn_food, INPUT);
  pinMode(btn_bath, INPUT);
  pinMode(btn_help, INPUT);

  //ir as input
  pinMode(IR_Sensor, INPUT);
}

void loop() {
  // light detect and red led on/off
  int lightLevel = analogRead(LDRPin);
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  if (lightLevel < lightThreshold) {
    digitalWrite(RedLED, HIGH);
    Serial.println("Low light detected - Red LED ON");
  } else {
    digitalWrite(RedLED, LOW);
  }
  //////////////////////////////////////////////////////////////////////////////////

  //read buttons and send msg
  int btn_food_read = digitalRead(btn_food);
  int btn_bath_read = digitalRead(btn_bath);
  int btn_help_read = digitalRead(btn_help);

  if (btn_food_read == HIGH) {
    Serial.println("btn_food_read Activated");
    send_sms("I Need food !");
      // green led after sending msg
    digitalWrite(GreenLED, HIGH);
    delay(2000);
    digitalWrite(GreenLED, LOW);
  }
  if (btn_bath_read == HIGH) {
    Serial.println("btn_bath_read Activated");
    send_sms("I Need Bath !");
      // green led after sending msg
    digitalWrite(GreenLED, HIGH);
    delay(2000);
    digitalWrite(GreenLED, LOW);
  }
  if (btn_help_read == HIGH) {
    Serial.println("btn_help_read Activated");
    delay(500);
    send_sms("I Need Help !");
      // green led after sending msg
    digitalWrite(GreenLED, HIGH);
    delay(2000);
    digitalWrite(GreenLED, LOW);
  }

  //////////////////////////////////////////////////////////////////////////////////

  //read ir sos
  int irState = !digitalRead(IR_Sensor);
  Serial.print("IR Sensor State: ");
  Serial.println(irState);

  if (irState == HIGH) {
    Serial.println("IR Sensor Triggered");
    send_sms("I need Help!!!");
    delay(500);
     // green led after sending msg
    digitalWrite(GreenLED, HIGH);
    delay(2000);
    digitalWrite(GreenLED, LOW);
  }
  
  delay(1000);
}


void send_sms(String msg) {

  Serial.print(">>>>>> send sms >>>>>> : ");
  Serial.print("Number: ");
  Serial.print(recipientNumber);
  Serial.print("  msg: ");
  Serial.println(msg);

  sim.println("AT+CMGF=1");
  delay(500);
  sim.println("AT+CMGS=\"" + recipientNumber + "\"\r");
  delay(500);
  sim.println(msg);
  delay(500);
  sim.println((char)26);

  // green led after sending msg
  digitalWrite(GreenLED, HIGH);
  delay(2000);
  digitalWrite(GreenLED, LOW);
}
