/*
   Created by ArduinoGetStarted.com

   This example code is in the public domain

   Tutorial page: https://arduinogetstarted.com/tutorials/communication-between-two-arduino
*/

// ARDUINO #2: TCP SERVER + AN LED
#include <SPI.h>
#include <Ethernet.h>

#include <utility/w5100.h>

byte socketStat[MAX_SOCK_NUM];
const int LED_PIN = 3;
const int RELAY_1 = 9;
const int RELAY_2 = 7;
const int RELAY_3 = 6;
const int RELAY_4 = 5;
const int BUTTON_1 = 2;
const int BUTTON_2 = 3;
const int BUTTON_3 = 4;
const int BUTTON_4 = 8;


byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};

IPAddress ip(192, 168, 1, 177);
IPAddress myDns(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);

EthernetServer TCPserver(4080);
boolean gotAMessage = false; // whether or not you got a message from the client yet
  char command;
void setup() {
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  pinMode(LED_PIN, OUTPUT);

  Serial.println("ARDUINO #2: TCP SERVER + AN LED");

  // Initialize Ethernet Shield:
  if (Ethernet.begin(mac) == 0)
    Serial.println("Failed to configure Ethernet using DHCP");
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1); // do nothing, no point running without Ethernet hardware
      }
    }
     if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // initialize the Ethernet device not using DHCP:
    Ethernet.begin(mac, ip, myDns, gateway, subnet);
  delay(1000); // add a delay here

  // Print your local IP address:
  Serial.print("TCP Server IP address: ");
  Serial.println(Ethernet.localIP());
  Serial.println("-> Please update the serverAddress in Arduino #1 code");

  // Listening for a TCP client (from Arduino #1)
  TCPserver.begin();
}

void loop() {
  EthernetClient client = TCPserver.available();

  if (client) {
    if (!gotAMessage) {
      Serial.println("We have a new client");
      client.println("Hello, client!");
      gotAMessage = true;
      command = client.read();
      Serial.println("command: ");
      Serial.print(command);
    }
  }

  // Read the command from the TCP client:
  if (gotAMessage) {
    if (command == '1') {
      digitalWrite(RELAY_3, HIGH); // Turn Switch off relay - on forn unit 1
      digitalWrite(RELAY_4, HIGH); // Turn Switch off relay - on forn unit 2
      digitalWrite(RELAY_3, LOW); // Turn Switch off relay - OFF forn unit 1
      digitalWrite(RELAY_4, LOW); // Turn Switch off relay - OFF forn unit 1
      Serial.print("- Received command: 1");
      client.println("Hello, 1!");

      //this block act as pulse
      digitalWrite(RELAY_1, HIGH); //  Turn Switch on relay - on forn unit 1
      delay(200);
      digitalWrite(RELAY_1, LOW); //  Turn Switch on relay - off forn unit 1
      
      gotAMessage = false;
    } else if (command == '2') {
      digitalWrite(RELAY_3, HIGH); // Turn Switch off relay - on forn unit 1
      digitalWrite(RELAY_4, HIGH); // Turn Switch off relay - on forn unit 2
      digitalWrite(RELAY_3, LOW); // Turn Switch off relay - OFF forn unit 1
      digitalWrite(RELAY_4, LOW); // Turn Switch off relay - OFF forn unit 1
      Serial.print("- Received command: 2");

      //this block act as pulse
      digitalWrite(RELAY_2, HIGH); //  Turn Switch on relay - on forn unit 2
      delay(200);
      digitalWrite(RELAY_2, LOW); //  Turn Switch on relay - off forn unit 2
      
      gotAMessage = false;
    }
     gotAMessage = false;
  }
}


 
