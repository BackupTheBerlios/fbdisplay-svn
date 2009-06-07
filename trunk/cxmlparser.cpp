#include "cxmlparser.h"

void parseFile(char * xmlName, std::list<list_frame> * pFrame)
{
    xmlDocPtr pDoc = NULL;
    xmlNodePtr pNode = NULL;

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
            list_frame pDummy;
            pDummy.node = NULL;
            pDummy.ulID = 0;
            pDummy.ulTime = 0;

            pFrame->push_back(pDummy);

            parseFrame(pDoc, pNode, &pFrame->back());
        }
        pNode = pNode->next;
    }

    xmlFreeDoc(pDoc);

    sortFrame(pFrame);

    return;
}

void parseFrame(xmlDocPtr pDoc, xmlNodePtr pNode, list_frame * pFrame)
{
    xmlChar * key = NULL;

    pNode = pNode->xmlChildrenNode;

    while (pNode != NULL)
    {
        if (!xmlStrcmp(pNode->name, (const xmlChar *)"object"))
        {
            list_node pDummy;;

            if (pFrame->node == NULL)
            {
                pFrame->node = new std::list<list_node>;
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

void parseObject(xmlDocPtr pDoc, xmlNodePtr pNode, list_node * pList)
{
    xmlChar * key = NULL;
    pNode = pNode->xmlChildrenNode;

    pList->type = getType(pDoc, pNode);
    switch (pList->type)
    {
        case GRAPHIC:
        {
            while(pNode != NULL)
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
            while(pNode != NULL)
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
            while(pNode != NULL)
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

void sortFrame(std::list<list_frame> * pFrame)
{
    if (pFrame == NULL)
    {
        return;
    }

    pFrame->sort(compareFrames);
    return;
}

bool compareFrames(list_frame first, list_frame second)
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
