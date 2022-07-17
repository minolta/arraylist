#include <Arduino.h>
#include <unity.h>
#include "listdata.h"

void testAddvalue(DataList *d, int size = 100)
{
    for (int i = 0; i < size; i++)
    {
        d->add(i, i * 1000, "xxxx");
    }
}
void testList()
{

    unsigned long f1 = ESP.getFreeHeap();
    DataList dl;
    testAddvalue(&dl);
    // dl.add(1,1000,"Data 1");
    // dl.add(2,2000,"DAta2");
    dl.list();
    unsigned long f2 = ESP.getFreeHeap();
    unsigned long f3 = ESP.getFreeHeap();
    Serial.printf("***** Before add value:  %ld  afteradd:%ld  diff %ld  free:%ld *****\n", f1, f2, (f1 - f2), f3);
}
void setup()
{

    // DataList dl;
    // dl.hello();
    // setled();
    // setupWiFi();
    // LITTLEFS.begin(true);
    Serial.begin(115200);
    // Serial.println("****** * * ** * * * *");
    pinMode(2, OUTPUT);
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();
    // RUN_TEST(printdata);
    // RUN_TEST(createFile);
    // RUN_TEST(countfile);
    RUN_TEST(testList);
    // RUN_TEST(saveDataforSendtofile);
    // RUN_TEST(testCheckdouble);
    // RUN_TEST(testPush);
    // RUN_TEST(testLED);
    // RUN_TEST(testRTCTONTP);
    UNITY_END();
}

void loop()
{
    digitalWrite(2, HIGH);
    delay(200);
    digitalWrite(2, LOW);
    delay(200);
}