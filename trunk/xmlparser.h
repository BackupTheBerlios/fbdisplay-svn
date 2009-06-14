#ifndef __XML_PARSER_H
#define __XML_PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#include "cobject.h"
#include "cclockobj.h"

//structs
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

class objList_node
{
public:
    objList_node();
    objList_node(const objList_node &old);
    ~objList_node();
    eType type;
    objData data;
    CObject * obj;
};

class objList_frame
{
public:
    objList_frame();
    objList_frame(const objList_frame &old);
    ~objList_frame();
    std::list<objList_node> * node;
    unsigned long ulTime;
    unsigned long ulID;
};
//methods
void parseFile(char * xmlName, std::list<objList_frame> * pFrame);

void parseFrame(xmlDocPtr pDoc, xmlNodePtr pNode, objList_frame * pFrame);
void parseObject(xmlDocPtr pDoc, xmlNodePtr pNode, objList_node * pList);
eType getType(xmlDocPtr pDoc, xmlNodePtr pNode);
void getPos(const char * str, posData &dat);
void sortFrame(std::list<objList_frame> * pFrame);
bool compareFrames(objList_frame first, objList_frame second);
void removeFrames(std::list<objList_frame> * pFrame);
void removeFrames(std::list<objList_frame> * pFrame, std::list<objList_frame>::iterator itExept);



#endif
