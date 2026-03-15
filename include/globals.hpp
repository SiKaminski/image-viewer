#pragma once
#ifndef _GLOBALS_HPP_
#define _GLOBALS_HPP_

#include <string>
#include <vector>

#include "skutils/logger/logger.hpp"

#ifndef PROJECT_NAME_STR
#define PROJECT_NAME_STR "cpp-image-viewer"
#endif

namespace Globals
{
    constexpr int MINIMUM_ARGUMENT_COUNT {3};

    constexpr int MINIMUM_WINDOW_WIDTH  {600};
    constexpr int MAXIMUM_WINDOW_WIDTH  {800};
    constexpr int MINIMUM_WINDOW_HEIGHT {-1};
    constexpr int MAXIMUM_WINDOW_HEIGHT {-1};

    inline const std::vector<std::string> SUPPORTED_FILE_FORMATS = {
        "bmp", ".dib"
    };

    inline Logger Logger;
    inline std::string FilePath; 
}
#endif // _GLOBALS_HPP_
