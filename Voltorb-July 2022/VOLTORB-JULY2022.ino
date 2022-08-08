#include<Servo.h>
Servo servo;
void setup() {
  // put your setup code here, to run once:
  servo.attach(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(A0) >= 1) {
    int d = 1 / analogRead(A0);
    servo.write(90);
    delay(d);
    servo.write(0);
    delay(d);
  }
}
