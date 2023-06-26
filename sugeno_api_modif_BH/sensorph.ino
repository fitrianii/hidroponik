
void konversi_ph() {
  ph = 0;
  mid_ph = 0;
  ph2 == ph3 ? ph = ph2 : ph = ph1;
  // cek nilai yang mendekati
  if (ph1 > ph2 && ph1 < ph3) {
    mid_ph = ph1;
    mid_ph - ph2 < ph3 - mid_ph ? ph = (ph2 + mid_ph) / 2 : ph = (mid_ph + ph3) / 2; //mid_ph - 2 kalau lebih kecil dari ph3 - mid_ph, nilai ph nya yg ph = (ph2+mid_ph)/2 kalau salah nilainya ph = (mid_ph+ph3)/2
  } else if (ph1 < ph2 && ph1 > ph3) {
    mid_ph = ph1;
    mid_ph - ph3 < ph2 - mid_ph ? ph = (ph3 + mid_ph) / 2 : ph = (mid_ph + ph2) / 2;
  } else if (ph2 > ph1 && ph2 < ph3) {
    mid_ph = ph2;
    mid_ph - ph1 < ph3 - mid_ph ? ph = (ph1 + mid_ph) / 2 : ph = (mid_ph + ph3) / 2;
  } else if (ph2 < ph1 && ph2 > ph3) {
    mid_ph = ph2;
    mid_ph - ph3 < ph1 - mid_ph ? ph = (ph3 + mid_ph) / 2 : ph = (mid_ph + ph1) / 2;
  } else if (ph3 > ph1 && ph3 < ph2) {
    mid_ph = ph3;
    mid_ph - ph1 < ph2 - mid_ph ? ph = (ph1 + mid_ph) / 2 : ph = (mid_ph + ph2) / 2;
  } else if (ph3 < ph1 && ph3 > ph2) {
    mid_ph = ph3;
    mid_ph - ph2 < ph1 - mid_ph ? ph = (ph2 + mid_ph) / 2 : ph = (mid_ph + ph1) / 2;
  }

}
//E201 READ
float get_ph(int index, int pin, double tegangan_ph_netral) {
  int samples = 10;
  float measurings = 0;
  for (int i = 0; i < samples; i++)
  {
    measurings += analogRead(pin);
    delay(10);
  }
  float teg0 = measurings / samples;
  float voltage = (teg0 * 5) / 1023;
  float ph = 7 + ((tegangan_ph_netral - voltage) / 0.18);
  ph = ph - 0.6;
  if (ph < 0) {
    ph = 0;
  }
  if (ph > 14) {
    ph = 14;
  }
//  Serial.print("Sensor PH");
//  Serial.print(index);
//  Serial.print(" ADC:");
//  Serial.print(voltage);
//  Serial.print("-> PH:");
//  Serial.println(ph);
  return ph;
}
