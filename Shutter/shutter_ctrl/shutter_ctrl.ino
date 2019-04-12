#include <ESP8266WiFi.h>
const char *ap_id = "QBLAB_3"; // The name of the Wi-Fi network that will be created
const char *ap_pwd = "02132140"; // The password required to connect to it
const char *ssid = "SUSTC-Wifi";

const unsigned int LED = D0; // buid in LED
const unsigned int pulse0_pin = D1;
const unsigned int pulse1_pin = D2;
unsigned int pulse0_on = 500; // 500 ms
unsigned int pulse0_off = 4500; // 4500ms
unsigned int pulse1_on = 1000; //100
unsigned int pulse1_off = 1000; //100

unsigned long int timer0 = millis();
unsigned long int timer1 = millis();
unsigned int flag0 = 0;
unsigned int flag1 = 0;

WiFiServer server(80);

void setup()
{
  pinMode(pulse0_pin, OUTPUT);
  digitalWrite(pulse0_pin, LOW);
  pinMode(pulse1_pin, OUTPUT);
  digitalWrite(pulse1_pin, LOW);

  WiFi.softAP(ap_id, ap_pwd);
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
}

void loop()
{
  // pluse0
  
  if (flag0 == 0 ) { // pluse0 is off
    if (millis() - timer0 > pulse0_off) {
      digitalWrite(pulse0_pin, HIGH);
      flag0 = 1;
      timer0 = millis();
    }
  } else { // pulse0 is on
    if (millis() - timer0 > pulse0_on ) {
      digitalWrite(pulse0_pin, LOW);
      flag0 = 0;
      timer0 = millis();
    }
  }

  // pluse1
  if (flag1 == 0 ) { // pluse0 is off
    if (millis() - timer1 > pulse1_off) {
      digitalWrite(pulse1_pin, HIGH);
      flag1 = 1;
      timer1 = millis();
    }
  } else { // pulse1 is on
    if (millis() - timer1 > pulse1_on ) {
      digitalWrite(pulse1_pin, LOW);
      flag1 = 0;
      timer1 = millis();
    }
  }

  /*
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  //Serial.println("Waiting for new client");
  while (!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  client.flush();

  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)
  {
    digitalWrite(LED, HIGH); // Turn ON LED
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)
  {
    digitalWrite(LED, LOW); // Turn OFF LED
    value = LOW;
  }
  */

  /*------------------HTML Page Creation---------------------*/
  /*
  client.println("HTTP/1.1 200 OK"); // standalone web server with an ESP8266
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.print("LED: ");

  if (value == HIGH)
  {
    client.print("ON");
  }
  else
  {
    client.print("OFF");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>OFF</button></a><br />");
  client.println("</html>");
  */

}
