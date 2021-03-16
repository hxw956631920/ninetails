
#include "ninetails.h"
#include <iostream>
#include <string>

using namespace std;

// #pragma comment (lib, "glew32.lib")
 
NT_USING_NAMESPACE

#include "./example/example1.h"
#include "./example/example2.h"

int main(int argc, char **argv)
{
    GLFWwindow* window;
    int example = -1;
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(960, 540, "NineTails", NULL, NULL);
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
        cerr << "Unable to initialize GLEW ... exiting" << endl;
        exit(1);
    }
    if (argc > 1)
    {
        for (int i = 0; i < argc; i++)
        {
            if (strcmp(argv[i], "--example=1") == 0)
            {
                example = 1;
                break;
            }
            else if (strcmp(argv[i], "--example=2") == 0)
            {
                example = 2;
                break;
            }
        }
        if (example == 1)
        {
            NT_EXAMPLE1::init();
            glfwSetKeyCallback(window, NT_EXAMPLE1::keyboardCallback);
        }
        else if(example == 1)
        {
            NT_EXAMPLE2::init();
            glfwSetKeyCallback(window, NT_EXAMPLE2::keyboardCallback);
        }
        else
        {
            NT_EXAMPLE1::init();
            glfwSetKeyCallback(window, NT_EXAMPLE1::keyboardCallback);
        }
    }
    else
    {
        NT_EXAMPLE1::init();
        glfwSetKeyCallback(window, NT_EXAMPLE1::keyboardCallback);
    }
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        /* Swap front and back buffers */
        
        /* Poll for and process events */
        if (example == 1)
        {
            NT_EXAMPLE1::display();
        }
        else if (example == 1)
        {
            NT_EXAMPLE2::display();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
        // std::cout << "baldwey baldwey" << endl;
    }

    glfwTerminate();
    return 0;
}