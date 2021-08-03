// if the moisture senser value is greater than this number, activate water pump
const int drySoil = 600;
// D12 pin used for water pump
const int waterPump = 12;
// A0 pin used for moisture sensor
const int moistureSensor = A0;

//delay: 1 second, 1 minute, 1 hours, 1 day. 
const long oneSecond = 1000;
const long oneMinute = oneSecond * 60;
const long oneHour   = oneMinute * 60;
const long oneDay    = oneHour * 24;

void setup() {
  pinMode(waterPump, OUTPUT);
  pinMode(moistureSensor, INPUT);
  Serial.begin(9600);
  digitalWrite(waterPump, HIGH);  
}

void delayOnceStable() {
  Serial.println("Soil moisture is good, next check in: 12 hours");
        delay(oneHour * 12);
        return;
}

void loop() {
  int moistureReading = analogRead(moistureSensor);
  delay(1000);

//if moisture reading is greater than or equal to 600
     if (moistureReading >= drySoil){
      Serial.println("Watering plant(s) for 2 seconds. Moisture level is currently: " + String(moistureReading));
      //turn on water pump
      digitalWrite(waterPump, LOW);
      //water for 2 seconds
      delay(2000);
      digitalWrite(waterPump, HIGH);
      Serial.println("Done watering.");
      delay(2000);
     }else {
      
//turn off water pump
      digitalWrite(waterPump, HIGH);
      
//if moistureReading is adequate for 5 times. Sleep for 1 Day.
      int i = 0;
       
      while (i < 10) {
        delay(10000);
       
        if ( moistureReading < drySoil) {
          int moistureReading = analogRead(moistureSensor);
          Serial.println("Soil moisture level is: " + String(moistureReading));
          delay(oneSecond);

          if (moistureReading >= drySoil) {
            break;  
            }else {
            i++;
            }}}
          
          if(i == 10) {
          delayOnceStable();
          }
        }}
