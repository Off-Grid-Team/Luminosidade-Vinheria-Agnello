// C++ code
//

int green = 5;
int yellow = 2;
int red = 3;
int buzz = 4;
int photo = A0;
int lightValue = 100;

int lowThreshold = 226;
int midThreshold = 452;

bool buzzerSounded;

void setup()
{
  pinMode(green, OUTPUT);
  pinMode (yellow, OUTPUT);
  pinMode (red, OUTPUT);
  pinMode (buzz, OUTPUT);
  pinMode (photo, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  lightValue = analogRead(photo);
  
  Serial.print("Light level: ");
  Serial.println(lightValue);
  
  if (lightValue < lowThreshold){
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }
  else if (lightValue < midThreshold){
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
  }
  else {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    if (!buzzerSounded){
    	buzzer();
    }
  }
}

void buzzer(){
  buzzerSounded = true;
  digitalWrite(buzz, HIGH);
  delay(3000);
  digitalWrite(buzz, LOW);
  delay(3000);
  buzzerSounded = false;
  }