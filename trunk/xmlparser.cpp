#include "xmlparser.h"

long int parseNextFrame(char *xmlName, stFrame *&pFrame, fbinfo *info)
{
    xmlDocPtr pDoc = NULL;
    xmlNodePtr pFirstNode = NULL;
    xmlNodePtr pNode = NULL;
    stFrame * pNewFrame = NULL;

    if ((xmlName == NULL) || (strlen(xmlName) == 0))
    {
        fprintf(stderr, "No file name\n");
        return -1;
    }

    pDoc = xmlParseFile(xmlName);

    if (pDoc == NULL)
    {
        fprintf(stderr, "xmlParseFile error\n");
        return -1;
    }

    pNode = xmlDocGetRootElement(pDoc);

    if (xmlStrcmp(pNode->name, (const xmlChar *)"fbdisplay"))
    {
        fprintf(stderr, "Wrong file type, root node != fbdisplay\n");
        xmlFreeDoc(pDoc);
        return -1;
    }

    pNewFrame = new stFrame;
    memset(pNewFrame, 0, sizeof(stFrame));

    pFirstNode = pNode->xmlChildrenNode;

    pNode = findNextFrame(pDoc, pFirstNode, pFrame);
    parseFrameContent(pDoc, pNode, pNewFrame);
    renewObjects(pFrame, pNewFrame, info);

    if (pFrame != NULL)
    {
        delete pFrame;
    }
    pFrame = pNewFrame;
    pNewFrame = NULL;

    xmlFreeDoc(pDoc);
    pDoc = NULL;
    return 0;
}

xmlNodePtr findNextFrame(xmlDocPtr pDoc, xmlNodePtr pNode, stFrame *pFrame)
{
    xmlNodePtr pFirstNode = pNode, pXmlTmp = NULL, pFrm = NULL;
    xmlChar *key = NULL;
    struct list_head *pos = NULL, *q = NULL;
    lstIDs *pTemp = NULL, *pHigher = NULL, *pSmallest = NULL;

    lstIDs idList;
    memset(&idList, 0, sizeof(lstIDs));
    INIT_LIST_HEAD(&idList.list);

    while (pNode != NULL)   //Search all Frame-IDs and store in list
    {
        if ((!xmlStrcmp(pNode->name, (const xmlChar *)"frame")))
        {
            pFrm = pNode->xmlChildrenNode;
            while (pFrm != NULL)
            {
                if (!xmlStrcmp(pFrm->name, (const xmlChar *)"id"))
                {
                    pTemp = new lstIDs;
                    memset(pTemp, 0, sizeof(lstIDs));
                    key = xmlNodeListGetString(pDoc, pFrm->xmlChildrenNode, 1);
                    pTemp->ulID = atol((const char *)key);
                    pTemp->pFrm = pNode;
                    xmlFree(key);
                    list_add(&(pTemp->list), &(idList.list));
                    pTemp = NULL;
                    break;
                }
                pFrm = pFrm->next;
            }
        }
        pFrm = NULL;
        pNode = pNode->next;
    }

    list_for_each_entry(pTemp, &idList.list, list)    //Search next Frame-ID in list
    {
        if (pFrame != NULL)
        {
            if (pHigher == NULL)
            {
                if (pTemp->ulID > pFrame->ulID)
                {
                    pHigher = pTemp;
                }
            }
            else if (pHigher->ulID > pTemp->ulID > pFrame->ulID)
            {
                pHigher = pTemp;
            }
        }

        if (pSmallest == NULL)
        {
            pSmallest = pTemp;
        }
        else if (pTemp->ulID < pSmallest->ulID)
        {
            pSmallest = pTemp;
        }
    }

    if (pHigher != NULL)
    {
        pXmlTmp = pHigher->pFrm;
    }
    else if (pSmallest != NULL)
    {
        pXmlTmp = pSmallest->pFrm;
    }
    else
    {
        return NULL;
    }

    pHigher = NULL;
    pSmallest = NULL;
    pTemp = NULL;

    list_for_each_safe(pos, q, &idList.list)    //Clear list
    {
        pTemp = list_entry(pos, struct lstIDs, list);
        list_del(pos);
        delete pTemp;
        pTemp = NULL;
    }

    return pXmlTmp;
}

