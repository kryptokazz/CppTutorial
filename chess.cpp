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


/*g++ -o modelImporter Main.cpp Model.cpp VAO.cpp EBO.cpp VBO.cpp Camera.cpp shaderClass.cpp Texture.cpp glad.c EBO.cpp stb.cpp -lglfw -lGL -lX11 -lpthread -lXrandr -lXi
/usr/bin/ld: /tmp/ccvaVhaL.o: in function `EBO::EBO(std::vector<unsigned int, std::allocator<unsigned int> >&)':
EBO.cpp:(.text+0x0): multiple definition of `EBO::EBO(std::vector<unsigned int, std::allocator<unsigned int> >&)'; /tmp/cclUUw4u.o:EBO.cpp:(.text+0x0): first defined here
/usr/bin/ld: /tmp/ccvaVhaL.o: in function `EBO::EBO(std::vector<unsigned int, std::allocator<unsigned int> >&)':
EBO.cpp:(.text+0x0): multiple definition of `EBO::EBO(std::vector<unsigned int, std::allocator<unsigned int> >&)'; /tmp/cclUUw4u.o:EBO.cpp:(.text+0x0): first defined here
/usr/bin/ld: /tmp/ccvaVhaL.o: in function `EBO::Bind()':
EBO.cpp:(.text+0x80): multiple definition of `EBO::Bind()'; /tmp/cclUUw4u.o:EBO.cpp:(.text+0x80): first defined here
/usr/bin/ld: /tmp/ccvaVhaL.o: in function `EBO::Unbind()':
EBO.cpp:(.text+0xa6): multiple definition of `EBO::Unbind()'; /tmp/cclUUw4u.o:EBO.cpp:(.text+0xa6): first defined here
/usr/bin/ld: /tmp/ccvaVhaL.o: in function `EBO::Delete()':
EBO.cpp:(.text+0xc8): multiple definition of `EBO::Delete()'; /tmp/cclUUw4u.o:EBO.cpp:(.text+0xc8): first defined here
/usr/bin/ld: /tmp/ccFwFusl.o: in function `main':
Main.cpp:(.text+0xdc6): undefined reference to `Mesh::Mesh(std::vector<Vertex, std::allocator<Vertex> >&, std::vector<unsigned int, std::allocator<unsigned int> >&, std::vector<Texture, std::allocator<Texture> >&)'
/usr/bin/ld: Main.cpp:(.text+0x1302): undefined reference to `Mesh::Draw(Shader&, Camera&, glm::mat<4, 4, float, (glm::qualifier)0>, glm::vec<3, float, (glm::qualifier)0>, glm::qua<float, (glm::qualifier)0>, glm::vec<3, float, (glm::qualifier)0>)'
/usr/bin/ld: /tmp/ccXIjw7z.o: in function `Model::Draw(Shader&, Camera&)':
Model.cpp:(.text+0x6fd): undefined reference to `Mesh::Draw(Shader&, Camera&, glm::mat<4, 4, float, (glm::qualifier)0>, glm::vec<3, float, (glm::qualifier)0>, glm::qua<float, (glm::qualifier)0>, glm::vec<3, float, (glm::qualifier)0>)'
/usr/bin/ld: /tmp/ccXIjw7z.o: in function `Model::loadMesh(unsigned int)':
Model.cpp:(.text+0xcd2): undefined reference to `Mesh::Mesh(std::vector<Vertex, std::allocator<Vertex> >&, std::vector<unsigned int, std::allocator<unsigned int> >&, std::vector<Texture, std::allocator<Texture> >&)'
collect2: error: ld returned 1 exit status*/
