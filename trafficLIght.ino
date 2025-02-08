// C++ code
//
int const green = 5;
int const yellow = 4;
int const red = 3;
long interval = 500;
unsigned long previousTime = 0;
int ledState = 0;
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  
  int buttonValue = digitalRead(9);
  Serial.println(buttonValue);
  if(buttonValue == LOW){
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  delay(3000);
    ledState = 0;
    
  }
 unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    if(ledState ==0){
    digitalWrite(green, HIGH);
    }
    else if(ledState ==1){
    digitalWrite(yellow, HIGH);
    }
    else if(ledState ==2){
    digitalWrite(red, HIGH);
    }
    
    ledState++;
    if(ledState >2){
    ledState = 0;
    }
    } 
  }
  

  
