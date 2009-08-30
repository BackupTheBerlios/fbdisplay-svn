#include "cobject.h"
#include <string.h>

struct fbinfo CObject::m_fbinfo = {0};

CObject::CObject(const struct fbinfo& info)
{
    m_fbinfo = info;
    m_iXpos = 0;
    m_iYpos = 0;
    m_iXsize = 0;
    m_iYsize = 0;
}

CObject::~CObject()
{
    int i;
    unsigned char* fbptr;
    fbptr = m_fbinfo.pFB + (m_iYpos * m_fbinfo.var->xres + m_iXpos) * m_fbinfo.cpp;
    for(i = 0; i < m_iYsize; i++, fbptr += m_fbinfo.var->xres * m_fbinfo.cpp)
        memset(fbptr, 0, m_iXsize * m_fbinfo.cpp);
}

void CObject::SetPos(unsigned int x, unsigned int y)
{
    m_iXpos = x;
    m_iYpos = y;
}

void CObject::GetPos(unsigned int& x, unsigned int& y)
{
    x = m_iXpos;
    y = m_iYpos;
}

void CObject::SetSize(unsigned int x, unsigned int y)
{
    m_iXsize = x;
    m_iYsize = y;
}

void CObject::GetSize(unsigned int& x, unsigned int& y)
{
    x = m_iXsize;
    y = m_iYsize;
}

void CObject::SetPixel(unsigned int x, unsigned int y, unsigned char color)
{
    if (y < m_fbinfo.var->yres && x < m_fbinfo.var->xres)
    {
        unsigned long  ulOffset = y * m_fbinfo.var->xres * m_fbinfo.cpp + x * m_fbinfo.cpp;

        if(color > 0)
          color = 0xff;

        m_fbinfo.pFB[ulOffset] = color;
        if (m_fbinfo.cpp >= 2)
            m_fbinfo.pFB[++ulOffset] = color;
        if (m_fbinfo.cpp == 4)
        {
            m_fbinfo.pFB[++ulOffset] = color;
            m_fbinfo.pFB[++ulOffset] = color;
        }
    }
    return;
}

void CObject::DrawHLine(unsigned int x, unsigned int y, unsigned int len, unsigned char color)
{
  unsigned int idx;

  for(idx = x; idx < (x + len); idx++)
    CObject::SetPixel(idx, y, color);
}

void CObject::DrawVLine(unsigned int x, unsigned int y, unsigned int len, unsigned char color)
{
  unsigned int idx;

  for(idx = y; idx < (y + len); idx++)
    SetPixel(x, idx, color);
}

void CObject::DrawRect(unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height, unsigned char color, unsigned char bFill)
{
  unsigned int x, y;

  for(x = xpos; x < (xpos + width); x++)
    for(y = ypos; y < (ypos + height); y++)
      if(bFill > 0)
        SetPixel(x, y, color);
      else
        if( (x == xpos) || (x == (xpos + width)) |
            (y == ypos) || (y == (ypos + height)) )
          SetPixel(x, y, color);
}

void CObject::gbham(short xstart, short ystart, short xend ,short yend)
/************************************************************************
 * Bresenham-Algorithmus: Linien auf Rastergeräten zeichnen
 *
 * Eingabeparameter:
 *    int xstart, ystart     = Koordinaten des Startpunkts
 *    int xend, yend         = Koordinaten des Endpunkts
 *
 ***********************************************************************/
{
  short x, y, t, dist, xerr, yerr, dx, dy, incx, incy;

/* Entfernung in beiden Dimensionen berechnen */
     dx = xend - xstart;
     dy = yend - ystart;

/* Vorzeichen des Inkrements bestimmen */
     if(dx<0)
     {
       incx = -1;
       dx = -dx;
     }
     else
       incx = dx ? 1 : 0;

     if(dy < 0)
     {
       incy = -1;
       dy = -dy;
     }
     else
       incy = dy ? 1 : 0;

//** feststellen, welche Entfernung größer ist
     dist = (dx > dy)?dx:dy;

//** Initialisierungen vor Schleifenbeginn
     x = xstart;
     y = ystart;
     xerr = yerr = (dist) >> 1; //dx;
     // yerr = dist >> 1; //dy1;

//** Pixel berechnen
     for(t = 0; t < dist; ++t)
     {
       SetPixel(x, y, 0xff);

       xerr += dx;
       yerr += dy;

       if(xerr >= dist)
       {
         xerr -= dist;
         x += incx;
       }

       if(yerr >= dist)
       {
         yerr -= dist;
         y += incy;
       }
     }

     SetPixel(x, y, 0xff);
}

void CObject::DrawCircle(unsigned short x0, unsigned short y0, unsigned short radius)
{
    int f = 1 - radius;
    int ddF_x = 0;
    int ddF_y = -2 * radius;
    int x = 0;
    int y = radius;

    SetPixel(x0, y0 + radius, 0xff);
    SetPixel(x0, y0 - radius, 0xff);
    SetPixel(x0 + radius, y0, 0xff);
    SetPixel(x0 - radius, y0, 0xff);

    while(x < y)
    {
        if(f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x + 1;

        SetPixel(x0 + x, y0 + y, 0xff);
        SetPixel(x0 - x, y0 + y, 0xff);
        SetPixel(x0 + x, y0 - y, 0xff);
        SetPixel(x0 - x, y0 - y, 0xff);
        SetPixel(x0 + y, y0 + x, 0xff);
        SetPixel(x0 - y, y0 + x, 0xff);
        SetPixel(x0 + y, y0 - x, 0xff);
        SetPixel(x0 - y, y0 - x, 0xff);
    }
}
