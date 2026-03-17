#include "formats/base/file.hpp"

namespace Format
{
    BaseFile::BaseFile(const std::string& filepath)
    {
        mFilepath = filepath;
    }

    BaseFile::~BaseFile() {}

    void BaseFile::showInfo() { }
    int BaseFile::parse() {return 0;}
}
