
#include "Image.h"

NT_USING_NAMESPACE

std::vector<NT_pngstruct> Image::pngVec;

void Image::loadBatchImage(const char* fileName)
{
    int iRetVal;
    NT_pngstruct pngStruct;

    pngStruct.png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,NULL,NULL,NULL);
    if(!pngStruct.png_ptr)
        return;
    pngStruct.info_ptr = png_create_info_struct(pngStruct.png_ptr);
    if(!pngStruct.info_ptr)
    {
        png_destroy_read_struct(&pngStruct.png_ptr,NULL,NULL);
        return;
    }
    iRetVal=setjmp(png_jmpbuf(pngStruct.png_ptr));//安装错误处理跳转点
    //当libpng内部出现错误的时候，libpng会调用longjmp直接跳转到这里运行。
    if(iRetVal)//setjmp的返回值就是libpng跳转后提供的错误代码（貌似总是1，但是还是请大家看libpng的官方文档）
    {
        fprintf(stderr,"错误码：%d\n",iRetVal);
        return;
    }

    FILE *fp = fopen("fileName", "rb");
    if(!fp)
        return;
    png_init_io(pngStruct.png_ptr, fp);
    png_read_info(pngStruct.png_ptr, pngStruct.info_ptr);

    unsigned int width, height; 
    int bit_depth, color_type;
    png_get_IHDR(pngStruct.png_ptr, pngStruct.info_ptr, &width, &height, &bit_depth, &color_type, NULL, NULL, NULL);

    png_color_16p pBackground;
    png_get_bKGD(pngStruct.png_ptr, pngStruct.info_ptr, &pBackground);

    if(color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(pngStruct.png_ptr);//要求转换索引颜色到RGB
    if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth<8)
        png_set_expand_gray_1_2_4_to_8(pngStruct.png_ptr);
    if(bit_depth == 16)
        png_set_strip_16(pngStruct.png_ptr);
    if(png_get_valid(pngStruct.png_ptr, pngStruct.info_ptr,PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(pngStruct.png_ptr);
    if(color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(pngStruct.png_ptr);
    
    // COLORREF** ppLinePtrs = (COLORREF**)malloc(height*sizeof(COLORREF*));//列指针
    // if(!ppLinePtrs)
    //     return;
    // int i = height;
    // int y = 0;
    // while(i--)
    //     ppLinePtrs[y++] = (COLORREF*)&g_pBits[i * width];
}
