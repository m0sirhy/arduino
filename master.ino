// Transmitter

int Button1 = 13;
int Button2 = 12;

void setup() {
// put your setup code here, to run once:

  Serial.begin(9600); // for communication
  pinMode(Button1, INPUT_PULLUP); // for read button
  pinMode(Button2, INPUT_PULLUP); // for read button



}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(Button1) == 0)
  {
    Serial.write('1');
    Serial.println("Relay On")
  }
  else if(digitalRead(Button2) == 0)
  {
    Serial.write('2');
        Serial.println("Relay Off")

  }
  delay(20); // waitting message send
}