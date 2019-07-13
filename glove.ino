int thumbFlex = A0;
int indexFlex = A1;
int middleFlex = A2;
int ringFlex = A3;
int pinkyFlex = A4;

void setup() {
  Serial.begin(9600);
  pinMode(thumbFlex, INPUT);
  pinMode(indexFlex, INPUT);
  pinMode(middleFlex, INPUT);
  pinMode(ringFlex, INPUT);
  pinMode(pinkyFlex, INPUT);
}

void loop() {
  int thumbValue = analogRead(thumbFlex);
  int indexValue = analogRead(indexFlex);
  int middleValue = analogRead(middleFlex);
  int ringValue = analogRead(ringFlex);
  int pinkyValue = analogRead(pinkyFlex);
  //Serial.println('T');
  //Serial.println(pinkyValue);

  Serial.println('T');
  int thumbAngle = map(thumbValue,480,710,0,180);
  thumbAngle = constrain(thumbAngle, 0, 180);
  Serial.println(thumbAngle);
  Serial.println('#');
  delay(50);

  Serial.println('I');
  int indexAngle = map(indexValue,570,800,0,180);
  indexAngle = constrain(indexAngle, 0, 180);
  Serial.println(indexAngle);
  Serial.println('#');
  delay(50);

  Serial.println('M');
  int middleAngle = map(middleValue,480,800,0,180);
  middleAngle = constrain(middleAngle, 0, 180);
  Serial.println(middleAngle);
  Serial.println('#');
  delay(50);

  Serial.println('R');
  int ringAngle = map(ringValue,510,760,0,180);
  ringAngle = constrain(ringAngle, 0, 180);
  Serial.println(ringAngle);
  Serial.println('#');
  delay(50);

  Serial.println('P');
  int pinkyAngle = map(pinkyValue,500,780,0,180);
  pinkyAngle = constrain(pinkyAngle, 0, 180);
  Serial.println(pinkyAngle);
  Serial.println('#');
  delay(50);
  
}
