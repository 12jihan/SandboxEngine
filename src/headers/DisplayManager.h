#include <GLFW/glfw3.h>
#include <string>

enum class WindowMode
{
    FULLSCREEN = 0,
    WINDOWED = 1
};

struct WindowProps
{
    unsigned int Width, Height;
    std::string Title;
    WindowMode Mode;
};

class DisplayManager {
    GLFWwindow* window;

    // WindowProps props = {
    //     unsigned int width = 1280;
    //     unsigned int height = 720;
    //     std::string title = "Default Title -- Please Set a Title";
    //     WindowMode mode = WindowMode::WINDOWED;
    // };

    DisplayManager(WindowProps const& properties);

    ~DisplayManager();

public:
    void createWindow();
    void setupWindow();
    GLFWwindow* getWindow();
    void render();
    void process();

};