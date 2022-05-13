#include <Arduino.h>
#ifndef LISTDATA_H
#define LISTDATA_H

class D
{
private:
    int id;
    uint32_t tag;
    uint32_t date;

public:
    D *next; //ชี้จากต้นไปหาง
    D *prv; // จากหางไปตัวถัดไป
    void setId(int id);
    int getId();
    void setTag(uint32_t tag);
    uint32_t getTag();
    void setDate(uint32_t date);
    uint32_t getDate();
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
    void add(uint32_t data, uint32_t date);
    // next popup head data and remove
    D *next();
    void list();
    void hello();
    int getsize();
    D *getFirst();
};

#endif