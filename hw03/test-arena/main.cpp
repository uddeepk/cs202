#include <GL/glew.h>
#include <GL/glext.h>
#include <GL/glx.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#define GLEW_STATIC

// Specify prototype of function
typedef void (*GENBUFFERS) (GLsizei, GLuint*);

//// Load address of function and assign it to a function pointer
//GENBUFFERS glGenBuffers = (GENBUFFERS)wglGetProcAddress("glGenBuffers");
//// or Linux:
//GENBUFFERS glGenBuffers = (GENBUFFERS)glXGetProcAddress((const GLubyte *) "glGenBuffers");
//// or OSX:
//GENBUFFERS glGenBuffers = (GENBUFFERS)NSGLGetProcAddress("glGenBuffers");

// Call function as normal
//GLuint buffer;
//glGenBuffers(1, &buffer);

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
int main(int argc, char *argv[])
{
    float vertices[] = {
            0.0f,  0.5f, // Vertex 1 (X, Y)
            0.5f, -0.5f, // Vertex 2 (X, Y)
            -0.5f, -0.5f  // Vertex 3 (X, Y)
    };
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
//    draw(); // not working ...
    SDL_Window* window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

    SDL_GLContext context = SDL_GL_CreateContext(window);
    // Fill with code ??...
    GENBUFFERS glGenBuffers = (GENBUFFERS)glXGetProcAddress((const GLubyte *) "glGenBuffers");
    SDL_Event windowEvent;
    while (true)
    {
        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//        draw();
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_KEYUP &&
                windowEvent.key.keysym.sym == SDLK_ESCAPE) break;
        }
        draw();
        SDL_GL_SwapWindow(window);
    }
    SDL_GL_DeleteContext(context);
    SDL_Delay(1000);

    SDL_Quit();
    return 0;
}