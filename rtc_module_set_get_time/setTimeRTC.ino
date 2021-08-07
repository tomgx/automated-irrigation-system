#include <Ds1302.h>


// DS1302 RTC instance
// PIN_RST, PIN_CLK, PIN_DAT
Ds1302 rtc(8, 6, 7);


uint8_t parseDigits(char* str, uint8_t count)
{
    uint8_t val = 0;
    while(count-- > 0) val = (val * 10) + (*str++ - '0');
    return val;
}


void setup()
{
    // initialize the RTC
    rtc.init();

    Serial.begin(9600);
    // YEAR, MONTH, DATE, DAY OF WEEK(1 to 7), HOUR, MINUTE, SECOND
    Serial.println("Input the date and time (YYMMDDWhhmmss): ");
}


void loop()
{
    static char buffer[13];
    static uint8_t char_idx = 0;

    if (char_idx == 13)
    {
        // structure to manage date-time
        Ds1302::DateTime dt;

        dt.year = parseDigits(buffer, 2);
        dt.month = parseDigits(buffer + 2, 2);
        dt.day = parseDigits(buffer + 4, 2);
        dt.dow = parseDigits(buffer + 6, 1);
        dt.hour = parseDigits(buffer + 7, 2);
        dt.minute = parseDigits(buffer + 9, 2);
        dt.second = parseDigits(buffer + 11, 2);

        // set the date and time
        rtc.setDateTime(&dt);

        char_idx = 0;
    }

    if (Serial.available())
    {
        buffer[char_idx++] = Serial.read();
    }
}
