// A program to try to spawn a window using opengl :D
#include<window.h>

int main(){
    // GLFW Library inits and configuration
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Window init and config
    GLFWwindow* window = glfwCreateWindow(1280,720, "heya tintu!", NULL, NULL);
    if(window == NULL){
        std::cout<< "Failed to create GLFW window :(\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // linking the created window object to the glfw states

    if( !gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        std::cout<< "Failed to intialize GLAD\n";
        return -1;
    }

    glViewport(0,0,1280,720);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(window)){
        // Input handling- currently only focussing on the exit :|
        processInput(window);

        // Rendering part here :D
        glClearColor(0.13f, 0.5f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width, height);
}