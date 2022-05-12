#include <Arduino.h>
#ifndef LISTDATA_H
#define LISTDATA_H

class D
{
private:
    int id;
    int tag;
    long date;

public:
    D *next; //ชี้จากต้นไปหาง
    D *prv; // จากหางไปตัวถัดไป
    void setId(int id);
    int getId();
    void setTag(int tag);
    int getTag();
    void setDate(long date);
    long getDate();
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
    void add(int data, long date);
    // next popup head data and remove
    D *next();
    void list();
    void hello();
    int getsize();
    D *getFirst();
};

#endif