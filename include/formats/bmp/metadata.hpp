#pragma once
#ifndef _FORMAT_BMP_METADATA_HPP_
#define _FORMAT_BMP_METADATA_HPP_


#include "types.hpp"

namespace Format
{
    namespace BMP
    {
        constexpr int HEADER_BYTE_LEN {14};

        struct FileHeader {
            byte Signature[2];
            byte FileSize[4];
            byte RESV[4];
            byte FileOffset[4];
        } __attribute__((packed));
    }
}

#endif // _FORMAT_BMP_METADATA_HPP_
