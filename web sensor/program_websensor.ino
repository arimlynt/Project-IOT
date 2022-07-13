#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

//setting jaringan
const char* ssid = "Aray"; //nama wifi
const char* password = "1sampe89"; //password wifi
const char* host = "192.168.47.245"; //alamat ip server

//variabel indikator koneksi
#define PIN_LED D1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);

  //setting koneksi wifi
//  WiFi.hostname("NodeMCU");
  WiFi.begin(ssid, password);

  //cek koneksi wifi
  while(WiFi.status() != WL_CONNECTED)
  {
    //led mati
    digitalWrite(PIN_LED, LOW);
    //nodemcu terus mencoba koneksi
    Serial.println(".");
    delay(500);
  }
  //apabila berhasil koneksi
  digitalWrite(PIN_LED, HIGH);
  //tampilkan pesan
  Serial.println("WiFi Connected");
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor = analogRead(0);
  Serial.println(sensor);
  //cek koneksi ke server
  WiFiClient client ;
  if(!client.connect(host, 80))
  {
    Serial.println("Connection Failed");
    return ;
  }

  //proses pengiriman data ke server
  String Link ;
  HTTPClient http;
  Link = "http://192.168.47.245/web%20sensor/kirimdata.php?sensor=" + String(sensor);         
  //eksekusi link
  http.begin(Link);
  // mode GET
  http.GET();
  http.end();
  delay(1000);
}
