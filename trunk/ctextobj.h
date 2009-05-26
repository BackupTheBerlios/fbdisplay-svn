#ifndef __CTEXTOBJ_H
#define __CTEXTOBJ_H

#include "cobject.h"
#include "font.h"

class CTextObj : public CObject
{
private:
    string m_text;
    timeval m_oldtime;
    int m_speed;
    int m_shiftpos;
    void DrawScrollText(void);
public:
    CTextObj(const struct fbinfo& info);
    bool Init(string& text, int speed);
    bool Refresh(void);
};

#endif
