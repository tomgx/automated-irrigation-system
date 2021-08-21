// if the moisture senser value is greater than this number, activate water pump (need to calibrate manually for different plants)
const int drySoil = 480;
// D12 pin used for water pump
const int waterPump = 12;
// A0 pin used for moisture sensor
const int moistureSensor = A0;
//water for x amount seconds
const int timeOn = 4000;

//RTC Module Digital pin 8, 6, 7

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

//if moisture reading is greater than or equal to drySoil
     if (moistureReading >= drySoil){
      Serial.println("Watering plant(s) for " + String(timeOn) + " ms. Moisture level is currently: " + String(moistureReading));
      //turn on water pump
      digitalWrite(waterPump, LOW);
      delay(timeOn);
      digitalWrite(waterPump, HIGH);
      Serial.println("Done watering. Next check in 10 seconds.");
      delay(10000);
     }else {
      
//turn off water pump
      digitalWrite(waterPump, HIGH);
      
//if moistureReading is adequate for 10 times. Delay for 12 hours.
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
