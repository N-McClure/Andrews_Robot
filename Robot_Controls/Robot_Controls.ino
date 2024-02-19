 //Pin Connections:

//The Ultra-Sonic Sensor:
int trigPin = 10;
int echoPin = 11;

//The L.E.D's:
int redLED = 4;
int greenLED = 3;

//The Buzzer:
int buzzerPin = 5;

//Distance and Duration:
int distance;
long duration;

//Motor Driver:

//Motor_1:
int in1 = 9;
int in2 = 8;
//Motor_2:
int in3 = 7;
int in4 = 6;

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  //Sending out and Receiving UltraSonic Waves:
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  
  //Duration Calculation:
  duration = pulseIn(echoPin, HIGH);

  //Distance Calculation:
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  
  if(distance <= 5){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    //Turn Off Motor 1:
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    //Turn Off Motor 2:
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }else{
    digitalWrite(buzzerPin, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    //Turn On Motor 1:
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    //Turn On Motor 2:
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  delay(500);
}
