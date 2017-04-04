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
#include "draw3D/draw3D.h"


using namespace glm;

//Global variables
GameModel *model;



//Handle callbacks.
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_RIGHT && model->direction != left)
		{
			model->direction_request = right;
		}
		if (key == GLFW_KEY_LEFT && model->direction != right)
		{
			model->direction_request = left;
		}
		if (key == GLFW_KEY_UP && model->direction != down)
		{
			model->direction_request = up;
		}
		if (key == GLFW_KEY_DOWN && model->direction != up)
		{
			model->direction_request = down;
		}
	}
}


<<<<<<< HEAD
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
		/* Problem: Nie uda³o siê zainicjowaæ biblioteki GLEW. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		exit(1);
=======
//Preliminary initialisation.
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
>>>>>>> origin/master
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
	if (!glfwInit()) { //Zainicjuj bibliotekê GLFW
		fprintf(stderr, "Nie mo¿na zainicjowaæ GLFW.\n");
		exit(EXIT_FAILURE);
	}


	minimap_window = glfwCreateWindow(500, 500, "OpenGL", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.
	preliminaryInit(minimap_window);

	//Set buffer moder, color, light and handle callbacks.
	initOpenGLProgram(minimap_window);

	//Game loop
	glfwSetTime(0);
	while (!glfwWindowShouldClose(minimap_window))
	{
		drawMinimap(minimap_window, model);

		//Simulate changes in game every 1 second.
		float passed_time = glfwGetTime();
		if (passed_time > model->timeout) {
			simulation(model);
			glfwSetTime(0);
		}

		glfwPollEvents(); //Wykonaj procedury callback w zaleznoœci od zdarzeñ jakie zasz³y.
	}

	//Release resources.
	glfwDestroyWindow(minimap_window); //Usuñ kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajête przez GLFW
	exit(EXIT_SUCCESS);
}