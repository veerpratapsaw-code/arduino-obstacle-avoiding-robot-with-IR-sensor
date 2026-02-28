// Motor Pins
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5
#define ENB 6

// IR Sensor Pins
#define IR_LEFT 2
#define IR_RIGHT 3

int speedLeft = 200; // you can change this from 0 to 255 (8bit) to change the speed and torque of the car by changing the voltage.   Note:- this changes voltage so if speed increses then also torque increses not like gear system in real vehicles 
int speedRight = 200;

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  Serial.begin(9600);
}

void loop() {

  int leftState = digitalRead(IR_LEFT);
  int rightState = digitalRead(IR_RIGHT);

  Serial.print("Left: ");
  Serial.print(leftState);
  Serial.print(" | Right: ");
  Serial.println(rightState);

  // If no obstacle
  if (leftState == HIGH && rightState == HIGH) {
    moveForward();
  }

  // Obstacle on left
  else if (leftState == LOW && rightState == HIGH) {
    turnRight();
  }

  // Obstacle on right
  else if (leftState == HIGH && rightState == LOW) {
    turnLeft();
  }

  // Obstacle on both sides
  else {
    moveBackward();
    delay(400);
    turnRight();
    delay(400);
  }

  delay(50);
}

void moveForward() {
  analogWrite(ENA, speedLeft);
  analogWrite(ENB, speedRight);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  analogWrite(ENA, speedLeft);
  analogWrite(ENB, speedRight);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  analogWrite(ENA, speedLeft);
  analogWrite(ENB, speedRight);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, speedLeft);
  analogWrite(ENB, speedRight);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
