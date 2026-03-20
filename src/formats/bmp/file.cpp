#include "formats/bmp/file.hpp"
#include "formats/base/file.hpp"
#include "formats/bmp/metadata.hpp"
#include "utils.hpp"
#include "globals.hpp"

namespace Format
{
    using namespace BMP;
    File::File(const std::string& filepath) : BaseFile(filepath)
    {
        mFilepath = filepath;
        mInStream = std::ifstream(filepath.c_str(), std::ifstream::in | std::ifstream::binary);

        parse();
    }

    File::~File() {}

    int File::parse()
    {
        int status;
        mHeader = new BMP::FileHeader;
        status = Read((void*)mHeader, sizeof(BMP::FileHeader), true, 0);
        
        std::string tmpHex = Utils::HexToAscii(reinterpret_cast<byte*>(mHeader->Signature), 2);
        Utils::PrintAscii(tmpHex);

        Globals::Logger.Log(INFO, "%i", mHeader->FileSize);

        tmpHex = Utils::HexToAscii(reinterpret_cast<byte*>(mHeader->RESV), 4);
        Utils::PrintAscii(tmpHex);

        tmpHex = Utils::HexToAscii(reinterpret_cast<byte*>(mHeader->FileOffset), 4);
        Utils::PrintAscii(tmpHex);

        return status; 
    }

    void File::showInfo()
    {
        std::string hexStr = Utils::HexToAscii(mRawFileData);
        Globals::Logger.Log(INFO, hexStr.c_str());
    }
}
