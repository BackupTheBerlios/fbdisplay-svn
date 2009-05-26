#ifndef __FONT_H
#define __FONT_H

#define BINARY8(_b1,_b2,_b3,_b4,_b5,_b6,_b7,_b8) \
(unsigned char)((((((((((((((_b1 << 1) | _b2) << 1) | _b3) << 1) | _b4) << 1) | _b5) << 1) | _b6) << 1) | _b7) << 1) | _b8)

const unsigned char abFont[128][8] =
{
    {       /* Char 0 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 1 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,1,1,1,0,1,1,1),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,1,1,0,0)
    },
    {       /* Char 2 */
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,1,1,1,0,1,1,1),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0)
    },
    {       /* Char 3 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,1,0,0),
        BINARY8(0,1,1,1,1,0,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,1,1,0,1,0),
        BINARY8(0,0,0,0,1,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 4 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,1,0,1,1,1,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,0,1,1,1,1),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 5 */
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,1,0,1,1,1,0,1),
        BINARY8(0,1,1,0,1,0,1,1),
        BINARY8(0,1,1,1,0,1,1,1),
        BINARY8(0,1,1,0,1,0,1,1),
        BINARY8(0,1,0,1,1,1,0,1),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 6 */
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,1,1,1,1,0,1),
        BINARY8(0,1,1,1,1,0,1,1),
        BINARY8(0,1,1,1,0,1,1,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 7 */
        BINARY8(0,1,1,1,0,1,1,1),
        BINARY8(0,1,1,0,1,0,1,1),
        BINARY8(0,1,0,1,1,1,0,1),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,1,0,1,1,1,0,1),
        BINARY8(0,1,1,0,1,0,1,1),
        BINARY8(0,1,1,1,0,1,1,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 8 */
        BINARY8(0,1,1,0,0,0,0,0),
        BINARY8(0,1,0,1,0,0,0,0),
        BINARY8(0,1,1,0,0,0,0,0),
        BINARY8(0,1,0,1,0,0,1,1),
        BINARY8(0,1,1,0,0,1,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,1,1,0)
    },
    {       /* Char 9 */
        BINARY8(0,1,0,1,0,0,0,0),
        BINARY8(0,1,0,1,0,0,0,0),
        BINARY8(0,1,1,1,0,0,0,0),
        BINARY8(0,1,0,1,0,1,1,1),
        BINARY8(0,1,0,1,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0)
    },
    {       /* Char 10 */
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,1,1,1),
        BINARY8(0,1,1,1,0,1,0,0),
        BINARY8(0,0,0,0,0,1,1,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0)
    },
    {       /* Char 11 */
        BINARY8(0,1,0,1,0,0,0,0),
        BINARY8(0,1,0,1,0,0,0,0),
        BINARY8(0,1,0,1,0,0,0,0),
        BINARY8(0,0,1,0,0,1,1,1),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0)
    },
    {       /* Char 12 */
        BINARY8(0,1,1,1,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,1,0,0,0,0,0),
        BINARY8(0,1,0,0,0,1,1,1),
        BINARY8(0,1,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,1,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0)
    },
    {       /* Char 13 */
        BINARY8(0,0,1,1,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,1,1,0),
        BINARY8(0,0,1,1,0,1,0,1),
        BINARY8(0,0,0,0,0,1,1,0),
        BINARY8(0,0,0,0,0,1,0,1),
        BINARY8(0,0,0,0,0,1,0,1)
    },
    {       /* Char 14 */
        BINARY8(0,0,0,0,0,1,0,1),
        BINARY8(0,0,0,0,0,1,0,1),
        BINARY8(0,0,0,0,0,1,0,1),
        BINARY8(0,0,0,0,1,1,0,1),
        BINARY8(0,0,0,0,1,1,0,1),
        BINARY8(0,0,0,0,1,1,0,1),
        BINARY8(0,0,0,1,1,0,0,1),
        BINARY8(0,1,1,1,1,0,0,1)
    },
    {       /* Char 15 */
        BINARY8(1,0,1,0,0,0,0,0),
        BINARY8(1,0,1,0,0,0,0,0),
        BINARY8(1,0,1,0,0,0,0,0),
        BINARY8(1,0,1,1,0,0,0,0),
        BINARY8(1,0,1,1,0,0,0,0),
        BINARY8(1,0,1,1,0,0,0,0),
        BINARY8(1,0,0,1,1,0,0,0),
        BINARY8(1,0,0,1,1,1,1,0)
    },
    {       /* Char 16 */
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 17 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 18 */
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 19 */
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 20 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 21 */
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 22 */
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 23 */
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 24 */
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 25 */
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 26 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,1),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 27 */
        BINARY8(0,1,1,1,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,1,1,0,0,0,0),
        BINARY8(0,1,0,0,0,0,1,1),
        BINARY8(0,1,1,1,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,0,1,1)
    },
    {       /* Char 28 */
        BINARY8(0,0,0,0,0,1,1,1),
        BINARY8(0,0,0,0,1,1,1,1),
        BINARY8(0,0,0,1,1,1,1,1),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,1,1,1,1,0),
        BINARY8(0,0,0,1,0,1,1,1)
    },
    {       /* Char 29 */
        BINARY8(1,1,1,1,0,0,0,0),
        BINARY8(1,1,1,1,1,0,0,0),
        BINARY8(1,1,1,0,1,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,1,0,1,0,1,0,0)
    },
    {       /* Char 30 */
        BINARY8(0,0,0,1,0,0,0,1),
        BINARY8(0,0,0,0,1,0,1,1),
        BINARY8(0,0,0,0,1,1,0,1),
        BINARY8(0,0,0,0,0,1,1,0),
        BINARY8(0,0,0,0,0,1,1,1),
        BINARY8(0,0,1,0,1,1,1,0),
        BINARY8(0,0,1,1,1,0,0,1),
        BINARY8(0,0,1,1,1,0,0,0)
    },
    {       /* Char 31 */
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,1,0,1,0,0,0),
        BINARY8(1,1,0,1,1,0,0,0),
        BINARY8(0,0,1,0,1,0,0,0),
        BINARY8(1,1,0,1,0,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(1,1,1,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 32 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 33 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 34 */
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 35 */
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 36 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,1,1,1,0),
        BINARY8(0,0,1,0,1,0,0,0),
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,0,0,1,0,1,0),
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 37 */
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,1,0,1,0,1,0,0),
        BINARY8(0,0,1,0,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,0,1,0),
        BINARY8(0,0,0,1,0,1,0,1),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 38 */
        BINARY8(0,0,1,1,1,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,1,1,0,0,0,0),
        BINARY8(0,1,0,0,1,0,1,0),
        BINARY8(0,1,0,0,0,1,0,0),
        BINARY8(0,0,1,1,1,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 39 */
        BINARY8(0,0,0,0,1,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 40 */
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 41 */
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 42 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,1,1,0,1,0,1,1),
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 43 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 44 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0)
    },
    {       /* Char 45 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 46 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 47 */
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0)
    },
    {       /* Char 48 */
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 49 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 50 */
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 51 */
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 52 */
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,1,0,0,1,0,0),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 53 */
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,1,1,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 54 */
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 55 */
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 56 */
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 57 */
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,1,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 58 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 59 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0)
    },
    {       /* Char 60 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,1,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,1,1,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 61 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 62 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,1,0,0,0,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,0,1,1,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,1,1,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 63 */
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 64 */
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,1,0,1,0,1,0,1),
        BINARY8(0,1,0,0,1,0,1,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 65 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,1,1,0,0,0,1,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 66 */
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 67 */
        BINARY8(0,0,0,1,1,1,1,0),
        BINARY8(0,0,1,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,1),
        BINARY8(0,0,0,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 68 */
        BINARY8(0,1,1,1,1,1,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,1,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 69 */
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 70 */
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 71 */
        BINARY8(0,0,0,1,1,1,1,0),
        BINARY8(0,0,1,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,1,1,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,0,0,0,0,1),
        BINARY8(0,0,0,1,1,1,1,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 72 */
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 73 */
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 74 */
        BINARY8(0,0,0,0,1,1,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 75 */
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,1,0,0),
        BINARY8(0,1,0,0,1,0,0,0),
        BINARY8(0,1,1,1,0,0,0,0),
        BINARY8(0,1,0,0,1,0,0,0),
        BINARY8(0,1,0,0,0,1,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 76 */
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 77 */
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,0,0,0,1,1),
        BINARY8(0,1,0,1,0,1,0,1),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 78 */
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,0,0,0,0,1),
        BINARY8(0,1,0,1,0,0,0,1),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,1,0,0,0,1,0,1),
        BINARY8(0,1,0,0,0,0,1,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 79 */
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 80 */
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 81 */
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,0,0,0,1,1,1)
    },
    {       /* Char 82 */
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,1,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 83 */
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 84 */
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 85 */
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 86 */
        BINARY8(0,1,1,0,0,0,1,1),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 87 */
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,1,0,1,0,1,0,1),
        BINARY8(0,1,1,0,0,0,1,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 88 */
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 89 */
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 90 */
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 91 */
        BINARY8(0,0,0,0,1,1,1,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 92 */
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,1,0,0)
    },
    {       /* Char 93 */
        BINARY8(0,0,1,1,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,1,1,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 94 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 95 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,1)
    },
    {       /* Char 96 */
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 97 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,0,1),
        BINARY8(0,1,0,0,0,0,1,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,1,1),
        BINARY8(0,0,1,1,1,1,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 98 */
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 99 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 100 */
        BINARY8(0,0,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,0,0,1),
        BINARY8(0,0,1,1,1,1,1,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,1,1,1,1,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 101 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,1,1,1,1,1),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 102 */
        BINARY8(0,0,0,1,1,1,1,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,1,1,1,1,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 103 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,1,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,1,1,1,1,1),
        BINARY8(0,0,0,0,0,0,0,1),
        BINARY8(0,0,1,1,1,1,1,0)
    },
    {       /* Char 104 */
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 105 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 106 */
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,0,0)
    },
    {       /* Char 107 */
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,1,1,0),
        BINARY8(0,1,0,0,1,0,0,0),
        BINARY8(0,1,1,1,0,0,0,0),
        BINARY8(0,1,0,0,1,0,0,0),
        BINARY8(0,1,0,0,0,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 108 */
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 109 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,1,1,0,1,1,0),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 110 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,0,1,1,1,1,0),
        BINARY8(0,1,1,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 111 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 112 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,0)
    },
    {       /* Char 113 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,1,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,0,1,1,1,1,1,1),
        BINARY8(0,0,0,0,0,0,0,1)
    },
    {       /* Char 114 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,1,0,1,1,1,0),
        BINARY8(0,0,1,1,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 115 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,1,0,0,0,0,0,0),
        BINARY8(0,0,1,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,1,1,1,1,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 116 */
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,0,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 117 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,0,0,1,1),
        BINARY8(0,0,1,1,1,1,0,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 118 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,1,0,0,0,1,1),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 119 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,0,1),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,0,1,1,0,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 120 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,1,0,0,0,1,1),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,1,1,0,0,0,1,1),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 121 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,1,0,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,0,0)
    },
    {       /* Char 122 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,1,1,0,0,0),
        BINARY8(0,0,1,0,0,0,0,0),
        BINARY8(0,1,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 123 */
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 124 */
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 125 */
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,0,1,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 126 */
        BINARY8(0,0,1,1,0,0,0,1),
        BINARY8(0,1,0,0,1,0,0,1),
        BINARY8(0,1,0,0,0,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,0,0,0,0)
    },
    {       /* Char 127 */
        BINARY8(0,0,0,0,0,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,0,1,0,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,0,1,0,1,0,0),
        BINARY8(0,0,1,0,0,0,1,0),
        BINARY8(0,0,1,1,1,1,1,0),
        BINARY8(0,0,0,0,0,0,0,0)
    }
};

#endif