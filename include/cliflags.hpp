#pragma once
#ifndef _CLI_FLAGS_HPP_
#define _CLI_FLAGS_HPP_

#include "skutils/skutilflagparser.hpp"

namespace CliArgs
{
    void InitalizeFlags(int argc, char** argv);
    void File(OPT int inputCount, OPT char** inputVals);
} // CliArgs

#endif // _CLI_FLAGS_HPP_
