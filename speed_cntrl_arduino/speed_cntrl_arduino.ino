int mtr_1 = 6; 
int mtr_2 = 5; 
int pot_pin = A0;
int ENA = 9;

int output;
int pwm_value;

void setup() {
  pinMode(pot_pin, INPUT);
  pinMode(mtr_1, OUTPUT);
  pinMode(mtr_2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
  //Reading from potentiometer
  digitalWrite( ENA, HIGH);
  digitalWrite( mtr_2, LOW);
  output = analogRead(pot_pin);
  //Mapping the Values between 0 to 255 because we can give output
  //from 0 -255 using the analogwrite funtion
  pwm_value = map(output, 0, 1023, 0, 255);
  analogWrite(mtr_1, pwm_value);
  delay(1);
}
