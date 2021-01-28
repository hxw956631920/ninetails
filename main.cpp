
#include "ninetails.h"
// #pragma comment (lib, "glew32.lib")
 
NT_USING_NAMESPACE

enum VAO_IDs { PosVAO, ColorVAO, NumVAOs};

enum Buffer_IDs { PosVBO, ColorVBO, NumVBOs};

// enum VAO_IDs { Triangles, NumVAOs };
// enum Buffer_IDs { ArrayBuffer, NumBuffers };
 
enum Attrib_IDs { vPosition = 0, vColor = 1 };
 
GLuint VAOs[NumVAOs];
GLuint Buffers[NumVBOs - 1];
 
const GLuint NumVertices = 3;
 
void init()
{
    glGenVertexArrays(1, &VAOs[0]);
    glBindVertexArray(VAOs[0]);
 
    // GLfloat vertices[NumVertices][2] = {
    //     { -0.90, -0.90},
    //     {  0.85, -0.90},
    //     { -0.90,  0.85},
    //     {  0.90, -0.85},
    //     {  0.90,  0.90},
    //     { -0.85,  0.90},
    // };
    // GLfloat vertices[NumVertices*5] = {
    //     -0.90, -0.90,
    //     1.0, 0.0, 0.0,
    //     0.85, -0.90,
    //     0.0, 1.0, 0.0,
    //     -0.90,  0.85,
    //     0.0, 0.0, 1.0,
    //     0.90, -0.85,
    //     1.0, 0.0, 0.0,
    //     0.90,  0.90,
    //     0.0, 1.0, 0.0,
    //     -0.85,  0.90,
    //     0.0, 0.0, 1.0,
    // };
 
    GLfloat vertices[NumVertices*6] = {
        // -0.90, -0.90,
        // 0.85, -0.90,
        // -0.90,  0.85,
        // 0.90, -0.85,
        // 0.90,  0.90,
        // -0.85,  0.90,
        -0.5, -0.5, 0.0,
        0.5, -0.5, 0.0,
        0, 0.5, .5,

        0.0, 1.0, 0.0,
        1.0, 0.0, 0.0,
        0.0, 0.0, 1.0,
        // 1.0, 0.0, 0.0,
        // 0.0, 1.0, 0.0,
        // 0.0, 0.0, 1.0,
    };

    glGenBuffers(1, &Buffers[0]);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    ShaderInfo shaders[] = {
        { GL_VERTEX_SHADER, "../shader/script/triangles.vert" },
        { GL_FRAGMENT_SHADER, "../shader/script/triangles.frag" },
        { GL_NONE, NULL }
    };
 
    GLuint program = LoadShaders(shaders);
    glUseProgram(program);
 
#define  BUFFER_OFFSET(offset) ((void *)(offset))
 
    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), BUFFER_OFFSET(9*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(vColor);
}
 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(VAOs[0]);
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