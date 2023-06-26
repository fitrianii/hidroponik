void read_bh(){
  uint16_t rawLux;
  float lux;
  uint16_t rawLuxS;
  float luxS;
  rawLux = readBH1750();
  if((mode==CHM_2)||(mode==OTH_2)){
    lux = (rawLux/2.4)/measuringTimeFactor;     
  }
  else{
    lux = (rawLux/1.2)/measuringTimeFactor;
  }
  rawLuxS = readBH1750S();
  if((mode==CHM_2)||(mode==OTH_2)){
    luxS = (rawLuxS/2.4)/measuringTimeFactor;     
  }
  else{
    luxS = (rawLuxS/1.2)/measuringTimeFactor;
  }
 lux1=lux;
 lux2=luxS;
}

void powerDown(){
  writeBH1750(POWER_DOWN);
  writeBH1750S(POWER_DOWN);
}
void powerOn(){
  writeBH1750(POWER_ON);
  writeBH1750S(POWER_ON);
  setMode();
}
void dataRegReset(){
  writeBH1750(DATA_REG_RESET);
  writeBH1750S(DATA_REG_RESET);
}
void setMode(){
  writeBH1750(mode);
  writeBH1750S(mode);
}
void setMeasuringTime(){
  byte mt = round(measuringTimeFactor*69);
  byte highByteMT = ((mt>>5) | 0b01000000);
  byte lowByteMT = (mt & 0b01111111);
  lowByteMT |= 0b01100000;
  writeBH1750(highByteMT);
  writeBH1750(lowByteMT);
  writeBH1750S(highByteMT);
  writeBH1750S(lowByteMT);
}
uint16_t readBH1750(){
  uint8_t MSbyte, LSbyte;
  Wire.requestFrom(BH_1750F, 2);
  if(Wire.available()){
    MSbyte=Wire.read();
    LSbyte=Wire.read(); 
  }
  return ((MSbyte<<8) + LSbyte);
}
void writeBH1750(byte val){
  Wire.beginTransmission(BH_1750F);
  Wire.write(val);
  Wire.endTransmission();
}
uint16_t readBH1750S(){
  uint8_t MSbyte, LSbyte;
  Wire.requestFrom(BH_1750S, 2);
  if(Wire.available()){
    MSbyte=Wire.read();
    LSbyte=Wire.read(); 
  }
  return ((MSbyte<<8) + LSbyte);
}
void writeBH1750S(byte val){
  Wire.beginTransmission(BH_1750S);
  Wire.write(val);
  Wire.endTransmission();
}
