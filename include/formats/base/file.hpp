#pragma once
#ifndef _FORMAT_BASE_FILE_HPP_
#define _FORMAT_BASE_FILE_HPP_

#include <string>
#include <vector>
#include <fstream>

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
            virtual int Read(void* buf, size_t size, bool changePos, size_t offset);

            std::vector<byte> mRawFileData;
            std::string       mFilepath;
            std::ifstream     mInStream;
    };
}

#endif // _FORMAT_BASE_FILE_HPP_
