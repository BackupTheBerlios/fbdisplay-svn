#include "xmlparser.h"

void parseFile(char * xmlName, std::list<objList_frame> * pFrame)
{
    xmlDocPtr pDoc = NULL;
    xmlNodePtr pNode = NULL;

    if (pFrame == NULL)
    {
        fprintf(stderr, "No list to store\n");
        return;
    }

    pDoc = xmlParseFile(xmlName);

    if (pDoc == NULL)
    {
        fprintf(stderr, "Parsing error\n");
        return;
    }

    pNode = xmlDocGetRootElement(pDoc);

    if (xmlStrcmp(pNode->name, (const xmlChar *)"fbdisplay"))
    {
        fprintf(stderr, "Wrong file type, root node != fbdisplay\n");
        xmlFreeDoc(pDoc);
        return;
    }

    pNode = pNode->xmlChildrenNode;

    while (pNode != NULL)
    {
        if ((!xmlStrcmp(pNode->name, (const xmlChar *)"frame")))
        {
            objList_frame pDummy;
            pDummy.node = NULL;
            pDummy.ulID = 0;
            pDummy.ulTime = 0;

            pFrame->push_back(pDummy);

            parseFrame(pDoc, pNode, &pFrame->back());
        }
        pNode = pNode->next;
    }

    xmlFreeDoc(pDoc);

//    sortFrame(pFrame);

    return;
}

void parseFrame(xmlDocPtr pDoc, xmlNodePtr pNode, objList_frame * pFrame)
{
    xmlChar * key = NULL;

    pNode = pNode->xmlChildrenNode;

    while (pNode != NULL)
    {
        if (!xmlStrcmp(pNode->name, (const xmlChar *)"object"))
        {
            objList_node pDummy;;

            if (pFrame->node == NULL)
            {
                pFrame->node = new std::list<objList_node>;
            }

            pDummy.obj = NULL;
            pDummy.type = NOTVALID;
            memset(&pDummy.data, 0, sizeof(objData));
            pFrame->node->push_back(pDummy);

            parseObject(pDoc, pNode, &pFrame->node->back());
        }
        else if (!xmlStrcmp(pNode->name, (const xmlChar *)"time"))
        {
            key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
            pFrame->ulTime = atol((const char *)key);
            xmlFree(key);
        }
        else if (!xmlStrcmp(pNode->name, (const xmlChar *)"id"))
        {
            key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
            pFrame->ulID = atol((const char *)key);
            xmlFree(key);
        }
        pNode = pNode->next;
    }
    return;
}

void parseObject(xmlDocPtr pDoc, xmlNodePtr pNode, objList_node * pList)
{
    xmlChar * key = NULL;
    pNode = pNode->xmlChildrenNode;

    pList->type = getType(pDoc, pNode);
    switch (pList->type)
    {
    case GRAPHIC:
    {
        while (pNode != NULL)
        {
            if (!xmlStrcmp(pNode->name, (const xmlChar *)"pos"))
            {
                key=xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                getPos((const char *)key, pList->data.dPos);
                xmlFree(key);
            }
            else if (!xmlStrcmp(pNode->name, (const xmlChar *)"path"))
            {
                key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                pList->data.dGraphic.text = new string((const char *)key);
                xmlFree(key);
            }
            pNode = pNode->next;
        }
        break;
    }
    case CLOCK:
    {
        while (pNode != NULL)
        {
            if (!xmlStrcmp(pNode->name, (const xmlChar *)"pos"))
            {
                key=xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                getPos((const char *)key, pList->data.dPos);
                xmlFree(key);
            }
            else if (!xmlStrcmp(pNode->name, (const xmlChar *)"clocktype"))
            {
                key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                if (!xmlStrcmp(key, (const xmlChar *)"digital"))
                {
                    pList->data.dClock.type = CLOCK_DIGI;
                }
                else if (!xmlStrcmp(key, (const xmlChar *)"digital_sec"))
                {
                    pList->data.dClock.type = CLOCK_DIGI_SEC;
                }
                else if (!xmlStrcmp(key, (const xmlChar *)"anoalog"))
                {
                    pList->data.dClock.type = CLOCK_ANALOG;
                }
                else if (!xmlStrcmp(key, (const xmlChar *)"analog_sec"))
                {
                    pList->data.dClock.type = CLOCK_ANALOG_SEC;
                }
                xmlFree(key);
            }
            pNode = pNode->next;
        }
        break;
    }
    case TEXT:
    {
        while (pNode != NULL)
        {
            if (!xmlStrcmp(pNode->name, (const xmlChar *)"pos"))
            {
                key=xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                getPos((const char *)key, pList->data.dPos);
                xmlFree(key);
            }
            else if (!xmlStrcmp(pNode->name, (const xmlChar *)"speed"))
            {
                key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                pList->data.dText.speed = atoi((const char *)key);
                xmlFree(key);
            }
            else if (!xmlStrcmp(pNode->name, (const xmlChar *)"data"))
            {
                key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                pList->data.dText.text = new string((const char *)key);
                xmlFree(key);
            }
            pNode = pNode->next;
        }
        break;
    }
    default:
        break;
    }
    return;
}

