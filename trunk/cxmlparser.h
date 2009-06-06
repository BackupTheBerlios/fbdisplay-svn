#ifndef __XML_PARSER_H
#define __XML_PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#include "structs.h"




    list_frame * parseFile(char * xmlName, list_frame * pFrame);


    void parseFrame(xmlDocPtr pDoc, xmlNodePtr pNode, list_frame * pFrame);
    void parseObject(xmlDocPtr pDoc, xmlNodePtr pNode, list_node * pList);
    eType getType(xmlDocPtr pDoc, xmlNodePtr pNode);
    void getPos(const char * str, posData &dat);


#endif
