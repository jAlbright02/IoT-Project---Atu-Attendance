#include <Tone32.h>
#include <tagIn.h> //library made by myself for this project to handle repetitive tasks
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <SPI.h>
#include <MFRC522.h>
#include <vector>
#include <iostream>
#include "page1.h"

#define SS_PIN  5  // ESP32 pin 5 
#define RST_PIN 27 // ESP32 pin 27
#define IRQ_PIN 25 //Interrupt pin on RC522
#define LED 32
#define BUZZ 21

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

MFRC522::MIFARE_Key key; //Creates instance to store and use MIFARE cards

tagIn tagin;
checkTagged checktagged;

volatile bool bNewInt = false;
byte regVal = 0x7F;
void activateRec(MFRC522 mfrc522);
void clearInt(MFRC522 mfrc522);

const char tagJ[8] = "33b53ac";
const char tagC[9] = "6ca3be2a";
const char tagP[9] = "b3bb6bad";
const char tagM[9] = "d39a7692";

std::vector<String> tagList = {"33b53ac", "6ca3be2a", "b3bb6bad", "d39a7692"};
std::vector<String> nameList = {"James", "Ciara", "Patrick", "Mark"};
std::vector<String>::iterator it;

String tag;
bool tagged = true;
bool tagged2 = true;
bool tagged3 = true;
bool tagged4 = true;
int var;

const char* ssid = "OnePlus 7";
const char* password = "12345678";

String inP = "0";
String inM = "0";
String inJ = "0";
String inC = "0";

WebServer server(80);

void setup(void) {

  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);

  //RFID set up
  SPI.begin(); // init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card
  pinMode(IRQ_PIN, INPUT_PULLUP); //setup the IRQ pin

  regVal = 0xA0; //rx irq
  mfrc522.PCD_WriteRegister(mfrc522.ComIEnReg, regVal); //enables rx irq interrupt on rfid module

  bNewInt = false; //interrupt flag

  /*Activate the interrupt*/
  attachInterrupt(digitalPinToInterrupt(IRQ_PIN), readCard, FALLING);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/reset", handleResetString);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks

  /*reads interrupt, reads tag data and stores in str var, clears pending bits,
    then finally stops communication and resets interrupt bool*/
  if (bNewInt) { //new read interrupt
    mfrc522.PICC_ReadCardSerial(); //read the tag data
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    clearInt(mfrc522);
    mfrc522.PICC_HaltA(); //stops communication with current card
    bNewInt = false;

    digitalWrite(LED, HIGH);
    tone(BUZZ, NOTE_B4, 1000, 0);
    delay(500);
    noTone(BUZZ, 0);
    digitalWrite(LED, LOW);

    //Algorithm to sort through known tags and compare it to the tag currently being read
    it = std::find (tagList.begin(), tagList.end(), tag);
    if (it != tagList.end()) {
      Serial.println("Found tag");
      Serial.print("Element ");
      Serial.print(tag);
      Serial.print(" found position : ");
      Serial.println(distance(tagList.begin(), it));

      var = it - tagList.begin();

      checktagged.checkTags(inP, tagged); //we check to see if this tag has been used already
      inP = tagin.tagInAll(tag, tagP, tagged); //sets inP string to "1", if tagged != false and tag == tagP

      checktagged.checkTags(inM, tagged2);
      inM = tagin.tagInAll(tag, tagM, tagged2);

      checktagged.checkTags(inJ, tagged3);
      inJ = tagin.tagInAll(tag, tagJ, tagged3);

      checktagged.checkTags(inC, tagged4);
      inC = tagin.tagInAll(tag, tagC, tagged4);

      
    }

    else {
      Serial.println("No tag found");
    }

    Serial.print("Tag owner: ");
    Serial.println(nameList.at(var));

  }
  activateRec(mfrc522);

  tag = "";

}

//Helper routine to dump a byte array as hex, which is then converted to a string and stored.
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    tag += String(buffer[i], HEX);
  }
}

//MFRC522 interrupt serving routine
void readCard() {
  bNewInt = true;
}

//The function sending to the MFRC522 the needed commands to activate the reception
void activateRec(MFRC522 mfrc522) {
  mfrc522.PCD_WriteRegister(mfrc522.FIFODataReg, mfrc522.PICC_CMD_REQA);
  mfrc522.PCD_WriteRegister(mfrc522.CommandReg, mfrc522.PCD_Transceive);
  mfrc522.PCD_WriteRegister(mfrc522.BitFramingReg, 0x87);
}

//The function to clear the pending interrupt bits after interrupt serving routine
void clearInt(MFRC522 mfrc522) {
  mfrc522.PCD_WriteRegister(mfrc522.ComIrqReg, 0x7F);
}


void handleRoot() {
  String message = WebSitePage1Pt1;
  //patrick in
  message += inP;
  message += WebSitePage1Pt2;
  //mark in
  message += inM;
  message += WebSitePage1Pt3;
  //James tag in
  message += inJ;
  message += WebSitePage1Pt4;
  //Ciara tag in
  message += inC;
  message += WebSitePage1Pt5;
  server.send(200, "text/html", message);
}

void handleResetString() {
  inP = "0"; // Reset the string to "0"
  inJ = "0";
  inC = "0";
  inM = "0";
  server.send(200, "text/plain", "String reset to 0"); // Send a response to the client
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
