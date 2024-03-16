#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Chessboard", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set viewport size and register framebuffer resize callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, 800, 600);

    // Main rendering loop
    while (!glfwWindowShouldClose(window)) {
        // Input handling
        glfwPollEvents();

        // Render commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw chessboard
        glBegin(GL_QUADS);
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if ((i + j) % 2 == 0)
                    glColor3f(1.0f, 1.0f, 1.0f); // White
                else
                    glColor3f(0.0f, 0.0f, 0.0f); // Black
                glVertex2f(-1.0f + i * 0.25f, -1.0f + j * 0.25f);
                glVertex2f(-1.0f + (i + 1) * 0.25f, -1.0f + j * 0.25f);
                glVertex2f(-1.0f + (i + 1) * 0.25f, -1.0f + (j + 1) * 0.25f);
                glVertex2f(-1.0f + i * 0.25f, -1.0f + (j + 1) * 0.25f);
            }
        }
        glEnd();

        // Swap the front and back buffers
        glfwSwapBuffers(window);
    }

    // Clean up
    glfwTerminate();
    return 0;
}
