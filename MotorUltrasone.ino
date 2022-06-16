#include <AFMotor.h>
#include <NewPing.h>

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR12_64KHZ);
AF_DCMotor motor4(4, MOTOR12_64KHZ);

NewPing sonar (9, 10, 1000);

int wasTurning = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setMotorSpeed(200);
  forward();
  delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:

  int distance = sonar.ping_cm();
  if (distance == 0) {
    if (wasTurning == 1) {
      turnLeft();
      delay(1000);
      wasTurning = 0;
    }
    
    Serial.println("DRIVE 0");
    Serial.println(distance);
    forward();
    setMotorSpeed(200);
    
  } else if (distance > 15) {

    if (wasTurning == 1) {
      turnLeft();
      delay(1000);
      wasTurning = 0;
    }
    
    Serial.println("DRIVE 10");
    Serial.println(distance);
    forward();
    setMotorSpeed(200);
    
  } else {
    wasTurning = 1;
    Serial.println("TURN");
    Serial.println(distance);
    turnLeft();
  }

  delay(100);
}

void setMotorSpeed(int speed) {

  int motorOffset = 35;
  
  motor1.setSpeed(speed);
  motor2.setSpeed(speed - motorOffset);
  motor3.setSpeed(speed - motorOffset);
  motor4.setSpeed(speed);
}

void stopMotors() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
}

void backward() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void forward() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void turnLeft() {
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
}

void turnRight() {
  motor1.run(FORWARD);
  motor4.run(BACKWARD);

  delay(5000);

  motor1.run(BACKWARD);
  motor4.run(FORWARD);
}
