
#include "example1.h"

using namespace NT_EXAMPLE1;
NT_USING_NAMESPACE

// 要在cpp里面定义时候也要加上 类空间名 而我们写c++类的定义不用写是因为 
// c++类内函数前都加上了类名 并且一开始也声明了 using namespace 相当于类名前面就已经包含命名空间了
namespace NT_EXAMPLE1{

GLuint VAOs[NumVAOs+1];
GLuint Buffers[NumVBOs+1];

const GLuint NumVertices = 12;

int flag = 1;
int mode = 1;

Shader shader;

void init()
{
    shader.createShaderByFile("../shader/script/triangles");
    shader.use();

    init1();
    init2();
    init3();
}
 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (mode == 1)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else if(mode == 2)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    
    if (flag == 1)
    {
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, NumVertices);
    }
    else if(flag == 2)
    {
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, NumVertices);
    }
    else if(flag == 3)
    {
        glBindVertexArray(VAOs[2]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
    float timeValue = glfwGetTime();
    shader.use();
    shader.setUniform1f("timeValue", timeValue);
    glFlush();
}

void init1()
{
    glGenVertexArrays(1, &VAOs[0]);
    glBindVertexArray(VAOs[0]);
    // Vec_Color vec_color[6] = {
    //     Vec_Color(Vec2(-0.90, -0.90), Color3f(1.0, 0.0, 0.0)),
    //     Vec_Color(Vec2(0.85, -0.90), Color3f(0.0, 1.0, 0.0)),
    //     Vec_Color(Vec2(-0.90,  0.85), Color3f(0.0, 0.0, 1.0)),
    //     Vec_Color(Vec2(0.90, -0.85), Color3f(1.0, 0.0, 0.0)),
    //     Vec_Color(Vec2(0.90,  0.90), Color3f(0.0, 1.0, 0.0)),
    //     Vec_Color(Vec2(-0.85,  0.90), Color3f(0.0, 0.0, 1.0)),
    // }
    // GLfloat ***vertices = (GLfloat **)vec_color;
    // Vec3 v(-0.90, -0.90);
    // Color3f c(1.0, 0.0, 0.0); 
    // Vec_Color vc(v, c);
    // Vec2(-0.90, -0.90);
    GLfloat vertices[NumVertices][3] = {
        {-0.90, -0.90},
        {1.0, 0.0, 0.0},
        {0.85, -0.90},
        {0.0, 1.0, 0.0},
        {-0.90,  0.85},
        {0.0, 0.0, 1.0},
        {0.90, -0.85},
        {1.0, 0.0, 0.0},
        {0.90,  0.90},
        {0.0, 1.0, 0.0},
        {-0.85,  0.90},
        {0.0, 0.0, 1.0},
    };

    glGenBuffers(1, &Buffers[0]);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // glUseProgram(program);
 
    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GL_FLOAT), BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GL_FLOAT), BUFFER_OFFSET(3*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(vColor);
}

void init2()
{
    glGenVertexArrays(1, &VAOs[1]);
    glBindVertexArray(VAOs[1]);

    GLfloat vertices1[NumVertices][3] = {
        {-0.90, -0.90},
        {1.0, 0.5, 0.0},
        {0.85, -0.90},
        {0.0, 1.5, 0.0},
        {-0.90,  0.85},
        {0.0, 0.50, 1.0},

        {0.85, -0.90},
        {0.0, 1.5, 0.0},
        {0.85,  0.85},
        {0.0, 1.5, 0.0},
        {-0.90,  0.85},
        {0.0, 0.5, 1.0},
    };

    glGenBuffers(1, &Buffers[1]);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GL_FLOAT), BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GL_FLOAT), BUFFER_OFFSET(3*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(vColor);
}

void init3()
{
    glGenVertexArrays(1, &VAOs[2]);
    glBindVertexArray(VAOs[2]);

    GLfloat vertices[NumVertices][3] = {
        {-0.90, -0.90},
        {1.0, 0.5, 0.0},
        {0.85, -0.90},
        {0.0, 1.5, 0.0},
        {-0.90,  0.85},
        {0.0, 0.50, 1.0},
        {0.85,  0.85},
        {0.0, 1.5, 0.0},
    };   

    GLuint indices[] = {
        0, 1, 2, 1, 2, 3
    };

    glGenBuffers(1, &Buffers[2]);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GL_FLOAT), BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GL_FLOAT), BUFFER_OFFSET(3*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(vColor);
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
                if (flag == 1) flag = 2;
                else if (flag == 2) flag = 3;
                else if (flag == 3) flag = 1;
                break;
            case NT_KEY_T:
                if (mode == 1) mode = 2;
                else if (mode == 2) mode = 1;
                break;
        }
    }
}

}