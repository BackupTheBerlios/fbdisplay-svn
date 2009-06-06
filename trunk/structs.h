#ifndef __STRUCTS_H
#define __STRUCTS_H

#include <string.h>
#include <list>
#include "cobject.h"

enum clock_type {
    CLOCK_DIGI,
    CLOCK_DIGI_SEC,
    CLOCK_ANALOG,
    CLOCK_ANALOG_SEC
};

struct clockData
{
    unsigned int xPos;
    unsigned int yPos;
    unsigned int xSize;
    unsigned int ySize;
    clock_type type;
};

struct textData
{
    unsigned int xPos;
    unsigned int yPos;
    unsigned int xSize;
    unsigned int ySize;
    int speed;
    string * text;
};

struct graphicData
{
    unsigned int xPos;
    unsigned int yPos;
    unsigned int xSize;
    unsigned int ySize;
    string * text;
};

struct posData
{
    unsigned int xPos;
    unsigned int yPos;
    unsigned int xSize;
    unsigned int ySize;
};

union objData
{
    clockData dClock;
    textData dText;
    graphicData dGraphic;
    posData dPos;
};

enum eType {
    NOTVALID,
    CLOCK,
    TEXT,
    GRAPHIC
};

struct list_node {
    eType type;
    objData data;
    CObject* obj;
};

struct list_frame{
    std::list<list_node> * node;
    unsigned long ulTime;
    unsigned long ulID;
};

#endif
