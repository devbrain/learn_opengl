//
// Created by igor on 30/09/2025.

#include <GLFW/glfw3.h>
#include <cstdio>

int main() {
    if (!glfwInit()) return 1;
    GLFWwindow* win = glfwCreateWindow(640, 480, "GLFW OK", nullptr, nullptr);
    if (!win) {
        glfwTerminate();
        return 1;
    }
    while (!glfwWindowShouldClose(win)) {
        glfwPollEvents();
        glfwSwapBuffers(win);
    }
    glfwDestroyWindow(win);
    glfwTerminate();
    return 0;
}
