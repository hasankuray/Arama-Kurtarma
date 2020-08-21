int calcLight() {
  int duration1;
  int duration2;
  while (1){
  if (digitalRead(ldr) == 0) { // 0 ken ışık var demek
    while (digitalRead(ldr) == 0) {
    }
    duration1 = millis();
    while (digitalRead(ldr) == 1) {
    }
    duration2 = millis();


  } else {
    while (digitalRead(ldr) == 1) {
    }
    duration1 = millis();
    while (digitalRead(ldr) == 0) {
    }
    duration2 = millis();


  }
  if(duration2 - duration1>20) break;
 }
 return (duration2 - duration1);
}

char whereAmI() {
  int value = calcLight();

  if (value < lightFreqs[0] + 100 && value > lightFreqs[0] - 100) room = 'A';
  else if (value < lightFreqs[1] + 100 && value > lightFreqs[1] - 100) room = 'B';
  else if (value < lightFreqs[2] + 100 && value > lightFreqs[2] - 100) room = 'C';
  else room ='D';
  return room;
}
