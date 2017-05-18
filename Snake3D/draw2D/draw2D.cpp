#include "draw2D.h"


using namespace glm;

//Global variables
float aspect = 1.0f; //Aktualny stosunek szeroko�ci do wysoko�ci okna




					 //Tablica wsp�rz�dnych wierzcho�k�w
float smallQuadVertices[] = {
	-1,-1,0,
	1,-1,0,
	1, 1,0,
	-1, 1,0
};
//Tablica kolor�w wierzcho�k�w
float smallQuadColorsRed[] = {
	1,0,0,
	1,0,0,
	1,0,0,
	1,0,0
};

float smallQuadColorsGreen[] = {
	0,1,0,
	0,1,0,
	0,1,0,
	0,1,0,
};

float smallQuadColorsBlue[] = {
	0,0,1,
	0,0,1,
	0,0,1,
	0,0,1,
};




//Procedura rysuj�ca zawarto�� sceny
void drawMinimap(GLFWwindow* window, GameModel* model) {
	//************Tutaj umieszczaj kod rysuj�cy obraz******************l

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wyczy�� bufor kolor�w (czyli przygotuj "p��tno" do rysowania)

													//***Przygotowanie do rysowania****
	mat4 P = perspective(50.0f*PI / 180.0f, aspect, 1.0f, 50.0f); //Wylicz macierz rzutowania P
	mat4 V = lookAt( //Wylicz macierz widoku
		vec3(0.0f, 0.0f,1.2*(float)model->size),		// observer
		vec3(0.0f, 0.0f, 0.0f),							//center
		vec3(0.0f, 1.0f, 0.0f));						//nose vector
	glMatrixMode(GL_PROJECTION); //W��cz tryb modyfikacji macierzy rzutowania
	glLoadMatrixf(value_ptr(P)); //Za�aduj macierz rzutowania
	glMatrixMode(GL_MODELVIEW);  //W��cz tryb modyfikacji macierzy model-widok
						 //***Rysowanie modelu***
								 //1. Wyliczenie i za�adowanie macierzy model-widok
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	

	// Rysowanie kwadrat�w
	for (int y = 0; y < model->size; y++)
	{
		for (int x = 0; x < model->size; x++)
		{
			float grid = 0.065*(float) model->size;            // grid ustawia szeroko�� czarnych lini na minimapce dobrane empirycznie
			float offset = 0.1 * 500;
			

			//Change color depending on enum value->
			
			if (model->elements[y][x] == empty) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsRed);
			}
			else if (model->elements[y][x] == fodder) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsGreen);
			}
			else if (model->elements[y][x] == snake_head) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue); 
			}
			else if (model->elements[y][x] == snake_part) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue); 
			}
			else if (model->elements[y][x] == snake_tail) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue); 
			}
			
			mat4 M = mat4(1.0f);
			M = scale(M, vec3(0.1f, 0.1f, 0.1f));
			M = translate(M, vec3( offset + x*grid + x,  offset +   y*grid + y, 0.0f));
			glLoadMatrixf(value_ptr(V*M));
			







			//glRectf(offset + (0.9f + x) / 5, offset + (0.1f + y) / 5, offset + (0.1f + x) / 5, offset + (0.9f + y) / 5);
			/*
			glBegin(GL_QUADS); // 1x1 pixel
			
			
			
			glVertex2f(offset + ( 0.1f + x)/5,offset + ( 0.9f + y)/5);
			glVertex2f(offset + (0.1f + x) / 5, offset + (0.1f + y) / 5);
			glVertex2f(offset + (0.9f + x) / 5, offset + (0.1f + y) / 5);
			glVertex2f(offset + (0.9f + x) / 5, offset + (0.9f + y) / 5);

			glEnd();*/

			glVertexPointer(3, GL_FLOAT, 0, smallQuadVertices); //Ustaw tablic� myCubeVertices jako tablic� wierzcho�k�w

			//glColorPointer(3, GL_FLOAT, 0, smallQuadColors); //Ustaw tablic� myCubeColors jako tablic� kolor�w

			glDrawArrays(GL_QUADS, 0, 4); //Rysuj model

										  //Posprz�taj po sobie
			
		}
		
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);


	//glfwSwapBuffers(window); //Przerzu� tylny bufor na przedni
}
