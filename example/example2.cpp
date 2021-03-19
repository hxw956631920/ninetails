#include "example2.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../image/stb_image.h"

using namespace NT_EXAMPLE2;
NT_USING_NAMESPACE

namespace NT_EXAMPLE2{

#define arrayNum 1

#include <string>

GLuint vao;
GLuint texture[arrayNum];
GLuint vbo[2];
GLuint ebo[2];

int flag = 1;
int mode = 1;

Shader shader;

int check_png(std::string path, FILE **fp)
{
    int number = 8;
    unsigned char *header = new unsigned char[8];
    *fp = fopen(path.c_str(), "rb");
    if (!(*fp))
    {
        return 0;
    }
    int result = fread(header, 1, number, *fp);
    if (result != number)
    {         
        *fp = 0x0;
        return 0;
    }

    if (png_sig_cmp((const unsigned char *)header, 0, number) == 0)
    {
        return -1;
    }
}

void init()
{
    shader.createShaderByFile("shader/script/example2");
    shader.use();
    
    int width[arrayNum], height[arrayNum], nrChannels[arrayNum];
    // png_byte* data[arrayNum];
    unsigned char *data[arrayNum];
    std::string path = "example/";
    for (int i = 0; i < arrayNum; i++)
    {
        // std::string name = path + std::to_string(i+1) + ".jpg";
        std::string name = path + "3.jpg";
        data[i] = stbi_load(name.c_str(), &width, &height, &nrChannels, 0); 
        // FILE *fp;
        // check_png(name, &fp);
        // if (fp != 0)
        // {
        //     png_structp png_ptr;
        //     png_infop info_ptr;
        //     // 初始化libpng数据结构
        //     png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        //     if (!png_ptr)
        //         return ;
        //     info_ptr = png_create_info_struct(png_ptr);
        //     if (!info_ptr)
        //     {
        //         png_destroy_read_struct(&png_ptr, NULL, NULL);
        //         return ;
        //     }
        //     // 设置错误返回点
        //     if (setjmp(png_jmpbuf(png_ptr)))
        //     {
        //         png_destroy_read_struct(&png_ptr,  NULL, NULL);
        //         fclose(fp);
        //         return ;
        //     }
        //     rewind(fp);
        //     // 将png结构体与io流绑定
        //     png_init_io(png_ptr, fp);
        //     // 读取png图片
        //     png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_EXPAND, 0);
        //     // 读取通道数 颜色类型
        //     int channels, color_type;
        //     // 位深度 alpha通道 宽 高 
        //     int bit_depth, alpha_flag, width, height;
        //     channels = png_get_channels(png_ptr, info_ptr);
        //     color_type = png_get_color_type(png_ptr, info_ptr);
        //     bit_depth = png_get_bit_depth(png_ptr, info_ptr);
        //     width = png_get_image_width(png_ptr, info_ptr);
        //     height = png_get_image_height(png_ptr, info_ptr);
        //     // 读取实际rgb数据
        //     png_bytepp row_pointers;
        //     row_pointers = png_get_rows(png_ptr, info_ptr);
        //     int size;
        //     int pos = 0;
        //     if (channels == 4 || color_type == PNG_COLOR_TYPE_RGB_ALPHA)
        //     {
        //         alpha_flag = 1;
        //         size = width*height*4;
        //         data[i] = (png_bytep)malloc(size);         
        //         if (data[i] == NULL)
        //         {
        //             png_destroy_read_struct(&png_ptr, &info_ptr, 0);
        //             fclose(fp);
        //             return;
        //         }
        //         int temp = channels - 1;
        //         for (int l = 0; l < height; l++)
        //         {
        //             for (int j = 0; j < width * 4; j+=4)
        //             {
        //                 for (int k = temp; k >= 0; k--)
        //                 {
        //                     data[i][pos++] = row_pointers[l][j + k];
        //                 }                       
        //             }                   
        //         }                
        //     }
        //     else if (channels == 3 || color_type == PNG_COLOR_TYPE_RGB)
        //     {
        //         alpha_flag = 2;
        //         size = width*height*3;
        //         data[i] = (png_bytep)malloc(size);
        //         if (data[i] == NULL)
        //         {
        //             png_destroy_read_struct(&png_ptr, &info_ptr, 0);
        //             fclose(fp);
        //             return;
        //         }
        //         int temp = 3*width;
        //         for (int l = 0; l < height; l++)
        //         {
        //             for (int j = 0; j < temp; j+=3)
        //             {
        //                 data[i][pos++] = row_pointers[l][j+2];
        //                 data[i][pos++] = row_pointers[l][j+1];
        //                 data[i][pos++] = row_pointers[l][j+0];
        //             }                 
        //         }
        //         std::cout << "三通道" << std::endl;             
        //     }
        //     else
        //     {
        //         return;
        //     }
        // }
    }

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLfloat vertices[32] = {
        -.5f, -.5f, 0.0,
        1.0, 0.0, 0.0,
        0.0f, 0.0f,

        .5f, -.5f, 0.0,
        1.0, 0.0, 0.0,
        1.0f, 0.0f,

        .5f, .5f, 0.0,
        1.0, 0.0, 0.0,
        1.0f, 1.0f,

        -.5f, .5f, 0.0,
        1.0, 0.0, 0.0,
        0.0f, 1.0f,
    };
    glGenBuffers(1, &vbo[0]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint element[] = {
        0, 1, 2,
        0, 2, 3
    };
    glGenBuffers(1, &ebo[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(element), element, GL_STATIC_DRAW);

    glGenTextures(1, &texture[0]);
    // glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    if(data[0])
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width[0], height[0], 0, GL_RGB, GL_UNSIGNED_BYTE, data[0]);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), BUFFER_OFFSET(3*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(vColor);
    glVertexAttribPointer(vTexture, 2, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), BUFFER_OFFSET(6*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(vTexture);

    shader.setUniform1i("texture1", 0);

    // for(int i = 0; i < 3; i++)
    // {
    //     stbi_image_free(data[i]);
    // }
}

void display()
{
    // glClearColor(1.0, 1.0, 1.0, 1.0);
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(vao);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    // glDrawArrays(GL_TRIANGLE_STRIP, 0, 12);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    shader.use();
    glFlush();
}

void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
            case NT_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, true);
                break;
            case NT_KEY_R:
                flag = flag + 1;
                if (flag >= arrayNum) flag = 1;
                break;
            case NT_KEY_T:
                if (mode == 1) mode = 2;
                else if (mode == 2) mode = 1;
                break;
        }
    }
}

}