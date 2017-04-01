#include <stdio.h>
#include <iostream>
#include "GL/glew.h"
#include "GL/glut.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <stdlib.h>
#include "GLFW/glfw3.h"
#include "constants.h"
#include "figures/allmodels.h"
#include "gamemodel.h"
#include "simulation/simulation.h"
#include "draw2D/draw2D.h"
#include "callback/callback.h"
#include "draw3D/draw3D.h"


using namespace glm;


void preliminaryInit(GLFWwindow* window)
{
	if (!window) //Je¿eli okna nie uda³o siê utworzyæ, to zamknij program
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//initializeGLUT(&argc, argv);

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje siê aktywny i polecenia OpenGL bêd¹ dotyczyæ w³aœnie jego.
	glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora


	GLenum err;
	if ((err = glewInit()) != GLEW_OK) { //Zainicjuj bibliotekê GLEW
		fprintf(stderr, "Nie mo¿na zainicjowaæ GLEW: %s\n", glewGetErrorString(err));
		exit(EXIT_FAILURE);
	}
}

//Initialisation procedure.
void initOpenGLProgram(GLFWwindow* window) {
	//************Tutaj umieszczaj kod, który nale¿y wykonaæ raz, na pocz¹tku programu************
	glfwSetFramebufferSizeCallback(window, false); //Zarejestruj procedurê obs³ugi zmiany rozdzielczoœci bufora ramki

	glClearColor(0, 0, 0, 1); //Ustaw kolor czyszczenia ekranu

	glEnable(GL_LIGHTING); //W³¹cz tryb cieniowania
	glEnable(GL_LIGHT0); //W³¹cz zerowe Ÿród³o œwiat³a
	glEnable(GL_DEPTH_TEST); //W³¹cz u¿ywanie budora g³êbokoœci
	glEnable(GL_COLOR_MATERIAL); //W³¹cz œledzenie kolorów przez materia³

	//Register callbacks.
	glfwSetKeyCallback(window, key_callback);
}

int main(int argc, char** argv) 
{
	//Variable definition
	GLFWwindow* window; //WskaŸnik na obiekt reprezentuj¹cy okno
	GameModel *model = new GameModel();

	//Init glfw and glm, create window, handle errors.
	if (!glfwInit()) { //Zainicjuj bibliotekê GLFW
		fprintf(stderr, "Nie mo¿na zainicjowaæ GLFW.\n");
		exit(EXIT_FAILURE);
	}


	window = glfwCreateWindow(500, 500, "OpenGL", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.
	preliminaryInit(window);

	//Set buffer moder, color, light and handle callbacks.
	initOpenGLProgram(window);

	//Game loop
	glfwSetTime(0);
	while (!glfwWindowShouldClose(window))
	{
		drawMinimap(window, model);

		//Simulate changes in game every 1 second.
		if (glfwGetTime() > 1) {
			simulation(model);
			glfwSetTime(0);
			std::cout << model->head_position[0] << model->head_position[1] << std::endl;
		}

		glfwPollEvents(); //Wykonaj procedury callback w zaleznoœci od zdarzeñ jakie zasz³y.
	}

	//Release resources.
	glfwDestroyWindow(window); //Usuñ kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajête przez GLFW
	exit(EXIT_SUCCESS);
}