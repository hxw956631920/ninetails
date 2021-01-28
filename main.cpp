
#include "ninetails.h"
// #pragma comment (lib, "glew32.lib")
 
NT_USING_NAMESPACE

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
 
enum Attrib_IDs { vPosition = 0 };
 
GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
 
const GLuint NumVertices = 6;
 
void init()
{
    glGenVertexArrays(NumVAOs, VAOs);
    glBindVertexArray(VAOs[Triangles]);
 
    GLfloat vertices[NumVertices][2] = {
        { -0.90, -0.90},
        {  0.85, -0.90},
        { -0.90,  0.85},
        {  0.90, -0.85},
        {  0.90,  0.90},
        { -0.85,  0.90},
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
 
    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
}
 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(VAOs[Triangles]);
    glDrawArrays(GL_TRIANGLES, 0, NumVertices);
 
    glFlush();
}

int main(void)
{
    MainWindow *window = MainWindow::create();
    window->createWindow();
    init();
    window->run(display);
    return 0;
}