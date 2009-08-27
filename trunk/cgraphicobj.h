#include "cobject.h"
#include "bmp.h"
#include "png.h"

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

enum eGraphicType {
    GRAPHIC_BMP,
    GRAPHIC_PNG
};

struct image
{
    unsigned int width, height;
	unsigned char *rgb;
	unsigned char *alpha;
};

class CGraphicObj : public CObject
{
private:
    enum eGraphicType eType;
    struct image m_i;
public:
    CGraphicObj(const struct fbinfo& info);
    bool Init(string& path);
    bool Refresh(void);
    bool FitToArea();
    bool Show();
};

unsigned char * simple_resize(unsigned char * orgin,int ox,int oy,int dx,int dy);
unsigned char * alpha_resize(unsigned char * alpha,int ox,int oy,int dx,int dy);

inline static unsigned short make16color(unsigned char r, unsigned char g, unsigned char b)
{
    return (
	(((r >> 3) & 31) << 11) |
	(((g >> 2) & 63) << 5)  |
	 ((b >> 3) & 31)        );
}

inline static unsigned short make15color(unsigned char r, unsigned char g, unsigned char b)
{
    return (
	(((r >> 3) & 31) << 10) |
	(((g >> 3) & 31) << 5)  |
	 ((b >> 3) & 31)        );
}

inline static unsigned char make8color(unsigned char r, unsigned char g, unsigned char b)
{
    return (
	(((r >> 5) & 7) << 5) |
	(((g >> 5) & 7) << 2) |
	 ((b >> 6) & 3)       );
}

inline static unsigned char make8grayscale(unsigned char r, unsigned char g, unsigned char b)
{
    return (0xff - (r+g+b)/3);
}

