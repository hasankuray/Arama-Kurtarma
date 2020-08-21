

void initNrfTrans() {
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  transmitter.channel(90);
  transmitter.TXaddress("tiny");
  transmitter.init();
}
void sendMessage(){
 transmitter.txPL(room);
 transmitter.send(FAST);
 delay(200); 
 Serial.println(room); 
}
