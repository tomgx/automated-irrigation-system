// if the moisture in the soil is less than this number, activate water pump
const int dry = 270;
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

}
