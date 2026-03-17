#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <string>
#include <vector>
#include "types.hpp"

namespace Utils
{
    bool SupportedFileFormat(const std::string& fmt);

    std::vector<std::string> SplitStr(const std::string& str, char delimiter);
    std::vector<byte> ReadFile(const std::string& filename);
    std::string HexToAscii(const std::string& hex);
    std::string HexToAscii(const std::vector<byte>& hexBuffer);
}

#endif // _UTILS_HPP_
