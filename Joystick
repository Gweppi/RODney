int SW = 2;
int VRx = A0;
int VRy = A1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  int SWState = digitalRead(SW);

//  Serial.println("x:");
//  Serial.println(xPosition);
//  Serial.println("");
//
//  Serial.println("y:");
//  Serial.println(yPosition);
//  Serial.println("");

  int mapX = map(xPosition, 0, 1023, -512, 512);
  int mapY = map(yPosition, 0, 1023, -512, 512);
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SWState);

  delay(1000);
}
