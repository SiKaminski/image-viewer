#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <string>
#include <vector>
#include "types.hpp"

namespace Utils
{
    bool SupportedFileFormat(const std::string& fmt);

    std::vector<std::string> SplitStr(const std::string& str, char delimiter);
    std::string HexToAscii(const std::string& hex);
    std::string HexToAscii(const std::vector<byte>& hexBuffer);
    std::string HexToAscii(const byte* hexBuffer, size_t len);
    void PrintAscii(const std::string& str);
}

#endif // _UTILS_HPP_
