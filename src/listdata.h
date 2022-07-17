#include <Arduino.h>
#ifndef LISTDATA_H
#define LISTDATA_H

class D
{
private:
    int id;
    uint32_t tag;
    char tags[16];
    uint32_t date;

public:
    D *next; //ชี้จากต้นไปหาง
    D *prv;  // จากหางไปตัวถัดไป
    void setId(int id);
    int getId();
    void setTag(uint32_t tag);
    void setTags(String tags);
    uint32_t getTag();
    void setDate(uint32_t date);
    uint32_t getDate();
    String getTags();
    D clone();
};

/**
 * @brief เป็นระบบเข้าก่อนออกก่อน Queue
 *
 */
class DataList

{
private:
    D *tail = NULL;
    D *first = NULL; //สำหรับชี้อไปตัวแรก
    int size = 0;
    int id = 0;

public:
    void add(uint32_t data, uint32_t date, String tags);
    // next popup head data and remove
    D *next();
    void list();
    void hello();
    int getsize();
    D *getFirst();
};

#endif