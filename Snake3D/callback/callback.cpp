#include "callback.h"
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	if (action == GLFW_PRESS) 
	{
		if (key == GLFW_KEY_RIGHT)
		{
			printf("R");
		}
		if (key == GLFW_KEY_LEFT) 
		{
			printf("L");

		}
		if (key == GLFW_KEY_UP)
		{
			printf("U");

		}
		if (key == GLFW_KEY_DOWN)
		{
			printf("D");

		}
	}
}