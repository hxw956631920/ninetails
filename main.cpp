
#include "ninetails.h"
#include <iostream>
#include <string>

using namespace std;

// #pragma comment (lib, "glew32.lib")
 
NT_USING_NAMESPACE

#include "./example/example1.h"
#include "./example/example2.h"

int main(void)
{
    // MainWindow *window = MainWindow::create();
    // window->createWindow();
    // init();
    // window->run(display);
    // return 0;

    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

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
        cerr << "Unable to initialize GLEW ... exiting" << endl;
        exit(1);
    }
    // NT_EXAMPLE1::init();
    NT_EXAMPLE2::init();

    glfwSetKeyCallback(window, NT_EXAMPLE2::keyboardCallback);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        /* Swap front and back buffers */
        
        /* Poll for and process events */
        NT_EXAMPLE2::display();
        glfwSwapBuffers(window);
        glfwPollEvents();
        // std::cout << "baldwey baldwey" << endl;
    }

    glfwTerminate();
    return 0;
}