void reading() {
  sensor = 0; //this is to refresh initial value
  sum = 0;
   int j;
    sensor ^= sensor;
 for(int I = 0, j = 0; I < NUM_SENSORS; I++,j++) {
  
      s[j] = digitalRead(sensor_pins[I]);

sensor = sensor << 1 | s[j] ;
sum = sum  + s[j];
  }
}
