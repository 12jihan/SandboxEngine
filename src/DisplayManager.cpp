#include "headers/DisplayManager.h"

DisplayManager::DisplayManager(WindowProps const& properties) {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
};


DisplayManager::createWindow() {
    // glfw window creation
    // --------------------
    window = glfwCreateWindow(Width, Height, "Sandbox Engine", NULL, NULL);
    if (Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    };
};

void DisplayManager::SetupWindow() {
    glfwMakeContextCurrent(window);
    // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // glfwSetCursorPosCallback(window, mouse_callback);
    // glfwSetScrollCallback(window, scroll_callback);
};

GLFWwindow* DisplayManager::getWindow() {
    return window;
};

void DisplayManager::render() {
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
};

void DisplayManager::process() {
    // input
        // -----
        processInput(window);
};

void DisplayManager::~DisplayManager() {
    glfwDestroyWindow(window);
    glfwTerminate();
};