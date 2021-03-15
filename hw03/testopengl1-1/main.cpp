/*
 * main.cpp
 * Uddeep Karki
 * 03/14/2021
 * Program that uses OpenGL1.1 with GLFW to draw the triangle from Additional Program 3 from hw03
 */

#include <iostream>

#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
//#include <glad/glad.h> // had to comment out because errors with 1.1
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void draw();

int main() {
    //settings
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;

    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1); //changing from 3 to 1
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1); // changing from 3 to 1
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Give error with 1.1 : Failet to create GLFW window

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);//For Mac OS X
#endif

    // glfw window creation

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "HelloWindow", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to crate GLFW window" <<std::endl;
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSwapInterval(1);

    // glad: load all OpenGL function pointers
    // glad: doesn't work with 1.1 as
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }

    //render loop
    while(!glfwWindowShouldClose(window))
    {
        // input


        processInput(window);

        // rendering commands here
        // ...
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);

        draw();

        // glfw: swap buffers and poll IO events (keys pressed/ released, mouse moved etc.

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //glfw: terminate, clearing all previously allocated GLFW resources.

    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released
// this frame and react accordingly

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this
// callback function executes

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //make sure the viewport matches the new window dimensions; note that
    // width and height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void draw() {
// clear the screen to something other than black
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
// draw a triangle that covers the screen
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();
}
