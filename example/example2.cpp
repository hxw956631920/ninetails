#include "example2.h"

using namespace NT_EXAMPLE2;
NT_USING_NAMESPACE

namespace NT_EXAMPLE2{

#define arrayNum 5

#include <string>

GLuint vao;
GLuint texture[arrayNum];
GLuint vbo[2];

int flag = 1;
int mode = 1;

Shader shader;

void init()
{
    shader.createShaderByFile("shader/script/triangles");
    shader.use();
    
    int width[arrayNum], height[arrayNum], nrChannels[arrayNum];
    unsigned char *data[arrayNum];
    std::string path = "example/";
    std::string suffixp[arrayNum] = {".jpeg", ".jpeg", ".jpeg", ".png", ".png"};
    stbi_set_flip_vertically_on_load(true);
    for (int i = 0; i < arrayNum; i++)
    {
        std::string name = path + std::to_string(i+1) + suffixp[i];
        unsigned char *pData = stbi_load(name.c_str(), &width[i], &height[i], &nrChannels[i], 0);
        int length = width[i] * height[i] * nrChannels[i];
        data[i] = new unsigned char[length];
        memcpy(data[i], pData, length);
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

    GLuint element[] = {
        0, 1, 2,
        0, 2, 3
    };

    glGenBuffers(1, &vbo[0]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenTextures(arrayNum, texture);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // for(int i = 0; i < arrayNum; i++)
    // {
    //     glActiveTexture(i);
    //     glBindTexture(GL_TEXTURE_2D, texture[i]);
    //     // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    //     // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    //     // GLfloat borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    //     // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    //     if(data[i])
    //     {
    //         // std::cout << width[i] << height[i] << nrChannels[i] << std::endl;
    //         if(nrChannels[i] == 3)
    //         {
    //             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width[i], height[i], 0, GL_RGB, GL_UNSIGNED_BYTE, data[i]);
    //             glGenerateMipmap(GL_TEXTURE_2D);
    //         }
    //         else if(nrChannels[i] == 4)
    //         {
    //             std::cout << "rgba" << endl;
    //             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width[i], height[i], 0, GL_RGBA, GL_UNSIGNED_BYTE, data[i]);
    //             glGenerateMipmap(GL_TEXTURE_2D);
    //         }
    //     }
    // }
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    if(data[1])
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width[1], height[1], 0, GL_RGB, GL_UNSIGNED_BYTE, data[1]);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    if(data[4])
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width[4], height[4], 0, GL_RGB, GL_UNSIGNED_BYTE, data[4]);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    glGenBuffers(1, &vbo[1]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(element), element, GL_STATIC_DRAW);

    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), BUFFER_OFFSET(3*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(vColor);
    glVertexAttribPointer(vTexture, 2, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), BUFFER_OFFSET(6*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(vTexture);

    shader.setUniform1i("texture1", 0);
    shader.setUniform1i("texture2", 1);

    // for(int i = 0; i < 3; i++)
    // {
    //     stbi_image_free(data[i]);
    // }
}

void display()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBindVertexArray(vao);
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