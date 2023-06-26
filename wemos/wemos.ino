#include <BH1750.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

BH1750 lightMeter;

WiFiClient client;
String request_string;
const char* host = "103.37.125.218"; // ip computer agan, bisa di lihat ipv4 di CMD dengan perintah ipconfig
HTTPClient http;

void setup() {
    WiFi.disconnect();
//    WiFi.begin("Bhattara Coffee","kedai_kopi*"); // nama wifi ssid dan Passwordnya
    WiFi.begin("REZA","sholawat nabi");
//    WiFi.begin("ITK-LAB.X","K@mpusM3rdeka!");
    while ((!(WiFi.status() == WL_CONNECTED))){
      delay(300); 
    }
    
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
}
String waterLevel , wl1, wl2, wl3;
String suhu, suhu1, suhu2, suhu3;
String kelembaban, kelembaban1, kelembaban2, kelembaban3;
String ph, ph1, ph2, ph3;
String lux_conversion, lux1, lux2, lux3;
String defuzzy_up, defuzzy_down, defuzzy_pompa;

String status_pompa ="MATI";
String status_pompa_ph_up = "MATI";
String status_pompa_ph_down = "MATI";

void loop() {
  float lux = lightMeter.readLightLevel();
    Serial.println((int)lux);
    delay(20000);
  if (Serial.available() > 1) {
    String data_serial = Serial.readStringUntil('\n');
    int aa = data_serial.indexOf("A");
    int bb = data_serial.indexOf("B");
    int cc = data_serial.indexOf("C");
    int dd = data_serial.indexOf("D");
    int ee = data_serial.indexOf("E");
    int ff = data_serial.indexOf("F");
    int gg = data_serial.indexOf("G");
    int hh = data_serial.indexOf("H");
    int ii = data_serial.indexOf("I");
    int jj = data_serial.indexOf("J");
    int kk = data_serial.indexOf("K");
    int ll = data_serial.indexOf("L");
    int mm = data_serial.indexOf("M");
    int nn = data_serial.indexOf("N");
    int oo = data_serial.indexOf("O");
    int pp = data_serial.indexOf("P");
    int qq = data_serial.indexOf("Q");
    int rr = data_serial.indexOf("R");
    int ss = data_serial.indexOf("S");
    int tt = data_serial.indexOf("T");
    int uu = data_serial.indexOf("U");
    int vv = data_serial.indexOf("V");
    int ww = data_serial.indexOf("W");
    int xx = data_serial.indexOf("X");

    waterLevel = data_serial.substring(aa + 1, bb);
    wl1 = data_serial.substring(bb + 1, cc);
    wl2 = data_serial.substring(cc + 1, dd);
    wl3 = data_serial.substring(dd + 1, ee);
    suhu = data_serial.substring(ee + 1, ff);
    suhu1 = data_serial.substring(ff + 1, gg);
    suhu2 = data_serial.substring(gg + 1, hh);
    suhu3 = data_serial.substring(hh + 1, ii);

    kelembaban = data_serial.substring(ii + 1, jj);
    kelembaban1 = data_serial.substring(jj + 1, kk);
    kelembaban2 = data_serial.substring(kk + 1, ll);
    kelembaban3 = data_serial.substring(ll + 1, mm);

    ph = data_serial.substring(mm + 1, nn);
    ph1 = data_serial.substring(nn + 1, oo);
    ph2 = data_serial.substring(oo + 1, pp);
    ph3 = data_serial.substring(pp + 1, qq);


    lux_conversion = data_serial.substring(qq + 1, rr);
    lux1 = data_serial.substring(rr + 1, ss);
    lux2 = data_serial.substring(ss + 1, tt);
    lux3 = data_serial.substring(tt + 1, uu);

    defuzzy_pompa = data_serial.substring(uu + 1, vv);
    defuzzy_up = data_serial.substring(vv + 1, ww);
    defuzzy_down = data_serial.substring(ww + 1, xx);

    if (!client.connect(host,80)) {
      Serial.println("Gagal Konek Server");
      return;
    }
    if (client.connect(host,80)) {
      Serial.print("Connected to Server, Server IP address: ");
      Serial.println(host);
        //return;

//    tampil();
//    kirim_data_keserver();

if (defuzzy_pompa.toInt() < 50) {
    status_pompa ="MATI";
        Serial.println("POMPA MATI");
  } else {
    status_pompa ="HIDUP";
        Serial.println("POMPA HIDUP");
  }
  if (defuzzy_up.toInt() <= 0 && defuzzy_down.toInt()<= 0) {
    status_pompa_ph_up = "MATI";
    status_pompa_ph_down = "MATI";
    Serial.println("Pompa pH up dan down Mati");
  } 
  else if (defuzzy_up.toInt()> 0 && defuzzy_down.toInt() <= 0) {
    status_pompa_ph_up = "HIDUP";
    Serial.println("Pompa pH up Hidup");
  }
  else if (defuzzy_up.toInt() <= 0 && defuzzy_down.toInt() > 0) {
    status_pompa_ph_down = "HIDUP";
    Serial.println("Pompa pH down Hidup");
  }

  //program kirim
  request_string = "/hidroponik/kirim.php?data1=";
  request_string += waterLevel;
  request_string += "&data2=";
  request_string += wl1;
  request_string += "&data3=";
  request_string += wl2;
  request_string += "&data4=";
  request_string += wl3;
  request_string += "&data5=";
  request_string += suhu;
  request_string += "&data6=";
  request_string += suhu1;
  request_string += "&data7=";
  request_string += suhu2;
  request_string += "&data8=";
  request_string += suhu3;
  request_string += "&data9=";
  request_string += kelembaban;
  request_string += "&data10=";
  request_string += kelembaban1;
  request_string += "&data11=";
  request_string += kelembaban2;
  request_string += "&data12=";
  request_string += kelembaban3;
  request_string += "&data13=";
  request_string += ph;
  request_string += "&data14=";
  request_string += ph1;
  request_string += "&data15=";
  request_string += ph2;
  request_string += "&data16=";
  request_string += ph3;
  request_string += "&data17=";
  request_string += lux_conversion;
  request_string += "&data18=";
  request_string += lux1;
  request_string += "&data19=";
  request_string += lux2;
  request_string += "&data20=";
  request_string += lux3;
  request_string += "&data21=";
  request_string += defuzzy_pompa;
  request_string += "&data22=";
  request_string += defuzzy_up;
  request_string += "&data23=";
  request_string += defuzzy_down;
  request_string += "&data24=";
  request_string += status_pompa;
  request_string += "&data25=";
  request_string += status_pompa_ph_up;
  request_string += "&data26=";
  request_string += status_pompa_ph_down;
  

  Serial.print("requesting URL: ");
  Serial.println(request_string);
  client.print(String("GET ") + request_string + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");

  }

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
    }
  }
  }
}
