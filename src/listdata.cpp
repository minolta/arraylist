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
void D::setTag(uint32_t t)
{
    tag = t;
}
uint32_t D::getTag()
{
    return tag;
}
void D::setTags(String t)
{
    tags = t;
}
String D::getTags()
{
    return tags;
}
void D::setDate(uint32_t d)
{
    date = d;
}
uint32_t D::getDate()
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
        {
            first = first->prv; //ขยับ first ไป node ถัดไป
        }
        else
            tail = first = NULL; //ถ้ามีอันเดียว
        size--;
    }
    return pointtofirst;
}
int DataList::getsize()
{
    return size;
}
void DataList::add(uint32_t cardid, uint32_t date, String tags)
{
    id++;
    size++;
    D *new_node = (D *)malloc(sizeof(D));
    new_node->next = NULL;
    new_node->prv = NULL;

    new_node->setId(id);
    new_node->setTag(cardid);
    new_node->setDate(date);
    new_node->setTags(tags);

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
        Serial.printf("\nDATA ID:%d  data:%zu date:%zu", point->getId(), point->getTag(), point->getDate());
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