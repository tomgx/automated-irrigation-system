#include <Ds1302.h>


// DS1302 RTC instance
// PIN_RST, PIN_CLK, PIN_DAT
Ds1302 rtc(8, 6, 7);


const static char* WeekDays[] =
{
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday",
  "Sunday"
};


void setup()
{
  Serial.begin(9600);

  // initialize RTC
  rtc.init();

  // test if clock is halted and set a date-time
  if (rtc.isHalted())
  {
    Serial.println("RTC is halted. Setting time...");

    Ds1302::DateTime dt = {
      .year = 21,
      .month = Ds1302::MONTH_AUG,
      .day = 7,
      .hour = 22,
      .minute = 38,
      .second = 05,
      .dow = Ds1302::DOW_SAT
    };

    rtc.setDateTime(&dt);
  }
}


void loop()
{
  // get the current time
  Ds1302::DateTime now;
  rtc.getDateTime(&now);

  static uint8_t last_second = 0;
  if (last_second != now.second)
  {
    last_second = now.second;

    Serial.print("20");
    Serial.print(now.year);    // 00-99
    Serial.print('-');
    if (now.month < 10) Serial.print('0');
    Serial.print(now.month);   // 01-12
    Serial.print('-');
    if (now.day < 10) Serial.print('0');
    Serial.print(now.day);     // 01-31
    Serial.print(' ');
    Serial.print(WeekDays[now.dow - 1]); // 1-7
    Serial.print(' ');
    if (now.hour < 10) Serial.print('0');
    Serial.print(now.hour);    // 00-23
    Serial.print(':');
    if (now.minute < 10) Serial.print('0');
    Serial.print(now.minute);  // 00-59
    Serial.print(':');
    if (now.second < 10) Serial.print('0');
    Serial.print(now.second);  // 00-59
    Serial.println();
  }

  delay(100);
}