void parseFrameContent(xmlDocPtr pDoc, xmlNodePtr pNode, stFrame *pFrame)
{
    xmlChar *key = NULL;
    lstNode *pTemp = NULL;

    pNode = pNode->xmlChildrenNode;

    while (pNode != NULL)
    {
        if (!xmlStrcmp(pNode->name, (const xmlChar *)"object"))
        {
            pTemp = new lstNode;
            memset(pTemp, 0, sizeof(lstNode));
            if (pFrame->node == NULL)
            {
                pFrame->node = new lstNode;
                INIT_LIST_HEAD(&pFrame->node->list);
            }
            pTemp->obj = NULL;
            pTemp->type = NOTVALID;
            memset(&pTemp->data, 0, sizeof(lstData));
            parseObject(pDoc, pNode, pTemp);
            list_add(&(pTemp->list), &(pFrame->node->list));
            pTemp = NULL;
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

void parseObject(xmlDocPtr pDoc, xmlNodePtr pNode, lstNode *pList)
{
    xmlChar *key = NULL;
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
            else if (!xmlStrcmp(pNode->name, (const xmlChar *)"id"))
            {
                key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                pList->data.dGraphic.id = atoi((const char *)key);
                xmlFree(key);
            }
            else if (!xmlStrcmp(pNode->name, (const xmlChar *)"path"))
            {
                key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                pList->data.dGraphic.path = new string((const char *)key);
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
            else if (!xmlStrcmp(pNode->name, (const xmlChar *)"id"))
            {
                key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                pList->data.dClock.id = atoi((const char *)key);
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
            else if (!xmlStrcmp(pNode->name, (const xmlChar *)"id"))
            {
                key = xmlNodeListGetString(pDoc, pNode->xmlChildrenNode, 1);
                pList->data.dText.id = atoi((const char *)key);
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

void renewObjects(stFrame *pFrame, stFrame *pNewFrame, fbinfo *info)
{
    lstNode *pFrmTemp = NULL, *pFrmTempOld = NULL;
    struct list_head *pos = NULL, *q = NULL;

    //Search existent objects
    if ((pFrame != NULL) && (pFrame->node != NULL) && (pNewFrame != NULL))
    {
        list_for_each_entry(pFrmTemp, &pNewFrame->node->list, list)
        {
            list_for_each_entry(pFrmTempOld, &pFrame->node->list, list)
            {
                if ((pFrmTemp->type == pFrmTempOld->type) &&
                    (pFrmTemp->data.dPos.id == pFrmTempOld->data.dPos.id) &&
                    (pFrmTemp->data.dPos.xPos == pFrmTempOld->data.dPos.xPos) &&
                    (pFrmTemp->data.dPos.yPos == pFrmTempOld->data.dPos.yPos) &&
                    (pFrmTemp->data.dPos.xSize == pFrmTempOld->data.dPos.xSize) &&
                    (pFrmTemp->data.dPos.ySize == pFrmTempOld->data.dPos.ySize))
                {
                    if(pFrmTemp->type == GRAPHIC)
                    {
                        if (pFrmTemp->data.dGraphic.path->compare(*pFrmTempOld->data.dGraphic.path) == 0)
                        {
                            break;
                        }
                    }
                    else if (pFrmTemp->type == TEXT)
                    {
                        if ((pFrmTemp->data.dText.speed == pFrmTempOld->data.dText.speed) &&
                            (pFrmTemp->data.dText.text->compare(*pFrmTempOld->data.dText.text) == 0))
                        {
                            break;
                        }
                    }
                    else if (pFrmTemp->type == CLOCK)
                    {
                        if (pFrmTemp->data.dClock.type == pFrmTempOld->data.dClock.type)
                        {
                            break;
                        }
                    }
                }
            }
            if (&pFrmTempOld->list != (&pFrame->node->list))
            {
                pFrmTemp->obj = pFrmTempOld->obj;
                pFrmTempOld->obj = NULL;
            }

        }
    }
    if ((pFrame != NULL) && (pFrame->node != NULL))
    {
        //delete current
        list_for_each_safe(pos, q, &pFrame->node->list)
        {
            pFrmTemp = list_entry(pos, struct lstNode, list);
            list_del(pos);
            if (pFrmTemp->obj != NULL)
            {
                delete pFrmTemp->obj;
            }
            pFrmTemp->obj = NULL;
            if ((pFrmTemp->type == TEXT) && (pFrmTemp->data.dText.text != NULL))
            {
                delete pFrmTemp->data.dText.text;
                pFrmTemp->data.dText.text = NULL;
            }
            else if ((pFrmTemp->type == GRAPHIC) && (pFrmTemp->data.dGraphic.path != NULL))
            {
                delete pFrmTemp->data.dGraphic.path;
                pFrmTemp->data.dGraphic.path = NULL;
            }
            delete pFrmTemp;
            pFrmTemp = NULL;
        }
        delete pFrame->node;
        pFrame->node = NULL;
    }

    if (pNewFrame != NULL)
    {
        //konstruct new
        list_for_each_entry(pFrmTemp, &pNewFrame->node->list, list)
        {
            if (pFrmTemp->obj == NULL)
            {
                switch (pFrmTemp->type)
                {
                case GRAPHIC:
                    pFrmTemp->obj = new CGraphicObj(*info);
                    ((CGraphicObj *)(pFrmTemp->obj))->SetPos(pFrmTemp->data.dGraphic.xPos,pFrmTemp->data.dGraphic.yPos);
                    ((CGraphicObj *)(pFrmTemp->obj))->SetSize(pFrmTemp->data.dGraphic.xSize, pFrmTemp->data.dGraphic.ySize);
                    ((CGraphicObj *)(pFrmTemp->obj))->Init(*pFrmTemp->data.dGraphic.path);
                    break;
                case TEXT:
                    pFrmTemp->obj = new CTextObj(*info);
                    ((CTextObj *)(pFrmTemp->obj))->SetPos(pFrmTemp->data.dText.xPos,pFrmTemp->data.dText.yPos);
                    ((CTextObj *)(pFrmTemp->obj))->SetSize(pFrmTemp->data.dText.xSize, pFrmTemp->data.dText.ySize);
                    ((CTextObj *)(pFrmTemp->obj))->Init(*pFrmTemp->data.dText.text, pFrmTemp->data.dText.speed);
                    break;
                case CLOCK:
                    pFrmTemp->obj = new CClockObj(*info);
                    ((CClockObj *)(pFrmTemp->obj))->SetPos(pFrmTemp->data.dClock.xPos,pFrmTemp->data.dClock.yPos);
                    ((CClockObj *)(pFrmTemp->obj))->SetSize(pFrmTemp->data.dClock.xSize, pFrmTemp->data.dClock.ySize);
                    ((CClockObj *)(pFrmTemp->obj))->SetClockType(pFrmTemp->data.dClock.type);
                    ((CClockObj *)(pFrmTemp->obj))->Init();
                    break;
                default:
                    break;
                }
            }
        }
    }
    return;
}
