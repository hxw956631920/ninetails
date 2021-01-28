#ifndef __NT_IMAGE_H__
#define __NT_IMAGE_H__

#include "../ninetails.h"
#include <png.h>

NT_NAMESPACE_BEGIN

typedef struct NT_pngstruct
{
    // libpng结构体
    png_structp png_ptr;
    // libpng信息
    png_infop info_ptr;
} NT_pngstruct;

class Image
{
public:
    static void loadBatchImage(const char* fileName);
private:
    static std::vector<NT_pngstruct> pngVec;
};

NT_NAMESPACE_END

#endif