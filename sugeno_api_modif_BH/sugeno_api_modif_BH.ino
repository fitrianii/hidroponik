#include <Wire.h>
#include "DHT.h"

#define echoPin1 2 // Echo Pin sensor ultrasonic 1 terhubung dengan pin 2
#define trigPin1 3 // Trigger Pin
#define echoPin2 4 // Echo Pin
#define trigPin2 5 // Trigger Pin
#define echoPin3 6 // Echo Pin
#define trigPin3 7 // Trigger Pin

#define DHTpin1 8 // pin DHT22 1 terhubung dengan pin 8
#define DHTpin2 9
#define DHTpin3 10

#define PHpin1 A0 // Sensor PH1 terhubung di pin A0
#define PHpin2 A1
#define PHpin3 A2

#define pin_up 41 //relay buffer up terhubung di pin 41
#define pin_down 43
#define pin_pompa 45


#define tinggi_bak 43

#define DHTTYPE DHT22

#define jml_mf_waterLevel 2
#define jml_mf_PH 3

#define min_waterLevel 0
#define max_waterLevel 43

#define min_PH 0
#define max_PH 14

#define rendah 0
#define tinggi 1

#define asam 0
#define ideal 1
#define basa 2

#define mati 0
#define nylah 1
#define cepat 1
#define lama 2

#define nyala 1
#define mati 0

#define durasi 5 //setting aktivasi pompa buffer setiap satuan menit
#define up_on digitalWrite(pin_up,LOW)
#define up_off digitalWrite(pin_up,HIGH)

#define down_on digitalWrite(pin_down,LOW)
#define down_off digitalWrite(pin_down,HIGH)

#define pompa_on digitalWrite(pin_pompa,LOW)
#define pompa_off digitalWrite(pin_pompa,HIGH)

DHT dht1(DHTpin1, DHTTYPE);
DHT dht2(DHTpin2, DHTTYPE);
DHT dht3(DHTpin3, DHTTYPE);

#define BH_1750F 0x23
#define BH_1750S 0x5C
#define DATA_REG_RESET 0b00000111
#define POWER_DOWN 0b00000000
#define POWER_ON 0b00000001
enum BH1750Mode {
  CHM = 0b00010000,     //CHM: Continuously H-Resolution Mode
  CHM_2 = 0b00010001,   //CHM_2: Continuously H-Resolution Mode2
  CLM = 0b00010011,     //CLM: Continuously L-Resolution Mode
  OTH = 0b00100000,     //OTH: One Time H-Resolution Mode
  OTH_2 = 0b00100001,   //OTH_2: One Time H-Resolution Mode2
  OTL = 0b00100011      //OTL: One Time L-Resolution Mode
} mode;
float measuringTimeFactor;

//+++++Var rule dan bobot
double rule[30];
double bobot_waterLevel[jml_mf_PH];
double bobot_ph[jml_mf_waterLevel];
double data_set_ph[200];
double data_set_suhu[50];

float wl1, wl2, wl3;
float waterLevel = 0;
int kelembaban, kelembaban1, kelembaban2, kelembaban3;
float suhu, suhu1, suhu2, suhu3;
float ph1, ph2, ph3;
float lux, lux1, lux2, lux3;

float mid_ph = 0, mid_ultra = 0, mid_lux = 0, mid_suhu = 0, mid_kelembaban = 0;
//+++++membership function untuk SUHU
double mf_ph [jml_mf_PH][3] = {
  { 0, 5, 5.5 },//Asam
  { 5, 6.5, 8.5 },//Ideal
  { 8, 8.5, 14 }//Basa
};

//+++++membership function untuk PH
double mf_waterLevel[jml_mf_waterLevel][3] = {
  { 0, 23, 33 },//rendah
  { 23, 33, 43 }//tinggi

};

//+++++membership function untuk banyaknya ph buffer yang keluar
double mf_ph_up[] = {0, 100, 200};
double mf_ph_down[] = {0, 100, 200};
double mf_pompa[] = {0, 100};

long old_millis;
int pulse;
int total_rule;
//bool mode;

int jml_loop_suhu, jml_loop_ph;
float ph = 0;

