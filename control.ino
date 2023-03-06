// Transmitter

int Button1 = 6;
int Button2 = 2;
char message;

int relay = 7;
int relay2 = 4;



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // for communication
  pinMode(Button1, INPUT_PULLUP); // for read button
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.println("hi");
  pinMode(relay, OUTPUT);

  pinMode(relay2, OUTPUT);

}

void loop() {

  // put your main code here, to run repeatedly:
  if (digitalRead(Button1) == 0)
  {

Serial.println( '1' );
Serial.write('1');

    delay(50);
  }
  else if (digitalRead(Button2) == 0)
  {

  }
  if (Serial.available())
  {
    message = Serial.read();
   // Serial.println(message);
    switch (message) {
      case '1':
        // statements
        digitalWrite(relay, HIGH);
        Serial.println("Relay 1 On");
        delay(200);
        digitalWrite(relay, LOW);
        Serial.println("Relay 1 off");
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);

        break;
      case '2':
        // statements
        digitalWrite(relay2, HIGH);
        Serial.println("Relay 2 On");
        delay(200);
        digitalWrite(relay2, LOW);
        Serial.println("Relay 2 off");
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);

        break;
         case '3':
        // statements
        digitalWrite(relay2, HIGH);
        Serial.println("Relay 3 On");
        delay(200);
        digitalWrite(relay2, LOW);
        Serial.println("Relay 3 off");
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);

        break;
         case '4':
        // statements
        digitalWrite(relay2, HIGH);
        Serial.println("Relay 4 On");
        delay(200);
        digitalWrite(relay2, LOW);
        Serial.println("Relay 4 off");
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);

        break;
      default:
        // statements

        break;
    }

  }

  delay(200); // waitting message send
}
