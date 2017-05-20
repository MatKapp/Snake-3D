#include "draw2D.h"


using namespace glm;

//Global variables
float aspect = 1.0f; //Aktualny stosunek szerokoœci do wysokoœci okna




					 //Tablica wspó³rzêdnych wierzcho³ków
float smallQuadVertices[] = {
	-0.5,-0.5,0,
	0.5,-0.5,0,
	0.5, 0.5,0,
	-0.5, 0.5,0
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

float smallQuadColorsWhite[] = {
	1,1,1,
	1,1,1,
	1,1,1,
	1,1,1,
};

float smallQuadColorsBlack[] = {
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
};

float smallQuadColorsYellow[] = {
	1,1,0,
	1,1,0,
	1,1,0,
	1,1,0,
};



//Procedura rysuj¹ca zawartoœæ sceny
void drawMinimap(GLFWwindow* window, GameModel* model) {
	//************Tutaj umieszczaj kod rysuj¹cy obraz******************l

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wyczyœæ bufor kolorów (czyli przygotuj "p³ótno" do rysowania)

													//***Przygotowanie do rysowania****
	mat4 P = perspective(50.0f*PI / 180.0f, aspect, 1.0f, 50.0f); //Wylicz macierz rzutowania P
	mat4 V = lookAt( //Wylicz macierz widoku
		vec3(0.0f, 0.0f, 1.2 * (float)model->size),		// observer
		vec3(0.0f, 0.0f, 0.0f),							//center
		vec3(0.0f, 1.0f, 0.0f));						//nose vector
	mat4 M;
	float size_coeficient = 35.f / (float)(model->size);
	float scale_value = 0.15f * size_coeficient;
	float offset = 90.0 /  size_coeficient;
	glMatrixMode(GL_PROJECTION); //W³¹cz tryb modyfikacji macierzy rzutowania
	glLoadMatrixf(value_ptr(P)); //Za³aduj macierz rzutowania
	glMatrixMode(GL_MODELVIEW);  //W³¹cz tryb modyfikacji macierzy model-widok
						 //***Rysowanie modelu***
								 //1. Wyliczenie i za³adowanie macierzy model-widok
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	//Draw the floor
	M = mat4(1.0f);
	M = scale(M, vec3(scale_value));
	M = translate(M, vec3(offset + 0.5 * model->size, offset + 0.5 * model->size,  -1.0f));	//Floor is under tales so z = -1
	M = scale(M, vec3(model->size));
	glLoadMatrixf(value_ptr(V*M));
	glVertexPointer(3, GL_FLOAT, 0, smallQuadVertices); //Ustaw tablicê myCubeVertices jako tablicê wierzcho³ków
	glColorPointer(3, GL_FLOAT, 0, smallQuadColorsRed); 	//Change color to floor color
	glDrawArrays(GL_QUADS, 0, 4);

	// Draw squares
	for (int y = 0; y < model->size; y++)
	{
		for (int x = 0; x < model->size; x++)
		{
			//float grid = 0.065*(float) model->size;            // grid ustawia szerokoœæ czarnych lini na minimapce dobrane empirycznie
			
			if (model->elements[y][x] == empty) {
				continue;
			}
			else {
				//Change color depending on enum value->
				if (model->elements[y][x] == fodder) {
					glColorPointer(3, GL_FLOAT, 0, smallQuadColorsGreen);
				}
				else if (model->elements[y][x] == snake_part) {
					glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue);
				}
				else if (model->elements[y][x] == snake_head) {
					glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue);
				}
				else if (model->elements[y][x] == snake_tail) {
					glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlue);
				}
				else if (model->elements[y][x] == trap) {
					glColorPointer(3, GL_FLOAT, 0, smallQuadColorsBlack);
				}
				else if (model->elements[y][x] == speed_boost) {
					glColorPointer(3, GL_FLOAT, 0, smallQuadColorsWhite);
				}
				else if (model->elements[y][x] == slow_boost) {
					glColorPointer(3, GL_FLOAT, 0, smallQuadColorsYellow);
				}

				M = mat4(1.0f);
				M = scale(M, vec3(scale_value));
				M = translate(M, vec3(offset + x, offset + y, 0.0f));
				glLoadMatrixf(value_ptr(V*M));
			
				glVertexPointer(3, GL_FLOAT, 0, smallQuadVertices); //Ustaw tablicê myCubeVertices jako tablicê wierzcho³ków
				glDrawArrays(GL_QUADS, 0, 4); //Rysuj model			
			}
		}		
	}
									  //Posprz¹taj po sobie
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);


	//glfwSwapBuffers(window); //Przerzuæ tylny bufor na przedni
}
