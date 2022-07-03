
const int BUILTIN_LED = 2;

bool toggleBlink = true;
int blinkDelay = 1000;


void setup() {
  Serial.begin(115200);
  pinMode(BUILTIN_LED, OUTPUT);

    Serial.println("--------------------------------------------------------------------------");
    Serial.println("To turn ON the led type \"on\"");
    Serial.println("To turn OFF the led type \"off\"");
    Serial.println("To control the blinking delay type \"delay\" then hit space, then choose a number from 1 to 999");
    Serial.println("For example type \"delay 500\" to make blink delay 500ms ");
     Serial.println("--------------------------------------------------------------------------");
  
}


void loop() {

    if(Serial.available() > 0){
        String incomingString = Serial.readString();
      if(incomingString.startsWith("on")){
        Serial.println("Turning ON LED");
        toggleBlink = true;
      }
      else if(incomingString.startsWith("off")){
        Serial.println("Turning OFF LED");
        toggleBlink = false;
      }
      else if(incomingString.startsWith("delay")){
       blinkDelay = incomingString.substring(6, 9).toInt();
          Serial.println(incomingString);
        }
    
    }


  if(toggleBlink){
  digitalWrite(BUILTIN_LED, HIGH);   
  delay(blinkDelay);                       
  digitalWrite(BUILTIN_LED, LOW);    
  delay(blinkDelay);               
  }     


    
}
