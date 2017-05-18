#include "draw3D.h"
using namespace glm;




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
		1,0,0, 1,0,0, 1,0,0, 1,0,0,
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
	//Tablica wspó³rzêdnych wierzcho³ków
	float smallQuadVertices[] = {
		-1,0, -1,
		1,0 ,-1,
		1,0, 1,
		-1,0, 1,
	};
	//Tablica kolorów wierzcho³ków
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wyczyœæ bufor kolorów (czyli przygotuj "p³ótno" do rysowania)

														//***Przygotowanie do rysowania****
	mat4 P = perspective(50.0f*PI / 180.0f, 1.0f, 1.0f, 100.0f); //Wylicz macierz rzutowania P
	/*mat4 V = lookAt( //Wylicz macierz widoku
		vec3(0.0f, 40.0f, 1.2*(float)model->size )+y,
		vec3(0.0f, 4.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0f));*/
	glMatrixMode(GL_PROJECTION); //W³¹cz tryb modyfikacji macierzy rzutowania
	glLoadMatrixf(value_ptr(P)); //Za³aduj macierz rzutowania
	glMatrixMode(GL_MODELVIEW);  //W³¹cz tryb modyfikacji macierzy model-widok
								 //***Rysowanie modelu***
								 //1. Wyliczenie i za³adowanie macierzy model-widok

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);



	// Rysowanie kwadratów
	for (int y = 0; y < model->size; y++)
	{
		for (int x = 0; x < model->size; x++)
		{
			float grid = 0.065*(float)model->size;            // grid ustawia szerokoœæ czarnych lini na minimapce dobrane empirycznie
			//float screen_width = 1000;


			//Change color depending on enum value->

			if (model->elements[y][x] == empty) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsRed); //Ustaw tablicê myCubeColors jako tablicê kolorów
			}
			else if (model->elements[y][x] == fodder) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsRed); //Ustaw tablicê myCubeColors jako tablicê kolorów
			}
			else if (model->elements[y][x] == snake_head) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue); //Ustaw tablicê myCubeColors jako tablicê kolorów
			}
			else if (model->elements[y][x] == snake_part) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue); //Ustaw tablicê myCubeColors jako tablicê kolorów
			}
			else if (model->elements[y][x] == snake_tail) {
				glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue); //Ustaw tablicê myCubeColors jako tablicê kolorów
			}

			mat4 M = mat4(1.0f);
			M = scale(M, vec3(0.4f, 0.4f, 0.4f));
			M = translate(M, vec3( x, -1.0f, 21 - y));
			mat4 V = lookAt( //Wylicz macierz widoku
				vec3( model->size + 0.4*model->head_position[1], 6.0f, ((1.5*(float)model->size) - 0.4 *model->head_position[0])),
				vec3(1.0*model->head_position[1]* 0.4f, 1.0f, -0.4*model->head_position[0]),
				vec3(0.0f, 1.0f, 0.0f));
			glLoadMatrixf(value_ptr(V*M));
			




			glVertexPointer(3, GL_FLOAT, 0, smallQuadVertices); //Ustaw tablicê myCubeVertices jako tablicê wierzcho³ków

																//glColorPointer(3, GL_FLOAT, 0, smallQuadColors); //Ustaw tablicê myCubeColors jako tablicê kolorów

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


	//glfwSwapBuffers(window); //Przerzuæ tylny bufor na przedni
};

	/*
	for (int y = 0; y < model->size; y++)
	{
		for (int x = 0; x < model->size; x++)
		{
			float grid = 0.065*(float)model->size;            // grid ustawia szerokoœæ czarnych lini na minimapce dobrane empirycznie
			float screen_width = 1000;


			//Change color depending on enum value->
			
			
			mat4 M = mat4(1.0f);
			M = scale(M, vec3(0.8f, 0.8f, 0.8f));
			M = translate(M, vec3(-0.02*screen_width + x*grid + x, 1.5f, 21 - y));
			mat4 V = lookAt( //Wylicz macierz widoku
				vec3(-0.5 * model->size + model->head_position[1], 10.0f, ((1.0*(float)model->size) - model->head_position[0])),
				vec3(0.0f, 4.0f, 0.0f),
				vec3(0.0f, 1.0f, 0.0f));
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


			glVertexPointer(3, GL_FLOAT, 0, smallQuadVertices); //Ustaw tablicê myCubeVertices jako tablicê wierzcho³ków

			glColorPointer(3, GL_FLOAT, 0, smallQuadColors); //Ustaw tablicê myCubeColors jako tablicê kolorów

			glDrawArrays(GL_QUADS, 0, 4); //Rysuj model
			
										  //Posprz¹taj po sobie

		}

	}
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);


	//glfwSwapBuffers(window); //Przerzuæ tylny bufor na przedni
};*/