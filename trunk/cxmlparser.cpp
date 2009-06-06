#include "cxmlparser.h"

list_frame * parseFile(char * xmlName, list_frame * pFrame)
{
    xmlDocPtr pDoc = NULL;
    xmlNodePtr pNode = NULL;

    list_frame * pFrmStart = pFrame;
    list_node * pList = NULL;

    pDoc = xmlParseFile(xmlName);

    if (pDoc == NULL)
    {
        fprintf(stderr, "Parsing error\n");
        return pFrame;
    }

    pNode = xmlDocGetRootElement(pDoc);

    if (xmlStrcmp(pNode->name, (const xmlChar *)"fbdisplay"))
    {
        fprintf(stderr, "Wrong file type, root node != fbdisplay\n");
        xmlFreeDoc(pDoc);
        return pFrame;
    }

    pNode = pNode->xmlChildrenNode;
    while (pNode != NULL)
    {
        if ((!xmlStrcmp(pNode->name, (const xmlChar *)"frame")))
        {
            if (pFrame == NULL)
            {
                pFrame = new list_frame;
                pFrmStart = pFrame;
                pFrame->next = NULL;
                pFrame->node = NULL;

                parseFrame(pDoc, pNode, pFrame);
            }
            else
            {
                pFrame->next = new list_frame;
                pFrame->next->next = NULL;
                pFrame->next->node = NULL;
                pFrame = pFrame->next;

                parseFrame(pDoc, pNode, pFrame);
            }
        }
        pNode = pNode->next;
    }

    xmlFreeDoc(pDoc);

    return pFrmStart;
}

void parseFrame(xmlDocPtr pDoc, xmlNodePtr pNode, list_frame * pFrame)
{
    xmlChar * key = NULL;
    list_node * pList = pFrame->node;

    pNode = pNode->xmlChildrenNode;

    while (pNode != NULL)
    {
        if (!xmlStrcmp(pNode->name, (const xmlChar *)"object"))
        {
            if (pList == NULL)
            {
                pFrame->node = new list_node;
                pList = pFrame->node;
            }
            else
            {
                pList->next = new list_node;
                pList = pList->next;
            }
            pList->next = NULL;
            pList->type = NOTVALID;
            pList->obj = NULL;
            memset(&pList->data, 0, sizeof(objData));
            parseObject(pDoc, pNode, pList);
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
