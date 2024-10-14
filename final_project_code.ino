 #include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
int buzzerPin = 8; 

Servo servoMotor;
LiquidCrystal_I2C lcd(0x27, 16, 4);
// Define the GSM module pins
#define GSM_TX_PIN 10
#define GSM_RX_PIN 9

// Create a SoftwareSerial object for the GSM module
SoftwareSerial gsmSerial(GSM_TX_PIN, GSM_RX_PIN);

// Array to store the operator number
char operatorNumber[16];

// Array to store the message text
char messageText[16];

String chop = "bKash";
String cham = "10";

void setup() {
  // Start serial communication
   pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  //attach motor to a pin
  servoMotor.attach(3);
  // Set up GSM module baud rate
  gsmSerial.begin(9600);

  // Initialize GSM module
  initGSM();
  lcd.begin();
  lcd.backlight();
  display();
  servoMotor.write(0);
}

void display() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("want a kitkat?");
  lcd.setCursor(4, 1);
  lcd.print("Send 10tk to");
  lcd.setCursor(4, 3);
  lcd.print("01793425032");
}

void loop() {
  // Check if there is an incoming SMS
  if (gsmSerial.available()) {
    // Read the incoming message
    readSMS();
  }
}

void initGSM() {
  delay(2000);

  // Set GSM module to text mode
  gsmSerial.println("AT+CMGF=1");
  delay(1000);

  // Enable message notifications
  gsmSerial.println("AT+CNMI=2,2,0,0,0");
  delay(1000);

  Serial.println("GSM initialized");
}

void readSMS() {
  // Read the GSM module response
  String response = gsmSerial.readString();

  // Check if the response contains "+CMT:"
  if (response.indexOf("+CMT:") != -1) {
    // Find the start and end positions of the operator number
    int start = response.indexOf("+CMT:") + 7;
    int end = start + 5;

    // Extract the operator number
    response.substring(start, end).toCharArray(operatorNumber, sizeof(operatorNumber));

    // Find the start and end positions of the message text
    start = response.indexOf("You") + 21;
    end = response.indexOf("from") - 4;

    // Extract the message text
    response.substring(start, end).toCharArray(messageText, sizeof(messageText));
    if (String(operatorNumber) == chop) {
      if (String(messageText) == cham) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Thank you");
        lcd.setCursor(8, 1);
        lcd.print("for");
        lcd.setCursor(2, 2);
        lcd.print("your purchase");
        delay(1000);
        //Serial.println("Thank god");
        for (int pos = 90; pos <= 180; pos++) {
          servoMotor.write(pos-7);
          delay(2);  // Adjust the delay time to control the speed of rotation
        }
        delay(1000);
        for (int pos = 180; pos >= 90; pos--) {
          servoMotor.write(pos-7);
          delay(2);  // Adjust the delay time to control the speed of rotation
        }
        tone(buzzerPin, 1260);
        delay(4000);
        noTone(buzzerPin);
        delay(200);
        lcd.clear();
        display();
      } else {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Insufficient");
        lcd.setCursor(5,2);
        lcd.print("Amount");
        delay(4000);
        lcd.clear();
        display();
      }
    } else {
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print("Trying to scam :(");
    }
    Serial.println("Operator Number: " + String(operatorNumber));
    Serial.println("Message Text: " + String(messageText));
    servoMotor.write(0);
  }
}
