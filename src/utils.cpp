#include "utils.hpp"

#include <sstream>

#include "globals.hpp"

namespace Utils
{
    bool SupportedFileFormat(const std::string& format)
    {
        for (auto allowedFormat : Globals::SUPPORTED_FILE_FORMATS) {
            if (format == allowedFormat) {
                return true;
            }
        }

        return false;
    }

    std::vector<std::string> SplitStr(const std::string& str, char delimiter)
    {
        std::vector<std::string> result;
        std::stringstream ss(str);
        std::string token;

        while (std::getline(ss, token, delimiter)) {
            result.push_back(token);
        }

        return result;
    }
}
