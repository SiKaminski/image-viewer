#include "cliflags.hpp"

#include <string>
#include <vector>

#include "globals.hpp"
#include "utils.hpp"
#include "skutils/skutilflagparser.hpp"

SKUTIL::SK_VEC<SKUTIL::Flag> flags = {
    {
        'f',
        "file",
        "Image file to open",
        1,
        CliArgs::File
    }
};

void CliArgs::InitalizeFlags(int argc, char **argv)
{
    SKUTIL::FlagParser parser = SKUTIL::FlagParser(&flags);
    parser.ParseFlags(argc, argv);
}

void CliArgs::File(OPT int inputCount, OPT char** inputVals)
{
    // First and only element is the actual filepath
    std::string givenFilepath = inputVals[0];
    std::vector<std::string> splitPath = Utils::SplitStr(givenFilepath, '.');

    if (Utils::SupportedFileFormat(splitPath[1])) {
        Globals::FilePath = givenFilepath;
    } else {
        Globals::FilePath = "";
    }
}
