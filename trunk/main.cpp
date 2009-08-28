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
#include "cgraphicobj.h"

#include "xmlparser.h"


void sighandler(int signum)
{
    return;
}

void printNodes(stFrame * pFrameList)
{
    struct lstNode *tmp = NULL;

    fprintf(stderr, "ID: %u\tTime: %u\n", pFrameList->ulID, pFrameList->ulTime);

    list_for_each_entry(tmp, &pFrameList->node->list, list)
    {
        fprintf(stderr, "pos: %u %u %u %u\ttype: %u\n", tmp->data.dPos.xPos, tmp->data.dPos.yPos, tmp->data.dPos.xSize, tmp->data.dPos.ySize, tmp->type);
        fprintf(stderr, "id: %u\tobjPtr: %p\n", tmp->data.dPos.id, tmp->obj);
    }
    return;
}

int main(int argc, char **argv)
{
    stFrame * pFrameList = NULL;
    lstNode *pEntry = NULL;

    int fh;
    struct fbinfo info;
    struct fb_var_screeninfo var;

    unsigned long ulTimer = 0, ulTimeNext = 0;

    signal(SIGHUP, sighandler);

    fh = open("/dev/fb0", O_RDWR);

    ioctl(fh, FBIOGET_VSCREENINFO, &var);

    info.var = new struct fb_var_screeninfo;
    ioctl(fh, FBIOGET_VSCREENINFO, info.var);
    info.fix = new struct fb_fix_screeninfo;
    ioctl(fh, FBIOGET_FSCREENINFO, info.fix);
    info.size = info.var->xres * info.var->yres;

    info.pFB = (unsigned char*)mmap(NULL, info.size, PROT_WRITE | PROT_READ, MAP_SHARED, fh, 0);

    if (info.pFB==MAP_FAILED)
    {
        close(fh);
        return -1;
    }

    printf("\033[?25l"); // Cursor ausschalten
    fflush(stdout);

    memset(info.pFB, 0x00, info.size);

    parseNextFrame("test.xml", pFrameList, &info);
    ulTimeNext = ulTimer + pFrameList->ulTime * 1000;
    while(1)
    {
        if (ulTimer > ulTimeNext)
        {
            parseNextFrame("test.xml", pFrameList, &info);
            fprintf(stderr, "\nBilddauer in sec: %u\n", pFrameList->ulTime);
            printNodes(pFrameList);
            ulTimeNext = ulTimer + pFrameList->ulTime * 1000;
        }

        list_for_each_entry(pEntry, &pFrameList->node->list, list)
        {
            if (pEntry->obj != NULL)
            {
                pEntry->obj->Refresh();
            }
        }

        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 1000000;
        nanosleep(&ts, NULL);
        ++ulTimer;
    }

    return 0;
}
