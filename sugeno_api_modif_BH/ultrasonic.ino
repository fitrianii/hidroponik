float distance(int trigPin , int echoPin, int max) {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT_PULLUP);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration, distance, wl3; // Duration used to calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  return  max - distance;
}

void  konversi_ultrasonik() {
  waterLevel = 0;
  mid_ultra = 0;
  wl2 == wl3 ? waterLevel = wl2 : waterLevel = wl1;
  // cek nilai yang mendekati
  if (wl1 > wl2 && wl1 < wl3) {
    mid_ultra = wl1;
    mid_ultra - wl2 < wl3 - mid_ultra ? waterLevel = (wl2 + mid_ultra) / 2 : waterLevel = (mid_ultra + wl3) / 2; //mid_ultra - 2 kalau lebih kecil dari t3 - mid_ultra, nilai temp nya yg Temp = (t2+mid_ultra)/2 kalau salah nilainya Temp = (mid_ultra+t3)/2
  } else if (wl1 < wl2 && wl1 > wl3) {
    mid_ultra = wl1;
    mid_ultra - wl3 < wl2 - mid_ultra ? waterLevel = (wl3 + mid_ultra) / 2 : waterLevel = (mid_ultra + wl2) / 2;
  } else if (wl2 > wl1 && wl2 < wl3) {
    mid_ultra = wl2;
    mid_ultra - wl1 < wl3 - mid_ultra ? waterLevel = (wl1 + mid_ultra) / 2 : waterLevel = (mid_ultra + wl3) / 2;
  } else if (wl2 < wl1 && wl2 > wl3) {
    mid_ultra = wl2;
    mid_ultra - wl3 < wl1 - mid_ultra ? waterLevel = (wl3 + mid_ultra) / 2 : waterLevel = (mid_ultra + wl1) / 2;
  } else if (wl3 > wl1 && wl3 < wl2) {
    mid_ultra = wl3;
    mid_ultra - wl1 < wl2 - mid_ultra ? waterLevel = (wl1 + mid_ultra) / 2 : waterLevel = (mid_ultra + wl2) / 2;
  } else if (wl3 < wl1 && wl3 > wl2) {
    mid_ultra = wl3;
    mid_ultra - wl2 < wl1 - mid_ultra ? waterLevel = (wl2 + mid_ultra) / 2 : waterLevel = (mid_ultra + wl1) / 2;
  }

}
