#ifndef __XML_PARSER_H
#define __XML_PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "initng_list.h"

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

union lstData
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

struct lstNode
{
    struct list_head list;
    eType type;
    lstData data;
    CObject * obj;
};

struct stFrame
{
    lstNode *node;
    unsigned long ulTime;
    unsigned long ulID;
};

struct lstIDs
{
    struct list_head list;
    unsigned long int ulID;
    xmlNodePtr pFrm;
};

//methods
long int parseNextFrame(char *xmlName, stFrame *&pFrame);
xmlNodePtr findNextFrame(xmlDocPtr pDoc, xmlNodePtr pNode, stFrame *pFrame);
void parseFrameContent(xmlDocPtr pDoc, xmlNodePtr pNode, stFrame *pFrame);
void parseObject(xmlDocPtr pDoc, xmlNodePtr pNode, lstNode *pList);
eType getType(xmlDocPtr pDoc, xmlNodePtr pNode);
void getPos(const char * str, posData &dat);
void renewObjects(stFrame *pFrame, stFrame *pNewFrame);

#endif
