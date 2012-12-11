#pragma once

#pragma pack(2)
typedef struct
{
    unsigned short bfType;           /* Magic number for file */
    unsigned int   bfSize;           /* Size of file */
    unsigned short bfReserved1;      /* Reserved */
    unsigned short bfReserved2;      /* Reserved */
    unsigned int   bfOffBits;        /* Offset to bitmap data */
} BITMAPFILEHEADER;
#pragma pack()

const unsigned short BF_TYPE = 0x4D42; /* Magic number of BMP files "MB" */
