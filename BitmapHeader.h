#pragma once

#pragma pack(2)
/**
 * @brief A bitmap file header.
 *
 * Used by CSteganoNonCheckedMethod.
 */
struct SBitmapFileHeader
{
    /**
     * @brief Magic number for file
     */
    unsigned short bfType;
    /**
     * @brief Size of file
     */
    unsigned int   bfSize;
    /**
     * @brief Reserved
     */
    unsigned short bfReserved1;
    /**
     * @brief Reserved
     */
    unsigned short bfReserved2;
    /**
     * @brief Offset to bitmap data
     */
    unsigned int   bfOffBits;
};
#pragma pack()

/**
 * @brief Magic number of BMP files "MB"
 */
const unsigned short BF_TYPE = 0x4D42;
