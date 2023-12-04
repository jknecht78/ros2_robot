struct Motor {
    int channel1;
    int channel2;
    int speed;
};
  
Motor motor_front_left;
Motor motor_front_right;
Motor motor_rear_left;
Motor motor_rear_right;

void setup() {  

  motor_front_left.channel1 = 8;
  motor_front_left.channel2 = 9;
  motor_front_left.speed = 10;

  motor_front_right.channel1 = 13;
  motor_front_right.channel2 = 12;
  motor_front_right.speed = 11;

  motor_rear_left.channel1 = 5;
  motor_rear_left.channel2 = 7;
  motor_rear_left.speed = 6;

  motor_rear_right.channel1 = 2;
  motor_rear_right.channel2 = 4;
  motor_rear_right.speed = 3;


  pinMode(motor_front_left.channel1, OUTPUT);
  pinMode(motor_front_left.channel2, OUTPUT);
  pinMode(motor_front_left.speed, OUTPUT);

  pinMode(motor_front_right.channel1, OUTPUT);
  pinMode(motor_front_right.channel2, OUTPUT);
  pinMode(motor_front_right.speed, OUTPUT); 

  pinMode(motor_rear_left.channel1, OUTPUT);
  pinMode(motor_rear_left.channel2, OUTPUT);
  pinMode(motor_rear_left.speed, OUTPUT);

  pinMode(motor_rear_right.channel1, OUTPUT);
  pinMode(motor_rear_right.channel2, OUTPUT);
  pinMode(motor_rear_right.speed, OUTPUT); 

  Serial.begin(96000);
}

void adjust_speed(int speed) {
  analogWrite(motor_front_left.speed, speed);
  analogWrite(motor_front_right.speed, speed);
  analogWrite(motor_rear_left.speed, speed);
  analogWrite(motor_rear_right.speed, speed); 
}

void stop() {
  adjust_speed(0); 
  digitalWrite(motor_front_left.channel1, LOW);
  digitalWrite(motor_front_left.channel2, LOW);

  digitalWrite(motor_front_right.channel1, LOW);
  digitalWrite(motor_front_right.channel2, LOW);

  digitalWrite(motor_rear_left.channel1, LOW);
  digitalWrite(motor_rear_left.channel2, LOW);

  digitalWrite(motor_rear_right.channel1, LOW);
  digitalWrite(motor_rear_right.channel2, LOW);  
  delay(10);
}

void forward(int speed) {
  stop();

  digitalWrite(motor_front_left.channel1, HIGH);
  digitalWrite(motor_front_left.channel2, LOW);

  digitalWrite(motor_front_right.channel1, HIGH);
  digitalWrite(motor_front_right.channel2, LOW);

  digitalWrite(motor_rear_left.channel1, HIGH);
  digitalWrite(motor_rear_left.channel2, LOW);

  digitalWrite(motor_rear_right.channel1, HIGH);
  digitalWrite(motor_rear_right.channel2, LOW);

  delay(10);
  adjust_speed(100); 
}

void backward(int speed) {
  stop();

  digitalWrite(motor_front_left.channel1, HIGH);
  digitalWrite(motor_front_left.channel2, LOW);

  digitalWrite(motor_front_right.channel1, HIGH);
  digitalWrite(motor_front_right.channel2, LOW);

  digitalWrite(motor_rear_left.channel1, HIGH);
  digitalWrite(motor_rear_left.channel2, LOW);

  digitalWrite(motor_rear_right.channel1, HIGH);
  digitalWrite(motor_rear_right.channel2, LOW);

  delay(10);
  adjust_speed(100); 
}

void loop() {
  int speed = 100;

  forward(speed);
  delay(1000);
  backward(speed);
  delay(1000);
}
