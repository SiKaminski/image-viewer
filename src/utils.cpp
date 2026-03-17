#include "utils.hpp"

#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

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

    std::string HexToAscii(const std::string& hex)
    {
        std::string ascii = "";
        for (size_t i = 0; i < hex.length(); i+=2) {
            std::string part = hex.substr(i, 2);
            char c = std::stoul(part, nullptr, 16);
            ascii += c;
        }

        return ascii;
    }

    std::string HexToAscii(const std::vector<byte>& buf)
    {
        return HexToAscii(buf.data(), buf.size());
    }
    
    std::string HexToAscii(const byte* buf, size_t len)
    {
        std::string s;
        s.reserve(len);
        for (size_t i = 0; i < len; ++i)
            s.push_back(static_cast<char>(buf[i]));

        return s;
    }

    void PrintAscii(const std::string& str)
    {
        std::string out;
        for (char c : str) {
            out += c;
        }

        Globals::Logger.Log(DEBUG, out.c_str());
    }
}
