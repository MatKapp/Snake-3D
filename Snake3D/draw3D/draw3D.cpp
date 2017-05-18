#include "draw3D.h"
using namespace glm;
int scale_value = 0.4;

mat4 change_camera(GameModel* model) {
	mat4 V;
	
	if (model->direction == up) {
		V = lookAt( //Wylicz macierz widoku
			vec3(0.4*model->head_position[1], model->size* 0.4f, ((1.2f *(float)model->size) - 0.4 *model->head_position[0])),
			vec3(model->head_position[1] * 0.4f, 1.0f, -0.4*model->head_position[0] + 0.4 * model->size),
			vec3(0.0f, 1.0f, 0.0f));

	}
	else if (model->direction == down) {
		V = lookAt( //Wylicz macierz widoku
			vec3(0.4*model->head_position[1], model->size* 0.4f, (-(0.4f *(float)model->size) - 0.4 *model->head_position[0])),
			vec3(model->head_position[1] * 0.4f, 1.0f, -0.4*model->head_position[0] + 0.4 * model->size),
			vec3(0.0f, 1.0f, 0.0f));

	}
	
	
	else if (model->direction == left) {
		V = lookAt( //Wylicz macierz widoku
			vec3(2 * 0.4f*model->size + 0.4 *model->head_position[1], model->size* 0.4f, 0.4* model->size - 0.4*model->head_position[0]),
			vec3(model->head_position[1] * 0.4f, 1.0f, -0.4*model->head_position[0] + 0.4 * model->size),
			vec3(0.0f, 1.0f, 0.0f));

	}
	else if (model->direction = right) {
		V = lookAt( //Wylicz macierz widoku
			vec3(-2 * 0.4f*model->size + 0.4 *model->head_position[1], model->size* 0.4f, 0.4* model->size - 0.4*model->head_position[0]),
			vec3(model->head_position[1] * 0.4f, 1.0f, -0.4*model->head_position[0] + 0.4 * model->size),
			vec3(0.0f, 1.0f, 0.0f));
	}

	return V;
}
	



void drawGame(GLFWwindow* window, GameModel *model) {
	unsigned int myCubeVertexCount = 24;

	float myCubeVertices[] = {
		-1,-1,-1,
		1,-1,-1,
		1,1,-1,
		-1,1,-1,

		-1,-1,1,
		1,-1,1,
		1,1,1,
		-1,1,1,

		-1,-1,-1,
		1,-1,-1,
		1,-1,1,
		-1,-1,1,

		-1,1,-1,
		1,1,-1,
		1,1,1,
		-1,1,1,

		-1,-1,-1,
		-1,-1,1,
		-1,1,1,
		-1,1,-1,

		1,-1,-1,
		1,-1,1,
		1,1,1,
		1,1,-1,
	};

	float myCubeColors[] = {
		0,1,0, 0,1,0, 0,1,0, 0,1,0,
		0,1,0, 0,1,0, 0,1,0, 0,1,0,
		0,0,1, 0,0,1, 0,0,1, 0,0,1,
		1,1,0, 1,1,0, 1,1,0, 1,1,0,
		0,1,1, 0,1,1, 0,1,1, 0,1,1,
		1,1,1, 1,1,1, 1,1,1, 1,1,1
	};
	float myCubeColors2[] = {
		0,0,1,	0,0,1,	0,0,1,	0,0,1,
		0,0,1,	0,0,1,	0,0,1,	0,0,1,
		1,1,0, 1,1,0, 1,1,0, 1,1,0,
		0,0,1,	0,0,1,	0,0,1,	0,0,1,
		0,0,1,	0,0,1,	0,0,1,	0,0,1,
		0,0,1,	0,0,1,	0,0,1,	0,0,1,
	};
	//Tablica wsp�rz�dnych wierzcho�k�w
	float smallQuadVertices[] = {
		-1,0, -1,
		1,0 ,-1,
		1,0, 1,
		-1,0, 1,
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wyczy�� bufor kolor�w (czyli przygotuj "p��tno" do rysowania)

														//***Przygotowanie do rysowania****
	mat4 P = perspective(50.0f*PI / 180.0f, 1.0f, 1.0f, 100.0f); //Wylicz macierz rzutowania P
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
			float grid = 0.065*(float)model->size;            // grid ustawia szeroko�� czarnych lini na minimapce dobrane empirycznie
			//float screen_width = 1000;


			//Change color depending on enum value->

			if (model->elements[y][x] == empty) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsRed); //Ustaw tablic� myCubeColors jako tablic� kolor�w
			}
			else if (model->elements[y][x] == fodder) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsRed); //Ustaw tablic� myCubeColors jako tablic� kolor�w
			}
			else if (model->elements[y][x] == snake_head) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue); //Ustaw tablic� myCubeColors jako tablic� kolor�w
			}
			else if (model->elements[y][x] == snake_part) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue); //Ustaw tablic� myCubeColors jako tablic� kolor�w
			}
			else if (model->elements[y][x] == snake_tail) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue); //Ustaw tablic� myCubeColors jako tablic� kolor�w
			}

			mat4 M = mat4(1.0f);
			M = scale(M, vec3(0.4f, 0.4f, 0.4f));
			M = translate(M, vec3( x, -1.0f, 21 - y));
			mat4 V= change_camera(model);
			glLoadMatrixf(value_ptr(V*M));
			




			glVertexPointer(3, GL_FLOAT, 0, smallQuadVertices); //Ustaw tablic� myCubeVertices jako tablic� wierzcho�k�w

																//glColorPointer(3, GL_FLOAT, 0, smallQuadColors); //Ustaw tablic� myCubeColors jako tablic� kolor�w

			glDrawArrays(GL_QUADS, 0, 4); //Rysuj model
			M = mat4(1.0f);
			M = scale(M, vec3(0.4f, 0.4f, 0.4f));
			M = translate(M, vec3( x, 0.0f, 21 - y));
			glLoadMatrixf(value_ptr(V*M));


			if (model->elements[y][x] == empty) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsRed);
			}
			else if (model->elements[y][x] == fodder) {
				glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);

				glColorPointer(3, GL_FLOAT, 0, myCubeColors);

				glDrawArrays(GL_QUADS, 0, myCubeVertexCount);
			}
			else if (model->elements[y][x] == snake_head) {

				glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);

				glColorPointer(3, GL_FLOAT, 0, myCubeColors2);

				glDrawArrays(GL_QUADS, 0, myCubeVertexCount);

			}
			else if (model->elements[y][x] == snake_part) {

				glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);

				glColorPointer(3, GL_FLOAT, 0, myCubeColors2);

				glDrawArrays(GL_QUADS, 0, myCubeVertexCount);

			}
			else if (model->elements[y][x] == snake_tail) {
				glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);

				glColorPointer(3, GL_FLOAT, 0, myCubeColors2);

				glDrawArrays(GL_QUADS, 0, myCubeVertexCount);

			}

		}
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);


	//glfwSwapBuffers(window); //Przerzu� tylny bufor na przedni
};

	