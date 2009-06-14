#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <asm/types.h>
#include <string.h>
#include <errno.h>
#include <linux/fb.h>
#include <signal.h>

#include "ctextobj.h"
#include "cclockobj.h"

#include "xmlparser.h"


void sighandler(int signum)
{
    return;
}

int main(int argc, char **argv)
{
    std::list<objList_frame> pFrameList;

    parseFile("test.xml", &pFrameList);

//    removeFrames(&pFrameList, ++pFrameList.begin());

    //Check parsed data
    fprintf(stderr, "Number of Frames: %i\n", pFrameList.size());
    std::list<objList_frame>::iterator itFrm = pFrameList.begin();
    std::list<objList_node>::iterator itNode = itFrm->node->begin();
    while (itFrm != pFrameList.end())
    {
        fprintf(stderr, "FrameID: %i\tFrametime: %i\n", itFrm->ulID, itFrm->ulTime);
        itNode = itFrm->node->begin();
        while (itNode != itFrm->node->end())
        {
            fprintf(stderr, "pos: %i %i %i %i\ttype: %i\n", itNode->data.dPos.xPos, itNode->data.dPos.yPos, itNode->data.dPos.xSize, itNode->data.dPos.ySize, itNode->type);
            itNode++;
        }
        itFrm++;
    }

    fprintf(stderr,"\nBegin Sort Algorithm\n\n");
    sortFrame(&pFrameList);

    //Check parsed data
    fprintf(stderr, "Number of Frames: %i\n", pFrameList.size());
    itFrm = pFrameList.begin();
    itNode = itFrm->node->begin();
    while (itFrm != pFrameList.end())
    {
        fprintf(stderr, "FrameID: %i\tFrametime: %i\n", itFrm->ulID, itFrm->ulTime);
        itNode = itFrm->node->begin();
        while (itNode != itFrm->node->end())
        {
            fprintf(stderr, "pos: %i %i %i %i\ttype: %i\n", itNode->data.dPos.xPos, itNode->data.dPos.yPos, itNode->data.dPos.xSize, itNode->data.dPos.ySize, itNode->type);
            itNode++;
        }
        itFrm++;
    }

    CTextObj* obj, *obj1;

    int fh;
    struct fbinfo info;
    struct fb_var_screeninfo var;

    signal(SIGHUP, sighandler);

    fh = open("/dev/fb0", O_RDWR);

    ioctl(fh, FBIOGET_VSCREENINFO, &var);

    info.xres = var.xres;
    info.yres = var.yres;

    info.pFB = (unsigned char*)mmap(NULL, info.xres*info.yres, PROT_WRITE | PROT_READ, MAP_SHARED, fh, 0);

    if (info.pFB==MAP_FAILED)
    {
        close(fh);
        return -1;
    }

    printf("\033[?25l"); // Cursor ausschalten
    fflush(stdout);

    memset(info.pFB, 0x00, info.xres*info.yres);

    obj = new CTextObj(info);
    obj->SetPos(20,30);
    obj->SetSize(100, 8);
    string test = "Hallo Welt!";
    obj->Init(test, 20);

    obj1 = new CTextObj(info);
    obj1->SetPos(75,3);
    obj1->SetSize(74, 8);
    string test1 = "test test!!";
    obj1->Init(test1, 75);

    CClockObj* obj3 = new CClockObj(info);
    obj3->SetPos(123,14);
    obj3->SetSize(60, 60);
    obj3->Init();

    CTextObj* obj4 = new CTextObj(info);
    obj4->SetPos(28,100);
    obj4->SetSize(200, 8);
    string test4 = "Test rueckwaerts";
    obj4->Init(test4, -75);

    CObject* o = obj;
    while(1)
    {
        o->Refresh();
        obj3->Refresh();
        obj1->Refresh();
        obj4->Refresh();

        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 1000000;
        nanosleep(&ts, NULL);
    }

    delete obj;

    return 0;
}
