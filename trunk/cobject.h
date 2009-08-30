#ifndef __COBJECT_H
#define __COBJECT_H

#include <sys/time.h>
#include <string>
#include <linux/fb.h>
using namespace std;

struct fbinfo {
    unsigned char* pFB;
    struct fb_var_screeninfo* var;
    struct fb_fix_screeninfo* fix;
    unsigned char cpp;
    size_t size;
};

class CObject
{
protected:
    static struct fbinfo m_fbinfo;
    unsigned int m_iXpos;
    unsigned int m_iYpos;
    unsigned int m_iXsize;
    unsigned int m_iYsize;
public:
    CObject(const struct fbinfo& info);
    virtual ~CObject();
    virtual bool Refresh(void) = 0;
    void SetPos(unsigned int x, unsigned int y);
    void GetPos(unsigned int& x, unsigned int& y);
    void SetSize(unsigned int x, unsigned int y);
    void GetSize(unsigned int& x, unsigned int& y);
    static void SetPixel(unsigned int x, unsigned int y, unsigned char color);
    static void DrawHLine(unsigned int x, unsigned int y, unsigned int len, unsigned char color);
    static void DrawVLine(unsigned int x, unsigned int y, unsigned int len, unsigned char color);
    static void DrawRect(unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height, unsigned char color, unsigned char bFill);
    static void DrawCircle(unsigned short x0, unsigned short y0, unsigned short radius);
    static void gbham(short xstart, short ystart, short xend ,short yend);
};

#endif