eType getType(xmlDocPtr pDoc, xmlNodePtr pNode)
{
    xmlChar * key = NULL;

    while (pNode != NULL)
    {
        if ((!xmlStrcmp(pNode->name, (const xmlChar *)"type")))
        {
            key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
            if (!xmlStrcmp(key, (const xmlChar *)"clock"))
            {
                xmlFree(key);
                return CLOCK;
            }
            if (!xmlStrcmp(key, (const xmlChar *)"text"))
            {
                xmlFree(key);
                return TEXT;
            }
            if (!xmlStrcmp(key, (const xmlChar *)"graphic"))
            {
                xmlFree(key);
                return GRAPHIC;
            }
            xmlFree(key);
        }
        pNode = pNode->next;
    }
    return NOTVALID;
}

void getPos(const char * str, posData &dat)
{
    dat.xPos = atoi(str);
    int i = 0;
    while (str[i] != ',') ++i;
    dat.yPos = atoi(str + ++i);
    while (str[i] != ',') ++i;
    dat.xSize = atoi(str + ++i);
    while (str[i] != ',') ++i;
    dat.ySize = atoi(str + ++i);
    return;
}

void sortFrame(std::list<objList_frame> * pFrame)
{
    if (pFrame == NULL)
    {
        return;
    }

    pFrame->sort(compareFrames);
    return;
}

bool compareFrames(objList_frame first, objList_frame second)
{
    if (first.ulID < second.ulID)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void removeFrames(std::list<objList_frame> * pFrame)
{
    pFrame->clear();
    return;
}

void removeFrames(std::list<objList_frame> * pFrame, std::list<objList_frame>::iterator itExept)
{
    std::list<objList_frame>::iterator itBegin;
    std::list<objList_frame>::iterator itEnd;

    itEnd = pFrame->end();
    itEnd--;
    if (itExept != itEnd)
    {
        itBegin = itExept;
        itBegin++;
        itEnd = pFrame->end();
        pFrame->erase(itBegin, itEnd);
    }
    itBegin = pFrame->begin();
    if (itExept != itBegin)
    {
        itEnd = itExept;
        pFrame->erase(itBegin,itEnd);
    }

    return;
}

objList_node::objList_node()
{
    type = NOTVALID;
    memset(&data, 0, sizeof(objData));
    obj = NULL;
    return;
}

objList_node::objList_node(const objList_node &old)
{
    type = old.type;
    memcpy(&data, &old.data, sizeof(objData));
    obj = old.obj;
    fprintf(stderr, "obj: %p\t old.obj: %p\n", obj, old.obj);
    return;
}

objList_node::~objList_node()
{
    if (type == TEXT)
    {
        if (data.dText.text != NULL)
        {
            delete data.dText.text;
            data.dText.text = NULL;
        }
    }
    else if (type == GRAPHIC)
    {
        if (data.dGraphic.text != NULL)
        {
            delete data.dGraphic.text;
            data.dGraphic.text = NULL;
        }
    }

    if (obj != NULL)
    {
        fprintf(stderr, "delete obj: %p\n", obj);
        delete obj;
        obj = NULL;
    }

    return;
}

objList_frame::objList_frame()
{
    node = NULL;
    ulID = 0;
    ulTime = 0;
    return;
}

objList_frame::objList_frame(const objList_frame &old)
{
    node = new std::list<objList_node>;
    if ((old.node != NULL) && (old.node->size() > 0))
    {
        for (std::list<objList_node>::iterator it = old.node->begin(); it != old.node->end();)
        {
            node->insert(node->end(), it, ++it);
        }
    }
    ulID = old.ulID;
    ulTime = old.ulTime;
    return;
}


objList_frame::~objList_frame()
{
    if (node != NULL)
    {
        delete node;
        node = NULL;
    }
    return;
}