// Variable sensor PH
#define SensorPin A0            //pH meter Analog output to Arduino Analog Input 0
#define Offset 0.00            //deviation compensate
#define samplingInterval 10
#define printInterval 100
#define ArrayLenth  20    //times of collection
int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex = 0;
double tegangan_ph_netral1 = 2.78; // setting referensi tegangan ketika PH 7
double  tegangan_ph_netral2 = 2.78;
double tegangan_ph_netral3 = 2.78;


long last_millis_wifi = 0;

int ulang;

//------tambahan----------
void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial2.begin(9600);

  pinMode(pin_up, OUTPUT);
  pinMode(pin_down, OUTPUT);
  pinMode(pin_pompa, OUTPUT);

  up_off;
  down_off;
  pompa_off;

  int index = 0;

  dht1.begin();
  dht2.begin();
  dht3.begin();

  mode = CHM;
  measuringTimeFactor = 1;
  setMode();
  setMeasuringTime();
  delay(200);
}

long last_on;
int minute, second;
int suhu_state = 0;
int ph_state = 0;
double defuzzy_up;
double defuzzy_down;
double defuzzy_pompa;

void loop() {

  if (Serial2.available() > 1) {
    lux3 = Serial2.parseInt();
    Serial.println("Data dari Wemos LUX 3:" + String(lux3));
  }

  wl1 = distance(trigPin1, echoPin1, tinggi_bak);
  wl2 = distance(trigPin2, echoPin2, tinggi_bak);
  wl3 = distance(trigPin3, echoPin3, tinggi_bak);
  konversi_ultrasonik();

  kelembaban1 =  dht1.readHumidity();
  kelembaban2 =  dht2.readHumidity();
  kelembaban3 =  dht3.readHumidity();
  konversi_kelembaban();

  suhu1 = dht1.readTemperature();
  suhu2 = dht2.readTemperature();
  suhu3 = dht3.readTemperature();
  konversi_suhu();

  ph1 = get_ph(1, PHpin1, tegangan_ph_netral1);
  ph2 = get_ph(2, PHpin2, tegangan_ph_netral2);
  ph3 = get_ph(3, PHpin3, tegangan_ph_netral3);
  konversi_ph();

  read_bh();
  konversi_lux();

  // ph = 6.7;
  // waterLevel = 15.99;

  Serial.print("Sensor PH:");
  Serial.print(ph1);
  Serial.print(" ");
  Serial.print(ph2);
  Serial.print(" ");
  Serial.print(ph3);
  Serial.print(" Konversi ->");
  Serial.println(ph);

  Serial.print("Sensor Kelembaban:");
  Serial.print(kelembaban1);
  Serial.print(" ");
  Serial.print(kelembaban2);
  Serial.print(" ");
  Serial.print(kelembaban3);
  Serial.print(" Konversi ->");
  Serial.println(kelembaban);

  Serial.print("Sensor Suhu:");
  Serial.print(suhu1);
  Serial.print(" ");
  Serial.print(suhu2);
  Serial.print(" ");
  Serial.print(suhu3);
  Serial.print(" Konversi ->");
  Serial.println(suhu);

  Serial.print("Sensor Ketinggian:");
  Serial.print(wl1);
  Serial.print(" ");
  Serial.print(wl2);
  Serial.print(" ");
  Serial.print(wl3);
  Serial.print(" Konversi ->");
  Serial.println(waterLevel);

  Serial.print("Sensor Lux:");
  Serial.print(lux1);
  Serial.print(" ");
  Serial.print(lux2);
  Serial.print(" ");
  Serial.print(lux3);
  Serial.print(" Konversi ->");
  Serial.println(lux);
  double xlux = lux;
  //Fuzzy Fikasi
  get_bobot_ph (ph, jml_mf_PH);
  get_bobot_waterLevel(waterLevel, jml_mf_waterLevel);

  //Rulebase
  rule[1] = min_val(bobot_waterLevel[rendah], bobot_ph[asam]);
  rule[2] = min_val(bobot_waterLevel[rendah], bobot_ph[ideal]);
  rule[3] = min_val(bobot_waterLevel[rendah], bobot_ph[basa]);
  rule[4] = min_val(bobot_waterLevel[tinggi], bobot_ph[asam]);
  rule[5] = min_val(bobot_waterLevel[tinggi], bobot_ph[ideal]);
  rule[6] = min_val(bobot_waterLevel[tinggi], bobot_ph[basa]);

  //kalkulasi nilai total rulebase
  double total_rule = 0;
  for (int xx = 1; xx <= 6; xx++) {
    total_rule = rule[xx] + total_rule;
    //Serial.println(rule[xx]);
  }
  // inference rule base fuzzy untuk buffer UP
  defuzzy_pompa = 0;
  defuzzy_pompa = rule[1] * mf_pompa[nyala] +
                  rule[2] * mf_pompa[nyala] +
                  rule[3] * mf_pompa[nyala] +
                  rule[4] * mf_pompa[mati] +
                  rule[5] * mf_pompa[mati] +
                  rule[6] * mf_pompa[mati];

  // inference rule base fuzzy untuk buffer UP
  defuzzy_up = 0;
  defuzzy_up = rule[1] * mf_ph_up[lama] +
               rule[2] * mf_ph_up[mati] +
               rule[3] * mf_ph_up[mati] +
               rule[4] * mf_ph_up[cepat] +
               rule[5] * mf_ph_up[mati] +
               rule[6] * mf_ph_up[mati];


  defuzzy_down = 0;
  defuzzy_down = rule[1] * mf_ph_down[mati] +
                 rule[2] * mf_ph_down[mati] +
                 rule[3] * mf_ph_down[lama] +
                 rule[4] * mf_ph_down[mati] +
                 rule[5] * mf_ph_down[mati] +
                 rule[6] * mf_ph_down[cepat] ;


  //  Serial.print("Bobot Pompa:");
  //  Serial.print(defuzzy_pompa);
  //  Serial.print("UP:");
  //  Serial.print(defuzzy_up);
  //  Serial.print("DOWN:");
  //  Serial.println(defuzzy_down);

  // defuzzifikasi
  defuzzy_pompa = defuzzy_pompa / total_rule;
  defuzzy_up = defuzzy_up / total_rule;
  defuzzy_down = defuzzy_down / total_rule;

  if (isnan(defuzzy_pompa )) {
    defuzzy_pompa = 0;
  }

  if (isnan(defuzzy_up )) {
    defuzzy_up = 0;
  }
  if (isnan(defuzzy_down )) {
    defuzzy_down = 0;
  }

  Serial.print("Output Fuzzy Pompa: ");
  Serial.print(defuzzy_pompa);
  Serial.print(" Buffer Up: ");
  Serial.print(defuzzy_up);
  Serial.print(" Buffer Down: ");
  Serial.println(defuzzy_down);

  // kalkulasi waktu action program untuk menyalakan buffer
  if ((millis() - last_on) > 1000) {
    second = second + ((millis() - last_on) / 1000);
    if (second > 59) {
      second = 0;
      minute++;
    }
    last_on = millis();
  }

  // pump action
  if (defuzzy_pompa < 50) {
    pompa_off;
    Serial.println("Pompa Mati");
  } else {
    pompa_on;
    Serial.println("Pompa Nyala");
    delay(defuzzy_pompa * 1000);
    pompa_off;
  }

  // buffer action
  if (minute >= durasi) {

    minute = 0;
    if (defuzzy_up <= 0 && defuzzy_down <= 0) {
      up_off; down_off;

      Serial.print("BUFFER OFF:");
      Serial.print("ADD: ");
      Serial.println(0);

    }
    else if (defuzzy_up > 0 && defuzzy_down <= 0) {
      Serial.print("BUFFER UP ACTIVE:");
      Serial.print("ADD: ");
      Serial.println(defuzzy_up);
      down_off;
      up_on;
      delay(defuzzy_up * 350); // ini delay yang di setting otomatis dari nilai fuzzy ketika buffer UP on
      down_off;
      up_off;
    }
    else if (defuzzy_up <= 0 && defuzzy_down > 0) {
      Serial.print("BUFFER DOWN ACTIVE:");
      Serial.print("ADD: ");
      Serial.println(defuzzy_down);

      up_off;
      down_on;
      delay(defuzzy_down * 350);
      down_off;
      up_off;
    }
    up_off; down_off;
    delay(2000);
  }
  send_data(xlux); // program untuk mengirim data ke wemos
  delay(180000);//pembacaan berikutnya tiap
}
