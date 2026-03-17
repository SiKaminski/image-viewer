#pragma once
#ifndef _FORMAT_BMP_METADATA_HPP_
#define _FORMAT_BMP_METADATA_HPP_


#include "types.hpp"

namespace Format
{
    namespace BMP
    {
        struct FileHeader {
            byte BmpFileHeader[14];
        } __attribute__((packed));
    }
}

#endif // _FORMAT_BMP_METADATA_HPP_
