#include "utils.hpp"

#include <sstream>
#include <fstream>
#include <stdexcept>
#include <vector>

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

    std::vector<unsigned char> ReadFile(const std::string& filename)
    {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);
        if (!file)
            throw std::runtime_error("Failed to open file");

        // Get the file size
        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);

        std::vector<unsigned char> buffer(size);
        if (!file.read(reinterpret_cast<char*>(buffer.data()), size))
            throw std::runtime_error("Failed to read file");

        return buffer;
    }
}
