#include "draw2D.h"


using namespace glm;

//Global variables
float aspect = 1.0f; //Aktualny stosunek szeroko�ci do wysoko�ci okna




					 //Tablica wsp�rz�dnych wierzcho�k�w
float smallQuadVertices[] = {
	-0.5,-0.5,0,
	0.5,-0.5,0,
	0.5, 0.5,0,
	-0.5, 0.5,0
};
//Tablica kolor�w wierzcho�k�w
float smallQuadColorsRed[] = {
	1,0,0,
	1,0,0,
	1,0,0,
	1,0,0
};
float smallQuadNormals[] = {
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f

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



//Procedura rysuj�ca zawarto�� sceny
void drawMinimap(GLFWwindow* window, GameModel* model) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glDisable(GL_LIGHTING); //W��cz tryb cieniowania
	glDisable(GL_LIGHT0); //W��cz zerowe �r�d�o �wiat�a
	
	mat4 P = perspective(50.0f*PI / 180.0f, aspect, 1.0f, 100.0f); //Wylicz macierz rzutowania P
	mat4 V = lookAt( //Wylicz macierz widoku
		vec3(-1.7f, -1.7f, 6.0f),		// observer		// empirycznie dobrane dane w celu drukowania minimapki w prawym g�rnym rogu
		vec3(-1.7f, -1.7f, 0.0f),							//center
		vec3(0.0f, 1.0f, 0.0f));						//nose vector
	mat4 M;
	
	
	float scale_value = 1.0f/model->size;
	glMatrixMode(GL_PROJECTION); //W��cz tryb modyfikacji macierzy rzutowania
	glLoadMatrixf(value_ptr(P)); //Za�aduj macierz rzutowania
	glMatrixMode(GL_MODELVIEW);  //W��cz tryb modyfikacji macierzy model-widok
						 //***Rysowanie modelu***
								 //1. Wyliczenie i za�adowanie macierzy model-widok
	
	
	
	//Draw the floor
	M = mat4(1.0f);
	M = translate(M, vec3( 0.5f, 0.5f, -0.00001f));  // na pocz�tek ukadu wsp�rz�dnych
	
	
	
	
	glLoadMatrixf(value_ptr(V*M));
	glVertexPointer(3, GL_FLOAT, 0, smallQuadVertices); //Ustaw tablic� myCubeVertices jako tablic� wierzcho�k�w
	glColorPointer(3, GL_FLOAT, 0, smallQuadColorsRed); 	//Change color to floor color
	
	glDrawArrays(GL_QUADS, 0, 4);

	// Draw squares
	for (int y = 0; y < model->size; y++)
	{
		for (int x = 0; x < model->size; x++)
		{
				
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
				M = translate(M, vec3( x*scale_value,  y*scale_value, 0));
				M = scale(M, vec3(scale_value));
				
				glLoadMatrixf(value_ptr(V*M));
			
				glVertexPointer(3, GL_FLOAT, 0, smallQuadVertices); //Ustaw tablic� myCubeVertices jako tablic� wierzcho�k�w
				glDrawArrays(GL_QUADS, 0, 4); //Rysuj model			
			}
		}		
	}
									  //Posprz�taj po sobie
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	glEnable(GL_LIGHTING); //W��cz tryb cieniowania
	glEnable(GL_LIGHT0); //W��cz zerowe �r�d�o �wiat�a


	
}
