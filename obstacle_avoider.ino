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

#define SPEED 255  // Full aggressive speed

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  // Set full speed once
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);
}

// Motor control functions
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void hardRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void hardLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverseSpin() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void loop() {
  int leftState  = digitalRead(IR_LEFT);
  int rightState = digitalRead(IR_RIGHT);

  // BOTH CLEAR → FULL SPEED FORWARD
  if (leftState == HIGH && rightState == HIGH) {
    forward();
  }
  // LEFT OBSTACLE → HARD RIGHT TURN
  else if (leftState == LOW && rightState == HIGH) {
    hardRight();
  }
  // RIGHT OBSTACLE → HARD LEFT TURN
  else if (leftState == HIGH && rightState == LOW) {
    hardLeft();
  }
  // BOTH DETECT → INSTANT REVERSE SPIN
  else {
    reverseSpin();
  }
}
