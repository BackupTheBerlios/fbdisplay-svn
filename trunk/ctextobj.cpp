#include "ctextobj.h"
#include <stdlib.h>

CTextObj::CTextObj(const struct fbinfo& info)
: CObject(info)
{
    m_speed = 0;
    m_shiftpos = 0;
    m_text = "";
    memset(&m_oldtime, 0, sizeof(timeval));
}

bool CTextObj::Init(string& text, int speed)
{
    m_text = text;
    m_speed = speed;
    if (m_speed > 100) m_speed = 100;
    if (m_speed < -100) m_speed = -100;
    m_shiftpos = 0;

    DrawScrollText();
    return true;
}

bool CTextObj::Refresh(void)
{
    timeval ts;
    gettimeofday(&ts,0);
    if (((ts.tv_sec*1000)+(ts.tv_usec/1000)) <=
        ((m_oldtime.tv_sec*1000)+(m_oldtime.tv_usec/1000)+100-abs(m_speed)))
    {
        return false;
    }

    m_oldtime = ts;
    if (m_speed > 0)
    {
        m_shiftpos++;
        if (m_shiftpos > (int)(m_text.length()*8))
            m_shiftpos = 0 - m_iXsize;
    }

    if (m_speed < 0)
    {
        m_shiftpos--;
        if (m_shiftpos < (int)(0 - m_iXsize))
            m_shiftpos = (int)(m_text.length()*8);
    }

    DrawScrollText();
    return true;
}

void CTextObj::DrawScrollText(void)
{
    unsigned char  bCharLine   = 0;
    unsigned char  bBitPos     = 0;
    unsigned char  bFontLine   = 0;
    unsigned char  bBit;
    unsigned char  bPosOffset;
    unsigned int absOffset;
    unsigned int i;
    unsigned int xpos;

    xpos = m_iXpos;

    if (m_shiftpos >= 0)
    {
        i = m_shiftpos / 8;
        bPosOffset = (unsigned char)(m_shiftpos % 8);
        absOffset = 0;
    }
    else
    {
        i = 0;
        absOffset = -m_shiftpos;
        bPosOffset = 0;
    }

    for (; i < m_text.length(); i++)
    {
        for(bCharLine = 0; bCharLine < 8; bCharLine ++)
        {
            bFontLine = abFont[(unsigned char)m_text.at(i)][bCharLine];
            for(bBitPos = 0; bBitPos < (8 - bPosOffset); bBitPos++)
            {
                if ((xpos + bBitPos + absOffset) > (m_iXpos + m_iXsize))
                    break;
                bBit = bFontLine & (1 << (7 - bBitPos - bPosOffset));
                SetPixel(xpos + bBitPos + absOffset, m_iYpos + bCharLine, (bBit > 0)? 1 : 0);
            }
        }
        if ((xpos + bBitPos + absOffset) > (m_iXpos + m_iXsize))
            return;
        xpos += bBitPos;
        bPosOffset = 0;
    }
}
