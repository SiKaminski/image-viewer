#pragma once
#ifndef _FORMAT_BMP_FILE_HPP_
#define _FORMAT_BMP_FILE_HPP_

#include <string>

#include "formats/base/file.hpp"
#include "formats/bmp/metadata.hpp"

namespace Format 
{
    namespace BMP
    {
        // https://en.wikipedia.org/wiki/BMP_file_format
        // https://www.daubnet.com/en/file-format-bmp
        class File : public BaseFile
        {
            public:
                File(const std::string& filepath);
                ~File();

                void showInfo();
                int parse();
            private:

                FileHeader header;
        };
    }
}

#endif // _FORMAT_BMP_FILE_HPP_
