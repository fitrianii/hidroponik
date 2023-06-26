void konversi_suhu() {
  suhu = 0;
  mid_suhu = 0;
  // cek apakah ada nilai suhu yang sama
  suhu2 == suhu3 ? suhu = suhu2 : suhu = suhu1;
  if (suhu1 > suhu2 && suhu1 < suhu3) {
    mid_suhu = suhu1;
    mid_suhu - suhu2 < suhu3 - mid_suhu ? suhu = (suhu2 + mid_suhu) / 2 : suhu = (mid_suhu + suhu3) / 2; //mid_suhu - 2 kalau lebih kecil dari suhu3 - mid_suhu, nilai suhu nya yg suhu = (suhu2+mid_suhu)/2 kalau salah nilainya suhu = (mid_suhu+suhu3)/2
  } else if (suhu1 < suhu2 && suhu1 > suhu3) {
    mid_suhu = suhu1;
    mid_suhu - suhu3 < suhu2 - mid_suhu ? suhu = (suhu3 + mid_suhu) / 2 : suhu = (mid_suhu + suhu2) / 2;
  } else if (suhu2 > suhu1 && suhu2 < suhu3) {
    mid_suhu = suhu2;
    mid_suhu - suhu1 < suhu3 - mid_suhu ? suhu = (suhu1 + mid_suhu) / 2 : suhu = (mid_suhu + suhu3) / 2;
  } else if (suhu2 < suhu1 && suhu2 > suhu3) {
    mid_suhu = suhu2;
    mid_suhu - suhu3 < suhu1 - mid_suhu ? suhu = (suhu3 + mid_suhu) / 2 : suhu = (mid_suhu + suhu1) / 2;
  } else if (suhu3 > suhu1 && suhu3 < suhu2) {
    mid_suhu = suhu3;
    mid_suhu - suhu1 < suhu2 - mid_suhu ? suhu = (suhu1 + mid_suhu) / 2 : suhu = (mid_suhu + suhu2) / 2;
  } else if (suhu3 < suhu1 && suhu3 > suhu2) {
    mid_suhu = suhu3;
    mid_suhu - suhu2 < suhu1 - mid_suhu ? suhu = (suhu2 + mid_suhu) / 2 : suhu = (mid_suhu + suhu1) / 2;
  }
}

void konversi_kelembaban() {
  kelembaban = 0;
  mid_kelembaban = 0;
  // cek apakah ada nilai kelembaban yang sama
  kelembaban2 == kelembaban3 ? kelembaban = kelembaban2 : kelembaban = kelembaban1;
  if (kelembaban1 > kelembaban2 && kelembaban1 < kelembaban3) {
    mid_kelembaban = kelembaban1;
    mid_kelembaban - kelembaban2 < kelembaban3 - mid_kelembaban ? kelembaban = (kelembaban2 + mid_kelembaban) / 2 : kelembaban = (mid_kelembaban + kelembaban3) / 2; //mid_kelembaban - 2 kalau lebih kecil dari t3 - mid_kelembaban, nilai temp nya yg Temp = (t2+mid_kelembaban)/2 kalau salah nilainya Temp = (mid_kelembaban+t3)/2
  } else if (kelembaban1 < kelembaban2 && kelembaban1 > kelembaban3) {
    mid_kelembaban = kelembaban1;
    mid_kelembaban - kelembaban3 < kelembaban2 - mid_kelembaban ? kelembaban = (kelembaban3 + mid_kelembaban) / 2 : kelembaban = (mid_kelembaban + kelembaban2) / 2;
  } else if (kelembaban2 > kelembaban1 && kelembaban2 < kelembaban3) {
    mid_kelembaban = kelembaban2;
    mid_kelembaban - kelembaban1 < kelembaban3 - mid_kelembaban ? kelembaban = (kelembaban1 + mid_kelembaban) / 2 : kelembaban = (mid_kelembaban + kelembaban3) / 2;
  } else if (kelembaban2 < kelembaban1 && kelembaban2 > kelembaban3) {
    mid_kelembaban = kelembaban2;
    mid_kelembaban - kelembaban3 < kelembaban1 - mid_kelembaban ? kelembaban = (kelembaban3 + mid_kelembaban) / 2 : kelembaban = (mid_kelembaban + kelembaban1) / 2;
  } else if (kelembaban3 > kelembaban1 && kelembaban3 < kelembaban2) {
    mid_kelembaban = kelembaban3;
    mid_kelembaban - kelembaban1 < kelembaban2 - mid_kelembaban ? kelembaban = (kelembaban1 + mid_kelembaban) / 2 : kelembaban = (mid_kelembaban + kelembaban2) / 2;
  } else if (kelembaban3 < kelembaban1 && kelembaban3 > kelembaban2) {
    mid_kelembaban = kelembaban3;
    mid_kelembaban - kelembaban2 < kelembaban1 - mid_kelembaban ? kelembaban = (kelembaban2 + mid_kelembaban) / 2 : kelembaban = (mid_kelembaban + kelembaban1) / 2;
  }

}
