void send_data(double xlux2) {
  String protokol = "A" + String( waterLevel )+"B" + String(wl1) + "C" + String( wl2) + "D" + String( wl3) + "E";
  protokol = protokol + String (suhu) + "F" +  String( suhu1)+"G" + String(  suhu2) + "H" + String( suhu3) + "I";
  protokol = protokol + String(kelembaban)+"J" + String(  kelembaban1) + "K" + String(  kelembaban2) + "L" + String( kelembaban3) + "M";
  protokol = protokol + String (ph) + "N" + String(  ph1) + "O" + String(  ph2) + "P" + String(  ph3) + "Q";
  protokol = protokol + String(xlux2) + "R" +String(  lux1) + "S" + String(  lux2) + "T" + String(  lux3) + "U";
  protokol = protokol + String(  defuzzy_pompa) + "V" +  String( defuzzy_up) + "W" + String(defuzzy_down) + "X";

  Serial.println(protokol);
  Serial2.println(protokol);
}
