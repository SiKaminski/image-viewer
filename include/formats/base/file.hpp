#pragma once
#ifndef _FORMAT_BASE_FILE_HPP_
#define _FORMAT_BASE_FILE_HPP_

#include <string>
#include <vector>

#include "types.hpp"

namespace Format
{
    class BaseFile
    {
        public:
            BaseFile(const std::string& filepath);
            virtual ~BaseFile(); 

            virtual void showInfo();
            virtual int parse();
        protected:

            std::vector<byte> mRawFileData;
            std::string       mFilepath;
    };
}

#endif // _FORMAT_BASE_FILE_HPP_
