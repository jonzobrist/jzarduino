//set a timer, relay pins, sensor pins, max delay
unsigned int timer = 100;
unsigned int minute = 15000;
unsigned int ledPin = 10;
unsigned int lightSwitch1 = 0;
//unsigned int lightSwitch2 = 5;
unsigned int pirPin = 4;
unsigned int motionDetect = 0;
unsigned int calibrationTime = 30;        
unsigned long counter = 60000;
unsigned long maxTime = 300000;

void setup()
{
  pinMode(lightSwitch1, OUTPUT);
  digitalWrite(lightSwitch1, HIGH);
//  pinMode(lightSwitch2, OUTPUT);
//  digitalWrite(lightSwitch2, HIGH);
  pinMode(ledPin, OUTPUT);     
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
  
  //give the sensor some time to calibrate
  Serial.println("Sensor Calibration in Progress");
  Serial.println("------------------------------");
  for(int i = 0; i < calibrationTime; i++){
    Serial.println(i);
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  }
}

void loop()
{
 delay(timer);
 counter = (counter - timer);
 if (counter > maxTime)
   {
     counter = maxTime;
     Serial.print("max time reached : ");
     Serial.println(counter);
   }
  motionDetect = digitalRead(pirPin);
  if (motionDetect == HIGH)
     {
      counter = (counter + minute);
      Serial.print("timer up : ");
      Serial.println(counter);
     }
     else
     {
      Serial.print("timer down : ");
      Serial.println(counter);
     }
//      Serial.println("timer is" + counter + "\r\n");
     Serial.print("timer is ");
     Serial.println (counter);
     if (counter > minute)
     {
       digitalWrite(lightSwitch1, LOW);
    //   counter = (counter - timer);
     }
     else
     {
       digitalWrite(lightSwitch1, HIGH);
       counter = minute;
     }
}
