void initNrf() {
  delay(150);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  receiver.channel(90);
  receiver.RXaddress("tiny");
  receiver.init();
  Serial.begin(9600);
  }

  void takeMessage(){
  while (message == ""){
     if(receiver.available()){
          receiver.read();
          receiver.rxPL(message);
     if(message != ""){
      Serial.println(message);


  }
     }
  }
  }
