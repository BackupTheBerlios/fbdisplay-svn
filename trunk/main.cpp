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
#include "pthread.h"

#include "ctextobj.h"
#include "cclockobj.h"
#include "cgraphicobj.h"

#include "xmlparser.h"

pthread_mutex_t ListMutex;
static stFrame * pFrameList = NULL;
static struct fbinfo info;

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

void timerhandler(int signum)
{
    long int lRetVal = 0;
    pthread_mutex_lock(&ListMutex);
    lRetVal = parseNextFrame("test.xml", pFrameList, &info);
//    fprintf(stderr, "\nBilddauer in sec: %u\n", pFrameList->ulTime);
//    printNodes(pFrameList);
    pthread_mutex_unlock(&ListMutex);

    struct itimerval itimerval;
    itimerval.it_interval.tv_sec = 0;
    itimerval.it_interval.tv_usec = 0;
    if (lRetVal < 0)
    {
        itimerval.it_value.tv_sec = 1;
    }
    else
    {
        itimerval.it_value.tv_sec = pFrameList->ulTime;
    }
    itimerval.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &itimerval, NULL);
    return;
}

int main(int argc, char **argv)
{
    lstNode *pEntry = NULL;

    int fh = 0;
    long int lRet = 0;
    struct itimerval itimerval={0};

    signal(SIGHUP, sighandler);
    signal(SIGALRM, timerhandler);

    fh = open("/dev/fb0", O_RDWR);

    info.var = new struct fb_var_screeninfo;
    ioctl(fh, FBIOGET_VSCREENINFO, info.var);
    info.fix = new struct fb_fix_screeninfo;
    ioctl(fh, FBIOGET_FSCREENINFO, info.fix);

    switch(info.var->bits_per_pixel)
    {
    case 8:
        info.cpp = 1;
        break;
    case 15:
    case 16:
        info.cpp = 2;
        break;
    case 24:
    case 32:
        info.cpp = 4;
        break;
    default:
        break;
    }

    info.size = info.var->xres * info.var->yres * info.cpp;

    info.pFB = (unsigned char*)mmap(NULL, info.size, PROT_WRITE | PROT_READ, MAP_SHARED, fh, 0);

    if (info.pFB==MAP_FAILED)
    {
        close(fh);
        return -1;
    }

    printf("\033[?25l"); // Cursor ausschalten
    fflush(stdout);

    memset(info.pFB, 0x00, info.size);

    pthread_mutex_init(&ListMutex, NULL);

    lRet = parseNextFrame("test.xml", pFrameList, &info);
    itimerval.it_interval.tv_sec = 0;
    itimerval.it_interval.tv_usec = 0;
    if (lRet < 0)
    {
        itimerval.it_value.tv_sec = 1;
    }
    else
    {
        itimerval.it_value.tv_sec = pFrameList->ulTime;
    }
    itimerval.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &itimerval, NULL);

    while(1)
    {
        pthread_mutex_lock(&ListMutex);
        list_for_each_entry(pEntry, &pFrameList->node->list, list)
        {

            if ((pEntry != NULL) && (pEntry->obj != NULL))
            {
                pEntry->obj->Refresh();
            }
        }
        pthread_mutex_unlock(&ListMutex);

        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 1000000;
        nanosleep(&ts, NULL);
    }

    struct timespec ts;
    ts.tv_sec = 10;
    ts.tv_nsec = 0;
    nanosleep(&ts, NULL);

    stFrame * pFrm = NULL;
    renewObjects(pFrameList, pFrm, &info);

    if(pFrameList != NULL)
    {
        if (pFrameList->node != NULL)
        {
            delete pFrameList->node;
            pFrameList->node = NULL;
        }
        delete pFrameList;
        pFrameList = NULL;
    }

    if (pFrm != NULL)
    {
        delete pFrm;
        pFrm = NULL;
    }

    if (info.var != NULL)
    {
        delete info.var;
        info.var = NULL;
    }

    if (info.fix != NULL)
    {
        delete info.fix;
        info.fix = NULL;
    }

    return 0;
}
