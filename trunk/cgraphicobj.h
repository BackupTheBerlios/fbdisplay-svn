#include "cobject.h"
#include "bmp.h"
#include "png.h"

enum eGraphicType {
    GRAPHIC_BMP,
    GRAPHIC_PNG
};

class CGraphicObj : public CObject
{
private:
    enum eGraphicType eType;
public:
    CGraphicObj();
    bool Init(string& path);
    bool Refresh(void);
};
