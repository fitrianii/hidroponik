void konversi_lux() {
  //konfigurasi 3 sensor
  lux = 0;
  mid_lux = 0;

  // cek apakah ada nilai suhu yang sama
  lux2 == lux3 ? lux = lux2 : lux = lux1;
  if (lux1 > lux2 && lux1 < lux3) {
    mid_lux = lux1;
    mid_lux - lux2 < lux3 - mid_lux ? lux = (lux2 + mid_lux) / 2 : lux = (mid_lux + lux3) / 2; //mid_lux - 2 kalau lebih kecil dari lux3 - mid_lux, nilai lux nya yg lux = (lux2+mid_lux)/2 kalau salah nilainya lux= (mid_lux+lux3)/2
  } else if (lux1 < lux2 && lux1 > lux3) {
    mid_lux = lux1;
    mid_lux - lux3 < lux2 - mid_lux ? lux = (lux3 + mid_lux) / 2 : lux = (mid_lux + lux2) / 2;
  } else if (lux2 > lux1 && lux2 < lux3) {
    mid_lux = lux2;
    mid_lux - lux1 < lux3 - mid_lux ? lux = (lux1 + mid_lux) / 2 : lux = (mid_lux + lux3) / 2;
  } else if (lux2 < lux1 && lux2 > lux3) {
    mid_lux = lux2;
    mid_lux - lux3 < lux1 - mid_lux ? lux = (lux3 + mid_lux) / 2 : lux = (mid_lux + lux1) / 2;
  } else if (lux3 > lux1 && lux3 < lux2) {
    mid_lux = lux3;
    mid_lux - lux1 < lux2 - mid_lux ? lux = (lux1 + mid_lux) / 2 : lux = (mid_lux + lux2) / 2;
  } else if (lux3 < lux1 && lux3 > lux2) {
    mid_lux = lux3;
    mid_lux - lux2 < lux1 - mid_lux ? lux = (lux2 + mid_lux) / 2 : lux = (mid_lux + lux1) / 2;
  }
}
