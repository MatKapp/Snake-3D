#include "draw2D.h"

using namespace glm;

//Global variables
float aspect = 1.0f; //Aktualny stosunek szeroko�ci do wysoko�ci okna

//Procedura rysuj�ca zawarto�� sceny
void drawMinimap(GLFWwindow* window, GameModel* model) {
	//************Tutaj umieszczaj kod rysuj�cy obraz******************l

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wyczy�� bufor kolor�w (czyli przygotuj "p��tno" do rysowania)

														//***Przygotowanie do rysowania****
	mat4 P = perspective(50.0f*PI / 180.0f, aspect, 1.0f, 50.0f); //Wylicz macierz rzutowania P
	mat4 V = lookAt( //Wylicz macierz widoku
		vec3(0.0f, 0.0f, 1.2 * (float)model->size),
		vec3(0.0f, 0.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0f));
	glMatrixMode(GL_PROJECTION); //W��cz tryb modyfikacji macierzy rzutowania
	glLoadMatrixf(value_ptr(P)); //Za�aduj macierz rzutowania
	glMatrixMode(GL_MODELVIEW);  //W��cz tryb modyfikacji macierzy model-widok

								 //***Rysowanie modelu***
								 //1. Wyliczenie i za�adowanie macierzy model-widok
	mat4 M = mat4(1.0f);
	glLoadMatrixf(value_ptr(V*M));

	// Rysowanie kwadrat�w
	for (int y = 0; y < model->size; y++)
	{
		for (int x = 0; x < model->size; x++)
		{
			float offset = -0.5*(float)model->size;

			//Change color depending on enum value->
			if (model->elements[y][x] == empty) {
				glColor3f(1.0f, 0.0f, 0.0f);
			}
			else if (model->elements[y][x] == fodder) {
				glColor3f(1.0f, 1.0f, 0.0f);
			}
			else if (model->elements[y][x] == snake_head) {
				glColor3f(1.0f, 1.0f, 1.0f);
			}
			else if (model->elements[y][x] == snake_part) {
				glColor3f(0.0f, 0.0f, 1.0f);
			}
			else if (model->elements[y][x] == snake_tail) {
				glColor3f(0.0f, 1.0f, 0.0f);
			}
			glBegin(GL_QUADS); // 1x1 pixel
			glVertex2f(offset + 0.1f + x, offset + 0.1f + y);
			glVertex2f(offset + 0.9f + x, offset + 0.1f + y);
			glVertex2f(offset + 0.9f + x, offset + 0.9f + y);
			glVertex2f(offset + 0.1f + x, offset + 0.9f + y);
			glEnd();
		}
	}


	glfwSwapBuffers(window); //Przerzu� tylny bufor na przedni
}
