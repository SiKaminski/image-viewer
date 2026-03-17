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
            byte BmpFileHeader[HEADER_BYTE_LEN];
        } __attribute__((packed));
    }
}

#endif // _FORMAT_BMP_METADATA_HPP_
