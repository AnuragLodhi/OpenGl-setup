#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

void error_callback(int error, const char* description) {
	std::cerr << "Error: " << description << std::endl;
}

int main() {
	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Window", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cerr << "Error initializing GLEW" << std::endl;
		glfwTerminate();
		return -1;
	}

	int glVersion[2] = { -1, 1 };
	glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
	glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);
	std::cout << "Using OpenGL: " << glVersion[0] << '.' << glVersion[1] << std::endl;

	glClearColor(1.0, 0.0, 0.0, 1.0);
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}
