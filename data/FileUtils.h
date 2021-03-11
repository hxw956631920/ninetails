#ifndef __NT_FILEUTILS_H__
#define __NT_FILEUTILS_H__

#include <string>
#include "NTMacro.h"
#include <iostream>
#include <string>

NT_NAMESPACE_BEGIN

class FileUtils
{
public:
    static const char* readFile(std::string fileName);
};

NT_NAMESPACE_END

#endif
