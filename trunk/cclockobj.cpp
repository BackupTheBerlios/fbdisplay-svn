#include "cclockobj.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

CClockObj::CClockObj(const struct fbinfo& info)
: CObject(info)
{
    m_type = CLOCK_ANALOG_SEC;
    m_panalog_clock = NULL;
}

CClockObj::~CClockObj()
{
    if (m_panalog_clock != NULL)
    {
        delete m_panalog_clock;
        m_panalog_clock = NULL;
    }
}

bool CClockObj::Init()
{
    timeval ts;
    gettimeofday(&ts,0);
    m_tv_sec = ts.tv_sec;
    switch (m_type)
    {
        case CLOCK_DIGI:
        case CLOCK_DIGI_SEC:
            DrawClock();
            break;
        case CLOCK_ANALOG:
        case CLOCK_ANALOG_SEC:
            InitAnalog();
            DrawAnalogClock();
            break;
        default:
            break;
    }
    return true;
}

void CClockObj::InitAnalog(void)
{
    short i;
    double d;
    short h_len, min_len, s_len, r, r_i;
    if (m_panalog_clock == NULL)
        m_panalog_clock = new struct analog_clock;

    r = min(m_iXsize, m_iYsize)/2;
    m_panalog_clock->radius = r;
    h_len = r/2;
    min_len = r*200/300;
    s_len = min_len;
    r_i = r*270/330;
    for (i = 0; i < 3; i++)
    {
        m_panalog_clock->line[i].x1 = (unsigned short)(sin_tab[5*i]*r_i);
        m_panalog_clock->line[i].y1 = (unsigned short)(cos_tab[5*i]*r_i);
        m_panalog_clock->line[i].x2 = (unsigned short)(sin_tab[5*i]*(r-2));
        m_panalog_clock->line[i].y2 = (unsigned short)(cos_tab[5*i]*(r-2));
    }

    for (i = 0; i < 16; i++)
    {
        d = sin_tab[i];
        m_panalog_clock->h[i] = (unsigned short)(d * h_len);
        m_panalog_clock->min[i] = (unsigned short)(d * min_len);
        m_panalog_clock->s[i] = (unsigned short)(d * s_len);
    }
}

bool CClockObj::Refresh(void)
{
    timeval ts;
    gettimeofday(&ts,0);

    if (m_tv_sec != ts.tv_sec)
    {
        m_tv_sec = ts.tv_sec;
        switch (m_type)
        {
            case CLOCK_DIGI:
            case CLOCK_DIGI_SEC:
                DrawClock();
                break;
            case CLOCK_ANALOG:
            case CLOCK_ANALOG_SEC:
                DrawAnalogClock();
                break;
            default:
                break;
        }
        return true;
    }
    return false;
}

void  CClockObj::SetClockType(enum clock_type type)
{
    m_type = type;
}

enum clock_type CClockObj::GetClockType(void)
{
    return m_type;
}

void CClockObj::DrawClock(void)
{
    char text[10];
    unsigned char  bCharLine   = 0;
    unsigned char  bBitPos     = 0;
    unsigned char  bFontLine   = 0;
    unsigned char  bBit;
    unsigned int i;
    unsigned int xpos;
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    if (m_type == CLOCK_DIGI_SEC)
        sprintf(text, "%.2i:%.2i:%.2i", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    else
        sprintf(text, "%.2i:%.2i", timeinfo->tm_hour, timeinfo->tm_min);

    xpos = m_iXpos;

    for (i = 0; i < strlen(text); i++)
    {
        for(bCharLine = 0; bCharLine < 8; bCharLine ++)
        {
            if (bCharLine >= m_iYsize)
                break;
            bFontLine = abFont[(unsigned char)text[i]][bCharLine];
            for(bBitPos = 0; bBitPos < 8; bBitPos++)
            {
                if ((xpos + bBitPos) > (m_iXpos + m_iXsize))
                    break;
                bBit = bFontLine & (1 << (7 - bBitPos));
                SetPixel(xpos + bBitPos, m_iYpos + bCharLine, (bBit > 0)? 1 : 0);
            }
        }
        if ((xpos + bBitPos) > (m_iXpos + m_iXsize))
            return;
        xpos += bBitPos;
    }
}

void CClockObj::get_zeiger_value(unsigned short w, const unsigned short *tab_ptr, short *x, short *y){
  if (w < 15){
    *x = +tab_ptr[w];
    *y = -tab_ptr[15-w];
  }
  else{
    if (w < 30){
      *x = +tab_ptr[30-w];
      *y = +tab_ptr[w-15];
    }
    else{
      if (w < 45){
        *x = -tab_ptr[w-30];
        *y = +tab_ptr[45-w];
      }
      else{
        *x = -tab_ptr[60-w];
        *y = -tab_ptr[w-45];
      }
    }
  }
}

void CClockObj::DrawAnalogClock(void)
{
    unsigned short i;
    short x, y;
    time_t rawtime;
    struct tm* timeinfo;
    unsigned short std, min, sec, r;

    r = m_panalog_clock->radius;

    DrawRect(m_iXpos, m_iYpos, m_iXsize, m_iYsize, 0x00, 1);
    DrawCircle(m_iXpos + r, m_iYpos + r, r);

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    std = timeinfo->tm_hour;
    min = timeinfo->tm_min;
    if (std > 12)
        std -= 12;

    for(i=0; i<3; i++){
        gbham( m_iXpos+r + m_panalog_clock->line[i].x1,
               m_iYpos+r + m_panalog_clock->line[i].y1,
               m_iXpos+r + m_panalog_clock->line[i].x2,
               m_iYpos+r + m_panalog_clock->line[i].y2);
        gbham( m_iXpos+r - m_panalog_clock->line[i].y1,
               m_iYpos+r + m_panalog_clock->line[i].x1,
               m_iXpos+r - m_panalog_clock->line[i].y2,
               m_iYpos+r + m_panalog_clock->line[i].x2);
        gbham( m_iXpos+r + m_panalog_clock->line[i].y1,
               m_iYpos+r - m_panalog_clock->line[i].x1,
               m_iXpos+r + m_panalog_clock->line[i].y2,
               m_iYpos+r - m_panalog_clock->line[i].x2);
        gbham( m_iXpos+r - m_panalog_clock->line[i].x1,
               m_iYpos+r - m_panalog_clock->line[i].y1,
               m_iXpos+r - m_panalog_clock->line[i].x2,
               m_iYpos+r - m_panalog_clock->line[i].y2);
    }
    get_zeiger_value(min, m_panalog_clock->min, &x, &y);
    gbham(m_iXpos + r, m_iYpos + r, m_iXpos + r+x, m_iYpos + r+y);

    if (m_type == CLOCK_ANALOG_SEC)
    {
        sec = timeinfo->tm_sec;
        get_zeiger_value(sec, m_panalog_clock->s, &x, &y);
        gbham(m_iXpos + r, m_iYpos + r, m_iXpos + r+x, m_iYpos + r+y);
    }

    std = std * 5;
    while(min >= 12){
        min -= 12;
        std++;
    }
    get_zeiger_value(std, m_panalog_clock->h, &x, &y);
    gbham(m_iXpos + r, m_iYpos + r, m_iXpos + r+x, m_iYpos + r+y);
    if (abs(x) > abs(y))
        gbham(m_iXpos + r, m_iYpos + r+1, m_iXpos + r+x, m_iYpos + r+y+1);
    else
        gbham(m_iXpos+r+1, m_iYpos+r, m_iXpos+r+x+1, m_iYpos+r+y);
}


