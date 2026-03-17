#include "utils.hpp"

#include <sstream>
#include <fstream>
#include <stdexcept>
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

    std::vector<byte> ReadFile(const std::string& filename)
    {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);
        if (!file)
            throw std::runtime_error("Failed to open file");

        // Get the file size
        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);

        std::vector<byte> buffer(size);
        if (!file.read(reinterpret_cast<char*>(buffer.data()), size))
            throw std::runtime_error("Failed to read file");

        return buffer;
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

    std::string HexToAscii(const std::vector<byte>& hexBuffer)
    {
        std::ostringstream oss;
        for (auto b : hexBuffer) {
            oss << std::hex << std::setw(2) 
                << std::setfill('0') << static_cast<int>(b);
        }

        return oss.str();
    }
}
