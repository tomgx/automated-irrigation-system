// if the moisture in the soil is less than this number, activate water pump
const int drySoil = 250;
// D12 pin used for water pump
const int waterPump = 12;
// A4 pin used for moisture sensor
const int moistureSensor = A0;

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
      //turn on water pump
      digitalWrite(waterPump, HIGH);
      //water for 2 seconds
      delay(2000);
      
     }else{
      //turn off water pump
      digitalWrite(waterPump, LOW);
      Serial.println("Watering complete. Moisture level: " String(moistureReading))
     }
}
