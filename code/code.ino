// if the moisture in the soil is less than this number, activate water pump
const int drySoil = 270;
// D12 pin used for water pump
const int waterPump = 12;
// A4 pin used for moisture sensor
const int moistureSensor = A4;

void setup() {
  pinMode(waterPump, OUTPUT);
  pinMode(moistureSensor, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  int moistureReading = analogRead(moistureSensor);
     Serial.println(moistureReading);
     delay(3000);

     if (moistureReading >= drySoil){
      Serial.println("Watering plant(s) for 2 seconds. Moisture level is currently: " + String(moistureReading));
      digitalWrite(waterPump, LOW);
      delay(2000);
      //water for 2 seconds
     }else{
      digitalWrite(waterPump, HIGH);
     }
}
