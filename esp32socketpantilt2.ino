#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include <WebSocketsServer.h>

const char* ssid ="SSID";
const char* password ="PASSWORD";
extern bool drive = false;
extern int current=0;
static int PAN=90;
static int TILT=90;
const int PIN_SERVO_PAN = 18;
const int PIN_SERVO_TILT = 19;
int* TP = &TILT;
int* PP = &PAN;

Servo panServo;
Servo tiltServo;
WebSocketsServer server(80);


void setup() {
Serial.begin(115200);
ESP32PWM::allocateTimer(0);
ESP32PWM::allocateTimer(1);
ESP32PWM::allocateTimer(2);
ESP32PWM::allocateTimer(3);
ESP32PWM::allocateTimer(4);

panServo.setPeriodHertz(50);
tiltServo.setPeriodHertz(50);
panServo.attach(PIN_SERVO_PAN,500, 2400);
tiltServo.attach(PIN_SERVO_TILT,500, 2400);
Serial.println("setting up connection");
WiFi.begin(ssid, password);
while(WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(".");
  }
  Serial.println("ServerIP:");
  Serial.print(WiFi.localIP());
  server.begin();
  server.onEvent(onWebSocketEvent);

}

void loop() {
server.loop();

}


void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t length){
  switch(type)
  {
    case WStype_DISCONNECTED:
    {
      Serial.printf("[%u] Disconnected!\n",num);
      break;
    }
    case WStype_CONNECTED:
     {
      IPAddress ip = server.remoteIP(num);
      Serial.printf("[%u] Connection from ",num);
      Serial.println(ip.toString());
      break;
     }
    case WStype_TEXT:
     {
     Serial.printf("[%u] text: %s\n", num, payload);
    
     char command = (char)payload[0]; 
     int val =(int) payload[1];
     
      if(command=='P'){
        Pan(val);
        break;
      }
      else if(command=='T'){
        Tilt(val);
        break;  
      }else{
          //Serial.println("?:");
      break;
      }
    }
  }
}
void Pan(int pm){
  Serial.print("Pan:");
  PAN=pm;
    panServo.write(PAN);
    delay(15);
  }
void Tilt(int pm){
  Serial.print("Tilt:");
  TILT = pm;
  tiltServo.write(TILT);
  }
