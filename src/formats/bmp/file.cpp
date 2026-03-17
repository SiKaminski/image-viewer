#include "formats/bmp/file.hpp"
#include "formats/base/file.hpp"
#include "formats/bmp/metadata.hpp"
#include "utils.hpp"
#include "globals.hpp"

namespace Format
{
    using namespace BMP;
    File::File(const std::string& filepath) : BaseFile(filepath) { }
    File::~File() {}

    int File::parse()
    {
        int status;
        mHeader = new BMP::FileHeader;
        status = Read((void*)mHeader, sizeof(BMP::FileHeader), true, 0);
        
        std::string tmpHex = Utils::HexToAscii(reinterpret_cast<byte*>(mHeader), HEADER_BYTE_LEN);
        Utils::PrintAscii(tmpHex);

        return status; 
    }

    void File::showInfo()
    {
        std::string hexStr = Utils::HexToAscii(mRawFileData);
        Globals::Logger.Log(INFO, hexStr.c_str());
    }
}
