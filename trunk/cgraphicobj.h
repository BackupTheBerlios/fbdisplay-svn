#include "cobject.h"

class CGraphicObj : public CObject
{
public:
    CGraphicObj();
    bool Init(string& path);
    bool Refresh(void);
};
