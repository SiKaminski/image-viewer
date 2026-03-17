#include "formats/bmp/file.hpp"
#include "formats/base/file.hpp"
#include "utils.hpp"
#include "globals.hpp"

namespace Format
{
    using namespace BMP;
    File::File(const std::string& filepath) : BaseFile(filepath) { }
    File::~File() {}

    int File::parse()
    {
        mRawFileData = Utils::ReadFile(mFilepath);
        return 0; 
    }

    void File::showInfo()
    {
        std::string hexStr = Utils::HexToAscii(mRawFileData);
        Globals::Logger.Log(INFO, hexStr.c_str());
    }
}
