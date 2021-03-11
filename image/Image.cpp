
#include "Image.h"
#include <memory.h>

NT_USING_NAMESPACE

void Image::loadImage(const std::string fileName)
{
    _data = FileUtils::readFile(fileName);
    switch (getImagePormat())
    {
        case IMAGE_FORMAT::PNG:

            break;
        case IMAGE_FORMAT::JPG:
            break;
    }
}

IMAGE_FORMAT Image::getImagePormat()
{
    if (isPng())
    {
        return IMAGE_FORMAT::PNG;
    }
    else if(isJpeg())
    {
        return IMAGE_FORMAT::JPG;
    }
    else
    {
        return IMAGE_FORMAT::UNDEFINE;
    }
}

bool Image::isPng()
{
    unsigned char png_signature[] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
    return memcmp(_data, png_signature, sizeof(png_signature)) == 0;
}

bool Image::isJpeg()
{
    return true;
}