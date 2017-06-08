#ifndef draw3D_H
#define draw3D_H
#include <stdio.h>
#include <iostream>
#include "../GL/glew.h"
#include "../GL/glut.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include <stdlib.h>
#include "../GLFW/glfw3.h"
#include "../constants.h"
#include "../figures/allmodels.h"
#include "../gamemodel.h"



void drawGame(GLFWwindow* window, GameModel *model, float passed_time);
void init_3D_drawing();
	
#endif
