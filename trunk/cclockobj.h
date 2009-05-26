#ifndef __CCLOCKOBJ_H
#define __CCLOCKOBJ_H

#include "cobject.h"
#include "font.h"
#include "time.h"

enum clock_type {
    CLOCK_DIGI,
    CLOCK_DIGI_SEC,
    CLOCK_ANALOG,
    CLOCK_ANALOG_SEC
};

struct line_typ {
  unsigned short x1;
  unsigned short y1;
  unsigned short x2;
  unsigned short y2;
};

struct analog_clock{
    unsigned short radius;
    struct line_typ line[3];
    unsigned short h[15];
    unsigned short min[15];
    unsigned short s[15];
};

class CClockObj : public CObject
{
public:
    CClockObj(const struct fbinfo& info);
    ~CClockObj();
    bool Init(void);
    bool Refresh(void);
    void SetClockType(enum clock_type type);
    enum clock_type GetClockType(void);
private:
    long m_tv_sec;
    enum clock_type m_type;
    struct analog_clock* m_panalog_clock;
    void DrawClock(void);
    void get_zeiger_value(unsigned short w, const unsigned short *tab_ptr, short *x, short *y);
    void DrawAnalogClock(void);
    void InitAnalog(void);
};

#define SIN_0		0
#define COS_0		1
#define SIN_6 		0.104528463267653
#define COS_6 		0.994521895368273
#define SIN_12		0.207911690817759
#define COS_12		0.978147600733806
#define SIN_18		0.309016994374947
#define COS_18		0.951056516295153
#define SIN_24		0.4067366430758
#define COS_24		0.913545457642601
#define SIN_30		0.5
#define COS_30		0.866025403784439
#define SIN_36		0.587785252292473
#define COS_36		0.809016994374947
#define SIN_42		0.669130606358858
#define COS_42		0.743144825477394
#define SIN_48		0.743144825477394
#define COS_48		0.669130606358858
#define SIN_54		0.809016994374947
#define COS_54		0.587785252292473
#define SIN_60		0.866025403784439
#define COS_60		0.5
#define SIN_66		0.913545457642601
#define COS_66		0.4067366430758
#define SIN_72		0.951056516295153
#define COS_72		0.309016994374947
#define SIN_78		0.978147600733806
#define COS_78		0.207911690817759
#define SIN_84		0.994521895368273
#define COS_84		0.104528463267653
#define SIN_90		1
#define COS_90		0

const double cos_tab[] = {
    COS_0, COS_6, COS_12, COS_18, COS_24, COS_30, COS_36,
    COS_42, COS_48, COS_54, COS_60, COS_66, COS_72, COS_78,
    COS_84, COS_90
};

const double sin_tab[] = {
    SIN_0, SIN_6, SIN_12, SIN_18, SIN_24, SIN_30, SIN_36,
    SIN_42, SIN_48, SIN_54, SIN_60, SIN_66, SIN_72, SIN_78,
    SIN_84, SIN_90
};

#endif
