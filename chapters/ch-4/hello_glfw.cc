//
// Created by igor on 30/09/2025.
//

#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

struct terminator {
    ~terminator() {
        glfwTerminate();
    }
};

static void process_input(GLFWwindow* w) {
    if (glfwGetKey(w, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(w, true);
    }
}

static void render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello GLFW", nullptr, nullptr);
    terminator guard;
    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        return 1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL(glfwGetProcAddress)) {
        std::cerr << "Failed to load GLAD" << std::endl;
        return 1;
    }
    std::cout << "Glad initialized" << std::endl;

    glfwSetFramebufferSizeCallback(window, []([[maybe_unused]] GLFWwindow* win, int w, int h) {
        glViewport(0,0, w, h);
    });

    std::cout << "Running... (press ESC to exit)" << std::endl;

    while (!glfwWindowShouldClose(window)) {
        process_input(window);
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    std::cout << "Terminating..." << std::endl;

    return 0;
}