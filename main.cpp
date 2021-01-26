#include <iostream>

#include "EventManager.h"
// #pragma comment (lib, "glew32.lib")
 
NT_USING_NAMESPACE

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
 
enum Attrib_IDs { vPosition = 0 };
 
GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
 
const GLuint NumVertices = 12;
 
void init()
{
    glGenVertexArrays(NumVAOs, VAOs);
    glBindVertexArray(VAOs[Triangles]);
 
    // GLfloat vertices[NumVertices][2] = {
    //     { -0.90, -0.90},
    //     {  0.85, -0.90},
    //     { -0.90,  0.85},
    //     {  0.90, -0.85},
    //     {  0.90,  0.90},
    //     { -0.85,  0.90},
    // };

    GLfloat vertices[NumVertices] = {
        -0.90, -0.90,
        0.85, -0.90,
        -0.90,  0.85,
         0.90, -0.85,
         0.90,  0.90,
        -0.85,  0.90,
    };
 
    glGenBuffers(NumBuffers, Buffers);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
 
    ShaderInfo shaders[] = {
        { GL_VERTEX_SHADER, "triangles.vert" },
        { GL_FRAGMENT_SHADER, "triangles.frag" },
        { GL_NONE, NULL }
    };
 
    GLuint program = LoadShaders(shaders);
    glUseProgram(program);
 
#define  BUFFER_OFFSET(offset) ((void *)(offset))
 
    glVertexAttribPointer(vPosition, 1, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
}
 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
 
    glBindVertexArray(VAOs[Triangles]);
    // glDrawArrays(GL_TRIANGLES, 0, NumVertices);
    glDrawArrays(GL_POINTS, 0, NumVertices);
 
    glFlush();
}

int main(void)
{
    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit())
    {
        std::cerr << "Unable to initialize GLEW ... exiting" << std::endl;
        exit(1);
    }
    init();
    // 创建事件管理器
    EventManager *eventManager = EventManager::create();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        /* Swap front and back buffers */
        display();
        glfwSwapBuffers(window);
        // glfwSetInputMode(window, GLFW_CURSOR | GL_);
        eventManager->dealEvent();
    }

    glfwTerminate();
    return 0;
}