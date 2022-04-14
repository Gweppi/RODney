int led = 13;
int obstacle = 2;
int isObstacle = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(obstacle, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  isObstacle = digitalRead(obstacle);
  if (isObstacle == LOW){
    Serial.println("Stop");
    digitalWrite(led, HIGH);
  } else {
    Serial.println("Clear");
    digitalWrite(led, LOW);
  }
  delay(1000);
}
