//Reciever
 
int LED1 = 13;
int LED2 = 12;
char message;
// Relay pin is controlled with D8. The active wire is connected to Normally Closed and common
int relay = 8;
volatile byte relayState = LOW;
  
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // communication
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
   // Pin for relay module set as output
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    message = Serial.read();
    if(message == '1')
    {
      digitalWrite(LED1, 1);
       relayState = HIGH;  
  Serial.println("ON");
    }
    else if(message == '2')
    {
      digitalWrite(LED2, 1);
       relayState = LOW;  
  Serial.println("OFF");
    }
  }
  delay(20); // waitting message reciev
  digitalWrite(LED1, 0);
  digitalWrite(LED2, 0);
}