#pragma once
#ifndef _FORMAT_BMP_METADATA_HPP_
#define _FORMAT_BMP_METADATA_HPP_


#include "types.hpp"

namespace Format
{
    namespace BMP
    {
        constexpr int HEADER_BYTE_LEN {14};
        constexpr int INFO_HEADER_BYTE_LEN {40};

        struct FileHeader {
            byte Signature[2];
            byte FileSize[4];
            byte RESV[4];
            byte FileOffset[4];
        } __attribute__((packed));

        struct InfoHeader {
            byte Size[4];
            byte Width[4];
            byte Height[4];
            byte Planes[2];
            byte BitCount[2];
            byte Compression [4];
            byte ImageSize[4];
            byte XpixelsPerM[4];
            byte YpixelsPerM[4];
            byte ColorsUsed[4];
            byte ColorsImportant[4];
            byte* ColorTable; // 4 * NumColors only if BitsPerPixel<=8
        } __attribute__((packed));
    }
}

#endif // _FORMAT_BMP_METADATA_HPP_
