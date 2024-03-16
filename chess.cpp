#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // GLFW window creation
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Chessboard", nullptr, nullptr);
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

    // Viewport and callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, 800, 600);

    // Vertex data
    std::vector<float> vertices;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            float x0 = -1.0f + i * 0.25f;
            float y0 = -1.0f + j * 0.25f;
            float x1 = x0 + 0.25f;
            float y1 = y0 + 0.25f;

            // First triangle
            vertices.push_back(x0);
            vertices.push_back(y0);
            vertices.push_back(x1);
            vertices.push_back(y0);
            vertices.push_back(x1);
            vertices.push_back(y1);

            // Second triangle
            vertices.push_back(x0);
            vertices.push_back(y0);
            vertices.push_back(x1);
            vertices.push_back(y1);
            vertices.push_back(x0);
            vertices.push_back(y1);
        }
    }

    // Vertex Buffer Object (VBO) and Vertex Array Object (VAO) creation
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Main rendering loop
    while (!glfwWindowShouldClose(window)) {
        // Input handling
        glfwPollEvents();

        // Rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw chessboard
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 2);
        glBindVertexArray(0);

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}


/* In file included from Model.h:5,
                 from Main.cpp:7:
Mesh.h:18:13: error: declaration of ‘VAO Mesh::VAO’ changes meaning of ‘VAO’ [-Wchanges-meaning]
   18 |         VAO VAO;
      |             ^~~
Mesh.h:18:9: note: used here to mean ‘class VAO’
   18 |         VAO VAO;
      |         ^~~
In file included from Mesh.h:6:
VAO.h:7:7: note: declared here
    7 | class VAO
      |       ^~~
Main.cpp:17:7: error: ‘float gamma’ redeclared as different kind of entity
   17 | float gamma = 2.2f;
      |       ^~~~~
In file included from /usr/include/features.h:503,
                 from /usr/include/c++/13.2.1/x86_64-pc-linux-gnu/bits/os_defines.h:39,
                 from /usr/include/c++/13.2.1/x86_64-pc-linux-gnu/bits/c++config.h:679,
                 from /usr/include/c++/13.2.1/bits/requires_hosted.h:31,
                 from /usr/include/c++/13.2.1/filesystem:35,
                 from Main.cpp:3:
/usr/include/bits/mathcalls.h:244:1: note: previous declaration ‘double gamma(double)’
  244 | __MATHCALL (gamma,, (_Mdouble_));
      | ^~~~~~~~~~
Main.cpp: In function ‘int main()’:
Main.cpp:100:75: error: cannot convert ‘double (*)(double) noexcept’ to ‘GLfloat’ {aka ‘float’} in argument passing
  100 |         glUniform1f(glGetUniformLocation(framebufferProgram.ID, "gamma"), gamma);
      |                                                                           ^~~~~
      |                                                                           |
      |                                                                           double (*)(double) noexcept */
