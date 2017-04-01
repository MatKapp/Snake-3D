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
	if (!window) //Je�eli okna nie uda�o si� utworzy�, to zamknij program
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//initializeGLUT(&argc, argv);

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje si� aktywny i polecenia OpenGL b�d� dotyczy� w�a�nie jego.
	glfwSwapInterval(1); //Czekaj na 1 powr�t plamki przed pokazaniem ukrytego bufora


	GLenum err;
	if ((err = glewInit()) != GLEW_OK) { //Zainicjuj bibliotek� GLEW
		fprintf(stderr, "Nie mo�na zainicjowa� GLEW: %s\n", glewGetErrorString(err));
		exit(EXIT_FAILURE);
	}
}

//Initialisation procedure.
void initOpenGLProgram(GLFWwindow* window) {
	//************Tutaj umieszczaj kod, kt�ry nale�y wykona� raz, na pocz�tku programu************
	glfwSetFramebufferSizeCallback(window, false); //Zarejestruj procedur� obs�ugi zmiany rozdzielczo�ci bufora ramki

	glClearColor(0, 0, 0, 1); //Ustaw kolor czyszczenia ekranu

	glEnable(GL_LIGHTING); //W��cz tryb cieniowania
	glEnable(GL_LIGHT0); //W��cz zerowe �r�d�o �wiat�a
	glEnable(GL_DEPTH_TEST); //W��cz u�ywanie budora g��boko�ci
	glEnable(GL_COLOR_MATERIAL); //W��cz �ledzenie kolor�w przez materia�

	//Register callbacks.
	glfwSetKeyCallback(window, key_callback);
}

int main(int argc, char** argv) 
{
	//Variable definition
	GLFWwindow* window; //Wska�nik na obiekt reprezentuj�cy okno
	GameModel *model = new GameModel();

	//Init glfw and glm, create window, handle errors.
	if (!glfwInit()) { //Zainicjuj bibliotek� GLFW
		fprintf(stderr, "Nie mo�na zainicjowa� GLFW.\n");
		exit(EXIT_FAILURE);
	}


	window = glfwCreateWindow(500, 500, "OpenGL", NULL, NULL);  //Utw�rz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.
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

		glfwPollEvents(); //Wykonaj procedury callback w zalezno�ci od zdarze� jakie zasz�y.
	}

	//Release resources.
	glfwDestroyWindow(window); //Usu� kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zaj�te przez GLFW
	exit(EXIT_SUCCESS);
}