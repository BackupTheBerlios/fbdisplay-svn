#include "cgraphicobj.h"

CGraphicObj::CGraphicObj(const struct fbinfo& info)
: CObject(info)
{

}

CGraphicObj::~CGraphicObj()
{
    if (m_i.rgb)
    {
        delete[] m_i.rgb;
        m_i.rgb = NULL;
    }
    if (m_i.alpha)
    {
        delete[] m_i.alpha;
        m_i.alpha = NULL;
    }
}

bool CGraphicObj::Init(string& path)
{
    char filename[500];
    int xsize, ysize;
    unsigned char* image = NULL;
    unsigned char* alpha = NULL;

    strcpy(filename, path.c_str());
    if (png_id(filename))
        eType = GRAPHIC_PNG;
    else if (bmp_id(filename))
        eType = GRAPHIC_BMP;

    switch(eType)
    {
    case GRAPHIC_BMP:
        if (bmp_getsize(filename, &xsize, &ysize) == 0)
        {
            image = new unsigned char[xsize * ysize * 3];
            if (image)
                if (bmp_load(filename, image, &alpha, xsize, ysize) != 0)
                {
                    delete[] image;
                    image = NULL;
                }
        }
        break;
    case GRAPHIC_PNG:
        if (png_getsize(filename, &xsize, &ysize) == 0)
        {
            image = new unsigned char[xsize * ysize * 3];
            if (image)
                if (png_load(filename, image, &alpha, xsize, ysize) != 0)
                {
                    delete[] image;
                    image = NULL;
                }
        }
        break;
    default:
        break;
    }
    if (!image)
        return false;

    m_i.width = xsize;
    m_i.height = ysize;
    m_i.rgb = image;
    m_i.alpha = alpha;
    FitToArea();
    Show();
    return true;
}

bool CGraphicObj::FitToArea()
{
    if((m_i.width > m_iXsize) || (m_i.height > m_iYsize))
	{
		unsigned char * new_image, * new_alpha = NULL;
		int nx_size = m_i.width, ny_size = m_i.height;

        if((m_i.height * m_iXsize / m_i.width) <= m_iYsize)
        {
            nx_size = m_iXsize;
            ny_size = m_i.height * m_iXsize / m_i.width;
        }
        else
        {
            nx_size = m_i.width * m_iYsize / m_i.height;
            ny_size = m_iYsize;
        }


		new_image = simple_resize(m_i.rgb, m_i.width, m_i.height, nx_size, ny_size);
		delete[] m_i.rgb;

		if(m_i.alpha)
		{
			new_alpha = alpha_resize(m_i.alpha, m_i.width, m_i.height, nx_size, ny_size);
			delete[] m_i.alpha;
		}

		m_i.rgb = new_image;
		m_i.alpha = new_alpha;
		m_i.width = nx_size;
		m_i.height = ny_size;
	}
    return true;
}

bool CGraphicObj::Show()
{
    unsigned long i;
    union {
        unsigned char* pc;
        unsigned short* ps;
        unsigned long* pl;
        void* pv;
    } ptr;
    unsigned char* fbptr;
    void *p;

    switch(m_fbinfo.var->bits_per_pixel)
    {
	case 8:
	    ptr.pc = new unsigned char[m_i.width*m_i.height];
	    for(i = 0; i < m_i.width*m_i.height; i++)
		ptr.pc[i] = make8grayscale(m_i.rgb[i*3], m_i.rgb[i*3+1], m_i.rgb[i*3+2]);
	    break;
	case 15:
	    ptr.ps = new unsigned short[m_i.width*m_i.height];
	    for(i = 0; i < m_i.width*m_i.height ; i++)
		ptr.ps[i] = make15color(m_i.rgb[i*3], m_i.rgb[i*3+1], m_i.rgb[i*3+2]);
	    break;
	case 16:
	    ptr.ps = new unsigned short[m_i.width*m_i.height];
	    for(i = 0; i < m_i.width*m_i.height ; i++)
		ptr.ps[i] = make16color(m_i.rgb[i*3], m_i.rgb[i*3+1], m_i.rgb[i*3+2]);
	    break;
	case 24:
	case 32:
        ptr.pl = new unsigned long[m_i.width*m_i.height];
	    for(i = 0; i < m_i.width*m_i.height ; i++)
		ptr.pl[i] = ((m_i.rgb[i*3] << 16) & 0xFF0000) |
                    ((m_i.rgb[i*3+1] << 8) & 0xFF00) |
                     (m_i.rgb[i*3+2] & 0xFF);
	    break;
	default:
	    fprintf(stderr, "Unsupported video mode! You've got: %dbpp\n", m_fbinfo.var->bits_per_pixel);
	    exit(1);
    }
    p = ptr.pv;
	fbptr = m_fbinfo.pFB + (m_iYpos * m_fbinfo.var->xres + m_iXpos) * m_fbinfo.cpp;
/*
	if(m_i.alpha)
	{
	 	unsigned char * alphaptr;
		int from, to, x;

		alphaptr = m_i.alpha;

		for(i = 0; i < yc; i++, fbptr += scr_xs * cpp, imptr += pic_xs * cpp, alphaptr += pic_xs)
		{
			for(x = 0; x<xc; x++)
			{
				int v;

				from = to = -1;
				for(v = x; v<xc; v++)
				{
					if(from == -1)
					{
						if(alphaptr[v] > 0x80) from = v;
					}
					else
					{
						if(alphaptr[v] < 0x80)
						{
							to = v;
							break;
						}
					}
				}
				if(from == -1)
					break;

				if(to == -1) to = xc;

				memcpy(fbptr + (from * cpp), imptr + (from * cpp), (to - from - 1) * cpp);
				x += to - from - 1;
			}
		}
	}
	else
	*/
	    for(i = 0; i < m_i.height; i++, fbptr += m_fbinfo.var->xres * m_fbinfo.cpp, ptr.pc += m_i.width * m_fbinfo.cpp)
			memcpy(fbptr, ptr.pc, m_i.width * m_fbinfo.cpp);

    delete[] p;
    return true;
}


bool CGraphicObj::Refresh(void)
{
    return true;
}


unsigned char* simple_resize(unsigned char* orgin,int ox,int oy,int dx,int dy)
{
    unsigned char *cr,*p,*l;
    int i,j,k,ip;
    cr = new unsigned char[dx*dy*3];
    l=cr;

    for(j=0;j<dy;j++,l+=dx*3)
    {
	p=orgin+(j*oy/dy*ox*3);
	for(i=0,k=0;i<dx;i++,k+=3)
	{
	    ip=i*ox/dx*3;
	    l[k]=p[ip];
	    l[k+1]=p[ip+1];
	    l[k+2]=p[ip+2];
	}
    }
    return(cr);
}

unsigned char* alpha_resize(unsigned char* alpha,int ox,int oy,int dx,int dy)
{
    unsigned char *cr,*p,*l;
    int i,j,k;
    cr = new unsigned char[dx*dy];
    l=cr;

    for(j=0;j<dy;j++,l+=dx)
    {
		p = alpha+(j*oy/dy*ox);
		for(i=0,k=0;i<dx;i++)
		    l[k++]=p[i*ox/dx];
	}

    return(cr);
}

