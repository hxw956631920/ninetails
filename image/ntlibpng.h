#ifndef __NT_LIBPNG_H__
#define __NT_LIBPNG_H__

// png图像头部块
typedef struct IMAGE_PNG_IHDR{
    // 宽度
    int width;
    // 高度
    int heith;
    // 深度
    char depth;
    // 颜色类型 
    char colorType;
    
    char compressMethod;
}IMAGE_PNG_IHDR;

// png图像数据块
typedef struct IMAGE_PNG_IDAT{

}IMAGE_PNG_IDAT;

// png图像结束块
typedef struct IMAGE_PNT_IEND{

}IMAGE_PNT_IEND;

#endif