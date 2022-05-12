#include "listdata.h"
void D::setId(int d)
{
    id = d;
}
D D::clone()
{
    D clone;
    clone.setDate(date);
    clone.setId(id);
    clone.setTag(tag);
    return clone;
}
int D::getId()
{
    return id;
}
void D::setTag(int t)
{
    tag = t;
}
int D::getTag()
{
    return tag;
}
void D::setDate(long d)
{
    date = d;
}
long D::getDate()
{
    return date;
}

D *DataList::getFirst()
{
    D *pointtofirst = NULL;
    if (first != NULL)
    {
        pointtofirst = first;
        if (first->prv != NULL)
            first = first->prv; //ขยับ first ไป node ถัดไป
        else
            first = NULL; //ถ้ามีอันเดียว
    }
    return pointtofirst;
}
int DataList::getsize()
{
    return size;
}
void DataList::add(int data, long date)
{
    id++;
    size++;
    D *new_node = (D *)malloc(sizeof(D));
    new_node->next = NULL;
    new_node->prv = NULL;

    new_node->setId(id);
    new_node->setTag(data);
    new_node->setDate(date);

    if (tail != NULL)
    {
        new_node->next = tail; // new node ชี้ไป  node ก่อนหน้า
        tail->prv = new_node;  // node เก่า ชี้ไปพูกกับตัว node ใหม่
        tail = new_node;       //ขยับ
    }
    else
    {
        tail = new_node;
        first = new_node;
    }
}
void DataList::hello()
{
    Serial.println("Hello");
}
void DataList::list()
{
    D *point = first;
    while (point != NULL)
    {
        Serial.printf("DATA ID:%d  data:%d date:%ld\n", point->getId(), point->getTag(), point->getDate());
        point = point->prv;
    }
    Serial.println("DATALIST");
}
D *DataList::next()
{
    if (tail != NULL)
    {
        size--;
        D *last = tail;
        tail = tail->next;
        return last;
    }

    return tail;
}