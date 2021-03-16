#ifndef __NT_IMAGE_H__
#define __NT_IMAGE_H__

#include "../NTMacro.h"
#include "../data/FileUtils.h"

NT_NAMESPACE_BEGIN

enum IMAGE_FORMAT{
    PNG,
    JPG,
    UNDEFINE
};

class Image
{
public:
    void loadImage(const std::string fileName);
private:
    // 获取图像格式 
    IMAGE_FORMAT getImagePormat();
    // 是否为png
    bool isPng();
    // 是否为jpg
    bool isJpeg();
    // 加载png图像至内存

private:
    NT_PROPERTY_RDONLY(const char*, _data, Data)
};

NT_NAMESPACE_END

#endif