/*
 * Carl Rover
 * Autonomous Arduino Sketch
 *
 * Steve Rayner Makes
 * 31st Aug 2024
 */

int L298_EN_A =  6; // pwm
int L298_IN_2 =  7;
int L298_IN_1 =  8;
int L298_EN_B = 10; // pwm
int L298_IN_4 = 11;
int L298_IN_3 = 12;

int SPEED_FULL = 255;
int SPEED_HALF = 127;

void setup()
{
  // Configure motor control pins
  pinMode(L298_IN_1, OUTPUT);
  pinMode(L298_IN_2, OUTPUT);
  pinMode(L298_IN_3, OUTPUT);
  pinMode(L298_IN_4, OUTPUT);
  pinMode(L298_EN_A, OUTPUT);
  pinMode(L298_EN_B, OUTPUT);

  // Initial start up delay
  halt();
  delay(3000);
}

void loop()
{
  forward(SPEED_HALF, 2000);
  halt();
  delay(1000);

  reverse(SPEED_HALF, 2000);
  halt();
  delay(1000);

  forward(SPEED_FULL, 2000);
  halt();
  delay(1000);
  
  reverse(SPEED_FULL, 2000);
  halt();
  delay(1000);
}

void forward(int velocity, int time)
{
  // Left motor forward
  digitalWrite(L298_IN_1, LOW);
  digitalWrite(L298_IN_2, HIGH);

  // Right motor forward
  digitalWrite(L298_IN_3, LOW);
  digitalWrite(L298_IN_4, HIGH);

  // Enable motors
  analogWrite(L298_EN_A, velocity);
  analogWrite(L298_EN_B, velocity);

  delay(time);
}

void reverse(int velocity, int time)
{
  // Left motors reverse
  digitalWrite(L298_IN_1, HIGH);
  digitalWrite(L298_IN_2, LOW);

  // Right motors reverse
  digitalWrite(L298_IN_3, HIGH);
  digitalWrite(L298_IN_4, LOW);

  // Enable all motors
  analogWrite(L298_EN_A, velocity);
  analogWrite(L298_EN_B, velocity);

  delay(time);
}

void halt()
{
  // Stop left motors
  digitalWrite(L298_IN_1, LOW);
  digitalWrite(L298_IN_2, LOW);

  // Stop right motors
  digitalWrite(L298_IN_3, LOW);
  digitalWrite(L298_IN_4, LOW);

  // Breaking on both sides
  analogWrite(L298_EN_A, 255);  
  analogWrite(L298_EN_B, 255);
}