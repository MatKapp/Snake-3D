#include <stdio.h>
#include <cstdio>
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
#include "draw3D/draw3D.h"


using namespace glm;

//Global variables
GameModel *model;

int callback_temp;


//Handle callbacks.
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_RIGHT)
		{
			//model->direction_request = right;
			model->direction_request = Direction((model->direction + 1) % 4);
		}
		if (key == GLFW_KEY_LEFT)
		{
			//model->direction_request = left;
			callback_temp = int(model->direction) - 1;
			if (callback_temp == -1) callback_temp = 3;

			//model->direction_request = (Direction)( ( (int)model->direction_request - 1 ) % 4);

			model->direction_request = Direction(callback_temp);

		}
	}
}
	



void displayFrame() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

void initializeGLUT(int* pargc, char** argv) {
	glutInit(pargc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Program OpenGL");
	glutDisplayFunc(displayFrame);
}

void initializeGLEW() {
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		/* Problem: Nie uda�o si� zainicjowa� biblioteki GLEW. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		exit(1);
	}
}
//Preliminary initialisation.
void preliminaryInit(GLFWwindow* window){
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
	glEnable(GL_LIGHT1); //W��cz zerowe �r�d�o �wiat�a
	glEnable(GL_DEPTH_TEST); //W��cz u�ywanie bufora g��boko�ci
	glEnable(GL_COLOR_MATERIAL); //W��cz �ledzenie kolor�w przez materia�

	//Set attributes for window.

	//Register callbacks.
	glfwSetKeyCallback(window, key_callback);

	//Set basis for random choice.
	srand(time(NULL));
}





int main(int argc, char** argv) 
{
	
	//Hide console window.
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);

	//Variable definition
	GLFWwindow* minimap_window; //Pointer to a minimap
	model = new GameModel();

	//Init glfw and glm, create window, handle errors.
	if (!glfwInit()) { //Zainicjuj bibliotek� GLFW
		fprintf(stderr, "Nie mo�na zainicjowa� GLFW.\n");
		exit(EXIT_FAILURE);
	}
	
	minimap_window = glfwCreateWindow(1000, 1000, "Minimap", NULL, NULL);  //Utw�rz okno 500x500 o tytule "Minimap" i kontekst OpenGL.
	preliminaryInit(minimap_window);

	//Set buffer moder, color, light and handle callbacks.
	initOpenGLProgram(minimap_window);
	
	
	//Game loop
	float passed_time = 0;
	glfwSetTime(0.0f);
	while (!glfwWindowShouldClose(minimap_window)){
		passed_time = glfwGetTime();
		// Rysowanie gry i nak�adanie na obraz minimapy
		drawGame(minimap_window, model, passed_time);
		//drawMinimap(minimap_window, model);
		glfwSwapBuffers(minimap_window); //Przerzu� tylny bufor na przedni

		//Simulate changes in game every 1 second.
		passed_time = glfwGetTime();
		if (passed_time > model->timeout) {
			simulation(model, passed_time);
			glfwSetTime(0.0f);
		}
		
		glfwPollEvents(); //Wykonaj procedury callback w zalezno�ci od zdarze� jakie zasz�y.
	}

	//Release resources.
	glfwDestroyWindow(minimap_window); //Usu� kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zaj�te przez GLFW
	exit(EXIT_SUCCESS);
}