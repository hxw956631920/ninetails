#include "FileUtils.h"
#include <cstdlib>
#include <string.h>

NT_USING_NAMESPACE

const char* FileUtils::readFile(std::string fileName)
{
    FILE* infile;
#ifdef WIN32
    fopen_s( &infile, fileName.c_str(), "rb" );
#else
    infile = fopen( fileName.c_str(), "rb" );
#endif // WIN32
    fseek( infile, 0, SEEK_END );
    int len = ftell( infile );
    fseek( infile, 0, SEEK_SET );

    char* data = new char[len+1];
 
    fread( data, 1, len, infile );
    fclose( infile );
 
    data[len] = 0;

    return const_cast<const char*>(data);
}