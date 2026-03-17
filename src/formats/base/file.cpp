#include "formats/base/file.hpp"
#include "globals.hpp"
#include "error.hpp"

namespace Format
{
    BaseFile::BaseFile(const std::string& filepath)
    {
        mFilepath = filepath;
        mInStream = std::ifstream(filepath.c_str(), std::ifstream::in | std::ifstream::binary);

        parse();
    }

    BaseFile::~BaseFile() {}

    void BaseFile::showInfo() { }
    int BaseFile::parse() {return 0;}

    int BaseFile::Read(void* buf, size_t size, bool changePos, size_t offset)
    {
        int status = 0;

        try {
            if (changePos)
                mInStream.seekg(offset);
            else
                offset = mInStream.cur;
        } catch (std::exception err) {
            Globals::Logger.Log(ERROR, err.what());
            Globals::Logger.Log(ERROR, "Attempted to update file pos to: %d", offset);
            error(Severity::high, "File Pos Update:", "Error Setting position of file Read");
        }

        try {
            mInStream.read(reinterpret_cast<char*>(buf), size);
        } catch (std::exception err) {
            Globals::Logger.Log(ERROR, err.what());
            Globals::Logger.Log(ERROR, "Attempted to cast");
            error(Severity::high, "Cast Error:", "Error casting buffer type to char");
        }

        return status;
    }
}
