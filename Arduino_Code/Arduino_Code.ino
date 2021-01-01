//BUTTONs
int redButton = 6;
int yellowButton = 7;
int blueButton = 8;
int greenButton = 9;

//LEDs
int redLED = 2;
int yelLED = 3;
int bluLED = 4;
int greLED = 5;
//stop button plugged into reset pin

//Button State VARs
int redButtonState = 0;
int yellowButtonState = 0;
int blueButtonState = 0;
int greenButtonState = 0;

//locked out state variables
boolean pause = false;
int secs = 50000;

void setup() {
  //Debug Serial
  Serial.begin(9600);
  
  //Button pins are inputs
  pinMode(redButton, INPUT_PULLUP);
  pinMode(yellowButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);


  //Pull up system *Fingers Crossed*
  digitalWrite(redButton, HIGH);
  digitalWrite(yellowButton, HIGH);
  digitalWrite(blueButton, HIGH);
  digitalWrite(greenButton, HIGH);

  //LED pins are outputs
  pinMode(redLED, OUTPUT);
  pinMode(yelLED, OUTPUT);
  pinMode(bluLED, OUTPUT);
  pinMode(greLED, OUTPUT);

  //initilize LEDs to Off
  digitalWrite(redLED, LOW);
  digitalWrite(yelLED, LOW);
  digitalWrite(bluLED, LOW);
  digitalWrite(greLED, LOW);
}

void loop() {
  if(pause == false){
  
    redButtonState = digitalRead(redButton);
    yellowButtonState = digitalRead(yellowButton);
    blueButtonState = digitalRead(blueButton);
    greenButtonState = digitalRead(greenButton);
    
    if (greenButtonState == LOW){
      pause = true;
      digitalWrite(greLED, HIGH);
      Serial.println("TEAM GREEN");
      delay(secs);
      digitalWrite(greLED, LOW);
      Serial.println("RESET");
      pause = false;
    }
  
    if (redButtonState == LOW){
      pause = true;
      digitalWrite(redLED, HIGH);
      Serial.println("TEAM RED");
      delay(secs);
      digitalWrite(redLED, LOW);
      Serial.println("RESET");
      pause = false;       
    }
  
    if (yellowButtonState == LOW){
      pause = true;
      digitalWrite(yelLED, HIGH);
      Serial.println("TEAM BLUE");
      delay(secs); 
      digitalWrite(yelLED, LOW);
      Serial.println("RESET");
      pause = false;
    }
  
    if (blueButtonState == LOW){
      pause = true;
      digitalWrite(bluLED, HIGH);
      Serial.println("TEAM YELLOW");
      delay(secs);
      digitalWrite(bluLED, LOW);
      Serial.println("RESET");
      pause = false;
    }

  }
}
