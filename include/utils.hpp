#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <string>
#include <vector>

namespace Utils
{
    bool SupportedFileFormat(const std::string& fmt);

    std::vector<std::string> SplitStr(const std::string& str, char delimiter);
    std::vector<unsigned char> ReadFile(const std::string& filename);
}

#endif // _UTILS_HPP_
