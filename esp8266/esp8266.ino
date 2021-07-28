/*  
 _____________________________
 | ╔═╗╦╦  ╦ ╦╦╔═  ╔╗ ╔═╗╔═╗┬ |
 | ║  ║║  ║ ║╠╩╗  ╠╩╗╠═╣╠═╣│ |
 | ╚═╝╩╩═╝╚═╝╩ ╩  ╚═╝╩ ╩╩ ╩o |
 |                           |
 |___________________________|
         o
           o
            o          __---__
                    _-       /--______
               __--( /     \ )XXXXXXXXXXX\v.
             .-XXX(   O   O  )XXXXXXXXXXXXXXX-
            /XXX(       U     )        XXXXXXX\
          /XXXXX(              )--_  XXXXXXXXXXX\
         /XXXXX/ (      O     )   XXXXXX   \XXXXX\
         XXXXX/   /            XXXXXX   \__ \XXXXX
         XXXXXX__/          XXXXXX         \__---->
 ---___  XXX__/          XXXXXX      \__         /
   \-  --__/   ___/\  XXXXXX            /  ___--/=
    \-\    ___/    XXXXXX              '--- XXXXXX
       \-\/XXX\ XXXXXX                      /XXXXX
         \XXXXXXXXX   \                    /XXXXX/
          \XXXXXX      >                 _/XXXXX/
            \XXXXX--__/              __-- XXXX/
             -XXXXXXXX---------------  XXXXXX-
                \XXXXXXXXXXXXXXXXXXXXXXXXXX/
                  ""VXXXXXXXXXXXXXXXXXXV""

*/

#include <PubSubClient.h>
#include <ESP8266WiFi.h>

/********************************************************** START SETUP WIFI and MQTT SERVER *********************************************************************************************************/
#define MQTT_SERVER "broker.mqtt-dashboard.com"  //MQTBroker/Server
const char* ssid = "pentiltuyul";                //WifiSSID
const char* password = "pentilkucing";           //PassWifi

/********************************************************** MQTT TOPICS (change these topics as whatever you want)******************************************************************************************/

char* Topic = "gasoli/minuman/keluarga/sehat"; //Topic <> Sub

WiFiClient wifiClient;

void setup() {
  Serial.begin(9600);
  delay(100);


  //Memulai wifi
  WiFi.begin(ssid, password);
  reconnect();
  //
  delay(2000);
}

/********************************************************* START CALLBACK *********************************************************************************************************/

PubSubClient client(MQTT_SERVER, 1883, callback, wifiClient);

void loop() {

  //Koneksi serer mqtt
  if (!client.connected() && WiFi.status() == 3) {
    reconnect();
  }
  client.loop();
  
  delay(20);
}


void callback(char* topic, byte* payload, unsigned int length) {

/********************************************************* START PROCESS *********************************************************************************************************/

  String asdfTopic = topic;
  payload[length] = '\0';
  String asdfPayload = String((char *)payload);

  //perintah "String" lampu on off
  if (asdfPayload == "112") {
    client.publish("gasoli/minuman/keluarga/sehat/state", "Lampu_1 ON"); //change this STATE whatever you want
    Serial.println("112");                                               //change this to whatever you want to call your device
  }
  if (asdfPayload == "111") {
    client.publish("gasoli/minuman/keluarga/sehat/state", "Lampu_1 OFF");//change this STATE whatever you want
    Serial.println("111");                                               //change this to whatever you want to call your device
  }
  if (asdfPayload == "222") {
    client.publish("gasoli/minuman/keluarga/sehat/state", "Lampu_2 ON"); //change this STATE whatever you want
    Serial.println("222");                                               //change this to whatever you want to call your device
  }
  if (asdfPayload == "221") {
    client.publish("gasoli/minuman/keluarga/sehat/state", "Lampu_2 OFF");//change this STATE whatever you want
    Serial.println("221");                                               //change this to whatever you want to call your device
  }
}

/********************************************************* START RECONNECT *********************************************************************************************************/

void reconnect() {

  if (WiFi.status() != WL_CONNECTED) {

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    while (!client.connected()) {
      String clientName;
      clientName += "esp8266-";
      uint8_t mac[6];
      WiFi.macAddress(mac);
      clientName += macToStr(mac);
      if (client.connect((char*) clientName.c_str())) {
        Serial.print("\tMTQQ Connected");
        client.subscribe(Topic);
      }
      else {
        Serial.println("\tFailed.");
        abort();
      }
    }
  }
}

String macToStr(const uint8_t* mac) {

  String result;

  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);

    if (i < 5) {
      result += ':';
    }
  }

  return result;
}
